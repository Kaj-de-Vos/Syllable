/* config.h.  Generated automatically by configure.  */
/* config.h -- Configuration file for bash. */

/* Copyright (C) 1987-2001 Free Software Foundation, Inc.

   This file is part of GNU Bash, the Bourne Again SHell.

   Bash is free software; you can redistribute it and/or modify it
   under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   Bash is distributed in the hope that it will be useful, but WITHOUT
   ANY WARRANTY; without even the implied warranty of MERCHANTABILITY
   or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public
   License for more details.

   You should have received a copy of the GNU General Public License
   along with Bash; see the file COPYING.  If not, write to the Free
   Software Foundation, 59 Temple Place, Suite 330, Boston, MA 02111 USA. */

#ifndef _CONFIG_H_
#define _CONFIG_H_

/* Configuration feature settings controllable by autoconf. */

/* Define JOB_CONTROL if your operating system supports
   BSD-like job control. */
#define JOB_CONTROL 1

/* Define ALIAS if you want the alias features. */
#define ALIAS 1

/* Define PUSHD_AND_POPD if you want those commands to be compiled in.
   (Also the `dirs' commands.) */
#define PUSHD_AND_POPD 1

/* Define BRACE_EXPANSION if you want curly brace expansion a la Csh:
   foo{a,b} -> fooa foob.  Even if this is compiled in (the default) you
   can turn it off at shell startup with `-nobraceexpansion', or during
   shell execution with `set +o braceexpand'. */
#define BRACE_EXPANSION 1

/* Define READLINE to get the nifty/glitzy editing features.
   This is on by default.  You can turn it off interactively
   with the -nolineediting flag. */
#define READLINE 1

/* Define BANG_HISTORY if you want to have Csh style "!" history expansion.
   This is unrelated to READLINE. */
#define BANG_HISTORY 1

/* Define HISTORY if you want to have access to previously typed commands.

   If both HISTORY and READLINE are defined, you can get at the commands
   with line editing commands, and you can directly manipulate the history
   from the command line.

   If only HISTORY is defined, the `fc' and `history' builtins are
   available. */
#define HISTORY 1

/* Define this if you want completion that puts all alternatives into
   a brace expansion shell expression. */
#if defined (BRACE_EXPANSION) && defined (READLINE)
#  define BRACE_COMPLETION
#endif /* BRACE_EXPANSION */

/* Define DEFAULT_ECHO_TO_XPG if you want the echo builtin to interpret
   the backslash-escape characters by default, like the XPG Single Unix
   Specification V2 for echo.
   This requires that V9_ECHO be defined. */
/* #undef DEFAULT_ECHO_TO_XPG */

/* Define HELP_BUILTIN if you want the `help' shell builtin and the long
   documentation strings compiled into the shell. */
#define HELP_BUILTIN 1

/* Define RESTRICTED_SHELL if you want the generated shell to have the
   ability to be a restricted one.  The shell thus generated can become
   restricted by being run with the name "rbash", or by setting the -r
   flag. */
#define RESTRICTED_SHELL 1

/* Define DISABLED_BUILTINS if you want "builtin foo" to always run the
   shell builtin "foo", even if it has been disabled with "enable -n foo". */
/* #undef DISABLED_BUILTINS */

/* Define PROCESS_SUBSTITUTION if you want the K*rn shell-like process
   substitution features "<(file)". */
/* Right now, you cannot do this on machines without fully operational
   FIFO support.  This currently include NeXT and Alliant. */
#define PROCESS_SUBSTITUTION 1

/* Define PROMPT_STRING_DECODE if you want the backslash-escaped special
   characters in PS1 and PS2 expanded.  Variable expansion will still be
   performed. */
#define PROMPT_STRING_DECODE 1

/* Define SELECT_COMMAND if you want the Korn-shell style `select' command:
	select word in word_list; do command_list; done */
#define SELECT_COMMAND 1

/* Define COMMAND_TIMING of you want the ksh-style `time' reserved word and
   the ability to time pipelines, functions, and builtins. */
#define COMMAND_TIMING 1

/* Define ARRAY_VARS if you want ksh-style one-dimensional array variables. */
#define ARRAY_VARS 1

/* Define DPAREN_ARITHMETIC if you want the ksh-style ((...)) arithmetic
   evaluation command. */
#define DPAREN_ARITHMETIC 1

/* Define EXTENDED_GLOB if you want the ksh-style [*+@?!](patlist) extended
   pattern matching. */
#define EXTENDED_GLOB 1

/* Define COND_COMMAND if you want the ksh-style [[...]] conditional
   command. */
#define COND_COMMAND 1

/* Define ARITH_FOR_COMMAND if you want the ksh93-style
	for (( init; test; step )) do list; done
   arithmetic for command. */
#define ARITH_FOR_COMMAND 1

/* Define NETWORK_REDIRECTIONS if you want /dev/(tcp|udp)/host/port to open
   socket connections when used in redirections */
#define NETWORK_REDIRECTIONS 1

/* Define PROGRAMMABLE_COMPLETION for the programmable completion features
   and the complete builtin. */
#define PROGRAMMABLE_COMPLETION 1

/* Define AFS if you are using Transarc's AFS. */
/* #undef AFS */

/* End of configuration settings controllable by autoconf. */
/* Other settable options appear in config-top.h. */

#include "config-top.h"

/* Beginning of autoconf additions. */

/* Characteristics of the C compiler */
/* #undef const */

/* #undef inline */

/* Define if cpp supports the ANSI-C stringizing `#' operator */
#define HAVE_STRINGIZE 1

/* Define if the compiler supports `long double' variables. */
#define HAVE_LONG_DOUBLE 1

#define PROTOTYPES 1

/* #undef __CHAR_UNSIGNED__ */

/* Define if the compiler supports `long long' variables. */
#define HAVE_LONG_LONG 1

#define HAVE_UNSIGNED_LONG_LONG 1

/* The number of bytes in a int.  */
#define SIZEOF_INT 4

/* The number of bytes in a long.  */
#define SIZEOF_LONG 4

/* The number of bytes in a pointer to char.  */
#define SIZEOF_CHAR_P 4

/* The number of bytes in a double (hopefully 8). */
#define SIZEOF_DOUBLE 8

/* The number of bytes in a `long long', if we have one. */
#define SIZEOF_LONG_LONG 8

/* System paths */

#define DEFAULT_MAIL_DIRECTORY "unknown"

/* Characteristics of the system's header files and libraries that affect
   the compilation environment. */

/* Define if the system does not provide POSIX.1 features except
   with this defined.  */
/* #undef _POSIX_1_SOURCE */

/* Define if you need to in order for stat and other things to work.  */
/* #undef _POSIX_SOURCE */

/* Define to use GNU libc extensions */
#define _GNU_SOURCE 1

/* Define if you have the ANSI C header files.  */
#define STDC_HEADERS 1

/* Memory management functions. */

/* Define if using the bash version of malloc in lib/malloc/malloc.c */
#define USING_BASH_MALLOC 1

/* Define if using alloca.c.  */
/* #undef C_ALLOCA */

/* Define to one of _getb67, GETB67, getb67 for Cray-2 and Cray-YMP systems.
   This function is required for alloca.c support on those systems.  */
/* #undef CRAY_STACKSEG_END */

/* Define if you have alloca, as a function or macro.  */
#define HAVE_ALLOCA 1

/* Define if you have <alloca.h> and it should be used (not on Ultrix).  */
#define HAVE_ALLOCA_H 1


/* SYSTEM TYPES */

/* Define to `long' if <sys/types.h> doesn't define.  */
/* #undef off_t */

/* Define to `int' if <sys/types.h> doesn't define. */
/* #undef mode_t */

/* Define to `int' if <signal.h> doesn't define. */
/* #undef sigset_t */

/* Define to `int' if <sys/types.h> doesn't define.  */
/* #undef pid_t */

/* Define to `short' if <sys/types.h> doesn't define.  */
#define bits16_t short

/* Define to `unsigned short' if <sys/types.h> doesn't define.  */
#define u_bits16_t unsigned short

/* Define to `int' if <sys/types.h> doesn't define.  */
#define bits32_t int

/* Define to `unsigned int' if <sys/types.h> doesn't define.  */
#define u_bits32_t unsigned int

/* Define to `double' if <sys/types.h> doesn't define. */
#define bits64_t double

/* Define to `unsigned int' if <sys/types.h> doesn't define. */
/* #undef u_int */

/* Define to `unsigned long' if <sys/types.h> doesn't define.  */
/* #undef u_long */

/* Define to `int' if <sys/types.h> doesn't define. */
/* #undef ptrdiff_t */

/* Define to `unsigned' if <sys/types.h> doesn't define.  */
/* #undef size_t */

/* Define to `int' if <sys/types.h> doesn't define. */
/* #undef ssize_t */

/* Define to `long' if <stdint.h> doesn't define. */
/* #undef intmax_t */

/* Define to `unsigned long' if <stdint.h> doesn't define. */
/* #undef uintmax_t */

/* Define to `int' if <sys/types.h> doesn't define.  */
/* #undef uid_t */

/* Define to `long' if <sys/types.h> doesn't define.  */
/* #undef clock_t */

/* Define to `long' if <sys/types.h> doesn't define.  */
/* #undef time_t */

/* Define to `int' if <sys/types.h> doesn't define.  */
/* #undef gid_t */

/* Define to `unsigned int' if <sys/socket.h> doesn't define. */
/* #undef socklen_t */

/* Define if you have quad_t in <sys/types.h>. */
#define HAVE_QUAD_T 1

#define RLIMTYPE rlim_t

/* Define to the type of elements in the array set by `getgroups'.
   Usually this is either `int' or `gid_t'.  */
#define GETGROUPS_T gid_t

/* Characteristics of the machine archictecture. */

/* If using the C implementation of alloca, define if you know the
   direction of stack growth for your system; otherwise it will be
   automatically deduced at run-time.
	STACK_DIRECTION > 0 => grows toward higher addresses
	STACK_DIRECTION < 0 => grows toward lower addresses
	STACK_DIRECTION = 0 => direction of growth unknown
 */
/* #undef STACK_DIRECTION */

/* Define if the machine architecture is big-endian. */
/* #undef WORDS_BIGENDIAN */

/* Check for the presence of certain non-function symbols in the system
   libraries. */

/* Define if `sys_siglist' is declared by <signal.h> or <unistd.h>.  */
#define SYS_SIGLIST_DECLARED 1

/* Define if `_sys_siglist' is declared by <signal.h> or <unistd.h>.  */
#define UNDER_SYS_SIGLIST_DECLARED 1

#define HAVE_SYS_SIGLIST 1

#define HAVE_UNDER_SYS_SIGLIST 1

#define HAVE_SYS_ERRLIST 1

#define HAVE_TIMEVAL 1


/* Characteristics of some of the system structures. */

#define STRUCT_DIRENT_HAS_D_INO 1

#define STRUCT_DIRENT_HAS_D_FILENO 1

/* #undef TIOCSTAT_IN_SYS_IOCTL */

#define FIONREAD_IN_SYS_IOCTL 1

/* #undef GWINSZ_IN_SYS_IOCTL */

#define STRUCT_WINSIZE_IN_SYS_IOCTL 1

/* #undef STRUCT_WINSIZE_IN_TERMIOS */

/* #undef SPEED_T_IN_SYS_TYPES */

#define TERMIOS_LDISC 1

#define TERMIO_LDISC 1

#define HAVE_STRUCT_STAT_ST_BLOCKS 1

/* Characteristics of definitions in the system header files. */

#define HAVE_GETPW_DECLS 1

/* #undef HAVE_RESOURCE */

/* #undef HAVE_LIBC_FNM_EXTMATCH */

#define HAVE_DECL_CONFSTR 1

#define HAVE_DECL_STRTOLD 1

#define HAVE_DECL_SBRK 1

#define HAVE_DECL_PRINTF 1

#define HAVE_DECL_STRSIGNAL 1

/* These are checked with BASH_CHECK_DECL */

#define HAVE_DECL_STRTOIMAX 1
#define HAVE_DECL_STRTOL 1
#define HAVE_DECL_STRTOLL 1
#define HAVE_DECL_STRTOUL 1
#define HAVE_DECL_STRTOULL 1
#define HAVE_DECL_STRTOUMAX 1

/* Characteristics of system calls and C library functions. */

/* Define if the `getpgrp' function takes no argument.  */
#define GETPGRP_VOID 1

/* #undef NAMED_PIPES_MISSING */

/* #undef OPENDIR_NOT_ROBUST */

/* #undef PGRP_PIPE */

/* Define if the setvbuf function takes the buffering type as its second
   argument and the buffer pointer as the third, as on System V
   before release 3.  */
/* #undef SETVBUF_REVERSED */

/* #undef STAT_MACROS_BROKEN */

#define ULIMIT_MAXFDS 1

#define CAN_REDEFINE_GETENV 1

#define HAVE_PRINTF_A_FORMAT 1

/* Characteristics of properties exported by the kernel. */

/* Define if the kernel can exec files beginning with #! */
#define HAVE_HASH_BANG_EXEC 1

/* Define if you have the /dev/fd devices to map open files into the file system. */
/* #undef HAVE_DEV_FD */

/* Defined to /dev/fd or /proc/self/fd (linux). */
/* #undef DEV_FD_PREFIX */

/* Define if you have the /dev/stdin device. */
/* #undef HAVE_DEV_STDIN */


/* Type and behavior of signal handling functions. */

/* Define as the return type of signal handlers (int or void).  */
#define RETSIGTYPE void

/* Define if return type of signal handlers is void */
#define VOID_SIGHANDLER 1

/* #undef MUST_REINSTALL_SIGHANDLERS */

/* #undef HAVE_BSD_SIGNALS */

#define HAVE_POSIX_SIGNALS 1

/* #undef HAVE_USG_SIGHOLD */

/* #undef UNUSABLE_RT_SIGNALS */


/* Presence of system and C library functions. */

/* Define if you have the asprintf function.  */
#define HAVE_ASPRINTF 1

/* Define if you have the bcopy function.  */
#define HAVE_BCOPY 1

/* Define if you have the bindtextdomain function.  */
#define HAVE_BINDTEXTDOMAIN 1

/* Define if you have the bzero function.  */
#define HAVE_BZERO 1

/* Define if you have the confstr function.  */
#define HAVE_CONFSTR 1

/* Define if you have the dlclose function.  */
#define HAVE_DLCLOSE 1

/* Define if you have the dlopen function.  */
#define HAVE_DLOPEN 1

/* Define if you have the dlsym function.  */
#define HAVE_DLSYM 1

/* Define if you don't have vprintf but do have _doprnt.  */
/* #undef HAVE_DOPRNT */

/* Define if you have the dup2 function.  */
#define HAVE_DUP2 1

/* Define if you have the getaddrinfo function. */
#define HAVE_GETADDRINFO 1

/* Define if you have the getcwd function.  */
#define HAVE_GETCWD 1

/* Define if you have the getdtablesize function.  */
#define HAVE_GETDTABLESIZE 1

/* Define if you have the getgroups function.  */
#define HAVE_GETGROUPS 1

/* Define if you have the gethostbyname function.  */
#define HAVE_GETHOSTBYNAME 1

/* Define if you have the gethostname function.  */
#define HAVE_GETHOSTNAME 1

/* Define if you have the getpagesize function.  */
#define HAVE_GETPAGESIZE 1

/* Define if you have the getpeername function.  */
#define HAVE_GETPEERNAME 1

/* Define if you have the getrlimit function.  */
/* #undef HAVE_GETRLIMIT */

/* Define if you have the getrusage function.  */
/* #undef HAVE_GETRUSAGE */

/* Define if you have the getservbyname function.  */
#define HAVE_GETSERVBYNAME 1

/* Define if you have the gettext function. */
#define HAVE_GETTEXT 1

/* Define if you have the gettimeofday function.  */
#define HAVE_GETTIMEOFDAY 1

/* Define if you have the getwd function.  */
/* #undef HAVE_GETWD */

/* Define if you have the inet_aton function.  */
#define HAVE_INET_ATON 1

/* Define if you have the isascii function. */
#define HAVE_ISASCII 1

/* Define if you have the isblank function.  */
#define HAVE_ISBLANK 1

/* Define if you have the isgraph function.  */
#define HAVE_ISGRAPH 1

/* Define if you have the isprint function.  */
#define HAVE_ISPRINT 1

/* Define if you have the isspace function.  */
#define HAVE_ISSPACE 1

/* Define if you have the isxdigit function.  */
#define HAVE_ISXDIGIT 1

/* Define if you have the killpg function.  */
#define HAVE_KILLPG 1

/* Define if you have the lstat function. */
#define HAVE_LSTAT 1

/* Define if you have the memmove function.  */
#define HAVE_MEMMOVE 1

/* Define if you have the mkfifo function.  */
#define HAVE_MKFIFO 1

/* Define if you have the pathconf function. */
#define HAVE_PATHCONF 1

/* Define if you have the putenv function.  */
#define HAVE_PUTENV 1

/* Define if you have the readlink function. */
#define HAVE_READLINK 1

/* Define if you have the rename function. */
#define HAVE_RENAME 1

/* Define if you have the sbrk function. */
#define HAVE_SBRK 1

/* Define if you have the select function.  */
#define HAVE_SELECT 1

/* Define if you have the setdtablesize function.  */
/* #undef HAVE_SETDTABLESIZE */

/* Define if you have the setenv function.  */
#define HAVE_SETENV 1

/* Define if you have the setlinebuf function.  */
#define HAVE_SETLINEBUF 1

/* Define if you have the setlocale function.  */
#define HAVE_SETLOCALE 1

/* Define if you have the setostype function.  */
/* #undef HAVE_SETOSTYPE */

/* Define if you have the setvbuf function.  */
#define HAVE_SETVBUF 1

/* Define if you have the siginterrupt function.  */
#define HAVE_SIGINTERRUPT 1

/* Define if you have the POSIX.1-style sigsetjmp function.  */
#define HAVE_POSIX_SIGSETJMP 1

/* Define if you have the snprintf function.  */
#define HAVE_SNPRINTF 1

/* Define if you have the strcasecmp function.  */
#define HAVE_STRCASECMP 1

/* Define if you have the strchr function.  */
#define HAVE_STRCHR 1

/* Define if you have the strcoll function.  */
#define HAVE_STRCOLL 1

/* Define if you have the strerror function.  */
#define HAVE_STRERROR 1

/* Define if you have the strpbrk function. */
#define HAVE_STRPBRK 1

/* Define if you have the strtod function. */
#define HAVE_STRTOD 1

/* Define if you have the strtoimax function. */
#define HAVE_STRTOIMAX 1

/* Define if you have the strtol function. */
#define HAVE_STRTOL 1

/* Define if you have the strtoll function. */
#define HAVE_STRTOLL 1

/* Define if you have the strtoul function. */
#define HAVE_STRTOUL 1

/* Define if you have the strtoull function. */
#define HAVE_STRTOULL 1

/* Define if you have the strtoumax function. */
#define HAVE_STRTOUMAX 1

/* Define if you have the strsignal function or macro. */
#define HAVE_STRSIGNAL 1

/* Define if you have the sysconf function. */
#define HAVE_SYSCONF 1

/* Define if you have the tcgetattr function.  */
#define HAVE_TCGETATTR 1

/* Define if you have the tcgetpgrp function.  */
#define HAVE_TCGETPGRP 1

/* Define if you have the textdomain function.  */
#define HAVE_TEXTDOMAIN 1

/* Define if you have the times function.  */
/* #undef HAVE_TIMES */

/* Define if you have the ttyname function.  */
#define HAVE_TTYNAME 1

/* Define if you have the tzset function. */
#define HAVE_TZSET 1

/* Define if you have the ulimit function. */
#define HAVE_ULIMIT 1

/* Define if you have the uname function. */
#define HAVE_UNAME 1

/* Define if you have the vasprintf function.  */
#define HAVE_VASPRINTF 1

/* Define if you have the vprintf function.  */
#define HAVE_VPRINTF 1

/* Define if you have the vsnprintf function.  */
#define HAVE_VSNPRINTF 1

/* Define if you have the waitpid function. */
#define HAVE_WAITPID 1

/* Define if you have the wait3 function.  */
#define HAVE_WAIT3 1

/* Presence of certain system include files. */

/* Define if you have the <arpa/inet.h> header file. */
#define HAVE_ARPA_INET_H 1

/* Define if you have the <dirent.h> header file.  */
#define HAVE_DIRENT_H 1

/* Define if you have the <dlfcn.h> header file.  */
#define HAVE_DLFCN_H 1

/* Define if you have the <grp.h> header file.  */
#define HAVE_GRP_H 1

/* Define if you have the <inttypes.h> header file. */
#define HAVE_INTTYPES_H 1

/* Define if you have the <libintl.h> header file. */
#define HAVE_LIBINTL_H 1

/* Define if you have the <limits.h> header file.  */
#define HAVE_LIMITS_H 1

/* Define if you have the <locale.h> header file.  */
#define HAVE_LOCALE_H 1

/* Define if you have the <ndir.h> header file.  */
/* #undef HAVE_NDIR_H */

/* Define if you have the <netdh.h> header file. */
#define HAVE_NETDB_H 1

/* Define if you have the <netinet/in.h> header file. */
#define HAVE_NETINET_IN_H 1

/* Define if you have the <stdlib.h> header file.  */
#define HAVE_STDLIB_H 1

/* Define if you have the <stdarg.h> header file.  */
#define HAVE_STDARG_H 1

/* Define if you have the <string.h> header file.  */
#define HAVE_STRING_H 1

/* Define if you have the <strings.h> header file.  */
#define HAVE_STRINGS_H 1

/* Define if you have the <memory.h> header file.  */
#define HAVE_MEMORY_H 1

/* Define if you have the <stddef.h> header file. */
#define HAVE_STDDEF_H 1

/* Define if you have the <stdint.h> header file. */
#define HAVE_STDINT_H 1

/* Define if you have the <sys/dir.h> header file.  */
/* #undef HAVE_SYS_DIR_H */

/* Define if you have the <sys/file.h> header file.  */
#define HAVE_SYS_FILE_H 1

/* Define if you have the <sys/ndir.h> header file.  */
/* #undef HAVE_SYS_NDIR_H */

/* Define if you have the <sys/param.h> header file.  */
#define HAVE_SYS_PARAM_H 1

/* Define if you have the <sys/pte.h> header file.  */
/* #undef HAVE_SYS_PTE_H */

/* Define if you have the <sys/ptem.h> header file.  */
/* #undef HAVE_SYS_PTEM_H */

/* Define if you have the <sys/resource.h> header file.  */
#define HAVE_SYS_RESOURCE_H 1

/* Define if you have the <sys/select.h> header file.  */
#define HAVE_SYS_SELECT_H 1

/* Define if you have the <sys/socket.h> header file.  */
#define HAVE_SYS_SOCKET_H 1

/* Define if you have the <sys/stream.h> header file.  */
/* #undef HAVE_SYS_STREAM_H */

/* Define if you have <sys/time.h> */
#define HAVE_SYS_TIME_H 1

#define TIME_WITH_SYS_TIME 1

/* Define if you have <sys/times.h> */
#define HAVE_SYS_TIMES_H 1

/* Define if you have <sys/wait.h> that is POSIX.1 compatible.  */
#define HAVE_SYS_WAIT_H 1

/* Define if you have the <termcap.h> header file.  */
#define HAVE_TERMCAP_H 1

/* Define if you have the <termio.h> header file.  */
#define HAVE_TERMIO_H 1

/* Define if you have the <termios.h> header file.  */
#define HAVE_TERMIOS_H 1

/* Define if you have the <unistd.h> header file.  */
#define HAVE_UNISTD_H 1

/* Define if you have the <varargs.h> header file.  */
#define HAVE_VARARGS_H 1

/* Presence of certain system libraries. */

#define HAVE_LIBDL 1

/* #undef HAVE_LIBSUN */

/* #undef HAVE_LIBSOCKET */


/* Define if on MINIX.  */
/* #undef _MINIX */

/* Are we running SVR5 (UnixWare 7)? */
/* #undef SVR5 */

/* Are we running SVR4.2? */
/* #undef SVR4_2 */

/* Are we running some version of SVR4? */
/* #undef SVR4 */

/* Define if job control is unusable or unsupported. */
/* #undef JOB_CONTROL_MISSING */

/* Do we need to define _KERNEL to get the RLIMIT_* defines from
   <sys/resource.h>? */
/* #undef RLIMIT_NEEDS_KERNEL */

/* Number of bits in a file offset, on hosts where this is settable. */
/* #undef _FILE_OFFSET_BITS */

/* Define for large files on AIX-style hosts. */
/* #undef _LARGE_FILES */

/* Do strcoll(3) and strcmp(3) give different results in the default locale? */
/* #undef STRCOLL_BROKEN */

/* #undef DUP2_BROKEN */

/* #undef GETCWD_BROKEN */

#include "config-bot.h"

#endif /* _CONFIG_H_ */
