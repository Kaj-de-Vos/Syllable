/*
 *  The Syllable application server
 *  Copyright (C) 1999 - 2001  Kurt Skauen
 *  Copyright (C) 2003  Kristian Van Der Vliet
 *
 *  This program is free software; you can redistribute it and/or
 *  modify it under the terms of version 2 of the GNU Library
 *  General Public License as published by the Free Software
 *  Foundation.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program; if not, write to the Free Software
 *  Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 */

#include <gui/bitmap.h>
#include <exception>

#include "mga.h"
#include "mga_regs.h"
#include "mga_crtc.h"
#include "../../../server/bitmap.h"

using namespace os;

// FIXME: Merge into <atheos/pci_vendors.h>
#define PCI_VENDOR_ID_MATROX				0x102B
#define PCI_DEVICE_ID_MATROX_MGA			0x0010		// MGA-I [Impression]
#define PCI_DEVICE_ID_MATROX_MGA_2			0x0518		// MGA-II [Athena]
#define PCI_DEVICE_ID_MATROX_MIL			0x0519		// 2064W [Millennium]
#define PCI_DEVICE_ID_MATROX_MYS			0x051A		// 1064SG [Mystique]
#define PCI_DEVICE_ID_MATROX_MYS_2			0x0100		// 1064SG [Mystique]
#define PCI_DEVICE_ID_MATROX_MYS_AGP		0x051e		// 1064SG [Mystique] AGP
#define PCI_DEVICE_ID_MATROX_MIL_2			0x051b		// 2164W [Millennium II] PCI
#define PCI_DEVICE_ID_MATROX_MIL_2_AGP		0x051f		// 2164W [Millennium II] AGP
#define PCI_DEVICE_ID_MATROX_MGA_IMP		0x0d10		// Ultima
#define PCI_DEVICE_ID_MATROX_G100_PCI		0x1000		// G100 [Productiva] PCI
#define PCI_DEVICE_ID_MATROX_G100_AGP		0x1001		// G100 [Productiva] AGP
#define PCI_DEVICE_ID_MATROX_G200_PCI		0x0520		// G200 PCI
#define PCI_DEVICE_ID_MATROX_G200_AGP		0x0521		// G200 AGP
#define PCI_DEVICE_ID_MATROX_G400			0x0525		// G400
#define PCI_DEVICE_ID_MATROX_MIS			0x2007		// Mistral
#define PCI_DEVICE_ID_MATROX_G550			0x2527		// G550
#define PCI_DEVICE_ID_MATROX_PAR			0x0527		// Parhelia

static struct MGAChip_s gs_sChips[MAXCHIPS] = {
	{ PCI_DEVICE_ID_MATROX_MGA, "MGA-I [Impression]", TVP3026 },
	{ PCI_DEVICE_ID_MATROX_MGA_2, "MGA-II [Athena]", TVP3026 },
	{ PCI_DEVICE_ID_MATROX_MIL, "2064W [Millennium]", TVP3026 },
	{ PCI_DEVICE_ID_MATROX_MYS, "1064SG [Mystique]", TVP3026 },
	{ PCI_DEVICE_ID_MATROX_MYS_2, "1064SG [Mystique]", TVP3026 },
	{ PCI_DEVICE_ID_MATROX_MYS_AGP, "1064SG [Mystique] AGP", TVP3026 },
	{ PCI_DEVICE_ID_MATROX_MIL_2, "2164W [Millennium II] PCI", TVP3026 },
	{ PCI_DEVICE_ID_MATROX_MIL_2_AGP, "2164W [Millennium II] AGP", TVP3026 },
	{ PCI_DEVICE_ID_MATROX_MGA_IMP, "Ultima", TVP3026 },
	{ PCI_DEVICE_ID_MATROX_G100_PCI, "G100 [Productiva] PCI", MGAGx00 },
	{ PCI_DEVICE_ID_MATROX_G100_AGP, "G100 [Productiva] AGP", MGAGx00 },
	{ PCI_DEVICE_ID_MATROX_G200_PCI, "G200 PCI", MGAGx00 },
	{ PCI_DEVICE_ID_MATROX_G200_AGP, "G200 AGP", MGAGx00 },
	{ PCI_DEVICE_ID_MATROX_G400, "G400", MGAGx00 },
	{ PCI_DEVICE_ID_MATROX_MIS, "Mistral", MGAGx00 },
	{ PCI_DEVICE_ID_MATROX_G550, "G550", MGAGx50 },
	{ PCI_DEVICE_ID_MATROX_PAR, "Parhelia", MGAGx50 },
	{ 0, "Unknown", NONE }
};

Matrox::Matrox() : m_cGELock( "matrox_ge_lock" ), m_cCursorHotSpot(0,0)
{
	int i;
	bool bFound = false;

	m_bIsInitiated = false;
	m_hRegisterArea = -1;
	m_hFrameBufferArea = -1;

	for( i = 0; get_pci_info( &m_cPCIInfo, i ) == 0; i++ )
	{
		if( m_cPCIInfo.nVendorID == PCI_VENDOR_ID_MATROX )
		{
			bFound = true;
			break;
		}
	}

	if ( bFound == false )
	{
		dbprintf( "No MGA card\n" );
		return;
	}

	// Poison the chip info
	m_sChip.nDeviceID = gs_sChips[MAXCHIPS].nDeviceID;
	m_sChip.zName = gs_sChips[MAXCHIPS].zName;
	m_sChip.eDAC = gs_sChips[MAXCHIPS].eDAC;

	// Match the card to our list and ensure it is a supported card
	for( i = 0; i < MAXCHIPS; i++ )
	{
		if( gs_sChips[i].nDeviceID == m_cPCIInfo.nDeviceID )
		{
			m_sChip.nDeviceID = gs_sChips[i].nDeviceID;
			m_sChip.zName = gs_sChips[i].zName;
			m_sChip.eDAC = gs_sChips[i].eDAC;

			break;
		}
	}

	if( m_sChip.nDeviceID == 0 )
	{
		dbprintf( "Found an Unknown Matrox device.  ID 0x%04x\n", m_cPCIInfo.nDeviceID );
		return;
	}
	else
		dbprintf( "Found a Matrox %s\n", m_sChip.zName );

	m_hRegisterArea = create_area( "matrox_regs",(void**) &m_pRegisterBase, MGA_REG_WINDOW, AREA_FULL_ACCESS, AREA_NO_LOCK );

	if ( m_hRegisterArea < 0 )
	{
		dbprintf( "Matrox::Open() failed to create register area (%d)\n", m_hRegisterArea );
		return;
	}

	if( m_sChip.nDeviceID == PCI_DEVICE_ID_MATROX_MIL )
	{
		// The Millenium I is a bit special, the frame buffer, and the
		// I/O area is swapped compared to the other Matrox boards...
		remap_area( m_hRegisterArea, (void*) (m_cPCIInfo.u.h0.nBase0 & PCI_ADDRESS_MEMORY_32_MASK) );
	}
	else
		remap_area( m_hRegisterArea, (void*) (m_cPCIInfo.u.h0.nBase1 & PCI_ADDRESS_MEMORY_32_MASK) );

	// FIXME: Remove all hardware pointer code
	m_nPointerScheme = POINTER_SPRITE;

	// FIXME: Re-write CRTC code
	if(	m_sChip.nDeviceID == PCI_DEVICE_ID_MATROX_G100_PCI	||
		m_sChip.nDeviceID == PCI_DEVICE_ID_MATROX_G100_AGP	||
		m_sChip.nDeviceID == PCI_DEVICE_ID_MATROX_G200_PCI	||
		m_sChip.nDeviceID == PCI_DEVICE_ID_MATROX_G200_AGP	||
		m_sChip.nDeviceID == PCI_DEVICE_ID_MATROX_G400 )
	{
		m_nCRTCScheme = CRTC_GX00;
	}
	else
		m_nCRTCScheme = CRTC_VESA;

	if( m_nCRTCScheme == CRTC_GX00 )
	{
		// FIXME: Find out if the actualy is ram for the resolution...
		color_space colspace[3] = { CS_RGB15, CS_RGB16, CS_RGB32 };
		int bpp[3] = { 2, 2, 4 };
		float rf[] = { 60.0f, 75.0f, 85.0f, 100.0f };

		for( int i=0; i<3; i++ )
		{
			for( int j = 0; j < 4; j++ ) 
			{
	    		m_cScreenModeList.push_back( os::screen_mode(640, 480, (640*bpp[i]+15)&~15, colspace[i], rf[j]) );
	    		m_cScreenModeList.push_back( os::screen_mode(800, 600, (800*bpp[i]+15)&~15, colspace[i], rf[j]) );
	    		m_cScreenModeList.push_back( os::screen_mode(1024, 768, (1024*bpp[i]+15)&~15, colspace[i], rf[j]) );
	    		m_cScreenModeList.push_back( os::screen_mode(1152, 864, (1152*bpp[i]+15)&~15, colspace[i], rf[j]) );
	    		m_cScreenModeList.push_back( os::screen_mode(1280, 1024, (1280*bpp[i]+15)&~15, colspace[i], rf[j]) );
	    		m_cScreenModeList.push_back( os::screen_mode(1376, 1068, (1376*bpp[i]+15)&~15, colspace[i], rf[j]) );
	    		m_cScreenModeList.push_back( os::screen_mode(1440, 1112, (1440*bpp[i]+15)&~15, colspace[i], rf[j]) );
	    		m_cScreenModeList.push_back( os::screen_mode(1536, 1156, (1536*bpp[i]+15)&~15, colspace[i], rf[j]) );
	    		m_cScreenModeList.push_back( os::screen_mode(1600, 1200, (1600*bpp[i]+15)&~15, colspace[i], rf[j]) );
	    		m_cScreenModeList.push_back( os::screen_mode(2048, 1536, (2048*bpp[i]+15)&~15, colspace[i], rf[j]) );
			}
		}

		m_hFrameBufferArea = create_area( "matrox_framebuffer",(void**) &m_pFrameBufferBase, 32*1024*1024, AREA_FULL_ACCESS, AREA_NO_LOCK );
		remap_area( m_hFrameBufferArea, (void*) (m_cPCIInfo.u.h0.nBase0 & PCI_ADDRESS_MEMORY_32_MASK) );

		m_cCrtc = new MgaCRTC( m_pRegisterBase );
	}
	// FIXME: Implement code for TVP3026 & Gx50 DAC types

	if( m_nPointerScheme == POINTER_MILLENIUM )
		m_cLastMousePosition = IPoint( 0, 0 );

	write_pci_config( m_cPCIInfo.nBus, m_cPCIInfo.nDevice, m_cPCIInfo.nFunction, 0x04, 4, 0x00000003 );
	m_bIsInitiated = true;
}

Matrox::~Matrox()
{
	if( m_cCrtc )
		delete( m_cCrtc );

	if( m_hRegisterArea != -1 )
		delete_area( m_hRegisterArea );

	if( m_nCRTCScheme == CRTC_GX00 && m_hFrameBufferArea != -1 )
		delete_area( m_hFrameBufferArea );
}

//-----------------------------------------------------------------------------

area_id Matrox::Open()
{
	area_id hFrameBufferArea;

	if( m_nCRTCScheme == CRTC_VESA )
	{
		hFrameBufferArea = VesaDriver::Open();
		if ( hFrameBufferArea < 0  )
		{
			dbprintf( "Matrox::Open() Vesa driver failed to initialize\n" );
			delete_area( m_hRegisterArea );
			hFrameBufferArea = -1;
		}
	}
	else
		hFrameBufferArea = m_hFrameBufferArea;

	return( hFrameBufferArea );
}

//-----------------------------------------------------------------------------

int Matrox::GetScreenModeCount()
{
	if( m_nCRTCScheme == CRTC_GX00 )
		return m_cScreenModeList.size();
	else
		return VesaDriver::GetScreenModeCount();
}

bool Matrox::GetScreenModeDesc( int nIndex, os::screen_mode* psMode )
{
	if( m_nCRTCScheme == CRTC_GX00 )
	{
		if( nIndex<0 || nIndex >= int( m_cScreenModeList.size() ) )
			return false;

			*psMode = m_cScreenModeList[nIndex];
			return true;
	}
	else
		return VesaDriver::GetScreenModeDesc( nIndex, psMode );
}

int Matrox::SetScreenMode( os::screen_mode sMode )
{
	int nError = -1;
	bool bModeFound = false;

	// Anti appserver hack 
	if( sMode.m_vRefreshRate == 55 )
		sMode.m_vRefreshRate = 70;

	if( m_nCRTCScheme == CRTC_GX00 )
	{
		for( uint i=0; i<m_cScreenModeList.size(); i++ )
		{
			if(	 m_cScreenModeList[i].m_nWidth == sMode.m_nWidth &&
				 m_cScreenModeList[i].m_nHeight == sMode.m_nHeight &&
				 m_cScreenModeList[i].m_eColorSpace == sMode.m_eColorSpace )
			{
				bModeFound = true;
				break;
			}
		}

		if( bModeFound )
		{
			int nBPP = 0;

			switch( sMode.m_eColorSpace )
			{
				case CS_RGB15:
					nBPP = 15;
					break;

				case CS_RGB16:
					nBPP = 16;
					break;

				case CS_RGB32:
					nBPP = 32;
					break;

				default:
					dbprintf("Unsupported colourspace %i requested\n", sMode.m_eColorSpace );
			}

			nError = m_cCrtc->SetMode( sMode.m_nWidth, sMode.m_nHeight, nBPP, sMode.m_vRefreshRate ) ? 0 : -1;
		}
	}
	else
		nError = VesaDriver::SetScreenMode( sMode );

	if( m_nPointerScheme == POINTER_MILLENIUM )
	{
		// The BIOS seems to screw around with the mouse registers :(
		SetMousePos( m_cLastMousePosition );

		// show the pointer:
		int tmp = inb(TVP3026_CURSOR_CTL)&0x6c;
		outb( TVP3026_INDEX, TVP3026_CURSOR_CTL );
		outb( TVP3026_DATA, tmp|0x13 );
	}

	m_sCurrentMode = sMode;
	m_sCurrentMode.m_nBytesPerLine = sMode.m_nWidth * ( ( BitsPerPixel( sMode.m_eColorSpace ) + 1 ) / 8 );

	return( nError );
}

os::screen_mode Matrox::GetCurrentScreenMode()
{
	return( m_sCurrentMode );
}

//-----------------------------------------------------------------------------

void Matrox::MouseOn( void )
{
	if( m_nPointerScheme == POINTER_SPRITE )
		VesaDriver::MouseOn();
}

void Matrox::MouseOff( void )
{
	if( m_nPointerScheme == POINTER_SPRITE )
		VesaDriver::MouseOff();
}

void Matrox::SetMousePos( IPoint cNewPos )
{
	if( m_nPointerScheme == POINTER_MILLENIUM )
	{
		int x = cNewPos.x - m_cCursorHotSpot.x + 64;
		int y = (cNewPos.y*2) - (m_cCursorHotSpot.y*2) + 64;
		
		m_cGELock.Lock();	 // The pointer stuff is likely to be independent from the blitter stuff,
							 //  but just to be sure...
		outb( TVP3026_CUR_XLOW, x&0xff );
		outb( TVP3026_CUR_XHI, (x>>8)&0x0f );
		outb( TVP3026_CUR_YLOW, y&0xff );
		outb( TVP3026_CUR_YHI, (y>>8)&0x0f );

		m_cGELock.Unlock();
		m_cLastMousePosition = cNewPos;
	}
	else
		VesaDriver::SetMousePos( cNewPos );
}

void Matrox::SetCursorBitmap( mouse_ptr_mode eMode, const IPoint& cHotSpot, const void* pRaster, int nWidth, int nHeight )
{
	m_cCursorHotSpot = cHotSpot;

	if( eMode == MPTR_MONO && m_nPointerScheme == POINTER_MILLENIUM )
	{
		const uint8* bits = static_cast<const uint8*>(pRaster);
		m_cGELock.Lock();

		// Disable cursor
		int tmp = inb(TVP3026_CURSOR_CTL)&0xfc;
		outb( TVP3026_INDEX, TVP3026_CURSOR_CTL );
		outb( TVP3026_DATA, tmp );

		tmp = inb(TVP3026_CURSOR_CTL)&0xf3;
		outb( TVP3026_INDEX, TVP3026_CURSOR_CTL );
		outb( TVP3026_DATA, tmp );
		outb( TVP3026_WADR_PAL, 0x00 );

		for( int imask=0x01; imask<=0x02; imask<<=1 )
		{
			for( int iy=0; iy<64; iy++ )
			{
				for( int ix=0; ix<64; ix+=8 )
				{
					uint8 bit = 0;
					for( int ix2=0; ix2<8; ix2++ )
					{
						int srcy = iy/2;	// for some unknown reason, only every second scanline shows up,
											// maybe it's an interlace thing?
						uint8 col = ((ix+ix2)<nWidth && srcy < nHeight) ? bits[(ix+ix2)+srcy*nWidth] : 0x00;
						bit |= ((col&imask)?1:0)<<(7-ix2);
					}

					while (inb(0x1fda) & 0x01);
					while (!(inb(0x1fda) & 0x01));
					outb( TVP3026_CUR_RAM, bit );

				}
			}
		}

		// set pointer colors:
		outb(TVP3026_CUR_COL_ADDR, 1);
		outb(TVP3026_CUR_COL_DATA, 0x00 );
		outb(TVP3026_CUR_COL_DATA, 0x00 );
		outb(TVP3026_CUR_COL_DATA, 0x00 );
		outb(TVP3026_CUR_COL_ADDR, 2);
		outb(TVP3026_CUR_COL_DATA, 0xff );
		outb(TVP3026_CUR_COL_DATA, 0xff );
		outb(TVP3026_CUR_COL_DATA, 0xff );

		// Enable cursor
		tmp = inb(TVP3026_CURSOR_CTL)&0x6c;
		outb( TVP3026_INDEX, TVP3026_CURSOR_CTL );
		outb( TVP3026_DATA, tmp|0x13 );

		m_cGELock.Unlock();
		SetMousePos( m_cLastMousePosition );
	}
	else
		VesaDriver::SetCursorBitmap( eMode, cHotSpot, pRaster, nWidth, nHeight );
}

//-----------------------------------------------------------------------------

bool Matrox::DrawLine( SrvBitmap* pcBitMap, const IRect& cClipRect,
			   const IPoint& cPnt1, const IPoint& cPnt2, const Color32_s& sColor, int nMode )
{
    if ( pcBitMap->m_bVideoMem == false || nMode != DM_COPY ) {
	return( VesaDriver::DrawLine( pcBitMap, cClipRect, cPnt1, cPnt2, sColor, nMode ) );
    }
    int nYDstOrg = 0; // Number of pixels (not bytes) from top of memory to frame buffer
    int nPitch = pcBitMap->m_nBytesPerLine ;
    uint32 nColor;
  
    uint32 nCtrl = M2_OPCODE_AUTOLINE_CLOSE | M2_ATYPE_RPL | M2_SOLID | M2_SHFTZERO | M2_BLTMOD_BFCOL | 0xc0000;


    int x1 = cPnt1.x;
    int y1 = cPnt1.y;
    int x2 = cPnt2.x;
    int y2 = cPnt2.y;
  
    IRect cBmRect( -32768, -32768, 32767, 32767 );
      // Clip the line to valid values
    if ( ClipLine( cBmRect, &x1, &y1, &x2, &y2 ) == false ) {
	return( false );
    }
  
    switch( pcBitMap->m_eColorSpc )
    {
//    case CS_CMAP8:
//      break;
	case CS_RGB15:
	    nColor = COL_TO_RGB15( sColor );
	    nColor |= nColor << 16;
	    nPitch /= 2;
	    break;
	case CS_RGB16:
	    nColor = COL_TO_RGB16( sColor );
	    nColor |= nColor << 16;
	    nPitch /= 2;
	    break;
	case CS_RGB24:
	    nColor = COL_TO_RGB32( sColor );
	    nPitch /= 3;
	    break;
	case CS_RGB32:
	    nColor = COL_TO_RGB32( sColor );
	    nPitch /= 4;
	    break;
	default:
	    nColor = 0;
	    dbprintf( "Matrox::BltBitmap() invalid color space %d\n", pcBitMap->m_eColorSpc );
	    break;
    }
  
    m_cGELock.Lock();
  
    outl( M2_DWGCTL, nCtrl  );
    outl( M2_PITCH, nPitch );
  
      // Init the clipper
    outl( M2_CXBNDRY, cClipRect.left | (cClipRect.right << 16) );	// Left/right clipping boundary
    outl( M2_YTOP, cClipRect.top * nPitch + nYDstOrg );
    outl( M2_YBOT, cClipRect.bottom * nPitch + nYDstOrg );
      // Set line coordinates

    outl( M2_XYSTRT, (x1 & 0xffff) | ((y1 & 0xffff) << 16) );
    outl( M2_XYEND, (x2 & 0xffff) | ((y2 & 0xffff) << 16) );

    outl( M2_FCOL + 0x100, nColor );
  
    while( inl( M2_STATUS ) & M2_DWGENGSTS );
  
    m_cGELock.Unlock();
    return( true );
}

bool Matrox::FillRect( SrvBitmap* pcBitMap, const IRect& cRect, const Color32_s& sColor )
{
    if ( pcBitMap->m_bVideoMem == false /*|| nMode != DM_COPY*/ ) {
	return( VesaDriver::FillRect( pcBitMap, cRect, sColor ) );
    }
      // Page 242
    int nHeight= cRect.Height() + 1;
    int nPitch = pcBitMap->m_nBytesPerLine;
    int nYDstOrg = 0; // Number of pixels (not bytes) from top of memory to frame buffer
    uint32 nColor;
  
      // Page 87/243
    uint32 nCtrl =
	M2_OPCODE_TRAP |
	M2_ATYPE_RPL |
	M2_SOLID |
	M2_ARZERO |
	M2_SGNZERO |
	M2_SHFTZERO |
	M2_BLTMOD_BMONOLEF |
	M2_TRANSC |
	0xc0000;

    m_cGELock.Lock();
    outl( M2_DWGCTL, nCtrl  );

    switch( pcBitMap->m_eColorSpc )
    {
//    case CS_CMAP8:
//      outl( M2_MACCESS, 0x00 );
//      break;
	case CS_RGB15:
	    nPitch /= 2;
	    outl( M2_MACCESS, 0x01 );
	    nColor = COL_TO_RGB15( sColor );
	    nColor |= nColor << 16;
	    break;
	case CS_RGB16:
	    nPitch /= 2;
	    outl( M2_MACCESS, 0x01 );
	    nColor = COL_TO_RGB16( sColor );
	    nColor |= nColor << 16;
	    break;
	case CS_RGB24:
	    nPitch /= 3;
	    outl( M2_MACCESS, 0x03 );
	    nColor = COL_TO_RGB32( sColor );
	    break;
	case CS_RGB32:
	    nPitch /= 4;
	    outl( M2_MACCESS, 0x02 );
	    nColor = COL_TO_RGB32( sColor );
	    break;
	default:
	    nColor = 0;
	    dbprintf( "Matrox::BltBitmap() invalid color space %d\n", pcBitMap->m_eColorSpc );
	    break;
    }
    outl( M2_PITCH, nPitch );

    outl( M2_YDSTLEN, (cRect.top << 16) | nHeight );
    outl( M2_YDSTORG, nYDstOrg );
  
    outl( M2_CXBNDRY, 0 | ((pcBitMap->m_nWidth-1) << 16) );	// Left/right clipping boundary
    outl( M2_YTOP, 0 * nPitch + nYDstOrg );
    outl( M2_YBOT, (pcBitMap->m_nHeight-1) * nPitch + nYDstOrg );
    outl( M2_PLNWT, ~0L );
    outl( M2_FXBNDRY, cRect.left | ((cRect.right + 1) << 16) );
    outl( M2_FCOL + 0x100, nColor );
  
    while( inl( M2_STATUS ) & M2_DWGENGSTS );
    m_cGELock.Unlock();
    return( true );
  
}

bool Matrox::BltBitmap( SrvBitmap* pcDstBitMap, SrvBitmap* pcSrcBitMap,
			    IRect cSrcRect, IPoint cDstPos, int nMode )
{
    if ( pcDstBitMap->m_bVideoMem == false || pcSrcBitMap->m_bVideoMem == false || nMode != DM_COPY ) {
	return( VesaDriver::BltBitmap( pcDstBitMap, pcSrcBitMap, cSrcRect, cDstPos, nMode ) );
    }
      // Page 242
    int nWidth = cSrcRect.Width() + 1;
    int nHeight= cSrcRect.Height() + 1;
    int nPitch = pcSrcBitMap->m_nBytesPerLine;
    int nYDstOrg = 0; // Number of pixels (not bytes) from top of memory to frame buffer
    uint32 nSign = 0;
  
      // Page 87/243
    uint32 nCtrl = M2_OPCODE_BITBLT | M2_ATYPE_RPL | M2_SHFTZERO | M2_BLTMOD_BFCOL | 0xc0000;

    switch( pcSrcBitMap->m_eColorSpc )
    {
	case CS_RGB15:
	case CS_RGB16:
	    nPitch /= 2;
	    break;
	case CS_RGB24:
	    nPitch /= 3;
	    break;
	case CS_RGB32:
	    nPitch /= 4;
	    break;
	default:
	    dbprintf( "Matrox::BltBitmap() invalid color space %d\n", pcSrcBitMap->m_eColorSpc );
	    break;
    }
    int nSrcStartAddr = cSrcRect.left + cSrcRect.top * nPitch;
  
    m_cGELock.Lock();
  
    outl( M2_DWGCTL, nCtrl  );
    outl( M2_PITCH, nPitch );

    if ( cSrcRect.top < cDstPos.y ) {
	nSrcStartAddr = cSrcRect.left + (cSrcRect.bottom) * nPitch;
//	outl( M2_AR5, (-nPitch) & 0x3ffff );	// For Mil->G200
//	outl( M2_AR5, (-nPitch) & 0x3fffff );	// For G400
	outl( M2_AR5, (-nPitch) );		// Safe according to the manuals
	outl( M2_YDSTLEN, ((cDstPos.y + nHeight - 1) << 16) | nHeight );
	nSign |= M2_SGN_SDY; // Negative delta y
    } else {
	outl( M2_AR5, nPitch );
	outl( M2_YDSTLEN, (cDstPos.y << 16) | nHeight );
    }
    outl( M2_YDSTORG, nYDstOrg );

    switch( pcSrcBitMap->m_eColorSpc )
    {
	case CS_CMAP8:
	    outl( M2_MACCESS, 0x00 );
	    break;
	case CS_RGB15:
	case CS_RGB16:
	    outl( M2_MACCESS, 0x01 );
	    break;
	case CS_RGB24:
	    outl( M2_MACCESS, 0x03 );
	    break;
	case CS_RGB32:
	    outl( M2_MACCESS, 0x02 );
	    break;
	default:
	    dbprintf( "Matrox::BltBitmap() invalid color space %d\n", pcSrcBitMap->m_eColorSpc );
	    break;
    }
    outl( M2_CXBNDRY, 0 | ((pcDstBitMap->m_nWidth-1) << 16) );	// Left/right clipping boundary
    outl( M2_YTOP, 0 * nPitch + nYDstOrg );
    outl( M2_YBOT, (pcDstBitMap->m_nHeight-1) * nPitch + nYDstOrg );
    outl( M2_PLNWT, ~0L );

    outl( M2_FXBNDRY, cDstPos.x | ((cDstPos.x + nWidth - 1) << 16) );

    if ( cSrcRect.left < cDstPos.x ) {
	outl( M2_AR0, nSrcStartAddr );
	outl( M2_AR3, nSrcStartAddr + nWidth - 1 );
	nSign |= M2_SGN_SCANLEFT;
    } else {
	outl( M2_AR3, nSrcStartAddr );
	outl( M2_AR0, nSrcStartAddr + nWidth - 1 );
    }
    outl( M2_SGN + 0x100, nSign );

    while( inl( M2_STATUS ) & M2_DWGENGSTS );
    m_cGELock.Unlock();
    return( true );
}

extern "C" DisplayDriver* init_gfx_driver()
{
	dbprintf( "mga driver attempts to initialize\n" );

	Matrox* pcDriver = new Matrox();

	if ( pcDriver->IsInitiated() ) {
		return( pcDriver );
	}
	else
	{
		delete pcDriver;
		return( NULL );
	}
}

