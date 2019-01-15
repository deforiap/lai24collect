/*!
 * \copyright JSC "Rudnev-Shilyaev"
 * 
 * \file RshDefChk.h
 * \date 25.12.2015
 * \version 1.0 [SDK 2.1]
 * 
 * \~english
 * \brief
 * Operating system, compiler and plain data type definitions.
 * 
 * \~russian
 * \brief
 * Определения констант операционных систем, компиляторов и простых типов данных.
 * 
 */

#ifndef RSH_DEF_CHK_H
#define RSH_DEF_CHK_H

//check what compiler is used
#if defined(__MINGW32__) || defined (__MINGW64__)
 #define RSH_COMPILER_MINGW
#elif defined(__GNUC__)
 #define RSH_COMPILER_GNUC
#elif defined(__BORLANDC__)
 #define RSH_COMPILER_BORLANDC
 #define __attribute__(a)
#elif defined (_MSC_VER)
 #define RSH_COMPILER_MSVC
 #define __attribute__(a)
#else
 #error Unknown compiler is used! Comment this line if you know what you do.
#endif

//check what system we are running on
#if defined(_WIN32) || defined(_WIN64)
 #define RSH_MSWINDOWS
#elif defined (__linux__)
 #define RSH_LINUX
#else
 #error Rsh API is not tested with this OS! Comment this line if you know what you do.
#endif

#if defined(RSH_MSWINDOWS)

#define  NOMINMAX // fix problem with QDataTime -> windows.h in Qt; must be defined before include of windows.h

#include <windows.h>
#include <process.h>
#include <time.h>

#define __RSHCALLCONV       __stdcall
#define __rshisfinite(a)    _finite(a)
#define __rshmssleep(a)     Sleep(a)

#ifdef RSH_COMPILER_BORLANDC
	#define __rshgetpid() getpid()
#else
	#define __rshgetpid() _getpid()
#endif

#elif defined(RSH_LINUX)

//default paths to rsh binaries
//these defines are used in RshDllClient class and RshStaticFactory.cpp 
#define RSH_DLL_BOARDS_DIRECTORY "/usr/lib/RSH/boards/"
#define RSH_DLL_LIBRARIES_DIRECTORY "/usr/lib/RSH/libraries/"
#define RSH_DLL_DPA_DIRECTORY "/usr/lib/RSH/DPA/"

#include <cstdarg>
#include <float.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <dlfcn.h>
#include <errno.h>
#include <linux/types.h>    // Linux types
#include <linux/stddef.h>	// size_t, ptrdiff_t
#include <sys/time.h>

#define __RSHCALLCONV
#define __rshisfinite(a)     isfinite(a)
#define __rshmssleep(a)      usleep(a * 1000)
#define __rshgetpid()        getpid()
#endif



#if !defined(PLX_LINUX) && !defined(PLX_MSWINDOWS)
#if defined(RSH_LINUX)
typedef __s8 S8;
typedef __u8 U8;
typedef __s16 S16;
typedef __u16 U16;
typedef __s32 S32;
typedef __u32 U32;
typedef __s64 S64;
typedef __u64 U64;
#elif defined(RSH_MSWINDOWS)
typedef signed char           S8;
typedef unsigned char         U8;
typedef signed short          S16;
typedef unsigned short        U16;
typedef signed long           S32;
typedef unsigned long         U32;
typedef signed __int64         S64;
typedef unsigned __int64       U64;
#endif
#endif

#define	IN   // input parameter marker
#define OUT  // output parameter marker

#if !defined(VOID)
typedef void VOID;
#endif

#if !defined(NULL)
#define NULL              ((VOID *) 0x0)
#endif


#endif //RSH_DEF_CHK_H
