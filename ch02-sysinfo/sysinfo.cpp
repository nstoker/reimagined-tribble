#include "sysinfo.h"
#include <QtGlobal>

#ifdef Q_OS_WIN
    #include "sysinfowindowsimpl.h"
#elif defined(Q_OS_MAC)
    #include "sysinfomacimpl.h"
#elif defined(Q_OS_LINUX)
    #include "sysinfolinuximpl.h"
#else
    #error Unrecognised build system
#endif

SysInfo::SysInfo()
{

}


SysInfo::~SysInfo()
{

}


SysInfo& SysInfo::instance()
{
#ifdef Q_OS_WIN
    static SysInfoWindowsImpl singleton;
#elif defined(Q_OS_MAC)
    static SysInfoMacImpl singleton;
#elif defined(Q_OS_LINUX)
    static SysInfoLinuxImpl singleton;
#else
    #error Unrecognised build system
#endif

    return singleton;
}
