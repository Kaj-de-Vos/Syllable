#ifndef DRIVE_SETTINGS_H
#define DRIVE_SETTINGS_H

#include <gui/window.h>
#include <gui/listview.h>
#include <gui/button.h>
#include <gui/textview.h>
#include <gui/dropdownmenu.h>
#include <gui/stringview.h>
#include <util/message.h>
#include "drives_messages.h"
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <atheos/device.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/ioctl.h>
#include <atheos/types.h>
#include <atheos/time.h>
#include <atheos/kernel.h>
#include <atheos/device.h>
#include <dirent.h>
#include <gui/imagebutton.h>
#include <gui/image.h>
#include <util/resources.h>
#include <gui/filerequester.h>
#include "crect.h"
using namespace os;

class DiskInfo;
class DriveWindow : public Window
{
public:
	DriveWindow(Window* pcWindow);
	~DriveWindow();
	
	
private:	
	Button* pcOk;
	Button* pcCancel;
	Button* pcAdd;
	Button* pcRemove;
	Button* pcRefresh;
	ListView* pcList;
	void SetupDrives();
	char* GetInit();
	void HandleMessage(Message* pcMessage);
	char pzDriveDevice[20][200];
	char pzDriveMount[20][200];
	void SaveInit();
	void Add();
	FILE* fout;
	Window* pcAddWindow;
};


class AddWindow : public Window
{
public:
	AddWindow(Window* pcWindow);
	//~AddWindow();

private:
	DropdownMenu* pcDeviceDrop;
	Button* pcOk;
	Button* pcCancel;
	TextView* pcText;
	BitmapImage* GetImage(const char* pzFile);
	StringView* pcDeviceString;
	StringView* pcMountString;
	void HandleMessage(Message* pcMessage);
	Window* pcWin;
	FileRequester* pcOpenRequest;
	string pzFPath, pzStorePath;
	
};

struct DiskInfo
{
    std::string		m_cPath;
    int			m_nDiskFD;
    device_geometry	m_sDriveInfo;
};
	
#endif


















