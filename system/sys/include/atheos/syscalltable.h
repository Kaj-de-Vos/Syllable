/*
 *  The Syllable kernel
 *  Copyright (C) 1999 Kurt Skauen
 *  Copyright (C) 2004 Kristian Van Der Vliet
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

#ifndef _F_SYSCALLTABLE_H_
#define _F_SYSCALLTABLE_H_

/* Syscall description table */

static struct SysCall_info g_sSysCallTable[] = {
 /* Memory */

 {__NR_create_area,"create_area", SYSC_GROUP_MM, 5,	SYSC_ARG_T_INT, SYSC_ARG_T_STRING, SYSC_ARG_T_POINTER, SYSC_ARG_T_LONG_INT, SYSC_ARG_T_LONG_INT, SYSC_ARG_T_INT},
 {__NR_remap_area,"remap_area", SYSC_GROUP_MM, 2, SYSC_ARG_T_STATUS_T, SYSC_ARG_T_INT, SYSC_ARG_T_POINTER, SYSC_ARG_T_NONE, SYSC_ARG_T_NONE, SYSC_ARG_T_NONE},
 {__NR_get_area_info,"get_area_info", SYSC_GROUP_MM, 2, SYSC_ARG_T_STATUS_T, SYSC_ARG_T_INT, SYSC_ARG_T_POINTER, SYSC_ARG_T_NONE, SYSC_ARG_T_NONE, SYSC_ARG_T_NONE},
 {__NR_sbrk,"sbrk", SYSC_GROUP_MM, 1, SYSC_ARG_T_POINTER, SYSC_ARG_T_INT, SYSC_ARG_T_NONE, SYSC_ARG_T_NONE, SYSC_ARG_T_NONE, SYSC_ARG_T_NONE},
 {__NR_clone_area,"clone_area", SYSC_GROUP_MM, 5, SYSC_ARG_T_INT, SYSC_ARG_T_STRING, SYSC_ARG_T_POINTER, SYSC_ARG_T_LONG_INT, SYSC_ARG_T_INT, SYSC_ARG_T_INT},
 {__NR_delete_area,"delete_area", SYSC_GROUP_MM, 1, SYSC_ARG_T_STATUS_T, SYSC_ARG_T_INT, SYSC_ARG_T_NONE, SYSC_ARG_T_NONE, SYSC_ARG_T_NONE, SYSC_ARG_T_NONE},
 {__NR_mmap, "mmap", SYSC_GROUP_MM, 6, SYSC_ARG_T_POINTER, SYSC_ARG_T_POINTER, SYSC_ARG_T_INT, SYSC_ARG_T_INT, SYSC_ARG_T_INT, SYSC_ARG_T_INT},
 {__NR_munmap, "munmap", SYSC_GROUP_MM, 2, SYSC_ARG_T_INT, SYSC_ARG_T_POINTER, SYSC_ARG_T_INT, SYSC_ARG_T_NONE, SYSC_ARG_T_NONE, SYSC_ARG_T_NONE},
 {__NR_mprotect, "mprotect", SYSC_GROUP_MM, 3, SYSC_ARG_T_INT, SYSC_ARG_T_POINTER, SYSC_ARG_T_INT, SYSC_ARG_T_INT, SYSC_ARG_T_NONE, SYSC_ARG_T_NONE},

 /* Processes & threads */

 {__NR_Fork,"Fork", SYSC_GROUP_PROC, 1, SYSC_ARG_T_INT, SYSC_ARG_T_STRING, SYSC_ARG_T_NONE, SYSC_ARG_T_NONE, SYSC_ARG_T_NONE, SYSC_ARG_T_NONE},
 {__NR_exit,"exit", SYSC_GROUP_PROC, 1, SYSC_ARG_T_INT, SYSC_ARG_T_INT, SYSC_ARG_T_NONE, SYSC_ARG_T_NONE, SYSC_ARG_T_NONE, SYSC_ARG_T_NONE},
 {__NR_wait4,"wait4", SYSC_GROUP_PROC, 4, SYSC_ARG_T_INT, SYSC_ARG_T_INT, SYSC_ARG_T_POINTER, SYSC_ARG_T_INT, SYSC_ARG_T_INT, SYSC_ARG_T_NONE},
 {__NR_get_thread_info,"get_thread_info", SYSC_GROUP_PROC, 1, SYSC_ARG_T_STATUS_T, SYSC_ARG_T_POINTER, SYSC_ARG_T_NONE, SYSC_ARG_T_NONE, SYSC_ARG_T_NONE, SYSC_ARG_T_NONE},
 {__NR_get_thread_proc,"get_thread_proc", SYSC_GROUP_PROC, 1, SYSC_ARG_T_INT, SYSC_ARG_T_INT, SYSC_ARG_T_NONE, SYSC_ARG_T_NONE, SYSC_ARG_T_NONE, SYSC_ARG_T_NONE},
 {__NR_get_next_thread_info,"get_next_thread_info", SYSC_GROUP_PROC, 1, SYSC_ARG_T_STATUS_T, SYSC_ARG_T_POINTER, SYSC_ARG_T_NONE, SYSC_ARG_T_NONE, SYSC_ARG_T_NONE, SYSC_ARG_T_NONE},
 {__NR_get_thread_id,"get_thread_id", SYSC_GROUP_PROC, 1, SYSC_ARG_T_INT, SYSC_ARG_T_STRING, SYSC_ARG_T_NONE, SYSC_ARG_T_NONE, SYSC_ARG_T_NONE, SYSC_ARG_T_NONE},
 {__NR_SetThreadExitCode,"SetThreadExitCode", SYSC_GROUP_PROC, 0, SYSC_ARG_T_INT, SYSC_ARG_T_NONE, SYSC_ARG_T_NONE, SYSC_ARG_T_NONE, SYSC_ARG_T_NONE, SYSC_ARG_T_NONE},
 {__NR_old_spawn_thread,"old_spawn_thread", SYSC_GROUP_PROC, 0, SYSC_ARG_T_INT, SYSC_ARG_T_NONE, SYSC_ARG_T_NONE, SYSC_ARG_T_NONE, SYSC_ARG_T_NONE, SYSC_ARG_T_NONE},
 {__NR_spawn_thread,"spawn_thread", SYSC_GROUP_PROC, 5, SYSC_ARG_T_INT, SYSC_ARG_T_STRING, SYSC_ARG_T_POINTER, SYSC_ARG_T_INT, SYSC_ARG_T_INT, SYSC_ARG_T_POINTER},
 {__NR_exit_thread,"exit_thread", SYSC_GROUP_PROC, 1, SYSC_ARG_T_INT, SYSC_ARG_T_INT, SYSC_ARG_T_NONE, SYSC_ARG_T_NONE, SYSC_ARG_T_NONE, SYSC_ARG_T_NONE},
 {__NR_execve,"execve", SYSC_GROUP_PROC, 3, SYSC_ARG_T_INT, SYSC_ARG_T_STRING, SYSC_ARG_T_POINTER, SYSC_ARG_T_POINTER, SYSC_ARG_T_NONE, SYSC_ARG_T_NONE},
 {__NR_old_load_library,"old_load_library", SYSC_GROUP_PROC, 0, SYSC_ARG_T_INT, SYSC_ARG_T_NONE, SYSC_ARG_T_NONE, SYSC_ARG_T_NONE, SYSC_ARG_T_NONE, SYSC_ARG_T_NONE},
 {__NR_unload_library,"unload_library", SYSC_GROUP_PROC, 1, SYSC_ARG_T_INT, SYSC_ARG_T_INT, SYSC_ARG_T_NONE, SYSC_ARG_T_NONE, SYSC_ARG_T_NONE, SYSC_ARG_T_NONE},
 {__NR_load_library,"load_library", SYSC_GROUP_PROC, 2, SYSC_ARG_T_INT, SYSC_ARG_T_STRING, SYSC_ARG_T_LONG_HEX, SYSC_ARG_T_NONE, SYSC_ARG_T_NONE, SYSC_ARG_T_NONE},
 {__NR_get_symbol_address,"get_symbol_address", SYSC_GROUP_PROC, 4, SYSC_ARG_T_INT, SYSC_ARG_T_INT, SYSC_ARG_T_STRING, SYSC_ARG_T_INT, SYSC_ARG_T_POINTER, SYSC_ARG_T_NONE},
 {__NR_set_thread_priority,"set_thread_priority", SYSC_GROUP_PROC, 2, SYSC_ARG_T_INT, SYSC_ARG_T_INT, SYSC_ARG_T_INT, SYSC_ARG_T_NONE, SYSC_ARG_T_NONE, SYSC_ARG_T_NONE},
 {__NR_suspend_thread,"suspend_thread", SYSC_GROUP_PROC, 1, SYSC_ARG_T_STATUS_T, SYSC_ARG_T_INT, SYSC_ARG_T_NONE, SYSC_ARG_T_NONE, SYSC_ARG_T_NONE, SYSC_ARG_T_NONE},
 {__NR_resume_thread,"resume_thread", SYSC_GROUP_PROC, 1, SYSC_ARG_T_STATUS_T, SYSC_ARG_T_INT, SYSC_ARG_T_NONE, SYSC_ARG_T_NONE, SYSC_ARG_T_NONE, SYSC_ARG_T_NONE},
 {__NR_wait_for_thread,"wait_for_thread", SYSC_GROUP_PROC, 1, SYSC_ARG_T_INT, SYSC_ARG_T_INT, SYSC_ARG_T_NONE, SYSC_ARG_T_NONE, SYSC_ARG_T_NONE, SYSC_ARG_T_NONE},
 {__NR_snooze,"snooze", SYSC_GROUP_PROC, 1, SYSC_ARG_T_STATUS_T, SYSC_ARG_T_LONG_INT, SYSC_ARG_T_NONE, SYSC_ARG_T_NONE, SYSC_ARG_T_NONE, SYSC_ARG_T_NONE},
 {__NR_killpg,"killpg", SYSC_GROUP_PROC, 2, SYSC_ARG_T_INT, SYSC_ARG_T_INT, SYSC_ARG_T_INT, SYSC_ARG_T_NONE, SYSC_ARG_T_NONE, SYSC_ARG_T_NONE},
 {__NR_kill_proc,"kill_proc", SYSC_GROUP_PROC, 2, SYSC_ARG_T_INT, SYSC_ARG_T_INT, SYSC_ARG_T_INT, SYSC_ARG_T_NONE, SYSC_ARG_T_NONE, SYSC_ARG_T_NONE},
 {__NR_get_process_id,"get_process_id", SYSC_GROUP_PROC, 1, SYSC_ARG_T_INT, SYSC_ARG_T_STRING, SYSC_ARG_T_NONE, SYSC_ARG_T_NONE, SYSC_ARG_T_NONE, SYSC_ARG_T_NONE},
 {__NR_setpgid,"setpgid", SYSC_GROUP_PROC, 2, SYSC_ARG_T_INT, SYSC_ARG_T_INT, SYSC_ARG_T_INT, SYSC_ARG_T_NONE, SYSC_ARG_T_NONE, SYSC_ARG_T_NONE},
 {__NR_getpgid,"getpgid", SYSC_GROUP_PROC, 1, SYSC_ARG_T_INT, SYSC_ARG_T_INT, SYSC_ARG_T_NONE, SYSC_ARG_T_NONE, SYSC_ARG_T_NONE, SYSC_ARG_T_NONE},
 {__NR_getpgrp,"getpgrp", SYSC_GROUP_PROC, 0, SYSC_ARG_T_INT, SYSC_ARG_T_NONE, SYSC_ARG_T_NONE, SYSC_ARG_T_NONE, SYSC_ARG_T_NONE, SYSC_ARG_T_NONE},
 {__NR_getppid,"getppid", SYSC_GROUP_PROC, 0, SYSC_ARG_T_INT, SYSC_ARG_T_NONE, SYSC_ARG_T_NONE, SYSC_ARG_T_NONE, SYSC_ARG_T_NONE, SYSC_ARG_T_NONE},
 {__NR_getsid,"getsid", SYSC_GROUP_PROC, 1, SYSC_ARG_T_INT, SYSC_ARG_T_INT, SYSC_ARG_T_NONE, SYSC_ARG_T_NONE, SYSC_ARG_T_NONE, SYSC_ARG_T_NONE},
 {__NR_setsid,"setsid", SYSC_GROUP_PROC, 0, SYSC_ARG_T_INT, SYSC_ARG_T_NONE, SYSC_ARG_T_NONE, SYSC_ARG_T_NONE, SYSC_ARG_T_NONE, SYSC_ARG_T_NONE},
 {__NR_getegid,"getegid", SYSC_GROUP_PROC, 0, SYSC_ARG_T_INT, SYSC_ARG_T_NONE, SYSC_ARG_T_NONE, SYSC_ARG_T_NONE, SYSC_ARG_T_NONE, SYSC_ARG_T_NONE},
 {__NR_geteuid,"geteuid", SYSC_GROUP_PROC, 0, SYSC_ARG_T_INT, SYSC_ARG_T_NONE, SYSC_ARG_T_NONE, SYSC_ARG_T_NONE, SYSC_ARG_T_NONE, SYSC_ARG_T_NONE},
 {__NR_getgid,"getgid", SYSC_GROUP_PROC, 0, SYSC_ARG_T_INT, SYSC_ARG_T_NONE, SYSC_ARG_T_NONE, SYSC_ARG_T_NONE, SYSC_ARG_T_NONE, SYSC_ARG_T_NONE},
 {__NR_getgroups,"getgroups", SYSC_GROUP_PROC, 2, SYSC_ARG_T_INT, SYSC_ARG_T_INT, SYSC_ARG_T_POINTER, SYSC_ARG_T_NONE, SYSC_ARG_T_NONE, SYSC_ARG_T_NONE},
 {__NR_getuid,"getuid", SYSC_GROUP_PROC, 0, SYSC_ARG_T_INT, SYSC_ARG_T_NONE, SYSC_ARG_T_NONE, SYSC_ARG_T_NONE, SYSC_ARG_T_NONE, SYSC_ARG_T_NONE},
 {__NR_setgid,"setgid", SYSC_GROUP_PROC, 1, SYSC_ARG_T_INT, SYSC_ARG_T_INT, SYSC_ARG_T_NONE, SYSC_ARG_T_NONE, SYSC_ARG_T_NONE, SYSC_ARG_T_NONE},
 {__NR_setuid,"setuid", SYSC_GROUP_PROC, 1, SYSC_ARG_T_INT, SYSC_ARG_T_INT, SYSC_ARG_T_NONE, SYSC_ARG_T_NONE, SYSC_ARG_T_NONE, SYSC_ARG_T_NONE},
 {__NR_setregid,"setregid", SYSC_GROUP_PROC, 2, SYSC_ARG_T_INT, SYSC_ARG_T_INT, SYSC_ARG_T_INT, SYSC_ARG_T_NONE, SYSC_ARG_T_NONE, SYSC_ARG_T_NONE},
 {__NR_setgroups,"setgroups", SYSC_GROUP_PROC, 2, SYSC_ARG_T_INT, SYSC_ARG_T_INT, SYSC_ARG_T_POINTER, SYSC_ARG_T_NONE, SYSC_ARG_T_NONE, SYSC_ARG_T_NONE},
 {__NR_setreuid,"setreuid", SYSC_GROUP_PROC, 2, SYSC_ARG_T_INT, SYSC_ARG_T_INT, SYSC_ARG_T_INT, SYSC_ARG_T_NONE, SYSC_ARG_T_NONE, SYSC_ARG_T_NONE},
 {__NR_setresuid,"setresuid", SYSC_GROUP_PROC, 3, SYSC_ARG_T_INT, SYSC_ARG_T_INT, SYSC_ARG_T_INT, SYSC_ARG_T_INT, SYSC_ARG_T_NONE, SYSC_ARG_T_NONE},
 {__NR_getresuid,"getresuid", SYSC_GROUP_PROC, 3, SYSC_ARG_T_INT, SYSC_ARG_T_POINTER, SYSC_ARG_T_POINTER, SYSC_ARG_T_POINTER, SYSC_ARG_T_NONE, SYSC_ARG_T_NONE},
 {__NR_setresgid,"setresgid", SYSC_GROUP_PROC, 3, SYSC_ARG_T_INT, SYSC_ARG_T_INT, SYSC_ARG_T_INT, SYSC_ARG_T_INT, SYSC_ARG_T_NONE, SYSC_ARG_T_NONE},
 {__NR_getresgid,"getresgid", SYSC_GROUP_PROC, 3, SYSC_ARG_T_INT, SYSC_ARG_T_POINTER, SYSC_ARG_T_POINTER, SYSC_ARG_T_POINTER, SYSC_ARG_T_NONE, SYSC_ARG_T_NONE},
 {__NR_setfsuid,"setfsuid", SYSC_GROUP_PROC, 1, SYSC_ARG_T_INT, SYSC_ARG_T_INT, SYSC_ARG_T_NONE, SYSC_ARG_T_NONE, SYSC_ARG_T_NONE, SYSC_ARG_T_NONE},
 {__NR_setfsgid,"setfsgid", SYSC_GROUP_PROC, 1, SYSC_ARG_T_INT, SYSC_ARG_T_INT, SYSC_ARG_T_NONE, SYSC_ARG_T_NONE, SYSC_ARG_T_NONE, SYSC_ARG_T_NONE},
 {__NR_rename_thread,"rename_thread", SYSC_GROUP_PROC, 2, SYSC_ARG_T_STATUS_T, SYSC_ARG_T_INT, SYSC_ARG_T_STRING, SYSC_ARG_T_NONE, SYSC_ARG_T_NONE, SYSC_ARG_T_NONE},
 {__NR_get_image_info,"get_image_info", SYSC_GROUP_PROC, 3, SYSC_ARG_T_INT, SYSC_ARG_T_INT, SYSC_ARG_T_INT, SYSC_ARG_T_POINTER, SYSC_ARG_T_NONE, SYSC_ARG_T_NONE},
 {__NR_alloc_tld,"alloc_tld", SYSC_GROUP_PROC, 1, SYSC_ARG_T_INT, SYSC_ARG_T_POINTER, SYSC_ARG_T_NONE, SYSC_ARG_T_NONE, SYSC_ARG_T_NONE, SYSC_ARG_T_NONE},
 {__NR_free_tld,"free_tld", SYSC_GROUP_PROC, 1, SYSC_ARG_T_INT, SYSC_ARG_T_INT, SYSC_ARG_T_NONE, SYSC_ARG_T_NONE, SYSC_ARG_T_NONE, SYSC_ARG_T_NONE},
 {__NR_get_tld_addr,"get_tld_addr", SYSC_GROUP_PROC, 1, SYSC_ARG_T_POINTER, SYSC_ARG_T_INT, SYSC_ARG_T_NONE, SYSC_ARG_T_NONE, SYSC_ARG_T_NONE, SYSC_ARG_T_NONE},
 {__NR_open_image_file,"open_image_file", SYSC_GROUP_PROC, 1, SYSC_ARG_T_INT, SYSC_ARG_T_INT, SYSC_ARG_T_NONE, SYSC_ARG_T_NONE, SYSC_ARG_T_NONE, SYSC_ARG_T_NONE},
 {__NR_find_module_by_address,"find_module_by_address", SYSC_GROUP_PROC, 1, SYSC_ARG_T_INT, SYSC_ARG_T_POINTER, SYSC_ARG_T_NONE, SYSC_ARG_T_NONE, SYSC_ARG_T_NONE, SYSC_ARG_T_NONE},

 /* Devices */

 {__NR_raw_read_pci_config,"raw_read_pci_config", SYSC_GROUP_DEVICE, 5, SYSC_ARG_T_STATUS_T, SYSC_ARG_T_INT, SYSC_ARG_T_INT, SYSC_ARG_T_INT, SYSC_ARG_T_INT, SYSC_ARG_T_POINTER},
 {__NR_raw_write_pci_config,"raw_write_pci_config", SYSC_GROUP_DEVICE, 5, SYSC_ARG_T_STATUS_T, SYSC_ARG_T_INT, SYSC_ARG_T_INT, SYSC_ARG_T_INT, SYSC_ARG_T_INT, SYSC_ARG_T_LONG_INT},
 {__NR_get_pci_info,"get_pci_info", SYSC_GROUP_DEVICE, 2, SYSC_ARG_T_STATUS_T, SYSC_ARG_T_POINTER, SYSC_ARG_T_INT, SYSC_ARG_T_NONE, SYSC_ARG_T_NONE, SYSC_ARG_T_NONE},

 /* Network */

 {__NR_socket,"socket", SYSC_GROUP_NET, 3, SYSC_ARG_T_INT, SYSC_ARG_T_INT, SYSC_ARG_T_INT, SYSC_ARG_T_INT, SYSC_ARG_T_NONE, SYSC_ARG_T_NONE},
 {__NR_closesocket,"closesocket", SYSC_GROUP_NET, 1, SYSC_ARG_T_INT, SYSC_ARG_T_INT, SYSC_ARG_T_NONE, SYSC_ARG_T_NONE, SYSC_ARG_T_NONE, SYSC_ARG_T_NONE},
 {__NR_bind,"bind", SYSC_GROUP_NET, 3, SYSC_ARG_T_INT, SYSC_ARG_T_INT, SYSC_ARG_T_POINTER, SYSC_ARG_T_INT, SYSC_ARG_T_NONE, SYSC_ARG_T_NONE},
 {__NR_sendmsg,"sendmsg", SYSC_GROUP_NET, 3, SYSC_ARG_T_LONG_INT, SYSC_ARG_T_INT, SYSC_ARG_T_POINTER, SYSC_ARG_T_HEX, SYSC_ARG_T_NONE, SYSC_ARG_T_NONE},
 {__NR_recvmsg,"recvmsg", SYSC_GROUP_NET, 3, SYSC_ARG_T_LONG_INT, SYSC_ARG_T_INT, SYSC_ARG_T_POINTER, SYSC_ARG_T_HEX, SYSC_ARG_T_NONE, SYSC_ARG_T_NONE},
 {__NR_connect,"connect", SYSC_GROUP_NET, 3, SYSC_ARG_T_INT, SYSC_ARG_T_INT, SYSC_ARG_T_POINTER, SYSC_ARG_T_INT, SYSC_ARG_T_NONE, SYSC_ARG_T_NONE},
 {__NR_listen,"listen", SYSC_GROUP_NET, 2, SYSC_ARG_T_INT, SYSC_ARG_T_INT, SYSC_ARG_T_INT, SYSC_ARG_T_NONE, SYSC_ARG_T_NONE, SYSC_ARG_T_NONE},
 {__NR_accept,"accept", SYSC_GROUP_NET, 3, SYSC_ARG_T_INT, SYSC_ARG_T_INT, SYSC_ARG_T_POINTER, SYSC_ARG_T_POINTER, SYSC_ARG_T_NONE, SYSC_ARG_T_NONE},
 {__NR_setsockopt,"setsockopt", SYSC_GROUP_NET, 5, SYSC_ARG_T_INT, SYSC_ARG_T_INT, SYSC_ARG_T_INT, SYSC_ARG_T_INT, SYSC_ARG_T_POINTER, SYSC_ARG_T_INT},
 {__NR_getsockopt,"getsockopt", SYSC_GROUP_NET, 5, SYSC_ARG_T_INT, SYSC_ARG_T_INT, SYSC_ARG_T_INT, SYSC_ARG_T_INT, SYSC_ARG_T_POINTER, SYSC_ARG_T_INT},
 {__NR_getpeername,"getpeername", SYSC_GROUP_NET, 3, SYSC_ARG_T_INT, SYSC_ARG_T_INT, SYSC_ARG_T_POINTER, SYSC_ARG_T_POINTER, SYSC_ARG_T_NONE, SYSC_ARG_T_NONE},
 {__NR_shutdown,"shutdown", SYSC_GROUP_NET, 2, SYSC_ARG_T_INT, SYSC_ARG_T_INT, SYSC_ARG_T_INT, SYSC_ARG_T_NONE, SYSC_ARG_T_NONE, SYSC_ARG_T_NONE},
 {__NR_getsockname,"getsockname", SYSC_GROUP_NET, 3, SYSC_ARG_T_INT, SYSC_ARG_T_INT, SYSC_ARG_T_POINTER, SYSC_ARG_T_POINTER, SYSC_ARG_T_NONE, SYSC_ARG_T_NONE},

 /* Signals */

 {__NR_alarm,"alarm", SYSC_GROUP_SIGNAL, 1, SYSC_ARG_T_INT, SYSC_ARG_T_INT, SYSC_ARG_T_NONE, SYSC_ARG_T_NONE, SYSC_ARG_T_NONE, SYSC_ARG_T_NONE},
 {__NR_sig_return,"sig_return", SYSC_GROUP_SIGNAL, 1, SYSC_ARG_T_INT, SYSC_ARG_T_INT, SYSC_ARG_T_NONE, SYSC_ARG_T_NONE, SYSC_ARG_T_NONE, SYSC_ARG_T_NONE},
 {__NR_kill,"kill", SYSC_GROUP_SIGNAL, 2, SYSC_ARG_T_INT, SYSC_ARG_T_INT, SYSC_ARG_T_INT, SYSC_ARG_T_NONE, SYSC_ARG_T_NONE, SYSC_ARG_T_NONE},
 {__NR_sigaction,"sigaction", SYSC_GROUP_SIGNAL, 3, SYSC_ARG_T_INT, SYSC_ARG_T_INT, SYSC_ARG_T_POINTER, SYSC_ARG_T_POINTER, SYSC_ARG_T_NONE, SYSC_ARG_T_NONE},
 {__NR_sigpending,"sigpending", SYSC_GROUP_SIGNAL, 1, SYSC_ARG_T_INT, SYSC_ARG_T_POINTER, SYSC_ARG_T_NONE, SYSC_ARG_T_NONE, SYSC_ARG_T_NONE, SYSC_ARG_T_NONE},
 {__NR_sigprocmask,"sigprocmask", SYSC_GROUP_SIGNAL, 3, SYSC_ARG_T_INT, SYSC_ARG_T_INT, SYSC_ARG_T_POINTER, SYSC_ARG_T_POINTER, SYSC_ARG_T_NONE, SYSC_ARG_T_NONE},
 {__NR_sigsuspend,"sigsuspend", SYSC_GROUP_SIGNAL, 3, SYSC_ARG_T_INT, SYSC_ARG_T_LONG_INT, SYSC_ARG_T_LONG_INT, SYSC_ARG_T_INT, SYSC_ARG_T_NONE, SYSC_ARG_T_NONE},
 {__NR_sigaltstack,"sigaltstack", SYSC_GROUP_SIGNAL, 2, SYSC_ARG_T_INT, SYSC_ARG_T_POINTER, SYSC_ARG_T_POINTER, SYSC_ARG_T_NONE, SYSC_ARG_T_NONE, SYSC_ARG_T_NONE},
 {__NR_setitimer,"setitimer", SYSC_GROUP_SIGNAL, 3, SYSC_ARG_T_INT, SYSC_ARG_T_INT, SYSC_ARG_T_POINTER, SYSC_ARG_T_POINTER, SYSC_ARG_T_NONE, SYSC_ARG_T_NONE },
 {__NR_getitimer,"getitimer", SYSC_GROUP_SIGNAL, 2, SYSC_ARG_T_INT, SYSC_ARG_T_INT, SYSC_ARG_T_POINTER, SYSC_ARG_T_NONE, SYSC_ARG_T_NONE, SYSC_ARG_T_NONE },

 /* IPC */

 {__NR_send_data,"send_data", SYSC_GROUP_IPC, 4, SYSC_ARG_T_STATUS_T, SYSC_ARG_T_INT, SYSC_ARG_T_LONG_INT, SYSC_ARG_T_POINTER, SYSC_ARG_T_LONG_INT, SYSC_ARG_T_NONE},
 {__NR_receive_data,"receive_data", SYSC_GROUP_IPC, 3, SYSC_ARG_T_LONG_INT, SYSC_ARG_T_POINTER, SYSC_ARG_T_POINTER, SYSC_ARG_T_LONG_INT, SYSC_ARG_T_NONE, SYSC_ARG_T_NONE},
 {__NR_thread_data_size,"thread_data_size", SYSC_GROUP_IPC, 0, SYSC_ARG_T_INT, SYSC_ARG_T_NONE, SYSC_ARG_T_NONE, SYSC_ARG_T_NONE, SYSC_ARG_T_NONE, SYSC_ARG_T_NONE},
 {__NR_has_data,"has_data", SYSC_GROUP_IPC, 1, SYSC_ARG_T_INT, SYSC_ARG_T_INT, SYSC_ARG_T_NONE, SYSC_ARG_T_NONE, SYSC_ARG_T_NONE, SYSC_ARG_T_NONE},
 {__NR_create_port,"create_port", SYSC_GROUP_IPC, 2, SYSC_ARG_T_INT, SYSC_ARG_T_STRING, SYSC_ARG_T_INT, SYSC_ARG_T_NONE, SYSC_ARG_T_NONE, SYSC_ARG_T_NONE},
 {__NR_delete_port,"delete_port", SYSC_GROUP_IPC, 1, SYSC_ARG_T_STATUS_T, SYSC_ARG_T_INT, SYSC_ARG_T_NONE, SYSC_ARG_T_NONE, SYSC_ARG_T_NONE, SYSC_ARG_T_NONE},
 {__NR_send_msg,"send_msg", SYSC_GROUP_IPC, 4, SYSC_ARG_T_STATUS_T, SYSC_ARG_T_INT, SYSC_ARG_T_LONG_INT, SYSC_ARG_T_POINTER, SYSC_ARG_T_INT, SYSC_ARG_T_NONE},
 {__NR_get_msg,"get_msg", SYSC_GROUP_IPC, 4, SYSC_ARG_T_STATUS_T, SYSC_ARG_T_INT, SYSC_ARG_T_POINTER, SYSC_ARG_T_POINTER, SYSC_ARG_T_INT, SYSC_ARG_T_NONE},
 {__NR_raw_send_msg_x,"raw_send_msg_x", SYSC_GROUP_IPC, 5, SYSC_ARG_T_STATUS_T, SYSC_ARG_T_INT, SYSC_ARG_T_LONG_INT, SYSC_ARG_T_POINTER, SYSC_ARG_T_INT, SYSC_ARG_T_POINTER},
 {__NR_raw_get_msg_x,"raw_get_msg_x", SYSC_GROUP_IPC, 5, SYSC_ARG_T_STATUS_T, SYSC_ARG_T_INT, SYSC_ARG_T_POINTER, SYSC_ARG_T_POINTER, SYSC_ARG_T_INT, SYSC_ARG_T_POINTER},
 {__NR_create_semaphore,"create_semaphore", SYSC_GROUP_IPC, 3, SYSC_ARG_T_INT, SYSC_ARG_T_STRING, SYSC_ARG_T_INT, SYSC_ARG_T_LONG_HEX, SYSC_ARG_T_NONE, SYSC_ARG_T_NONE},
 {__NR_delete_semaphore,"delete_semaphore", SYSC_GROUP_IPC, 1, SYSC_ARG_T_STATUS_T, SYSC_ARG_T_INT, SYSC_ARG_T_NONE, SYSC_ARG_T_NONE, SYSC_ARG_T_NONE, SYSC_ARG_T_NONE},
 {__NR_lock_semaphore,"lock_semaphore", SYSC_GROUP_IPC, 1, SYSC_ARG_T_STATUS_T, SYSC_ARG_T_INT, SYSC_ARG_T_NONE, SYSC_ARG_T_NONE, SYSC_ARG_T_NONE, SYSC_ARG_T_NONE},
 {__NR_raw_lock_semaphore_x,"raw_lock_semaphore_x", SYSC_GROUP_IPC, 4, SYSC_ARG_T_STATUS_T, SYSC_ARG_T_INT, SYSC_ARG_T_INT, SYSC_ARG_T_LONG_HEX, SYSC_ARG_T_LONG_INT, SYSC_ARG_T_NONE},
 {__NR_unlock_semaphore_x,"unlock_semaphore_x", SYSC_GROUP_IPC, 3, SYSC_ARG_T_STATUS_T, SYSC_ARG_T_INT, SYSC_ARG_T_INT, SYSC_ARG_T_LONG_HEX, SYSC_ARG_T_NONE, SYSC_ARG_T_NONE},
 {__NR_get_semaphore_info,"get_semaphore_info", SYSC_GROUP_IPC, 3, SYSC_ARG_T_STATUS_T, SYSC_ARG_T_INT, SYSC_ARG_T_INT, SYSC_ARG_T_POINTER, SYSC_ARG_T_NONE, SYSC_ARG_T_NONE},
 {__NR_get_app_server_port,"get_app_server_port", SYSC_GROUP_IPC, 0, SYSC_ARG_T_INT, SYSC_ARG_T_NONE, SYSC_ARG_T_NONE, SYSC_ARG_T_NONE, SYSC_ARG_T_NONE, SYSC_ARG_T_NONE},
 {__NR_set_app_server_port,"set_app_server_port", SYSC_GROUP_IPC, 1, SYSC_ARG_T_INT, SYSC_ARG_T_INT, SYSC_ARG_T_NONE, SYSC_ARG_T_NONE, SYSC_ARG_T_NONE, SYSC_ARG_T_NONE},
 {__NR_get_next_semaphore_info,"get_next_semaphore_info", SYSC_GROUP_IPC, 1, SYSC_ARG_T_STATUS_T, SYSC_ARG_T_POINTER, SYSC_ARG_T_NONE, SYSC_ARG_T_NONE, SYSC_ARG_T_NONE, SYSC_ARG_T_NONE},
 {__NR_get_port_info,"get_port_info", SYSC_GROUP_IPC, 2, SYSC_ARG_T_STATUS_T, SYSC_ARG_T_INT, SYSC_ARG_T_POINTER, SYSC_ARG_T_NONE, SYSC_ARG_T_NONE, SYSC_ARG_T_NONE},
 {__NR_get_next_port_info,"get_next_port_info", SYSC_GROUP_IPC, 1, SYSC_ARG_T_STATUS_T, SYSC_ARG_T_POINTER, SYSC_ARG_T_NONE, SYSC_ARG_T_NONE, SYSC_ARG_T_NONE, SYSC_ARG_T_NONE},
 {__NR_make_port_public,"make_port_public", SYSC_GROUP_IPC, 1, SYSC_ARG_T_STATUS_T, SYSC_ARG_T_INT, SYSC_ARG_T_NONE, SYSC_ARG_T_NONE, SYSC_ARG_T_NONE, SYSC_ARG_T_NONE},
 {__NR_make_port_private,"make_port_private", SYSC_GROUP_IPC, 1, SYSC_ARG_T_STATUS_T, SYSC_ARG_T_INT, SYSC_ARG_T_NONE, SYSC_ARG_T_NONE, SYSC_ARG_T_NONE, SYSC_ARG_T_NONE},
 {__NR_find_port,"find_port", SYSC_GROUP_IPC, 1, SYSC_ARG_T_INT, SYSC_ARG_T_STRING, SYSC_ARG_T_NONE, SYSC_ARG_T_NONE, SYSC_ARG_T_NONE, SYSC_ARG_T_NONE},
 {__NR_get_msg_size,"get_msg_size", SYSC_GROUP_IPC, 1, SYSC_ARG_T_INT, SYSC_ARG_T_INT, SYSC_ARG_T_NONE, SYSC_ARG_T_NONE, SYSC_ARG_T_NONE, SYSC_ARG_T_NONE},
 {__NR_event,"event", SYSC_GROUP_IPC, 5, SYSC_ARG_T_STATUS_T, SYSC_ARG_T_INT, SYSC_ARG_T_INT, SYSC_ARG_T_INT, SYSC_ARG_T_POINTER, SYSC_ARG_T_INT },

 /* I/O */

 {__NR_open,"open", SYSC_GROUP_IO, 3, SYSC_ARG_T_INT, SYSC_ARG_T_STRING, SYSC_ARG_T_HEX, SYSC_ARG_T_SPECIAL, SYSC_ARG_T_NONE, SYSC_ARG_T_NONE},
 {__NR_close,"close", SYSC_GROUP_IO, 1, SYSC_ARG_T_INT, SYSC_ARG_T_INT, SYSC_ARG_T_NONE, SYSC_ARG_T_NONE, SYSC_ARG_T_NONE, SYSC_ARG_T_NONE},
 {__NR_read,"read", SYSC_GROUP_IO, 3, SYSC_ARG_T_LONG_INT, SYSC_ARG_T_INT, SYSC_ARG_T_POINTER, SYSC_ARG_T_INT, SYSC_ARG_T_NONE, SYSC_ARG_T_NONE},
 {__NR_write,"write", SYSC_GROUP_IO, 3, SYSC_ARG_T_LONG_INT, SYSC_ARG_T_INT, SYSC_ARG_T_POINTER, SYSC_ARG_T_INT, SYSC_ARG_T_NONE, SYSC_ARG_T_NONE},
 {__NR_rename,"rename", SYSC_GROUP_IO, 2, SYSC_ARG_T_INT, SYSC_ARG_T_STRING, SYSC_ARG_T_STRING, SYSC_ARG_T_NONE, SYSC_ARG_T_NONE, SYSC_ARG_T_NONE},
 {__NR_getdents,"getdents", SYSC_GROUP_IO, 3, SYSC_ARG_T_INT, SYSC_ARG_T_INT, SYSC_ARG_T_POINTER, SYSC_ARG_T_INT, SYSC_ARG_T_NONE, SYSC_ARG_T_NONE},
 {__NR_fstat,"fstat", SYSC_GROUP_IO, 2, SYSC_ARG_T_INT, SYSC_ARG_T_INT, SYSC_ARG_T_POINTER, SYSC_ARG_T_NONE, SYSC_ARG_T_NONE, SYSC_ARG_T_NONE},
 {__NR_FileLength,"FileLength", SYSC_GROUP_IO, 1, SYSC_ARG_T_LONG_INT, SYSC_ARG_T_INT, SYSC_ARG_T_NONE, SYSC_ARG_T_NONE, SYSC_ARG_T_NONE, SYSC_ARG_T_NONE},
 {__NR_old_lseek,"old_lseek", SYSC_GROUP_IO, 3, SYSC_ARG_T_INT, SYSC_ARG_T_INT, SYSC_ARG_T_INT, SYSC_ARG_T_INT, SYSC_ARG_T_NONE, SYSC_ARG_T_NONE},
 {__NR_mkdir,"mkdir", SYSC_GROUP_IO, 2, SYSC_ARG_T_INT, SYSC_ARG_T_STRING, SYSC_ARG_T_INT, SYSC_ARG_T_NONE, SYSC_ARG_T_NONE, SYSC_ARG_T_NONE},
 {__NR_rmdir,"rmdir", SYSC_GROUP_IO, 1, SYSC_ARG_T_INT, SYSC_ARG_T_STRING, SYSC_ARG_T_NONE, SYSC_ARG_T_NONE, SYSC_ARG_T_NONE, SYSC_ARG_T_NONE},
 {__NR_dup,"dup", SYSC_GROUP_IO, 1, SYSC_ARG_T_INT, SYSC_ARG_T_INT, SYSC_ARG_T_NONE, SYSC_ARG_T_NONE, SYSC_ARG_T_NONE, SYSC_ARG_T_NONE},
 {__NR_dup2,"dup2", SYSC_GROUP_IO, 2, SYSC_ARG_T_INT, SYSC_ARG_T_INT, SYSC_ARG_T_INT, SYSC_ARG_T_NONE, SYSC_ARG_T_NONE, SYSC_ARG_T_NONE},
 {__NR_fchdir,"fchdir", SYSC_GROUP_IO, 1, SYSC_ARG_T_INT, SYSC_ARG_T_INT, SYSC_ARG_T_NONE, SYSC_ARG_T_NONE, SYSC_ARG_T_NONE, SYSC_ARG_T_NONE},
 {__NR_chdir,"chdir", SYSC_GROUP_IO, 1, SYSC_ARG_T_INT, SYSC_ARG_T_STRING, SYSC_ARG_T_NONE, SYSC_ARG_T_NONE, SYSC_ARG_T_NONE, SYSC_ARG_T_NONE},
 {__NR_unlink,"unlink", SYSC_GROUP_IO, 1, SYSC_ARG_T_INT, SYSC_ARG_T_STRING, SYSC_ARG_T_NONE, SYSC_ARG_T_NONE, SYSC_ARG_T_NONE, SYSC_ARG_T_NONE},
 {__NR_rewinddir,"rewinddir", SYSC_GROUP_IO, 1, SYSC_ARG_T_INT, SYSC_ARG_T_INT, SYSC_ARG_T_NONE, SYSC_ARG_T_NONE, SYSC_ARG_T_NONE, SYSC_ARG_T_NONE},
 {__NR_umask,"umask", SYSC_GROUP_IO, 1, SYSC_ARG_T_INT, SYSC_ARG_T_INT, SYSC_ARG_T_NONE, SYSC_ARG_T_NONE, SYSC_ARG_T_NONE, SYSC_ARG_T_NONE},
 {__NR_mknod,"mknod", SYSC_GROUP_IO, 3, SYSC_ARG_T_INT, SYSC_ARG_T_STRING, SYSC_ARG_T_INT, SYSC_ARG_T_INT, SYSC_ARG_T_NONE, SYSC_ARG_T_NONE},
 {__NR_lseek,"lseek", SYSC_GROUP_IO, 5, SYSC_ARG_T_INT, SYSC_ARG_T_INT, SYSC_ARG_T_LONG_INT, SYSC_ARG_T_LONG_INT, SYSC_ARG_T_INT, SYSC_ARG_T_POINTER},
 {__NR_select,"select", SYSC_GROUP_IO, 5, SYSC_ARG_T_INT, SYSC_ARG_T_INT, SYSC_ARG_T_POINTER, SYSC_ARG_T_POINTER, SYSC_ARG_T_POINTER, SYSC_ARG_T_POINTER},
 {__NR_initialize_fs,"initialize_fs", SYSC_GROUP_IO, 5, SYSC_ARG_T_INT, SYSC_ARG_T_STRING, SYSC_ARG_T_STRING, SYSC_ARG_T_STRING, SYSC_ARG_T_POINTER, SYSC_ARG_T_INT},
 {__NR_mount,"mount", SYSC_GROUP_IO, 5, SYSC_ARG_T_INT, SYSC_ARG_T_STRING, SYSC_ARG_T_STRING, SYSC_ARG_T_STRING, SYSC_ARG_T_INT, SYSC_ARG_T_POINTER},
 {__NR_unmount,"unmount", SYSC_GROUP_IO, 2, SYSC_ARG_T_INT, SYSC_ARG_T_STRING, SYSC_ARG_T_BOOL, SYSC_ARG_T_NONE, SYSC_ARG_T_NONE, SYSC_ARG_T_NONE},
 {__NR_chmod,"chmod", SYSC_GROUP_IO, 2, SYSC_ARG_T_INT, SYSC_ARG_T_STRING, SYSC_ARG_T_INT, SYSC_ARG_T_NONE, SYSC_ARG_T_NONE, SYSC_ARG_T_NONE},
 {__NR_fchmod,"fchmod", SYSC_GROUP_IO, 2, SYSC_ARG_T_INT, SYSC_ARG_T_INT, SYSC_ARG_T_INT, SYSC_ARG_T_NONE, SYSC_ARG_T_NONE, SYSC_ARG_T_NONE},
 {__NR_chown,"chown", SYSC_GROUP_IO, 3, SYSC_ARG_T_INT, SYSC_ARG_T_STRING, SYSC_ARG_T_INT, SYSC_ARG_T_INT, SYSC_ARG_T_NONE, SYSC_ARG_T_NONE},
 {__NR_fchown,"fchown", SYSC_GROUP_IO, 3, SYSC_ARG_T_INT, SYSC_ARG_T_INT, SYSC_ARG_T_INT, SYSC_ARG_T_INT, SYSC_ARG_T_NONE, SYSC_ARG_T_NONE},
 {__NR_sync,"sync", SYSC_GROUP_IO, 0, SYSC_ARG_T_INT, SYSC_ARG_T_NONE, SYSC_ARG_T_NONE, SYSC_ARG_T_NONE, SYSC_ARG_T_NONE, SYSC_ARG_T_NONE},
 {__NR_fsync,"fsync", SYSC_GROUP_IO, 1, SYSC_ARG_T_INT, SYSC_ARG_T_INT, SYSC_ARG_T_NONE, SYSC_ARG_T_NONE, SYSC_ARG_T_NONE, SYSC_ARG_T_NONE},
 {__NR_isatty,"isatty", SYSC_GROUP_IO, 1, SYSC_ARG_T_INT, SYSC_ARG_T_INT, SYSC_ARG_T_NONE, SYSC_ARG_T_NONE, SYSC_ARG_T_NONE, SYSC_ARG_T_NONE},
 {__NR_fcntl,"fcntl", SYSC_GROUP_IO, 3, SYSC_ARG_T_INT, SYSC_ARG_T_INT, SYSC_ARG_T_INT, SYSC_ARG_T_INT, SYSC_ARG_T_NONE, SYSC_ARG_T_NONE},
 {__NR_ioctl,"ioctl", SYSC_GROUP_IO, 3, SYSC_ARG_T_INT, SYSC_ARG_T_INT, SYSC_ARG_T_INT, SYSC_ARG_T_POINTER, SYSC_ARG_T_NONE, SYSC_ARG_T_NONE},
 {__NR_pipe,"pipe", SYSC_GROUP_IO, 1, SYSC_ARG_T_INT, SYSC_ARG_T_POINTER, SYSC_ARG_T_NONE, SYSC_ARG_T_NONE, SYSC_ARG_T_NONE, SYSC_ARG_T_NONE},
 {__NR_access,"access", SYSC_GROUP_IO, 2, SYSC_ARG_T_INT, SYSC_ARG_T_STRING, SYSC_ARG_T_INT, SYSC_ARG_T_NONE, SYSC_ARG_T_NONE, SYSC_ARG_T_NONE},
 {__NR_symlink,"symlink", SYSC_GROUP_IO, 2, SYSC_ARG_T_INT, SYSC_ARG_T_STRING, SYSC_ARG_T_STRING, SYSC_ARG_T_NONE, SYSC_ARG_T_NONE, SYSC_ARG_T_NONE},
 {__NR_readlink,"readlink", SYSC_GROUP_IO, 3, SYSC_ARG_T_INT, SYSC_ARG_T_STRING, SYSC_ARG_T_POINTER, SYSC_ARG_T_INT, SYSC_ARG_T_NONE, SYSC_ARG_T_NONE},
 {__NR_stat,"stat", SYSC_GROUP_IO, 2, SYSC_ARG_T_INT, SYSC_ARG_T_STRING, SYSC_ARG_T_POINTER, SYSC_ARG_T_NONE, SYSC_ARG_T_NONE, SYSC_ARG_T_NONE},
 {__NR_lstat,"lstat", SYSC_GROUP_IO, 2, SYSC_ARG_T_INT, SYSC_ARG_T_STRING, SYSC_ARG_T_POINTER, SYSC_ARG_T_NONE, SYSC_ARG_T_NONE, SYSC_ARG_T_NONE},
 {__NR_get_mount_point_count,"get_mount_point_count", SYSC_GROUP_IO, 0, SYSC_ARG_T_INT, SYSC_ARG_T_NONE, SYSC_ARG_T_NONE, SYSC_ARG_T_NONE, SYSC_ARG_T_NONE, SYSC_ARG_T_NONE},
 {__NR_get_mount_point,"get_mount_point", SYSC_GROUP_IO, 3, SYSC_ARG_T_INT, SYSC_ARG_T_INT, SYSC_ARG_T_POINTER, SYSC_ARG_T_INT, SYSC_ARG_T_NONE, SYSC_ARG_T_NONE},
 {__NR_get_fs_info,"get_fs_info", SYSC_GROUP_IO, 3, SYSC_ARG_T_INT, SYSC_ARG_T_INT, SYSC_ARG_T_INT, SYSC_ARG_T_POINTER, SYSC_ARG_T_NONE, SYSC_ARG_T_NONE},
 {__NR_open_attrdir,"open_attrdir", SYSC_GROUP_IO, 1, SYSC_ARG_T_INT, SYSC_ARG_T_INT, SYSC_ARG_T_NONE, SYSC_ARG_T_NONE, SYSC_ARG_T_NONE, SYSC_ARG_T_NONE},
 {__NR_close_attrdir,"close_attrdir", SYSC_GROUP_IO, 1, SYSC_ARG_T_INT, SYSC_ARG_T_INT, SYSC_ARG_T_NONE, SYSC_ARG_T_NONE, SYSC_ARG_T_NONE, SYSC_ARG_T_NONE},
 {__NR_rewind_attrdir,"rewind_attrdir", SYSC_GROUP_IO, 1, SYSC_ARG_T_INT, SYSC_ARG_T_INT, SYSC_ARG_T_NONE, SYSC_ARG_T_NONE, SYSC_ARG_T_NONE, SYSC_ARG_T_NONE},
 {__NR_read_attrdir,"read_attrdir", SYSC_GROUP_IO, 3, SYSC_ARG_T_INT, SYSC_ARG_T_INT, SYSC_ARG_T_POINTER, SYSC_ARG_T_INT, SYSC_ARG_T_NONE, SYSC_ARG_T_NONE},
 {__NR_remove_attr,"remove_attr", SYSC_GROUP_IO, 2, SYSC_ARG_T_INT, SYSC_ARG_T_INT, SYSC_ARG_T_STRING, SYSC_ARG_T_NONE, SYSC_ARG_T_NONE, SYSC_ARG_T_NONE},
 {__NR_stat_attr,"stat_attr", SYSC_GROUP_IO, 3, SYSC_ARG_T_INT, SYSC_ARG_T_INT, SYSC_ARG_T_STRING, SYSC_ARG_T_POINTER, SYSC_ARG_T_NONE, SYSC_ARG_T_NONE},
 {__NR_write_attr,"write_attr", SYSC_GROUP_IO, 1, SYSC_ARG_T_INT, SYSC_ARG_T_POINTER, SYSC_ARG_T_NONE, SYSC_ARG_T_NONE, SYSC_ARG_T_NONE, SYSC_ARG_T_NONE},
 {__NR_read_attr,"read_attr", SYSC_GROUP_IO, 1, SYSC_ARG_T_INT, SYSC_ARG_T_POINTER, SYSC_ARG_T_NONE, SYSC_ARG_T_NONE, SYSC_ARG_T_NONE, SYSC_ARG_T_NONE},
 {__NR_freadlink,"freadlink", SYSC_GROUP_IO, 3, SYSC_ARG_T_INT, SYSC_ARG_T_INT, SYSC_ARG_T_POINTER, SYSC_ARG_T_INT, SYSC_ARG_T_NONE, SYSC_ARG_T_NONE},
 {__NR_get_directory_path,"get_directory_path", SYSC_GROUP_IO, 3, SYSC_ARG_T_INT, SYSC_ARG_T_INT, SYSC_ARG_T_POINTER, SYSC_ARG_T_INT, SYSC_ARG_T_NONE, SYSC_ARG_T_NONE},
 {__NR_chroot,"chroot", SYSC_GROUP_IO, 1, SYSC_ARG_T_INT, SYSC_ARG_T_STRING, SYSC_ARG_T_NONE, SYSC_ARG_T_NONE, SYSC_ARG_T_NONE, SYSC_ARG_T_NONE},
 {__NR_open_indexdir,"open_indexdir", SYSC_GROUP_IO, 1, SYSC_ARG_T_INT, SYSC_ARG_T_STRING, SYSC_ARG_T_NONE, SYSC_ARG_T_NONE, SYSC_ARG_T_NONE, SYSC_ARG_T_NONE},
 {__NR_rewind_indexdir,"rewind_indexdir", SYSC_GROUP_IO, 1, SYSC_ARG_T_INT, SYSC_ARG_T_INT, SYSC_ARG_T_NONE, SYSC_ARG_T_NONE, SYSC_ARG_T_NONE, SYSC_ARG_T_NONE},
 {__NR_read_indexdir,"read_indexdir", SYSC_GROUP_IO, 3, SYSC_ARG_T_INT, SYSC_ARG_T_INT, SYSC_ARG_T_POINTER, SYSC_ARG_T_INT, SYSC_ARG_T_NONE, SYSC_ARG_T_NONE},
 {__NR_create_index,"create_index", SYSC_GROUP_IO, 4, SYSC_ARG_T_INT, SYSC_ARG_T_STRING, SYSC_ARG_T_STRING, SYSC_ARG_T_INT, SYSC_ARG_T_HEX, SYSC_ARG_T_NONE},
 {__NR_remove_index,"remove_index", SYSC_GROUP_IO, 2, SYSC_ARG_T_INT, SYSC_ARG_T_STRING, SYSC_ARG_T_STRING, SYSC_ARG_T_NONE, SYSC_ARG_T_NONE, SYSC_ARG_T_NONE},
 {__NR_stat_index,"stat_index", SYSC_GROUP_IO, 3, SYSC_ARG_T_INT, SYSC_ARG_T_STRING, SYSC_ARG_T_STRING, SYSC_ARG_T_POINTER, SYSC_ARG_T_NONE, SYSC_ARG_T_NONE},
 {__NR_probe_fs,"probe_fs", SYSC_GROUP_IO, 3, SYSC_ARG_T_INT, SYSC_ARG_T_INT, SYSC_ARG_T_STRING, SYSC_ARG_T_POINTER, SYSC_ARG_T_NONE, SYSC_ARG_T_NONE},
 {__NR_read_pos,"read_pos", SYSC_GROUP_IO, 4, SYSC_ARG_T_INT, SYSC_ARG_T_INT, SYSC_ARG_T_INT, SYSC_ARG_T_POINTER, SYSC_ARG_T_INT, SYSC_ARG_T_NONE},
 {__NR_readv,"readv", SYSC_GROUP_IO, 3, SYSC_ARG_T_INT, SYSC_ARG_T_INT, SYSC_ARG_T_POINTER, SYSC_ARG_T_INT, SYSC_ARG_T_NONE, SYSC_ARG_T_NONE},
 {__NR_readv_pos,"readv_pos", SYSC_GROUP_IO, 4, SYSC_ARG_T_STATUS_T, SYSC_ARG_T_INT, SYSC_ARG_T_INT, SYSC_ARG_T_POINTER, SYSC_ARG_T_INT, SYSC_ARG_T_NONE},
 {__NR_write_pos,"write_pos", SYSC_GROUP_IO, 4, SYSC_ARG_T_STATUS_T, SYSC_ARG_T_INT, SYSC_ARG_T_INT, SYSC_ARG_T_POINTER, SYSC_ARG_T_INT, SYSC_ARG_T_NONE},
 {__NR_writev,"writev", SYSC_GROUP_IO, 3, SYSC_ARG_T_LONG_INT, SYSC_ARG_T_INT, SYSC_ARG_T_POINTER, SYSC_ARG_T_INT, SYSC_ARG_T_NONE, SYSC_ARG_T_NONE},
 {__NR_writev_pos,"writev_pos", SYSC_GROUP_IO, 4, SYSC_ARG_T_LONG_INT, SYSC_ARG_T_INT, SYSC_ARG_T_INT, SYSC_ARG_T_POINTER, SYSC_ARG_T_INT, SYSC_ARG_T_NONE},
 {__NR_watch_node,"watch_node", SYSC_GROUP_IO, 4, SYSC_ARG_T_INT, SYSC_ARG_T_INT, SYSC_ARG_T_INT, SYSC_ARG_T_LONG_HEX, SYSC_ARG_T_POINTER, SYSC_ARG_T_NONE},
 {__NR_delete_node_monitor,"delete_node_monitor", SYSC_GROUP_IO, 1, SYSC_ARG_T_INT, SYSC_ARG_T_INT, SYSC_ARG_T_NONE, SYSC_ARG_T_NONE, SYSC_ARG_T_NONE, SYSC_ARG_T_NONE},
 {__NR_based_mkdir,"based_mkdir", SYSC_GROUP_IO, 3, SYSC_ARG_T_INT, SYSC_ARG_T_INT, SYSC_ARG_T_STRING, SYSC_ARG_T_INT, SYSC_ARG_T_NONE, SYSC_ARG_T_NONE},
 {__NR_based_rmdir,"based_rmdir", SYSC_GROUP_IO, 2, SYSC_ARG_T_INT, SYSC_ARG_T_INT, SYSC_ARG_T_STRING, SYSC_ARG_T_NONE, SYSC_ARG_T_NONE, SYSC_ARG_T_NONE},
 {__NR_based_unlink,"based_unlink", SYSC_GROUP_IO, 2, SYSC_ARG_T_INT, SYSC_ARG_T_INT, SYSC_ARG_T_STRING, SYSC_ARG_T_NONE, SYSC_ARG_T_NONE, SYSC_ARG_T_NONE},
 {__NR_based_symlink,"based_symlink", SYSC_GROUP_IO, 3, SYSC_ARG_T_INT, SYSC_ARG_T_INT, SYSC_ARG_T_STRING, SYSC_ARG_T_STRING, SYSC_ARG_T_NONE, SYSC_ARG_T_NONE},
 {__NR_based_open,"based_open", SYSC_GROUP_IO, 4, SYSC_ARG_T_INT, SYSC_ARG_T_INT, SYSC_ARG_T_STRING, SYSC_ARG_T_INT, SYSC_ARG_T_SPECIAL, SYSC_ARG_T_NONE},
 {__NR_ftruncate,"ftruncate", SYSC_GROUP_IO, 3, SYSC_ARG_T_INT, SYSC_ARG_T_INT, SYSC_ARG_T_LONG_INT, SYSC_ARG_T_LONG_INT, SYSC_ARG_T_NONE, SYSC_ARG_T_NONE},
 {__NR_truncate,"truncate", SYSC_GROUP_IO, 3, SYSC_ARG_T_INT, SYSC_ARG_T_STRING, SYSC_ARG_T_LONG_INT, SYSC_ARG_T_LONG_INT, SYSC_ARG_T_NONE, SYSC_ARG_T_NONE},

 /* Debuging */

 {__NR_DebugPrint,"DebugPrint", SYSC_GROUP_DEBUG, 2, SYSC_ARG_T_INT, SYSC_ARG_T_STRING, SYSC_ARG_T_POINTER, SYSC_ARG_T_NONE, SYSC_ARG_T_NONE, SYSC_ARG_T_NONE},
 {__NR_debug_write,"debug_write", SYSC_GROUP_DEBUG, 3, SYSC_ARG_T_INT, SYSC_ARG_T_INT, SYSC_ARG_T_POINTER, SYSC_ARG_T_INT, SYSC_ARG_T_NONE, SYSC_ARG_T_NONE},
 {__NR_debug_read,"debug_read", SYSC_GROUP_DEBUG, 3, SYSC_ARG_T_INT, SYSC_ARG_T_INT, SYSC_ARG_T_POINTER, SYSC_ARG_T_INT, SYSC_ARG_T_NONE, SYSC_ARG_T_NONE},
 {__NR_strace,"strace", SYSC_GROUP_DEBUG, 3, SYSC_ARG_T_STATUS_T, SYSC_ARG_T_INT, SYSC_ARG_T_INT, SYSC_ARG_T_INT, SYSC_ARG_T_NONE, SYSC_ARG_T_NONE },
 {__NR_strace_exclude,"strace_exclude", SYSC_GROUP_DEBUG, 2, SYSC_ARG_T_STATUS_T, SYSC_ARG_T_INT, SYSC_ARG_T_INT, SYSC_ARG_T_NONE, SYSC_ARG_T_NONE, SYSC_ARG_T_NONE },
 {__NR_strace_include,"strace_include", SYSC_GROUP_DEBUG, 2, SYSC_ARG_T_STATUS_T, SYSC_ARG_T_INT, SYSC_ARG_T_INT, SYSC_ARG_T_NONE, SYSC_ARG_T_NONE, SYSC_ARG_T_NONE },
 {__NR_ptrace,"ptrace", SYSC_GROUP_DEBUG, 4, SYSC_ARG_T_INT, SYSC_ARG_T_INT, SYSC_ARG_T_INT, SYSC_ARG_T_POINTER, SYSC_ARG_T_POINTER, SYSC_ARG_T_NONE },

 /* Misc. */

 {__NR_get_raw_system_time,"get_raw_system_time", SYSC_GROUP_MISC, 1, SYSC_ARG_T_INT, SYSC_ARG_T_POINTER, SYSC_ARG_T_NONE, SYSC_ARG_T_NONE, SYSC_ARG_T_NONE, SYSC_ARG_T_NONE},
 {__NR_get_raw_real_time,"get_raw_real_time", SYSC_GROUP_MISC, 1, SYSC_ARG_T_INT, SYSC_ARG_T_POINTER, SYSC_ARG_T_NONE, SYSC_ARG_T_NONE, SYSC_ARG_T_NONE, SYSC_ARG_T_NONE},
 {__NR_get_raw_idle_time,"get_raw_idle_time", SYSC_GROUP_MISC, 1, SYSC_ARG_T_INT, SYSC_ARG_T_POINTER, SYSC_ARG_T_NONE, SYSC_ARG_T_NONE, SYSC_ARG_T_NONE, SYSC_ARG_T_NONE},
 {__NR_reboot,"reboot", SYSC_GROUP_MISC, 0, SYSC_ARG_T_INT, SYSC_ARG_T_NONE, SYSC_ARG_T_NONE, SYSC_ARG_T_NONE, SYSC_ARG_T_NONE, SYSC_ARG_T_NONE},
 {__NR_GetToken,"GetToken", SYSC_GROUP_MISC, 0, SYSC_ARG_T_LONG_INT, SYSC_ARG_T_NONE, SYSC_ARG_T_NONE, SYSC_ARG_T_NONE, SYSC_ARG_T_NONE, SYSC_ARG_T_NONE},
 {__NR_utime,"utime", SYSC_GROUP_MISC, 2, SYSC_ARG_T_INT, SYSC_ARG_T_STRING, SYSC_ARG_T_POINTER, SYSC_ARG_T_NONE, SYSC_ARG_T_NONE, SYSC_ARG_T_NONE},
 {__NR_realint,"realint", SYSC_GROUP_MISC, 2, SYSC_ARG_T_INT, SYSC_ARG_T_INT, SYSC_ARG_T_POINTER, SYSC_ARG_T_NONE, SYSC_ARG_T_NONE, SYSC_ARG_T_NONE},
 {__NR_get_system_path,"get_system_path", SYSC_GROUP_MISC, 2, SYSC_ARG_T_INT, SYSC_ARG_T_POINTER, SYSC_ARG_T_INT, SYSC_ARG_T_NONE, SYSC_ARG_T_NONE, SYSC_ARG_T_NONE},
 {__NR_get_vesa_info,"get_vesa_info", SYSC_GROUP_MISC, 3, SYSC_ARG_T_INT, SYSC_ARG_T_POINTER, SYSC_ARG_T_POINTER, SYSC_ARG_T_INT, SYSC_ARG_T_NONE, SYSC_ARG_T_NONE},
 {__NR_get_vesa_mode_info,"get_vesa_mode_info", SYSC_GROUP_MISC, 2, SYSC_ARG_T_INT, SYSC_ARG_T_POINTER, SYSC_ARG_T_LONG_INT, SYSC_ARG_T_NONE, SYSC_ARG_T_NONE, SYSC_ARG_T_NONE},
 {__NR_set_real_time,"set_real_time", SYSC_GROUP_MISC, 2, SYSC_ARG_T_INT, SYSC_ARG_T_INT, SYSC_ARG_T_INT, SYSC_ARG_T_NONE, SYSC_ARG_T_NONE, SYSC_ARG_T_NONE},
 {__NR_get_system_info,"get_system_info", SYSC_GROUP_MISC, 1, SYSC_ARG_T_STATUS_T, SYSC_ARG_T_POINTER, SYSC_ARG_T_NONE, SYSC_ARG_T_NONE, SYSC_ARG_T_NONE, SYSC_ARG_T_NONE},
 {__NR_GetTime,"GetTime", SYSC_GROUP_MISC, 1, SYSC_ARG_T_LONG_INT, SYSC_ARG_T_POINTER, SYSC_ARG_T_NONE, SYSC_ARG_T_NONE, SYSC_ARG_T_NONE, SYSC_ARG_T_NONE},
 {__NR_SetTime,"SetTime", SYSC_GROUP_MISC, 1, SYSC_ARG_T_LONG_INT, SYSC_ARG_T_POINTER, SYSC_ARG_T_NONE, SYSC_ARG_T_NONE, SYSC_ARG_T_NONE, SYSC_ARG_T_NONE},
 {__NR_call_v86,"call_v86", SYSC_GROUP_MISC, 1, SYSC_ARG_T_INT, SYSC_ARG_T_POINTER, SYSC_ARG_T_NONE, SYSC_ARG_T_NONE, SYSC_ARG_T_NONE, SYSC_ARG_T_NONE},
 {__NR_apm_poweroff,"apm_poweroff", SYSC_GROUP_MISC, 0, SYSC_ARG_T_INT, SYSC_ARG_T_NONE, SYSC_ARG_T_NONE, SYSC_ARG_T_NONE, SYSC_ARG_T_NONE, SYSC_ARG_T_NONE}
};

#endif /* _F_SYSCALLTABLE_H_ */
