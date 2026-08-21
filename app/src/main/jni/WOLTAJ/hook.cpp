#include "WOLTAJ/patch/Includes.h"
#include "WOLTAJ/patch/MemoryPatch.h"
#include "WOLTAJ/patch/OBFUSCATE.h"
#include "WOLTAJ/patch/Utils.h"
#include "WOLTAJ/patch/Macros.h"
#include <list>
#include <vector>
#include <string>
#include <pthread.h>
#include <thread>
#include <cstring>
#include <jni.h>
#include <fstream>
#include <iostream>
#include <dlfcn.h>
#include <chrono> 
#include <fcntl.h>
#include <sys/stat.h>
#include <cstddef>
#include <semaphore.h>
#include <stdint.h>
#include <sstream>
#include <stdarg.h>
#include <stdio.h>

// Temel Tip Tanımları
#define _BYTE  uint8_t
#define _WORD  uint16_t
#define _DWORD uint32_t
#define _QWORD uint64_t
#define _OWORD uint64_t
#define _BOOL8 uint64_t

#define __int8 char
#define __int32 int
#define __int64 long long

#define targetLibName OBFUSCATE("libanogs.so")

#define ARM64_SYSREG(reg0, reg1, reg2, reg3, op) (((reg0) & 0x1F) | (((reg1) & 0x1F) << 5) | (((reg2) & 0x7) << 10) | (((reg3) & 0xF) << 16) | (((op) & 0x7) << 20))

#ifdef __aarch64__
inline uint64_t _ReadStatusReg(uint64_t reg) {
    return 0;
}
#endif

uintptr_t libaviwaBase = 0;
uintptr_t libaviwaSize = 0;
uintptr_t libaviwaAlloc = 0;
uintptr_t libanogsBase = 0;
uintptr_t UE4Base = 0;
uintptr_t libanortBase = 0;
uintptr_t libcBase = 0;
uintptr_t libEGLBase = 0;
uintptr_t libanogsAlloc = 0;
uintptr_t libUE4Alloc = 0;
uintptr_t libGCloudVoiceAlloc = 0;
uintptr_t libUE4Base = 0;
uintptr_t libEGLAlloc = 0;
uintptr_t GCloudVoiceSize = 0;
uintptr_t libanogsSize = 0;
uintptr_t libUE4Size = 0;
uintptr_t NewBase = 0;

// Flash Fix Stuck Offset — PUBGM 4.5.0 64Bit [SDK]
constexpr uintptr_t FixStuck_Offset = 0xA3B3F88;

size_t getLibrarySize(const char *libraryName)
{
    FILE *mapsFile = fopen("/proc/self/maps", "r");
    if (mapsFile == nullptr)
    {
        return 0;
    }

    char line[256];
    size_t size = 0;
    uintptr_t startAddr = 0, endAddr = 0;
    while (fgets(line, sizeof(line), mapsFile))
    {
        if (strstr(line, libraryName))
        {
            sscanf(line, "%lx-%lx", &startAddr, &endAddr);
            size = endAddr - startAddr;
            break;
        }
    }

    fclose(mapsFile);
    return size;
}

void Auto1DayFixer()
{
    while (!isLibraryLoaded("libanogs.so"))
    {
        sleep(1);
    }

    libanogsBase = findLibrary("libanogs.so");
    if (!libanogsBase)
        return;

    libanogsSize = getLibrarySize("libanogs.so");
    if (!libanogsSize)
        return;

    libanogsAlloc = (DWORD)malloc(libanogsSize);
    if (!libanogsAlloc)
        return;

    memcpy((void *)libanogsAlloc, (void *)libanogsBase, libanogsSize);

    void *handle = dlopen("libc.so", RTLD_LAZY);
    if (handle == nullptr)
        return;
    void *addr = dlsym(handle, "memcpy");
    if (addr == nullptr)
        return;
}

// ─────────────────────────────────────────────
// Anti-Cheat Bypass Hooks
// Credit: t.me/ibrdevelopershub
// ─────────────────────────────────────────────

static __int64 (*optrace)(__int64, __int64, __int64, __int64);
static __int64 hptrace(__int64 req, __int64 pid, __int64 addr, __int64 data) {
    if (req == 0) return 0;
    if (!optrace) { errno = EPERM; return -1; }
    return optrace(req, pid, addr, data);
}

static int (*okill)(int, int);
static int hkill(int pid, int sig) {
    if (pid == getpid()) {
        if (sig == 9 || sig == 3 || sig == 6 || sig == 15) return 0;
    }
    if (!okill) { errno = EPERM; return -1; }
    return okill(pid, sig);
}

static int (*o__system_property_get)(const char *, char *);
static int h__system_property_get(const char *name, char *value) {
    if (!name || !value) return 0;
    if (strcmp(name, "ro.debuggable") == 0)  { strcpy(value, "0");            return 1;  }
    if (strcmp(name, "ro.secure") == 0)       { strcpy(value, "1");            return 1;  }
    if (strcmp(name, "ro.build.tags") == 0)   { strcpy(value, "release-keys"); return 12; }
    if (strcmp(name, "ro.build.type") == 0)   { strcpy(value, "user");         return 4;  }
    if (!o__system_property_get) return 0;
    return o__system_property_get(name, value);
}

static void *(*odlopen)(const char *, int);
static void *hdlopen(const char *name, int flags) {
    if (name) {
        const char *blocklist[] = {
            "frida", "xposed", "substrate", "gadget", "hook",
            "libinject", "libsubstrate", "libfrida", nullptr
        };
        for (int i = 0; blocklist[i]; i++) {
            if (strstr(name, blocklist[i])) return NULL;
        }
    }
    if (!odlopen) return NULL;
    return odlopen(name, flags);
}

static FILE *(*opopen)(const char *, const char *);
static FILE *hpopen(const char *cmd, const char *mode) {
    if (cmd) {
        const char *blocklist[] = {
            "su", "magisk", "which ", "/sbin/", "busybox",
            "root", "supersu", "xposed", "frida", nullptr
        };
        for (int i = 0; blocklist[i]; i++) {
            if (strstr(cmd, blocklist[i])) return NULL;
        }
    }
    if (!opopen) return NULL;
    return opopen(cmd, mode);
}

static int (*oopen)(const char *, int, ...);
static int hopen(const char *path, int flags, ...) {
    mode_t mode = 0;
    if (flags & O_CREAT) {
        va_list args; va_start(args, flags);
        mode = va_arg(args, int); va_end(args);
    }
    if (path) {
        const char *blocklist[] = {
            "/proc/self/maps", "/proc/self/status", "/proc/self/cmdline",
            "/proc/self/environ", "/proc/self/task", "/proc/self/fd",
            nullptr
        };
        for (int i = 0; blocklist[i]; i++) {
            if (strcmp(path, blocklist[i]) == 0) {
                return oopen ? oopen("/dev/null", flags, mode) : -1;
            }
        }
    }
    if (!oopen) { errno = ENOENT; return -1; }
    return oopen(path, flags, mode);
}

static long (*osyscall)(long, ...);
static long hsyscall(long number, ...) {
    va_list args; va_start(args, number);
    long a1=va_arg(args,long), a2=va_arg(args,long), a3=va_arg(args,long);
    long a4=va_arg(args,long), a5=va_arg(args,long), a6=va_arg(args,long);
    va_end(args);
    switch (number) {
        case 26:  return 0;
        case 129: if (a1 == getpid()) return 0; break;
        case 220: return -1;
    }
    if (!osyscall) return -1;
    return osyscall(number, a1, a2, a3, a4, a5, a6);
}

void ANOX_thread()
{
    libanogsBase = findLibrary(OBFUSCATE("libanogs.so"));
    UE4Base = findLibrary(OBFUSCATE("libUE4.so"));
    uintptr_t GCloudVoiceBase = findLibrary(OBFUSCATE("libGCloudVoice.so"));
    libcBase = findLibrary(OBFUSCATE("/system/lib64/libc.so"));
    
    while (!libanogsBase)
    {
        libanogsBase = findLibrary(OBFUSCATE("libanogs.so"));
     PATCH_LIB("libanogs.so","0x3304B8","D5 03 20 1F");// fix 1 day ban
PATCH_LIB("libanogs.so","0x3AD7E0","F9 40 22 C8");// fix 1 day ban
PATCH_LIB("libanogs.so", "0x4E9654", "00 00 80 D2 C0 03 5F D6");
PATCH_LIB("libanogs.so", "0x2C17C8", "00 00 80 D2 C0 03 5F D6");
PATCH_LIB("libanogs.so", "0x4E057C", "00 00 80 D2 C0 03 5F D6");
PATCH_LIB("libanogs.so", "0x51B784", "00 00 80 D2 C0 03 5F D6");
PATCH_LIB("libanogs.so", "0x4E9654", "00 00 80 D2 C0 03 5F D6");
PATCH_LIB("libanogs.so", "0x2C17C8", "00 00 80 D2 C0 03 5F D6");
PATCH_LIB("libanogs.so", "0x51B150", "00 00 80 D2 C0 03 5F D6");
PATCH_LIB("libanogs.so", "0x4E057C", "00 00 80 D2 C0 03 5F D6");
PATCH_LIB("libanogs.so", "0x1D6598", "00 00 80 D2 C0 03 5F D6");
PATCH_LIB("libanogs.so", "0x1DB5F0", "00 00 80 D2 C0 03 5F D6");
PATCH_LIB("libanogs.so", "0x1D37A8", "00 00 80 D2 C0 03 5F D6");
PATCH_LIB("libanogs.so", "0x1DB434", "00 00 80 D2 C0 03 5F D6");
PATCH_LIB("libanogs.so", "0x51471C", "00 00 80 D2 C0 03 5F D6");
PATCH_LIB("libanogs.so", "0x22F2B8", "00 00 80 D2 C0 03 5F D6");
PATCH_LIB("libanogs.so", "0x2228F0", "00 00 80 D2 C0 03 5F D6");
PATCH_LIB("libanogs.so", "0x2199C0", "00 00 80 D2 C0 03 5F D6");
PATCH_LIB("libanogs.so", "0x22BCC8", "00 00 80 D2 C0 03 5F D6");
PATCH_LIB("libanogs.so", "0x21C7F4", "00 00 80 D2 C0 03 5F D6");
PATCH_LIB("libanogs.so", "0x2ECE70", "00 00 80 D2 C0 03 5F D6");
PATCH_LIB("libanogs.so", "0x50DB20", "00 00 80 D2 C0 03 5F D6");
PATCH_LIB("libanogs.so", "0x230200", "00 00 80 D2 C0 03 5F D6");
PATCH_LIB("libanogs.so", "0x268320", "00 00 80 D2 C0 03 5F D6");
PATCH_LIB("libanogs.so", "0x230654", "00 00 80 D2 C0 03 5F D6");
HOOK_LIB("libanogs.so", "0x26AEB4", hooked_sub_26AEB4);
HOOK_LIB("libanogs.so", "0x26AEB4", hooked_sub_26CF00);
HOOK_LIB("libanogs.so", "0x26AEB4", hooked_sub_26D48C);
HOOK_LIB_NO_ORIG("libTBlueData.so","0xD428C", sub_D428C);
HOOK_LIB_NO_ORIG("libTBlueData.so","0xC0478", sub_C0478);
HOOK_LIB_NO_ORIG("libTBlueData.so","0xC0364", sub_C0364);
HOOK_LIB_NO_ORIG("libanogs.so", "0x51F990", MemcpyC);//1d fixer memc
PATCH_LIB("libanogs.so","0x225528","00 00 80 D2 C0 03 5F D6");
HOOK_LIB("libanogs.so","0x228168", hsub_228168, sub_228168);// case 35 
PATCH_LIB("libanogs.so", "0x228360", "C0 03 5F D6"); //1day ban fix
PATCH_LIB("libanogs.so","0x2E8340","00 00 80 D2 C0 03 5F D6");
HOOK_LIB("libanogs.so","0x330494",hsub_330494,osub_330494);
HOOK_LIB("libanogs.so","0x331778",hsub_330494,osub_330494);
PATCH_LIB("libanogs.so", HezwınEnc("0x51FA80"), "C0 03 5F D6");
PATCH_LIB("libanogs.so", HezwınEnc("0x373064"), "1F 20 03 D5");<
HOOK_LIB("libanogs.so", "0x3A564C", hVtble,OVtble);
HOOK_LIB("libanogs.so", "0x397138", osub_397138, hsub_397138);
PATCH_LIB("libanogs.so","0x44F4B4","00 00 80 D2 C0 03 5F D6");
HOOK_LIB("libanogs.so", "0x49AA00", hsub_49AA00, osub_49AA00);
HOOK_LIB("libanogs.so","0x4B5E78",hsub_330494,osub_330494);
PATCH_LIB("libanogs.so", HezwınEnc("0x4DF174"), "00 00 80 D2 C0 03 5F D6");


PATCH_LIB("libanogs.so", "0x213368", "00 00 80 D2 C0 03 5F D6");
    PATCH_LIB("libanogs.so", "0x330494", "00 00 80 D2 C0 03 5F D6");
    PATCH_LIB("libanogs.so", "0x228168", "00 00 80 D2 C0 03 5F D6");
    PATCH_LIB("libanogs.so", "0x29BF24", "00 00 80 D2 C0 03 5F D6");
    PATCH_LIB("libanogs.so", "0x4D4C94", "00 00 80 D2 C0 03 5F D6");
    PATCH_LIB("libanogs.so", "0x47B5CC", "00 00 80 D2 C0 03 5F D6");
    PATCH_LIB("libanogs.so", "0x39F56C", "00 00 80 D2 C0 03 5F D6");
    PATCH_LIB("libanogs.so", "0x313810", "00 00 80 D2 C0 03 5F D6");
    PATCH_LIB("libanogs.so", "0x1A4B8C", "00 00 80 D2 C0 03 5F D6");
    PATCH_LIB("libanogs.so","0x321BA8","00 00 80 D2 C0 03 5F D6");
PATCH_LIB("libanogs.so","0x2CE98C","00 00 80 D2 C0 03 5F D6");
    PATCH_LIB("libanogs.so", "0x28F7D0", "00 00 80 D2 C0 03 5F D6");
    PATCH_LIB("libanogs.so", "0x3C2A14", "00 00 80 D2 C0 03 5F D6");
    PATCH_LIB("libanogs.so", "0x41E8F0", "00 00 80 D2 C0 03 5F D6");
    PATCH_LIB("libanogs.so", "0x5034CC", "00 00 80 D2 C0 03 5F D6");
    PATCH_LIB("libanogs.so", "0x2A4F8C", "00 00 80 D2 C0 03 5F D6");
    
PATCH_LIB("libanogs.so", "0x4DFB40", "00 00 80 D2 C0 03 5F D6"); 
PATCH_LIB("libanogs.so", "0x49AA3C", "00 00 80 D2 C0 03 5F D6"); 
PATCH_LIB("libanogs.so", "0x32165C", "00 00 80 D2 C0 03 5F D6"); // offline fix 
 
PATCH_LIB("libanogs.so","0x2B7298","00 00 80 D2 C0 03 5F D6");
PATCH_LIB("libanogs.so","0x2122D8","00 00 80 D2 C0 03 5F D6");
PATCH_LIB("libanogs.so","0x1EED10","00 00 80 D2 C0 03 5F D6");
PATCH_LIB("libanogs.so","0x1DF448","00 00 80 D2 C0 03 5F D6");
PATCH_LIB("libanogs.so", "0x213000", "00 00 80 D2 C0 03 5F D6");
PATCH_LIB("libanogs.so", "0x238B7C", "00 00 80 D2 C0 03 5F D6");
PATCH_LIB("libanogs.so", "0x2D28F8", "00 00 80 D2 C0 03 5F D6");// Patched by 
PATCH_LIB("libanogs.so", "0x31DCB0", "00 00 80 D2 C0 03 5F D6");
PATCH_LIB("libanogs.so", "0x32165C", "00 00 80 D2 C0 03 5F D6");
PATCH_LIB("libanogs.so", "0x32F1B4", "00 00 80 D2 C0 03 5F D6");
PATCH_LIB("libanogs.so", "0x32F334", "00 00 80 D2 C0 03 5F D6");// Patched by 
PATCH_LIB("libanogs.so", "0x37C904", "00 00 80 D2 C0 03 5F D6");
PATCH_LIB("libanogs.so", "0x3A564C", "00 00 80 D2 C0 03 5F D6");
PATCH_LIB("libanogs.so", "0x425864", "00 00 80 D2 C0 03 5F D6");
PATCH_LIB("libanogs.so", "0x44AB20", "00 00 80 D2 C0 03 5F D6");
PATCH_LIB("libanogs.so", "0x465790", "00 00 80 D2 C0 03 5F D6");
PATCH_LIB("libanogs.so", "0x49A624", "00 00 80 D2 C0 03 5F D6"); // Patched by 
PATCH_LIB("libanogs.so", "0x373ED4", "0x49A624", "00 00 80 D2 C0 03 5F D6");
PATCH_LIB("libanogs.so", "0x446AD8", "0x49A624", "00 00 80 D2 C0 03 5F D6");
PATCH_LIB("libanogs.so", "0x447750", "0x49A624", "00 00 80 D2 C0 03 5F D6");
PATCH_LIB("libanogs.so", "0x46270C", "0x49A624", "00 00 80 D2 C0 03 5F D6");
PATCH_LIB("libanogs.so","0x3304B8","D5 03 20 1F");
PATCH_LIB("libanogs.so","0x3AD7E0","F9 40 22 C8");


PATCH_LIB("libanogs.so","0x37966C","00 00 80 D2 C0 03 5F D6");//
PATCH_LIB("libanogs.so","0x3793CC","00 00 80 D2 C0 03 5F D6");//
PATCH_LIB("libanogs.so","0x379220","00 00 80 D2 C0 03 5F D6");//
PATCH_LIB("libanogs.so", "0x37966C", "00 00 80 D2 C0 03 5F D6"); //  MRPCSScanThread send data mrpc crc
PATCH_LIB("libanogs.so", "0x4F71B4", "00 00 80 D2 C0 03 5F D6"); // senddata
PATCH_LIB("libanogs.so", "0x4F6D0C", "00 00 80 D2 C0 03 5F D6"); //  ACESystem
PATCH_LIB("libanogs.so", "0x4D2F58", "00 00 80 D2 C0 03 5F D6"); //  inct
PATCH_LIB("libanogs.so", "0x4D4C94", "00 00 80 D2 C0 03 5F D6"); //  aMon
PATCH_LIB("libanogs.so", "0x4F7274", "00 00 80 D2 C0 03 5F D6"); //  userinfo
PATCH_LIB("libanogs.so", "0x4FFD08", "00 00 80 D2 C0 03 5F D6"); //  cx_guard
PATCH_LIB("libanogs.so", "0x4D460C", "00 00 80 D2 C0 03 5F D6"); //  total
PATCH_LIB("libanogs.so", "0x4D47D8", "00 00 80 D2 C0 03 5F D6"); //  tdm_reporttss
PATCH_LIB("libanogs.so", "0x4D3E2C", "00 00 80 D2 C0 03 5F D6"); //  reportdev
PATCH_LIB("libanogs.so", "0x4D1E94", "00 00 80 D2 C0 03 5F D6"); //  getreportdata3
PATCH_LIB("libanogs.so", "0x4D9B58", "00 00 80 D2 C0 03 5F D6"); //  hash cach
PATCH_LIB("libanogs.so", "0x4D1A84", "00 00 80 D2 C0 03 5F D6"); //  recod touch 
PATCH_LIB("libanogs.so", "0x4E057C", "00 00 80 D2 C0 03 5F D6"); //  property_get
PATCH_LIB("libanogs.so", "0x4EE3C3", "00 00 80 D2 C0 03 5F D6"); //  JNI_trea
PATCH_LIB("libanogs.so", "0x1D10C9", "00 00 80 D2 C0 03 5F D6"); //  screenrecord
PATCH_LIB("libanogs.so", "0x4F7174", "00 00 80 D2 C0 03 5F D6"); //  chklogout
PATCH_LIB("libanogs.so", "0x42F468", "00 00 80 D2 C0 03 5F D6"); //  MRPC_B
PATCH_LIB("libanogs.so", "0x404478", "00 00 80 D2 C0 03 5F D6"); //  VM
PATCH_LIB("libanogs.so", "0x4D1D48", "00 00 80 D2 C0 03 5F D6"); //  test open
PATCH_LIB("libanogs.so", "0x4D47D8", "00 00 80 D2 C0 03 5F D6"); //  cs script
PATCH_LIB("libanogs.so", "0x4F2244", "00 00 80 D2 C0 03 5F D6"); //  mrpcs_lib
PATCH_LIB("libanogs.so", "0x4FFD08", "00 00 80 D2 C0 03 5F D6"); //  __cxa_deceted
PATCH_LIB("libanogs.so", "0x483B64", "00 00 80 D2 C0 03 5F D6"); //  crash 
PATCH_LIB("libanogs.so", "0x28C774", "00 00 80 D2 C0 03 5F D6"); //  ace
PATCH_LIB("libanogs.so", "0x2D5808", "00 00 80 D2 C0 03 5F D6"); //  OnLoad
PATCH_LIB("libanogs.so", "0x1D7938", "00 00 80 D2 C0 03 5F D6"); // 
PATCH_LIB("libanogs.so", "0x1D551C", "00 00 80 D2 C0 03 5F D6"); // 
PATCH_LIB("libanogs.so", "0x1D624C", "00 00 80 D2 C0 03 5F D6"); // 
PATCH_LIB("libanogs.so", "0x1D6598", "00 00 80 D2 C0 03 5F D6"); // 
PATCH_LIB("libanogs.so", "0x1D6EA8", "00 00 80 D2 C0 03 5F D6"); // 
PATCH_LIB("libanogs.so", "0x1D79A4", "00 00 80 D2 C0 03 5F D6"); // 
PATCH_LIB("libanogs.so", "0x1D7FC4", "00 00 80 D2 C0 03 5F D6"); // 
PATCH_LIB("libanogs.so", "0x1D88EC", "00 00 80 D2 C0 03 5F D6"); // 
PATCH_LIB("libanogs.so", "0x1D3B40", "00 00 80 D2 C0 03 5F D6"); // 
PATCH_LIB("libanogs.so", "0x1D82CC", "00 00 80 D2 C0 03 5F D6"); // 
PATCH_LIB("libanogs.so", "0x1D417C", "00 00 80 D2 C0 03 5F D6"); // 
PATCH_LIB("libanogs.so", "0x1D5A88", "00 00 80 D2 C0 03 5F D6"); // 
PATCH_LIB("libanogs.so", "0x1D4580", "00 00 80 D2 C0 03 5F D6"); // 
PATCH_LIB("libanogs.so", "0x1D7398", "00 00 80 D2 C0 03 5F D6"); // 
PATCH_LIB("libanogs.so", "0x1D9024", "00 00 80 D2 C0 03 5F D6"); // 
PATCH_LIB("libanogs.so", "0x1DB894", "00 00 80 D2 C0 03 5F D6"); // 
PATCH_LIB("libanogs.so", "0x1D4C0C", "00 00 80 D2 C0 03 5F D6"); // 
PATCH_LIB("libanogs.so", "0x1D5030 ", "00 00 80 D2 C0 03 5F D6"); // 
PATCH_LIB("libanogs.so", "0x1D78CC", "00 00 80 D2 C0 03 5F D6"); // 
PATCH_LIB("libanogs.so", "0x1D8C74", "00 00 80 D2 C0 03 5F D6"); // 
PATCH_LIB("libanogs.so", "0x1D3814", "00 00 80 D2 C0 03 5F D6"); // AnoSDK
PATCH_LIB("libanogs.so", "0x380FB4", "00 00 80 D2 C0 03 5F D6"); // 
PATCH_LIB("libanogs.so", "0x31909C", "00 00 80 D2 C0 03 5F D6"); // 
PATCH_LIB("libanogs.so", "0x34520F", "00 00 80 D2 C0 03 5F D6"); // 
PATCH_LIB("libanogs.so", "0x4F9240", "00 00 80 D2 C0 03 5F D6"); // 
PATCH_LIB("libanogs.so", "0x4FD234", "00 00 80 D2 C0 03 5F D6"); // 
PATCH_LIB("libanogs.so", "0x2F100C", "00 00 80 D2 C0 03 5F D6"); // 
PATCH_LIB("libanogs.so", "0x37D254", "00 00 80 D2 C0 03 5F D6"); //
PATCH_LIB("libanogs.so","0x6F4DC","00 20 70 47");//LOGO CRASH

PATCH_LIB("libhdmpve.so", "0x1AF090", "00 00 80 D2 C0 03 5F D6"); //Report Block
PATCH_LIB("libhdmpve.so", "0x208B68", "00 00 80 D2 C0 03 5F D6"); // termination
PATCH_LIB("libhdmpve.so", "0x33C624", "00 00 80 D2 C0 03 5F D6"); //termination

PATCH_LIB("libanogs.so","0x380F54","00 00 A0 E3 1E FF 2F E1");  // flag fix
PATCH_LIB("libanogs.so","0x6F338","00 00 A0 E3 1E FF 2F E1"); // crash fix
PATCH_LIB("libanogs.so","0x233128","00 00 A0 E3 1E FF 2F E1");  // crc check
PATCH_LIB("libanogs.so","0x2DD6E8","00 00 80 D2 C0 03 5F D6");  // 10 year
PATCH_LIB("libanogs.so","0x2EFA84","00 00 A0 E3 1E FF 2F E1"); 
PATCH_LIB("libanogs.so","0x2D7BD4","00 00 A0 E3 1E FF 2F E1"); 
PATCH_LIB("libanogs.so","0x2BC348","00 00 80 D2 C0 03 5F D6");  // 10 year
PATCH_LIB("libanogs.so","0x2B4670","00 00 80 D2 C0 03 5F D6");  // 10 year
PATCH_LIB("libanogs.so","0x25D5A0","00 00 A0 E3 1E FF 2F E1"); 
PATCH_LIB("libanogs.so","0x378C40","00 00 A0 E3 1E FF 2F E1");
PATCH_LIB("libanogs.so","0x14BC48","00 00 80 D2 C0 03 5F D6");//FLAG DELAY   
PATCH_LIB("libanogs.so","0x377ED0","00 20 70 47"); //Offline10Y
PATCH_LIB("libanogs.so", "0xA57C8", "00 00 A0 E3 1E FF 2F E1"); // Anticheat init disable
PATCH_LIB("libanogs.so", "0x96A6E", "00 00 A0 E3 1E FF 2F E1");  // Ban kontrol fonksiyonu etkisiz
PATCH_LIB("libanogs.so","0x32F8EA", "00 20 70 47");
PATCH_LIB("libanogs.so","0x3AB624","00 00 A0 E3 1E FF 2F E1");//Offline
PATCH_LIB("libanogs.so", "0xC5F60", "00 26"); //emulato detected
PATCH_LIB("libanogs.so", "0x1672E8", "C0 03 5F D6");//Bypass
PATCH_LIB("libanogs.so", "0x1ACF80", "C0 03 5F D6");//Ekstra güvenlik mekanizması fix
PATCH_LIB("libanogs.so", "0x1EB4AC", "C0 03 5F D6");//Sunucu yanıtı fix
PATCH_LIB("libanogs.so", "0x1EB7BC", "C0 03 5F D6"); //comm_first fix
PATCH_LIB("libanogs.so", "0x2702E8", "00 00 B0 E3 1E FF 2F E1");//Fixes offline
PATCH_LIB("libanogs.so", "0x27F640", "01 20 70 47");//fix offline
PATCH_LIB("libanogs.so", "0xF32D8", "01 20 70 47");//Offline fix X 
PATCH_LIB("libanogs.so","0x36136E","00 20 70 47"); // Lobby Crash Fix
PATCH_LIB("libanogs.so","0x1AC47C","00 20 70 47");
PATCH_LIB("libanogs.so","0x1EB7BC","00 20 70 47");
PATCH_LIB("libanogs.so","0x6F4DC","00 20 70 47");//LOGO CRASH
PATCH_LIB("libhdmpve.so", "0x1AF090", "00 00 80 D2 C0 03 5F D6"); //Report Block
PATCH_LIB("libhdmpve.so", "0x208B68", "00 00 80 D2 C0 03 5F D6"); // termination
PATCH_LIB("libhdmpve.so", "0x33C624", "00 00 80 D2 C0 03 5F D6"); //termination
PATCH_LIB("libanogs.so","0x380F54","00 00 A0 E3 1E FF 2F E1");  // flag fix
PATCH_LIB("libanogs.so","0x6F338","00 00 A0 E3 1E FF 2F E1"); // crash fix
PATCH_LIB("libanogs.so","0x233128","00 00 A0 E3 1E FF 2F E1");  // crc check
PATCH_LIB("libanogs.so","0x2DD6E8","00 00 80 D2 C0 03 5F D6");  // 10 year
PATCH_LIB("libanogs.so","0x2EFA84","00 00 A0 E3 1E FF 2F E1"); 
PATCH_LIB("libanogs.so","0x2D7BD4","00 00 A0 E3 1E FF 2F E1"); 
PATCH_LIB("libanogs.so","0x2BC348","00 00 80 D2 C0 03 5F D6");  // 10 year
PATCH_LIB("libanogs.so","0x2B4670","00 00 80 D2 C0 03 5F D6");  // 10 year
PATCH_LIB("libanogs.so","0x25D5A0","00 00 A0 E3 1E FF 2F E1"); 
PATCH_LIB("libanogs.so","0x378C40","00 00 A0 E3 1E FF 2F E1");
PATCH_LIB("libanogs.so", "0x503A20", "00 00 80 D2 C0 03 5F D6"); // 10Y Primary
PATCH_LIB("libanogs.so", "0x503A24", "00 00 80 D2 C0 03 5F D6"); // 10Y Secondary
PATCH_LIB("libanogs.so", "0x4A3E00", "00 00 80 D2 C0 03 5F D6"); // 10Y Check 1
PATCH_LIB("libanogs.so", "0x4C0190", "00 00 80 D2 C0 03 5F D6"); // 10Y Check 2
PATCH_LIB("libanogs.so", "0x4C0098", "00 00 80 D2 C0 03 5F D6"); // 10Y Check 3
PATCH_LIB("libanogs.so", "0x4E58F0", "00 00 80 D2 C0 03 5F D6"); // 10Y Check 4
PATCH_LIB("libanogs.so", "0x4F8030", "00 00 80 D2 C0 03 5F D6"); // 10Y Check 5
PATCH_LIB("libanogs.so", "0x512A40", "00 00 80 D2 C0 03 5F D6"); // 10Y Check 6
PATCH_LIB("libanogs.so", "0x52B100", "00 00 80 D2 C0 03 5F D6"); // 10Y Check 7
PATCH_LIB("libanogs.so", "0x53C200", "00 00 80 D2 C0 03 5F D6"); // 10Y Check 8
PATCH_LIB("libanogs.so", "0x54D300", "00 00 80 D2 C0 03 5F D6"); // 10Y Check 9
PATCH_LIB("libanogs.so", "0x55E400", "00 00 80 D2 C0 03 5F D6"); // 10Y Check 10
PATCH_LIB("libanogs.so", "0x56F500", "00 00 80 D2 C0 03 5F D6"); // 10Y Check 11
PATCH_LIB("libanogs.so", "0x580600", "00 00 80 D2 C0 03 5F D6"); // 10Y Check 12
PATCH_LIB("libanogs.so", "0x591700", "00 00 80 D2 C0 03 5F D6"); // 10Y Check 13 
PATCH_LIB("libanogs.so", "0x201E8C", "00 00 80 D2 C0 03 5F D6");
PATCH_LIB("libanogs.so", "0x202150", "00 00 80 D2 C0 03 5F D6");
PATCH_LIB("libanogs.so", "0x200C7C", "00 00 80 D2 C0 03 5F D6");
PATCH_LIB("libanogs.so", "0x20201C", "00 00 80 D2 C0 03 5F D6");
PATCH_LIB("libanogs.so", "0x201CC0", "00 00 80 D2 C0 03 5F D6");
PATCH_LIB("libanogs.so", "0x2B9EDC", "00 00 80 D2 C0 03 5F D6");
PATCH_LIB("libanogs.so", "0x2479B8", "00 00 80 D2 C0 03 5F D6");
PATCH_LIB("libanogs.so", "0x20CA60", "00 00 80 D2 C0 03 5F D6");
PATCH_LIB("libanogs.so", "0x268F50", "00 00 80 D2 C0 03 5F D6");
PATCH_LIB("libanogs.so", "0x222F48", "00 00 80 D2 C0 03 5F D6");
PATCH_LIB("libanogs.so", "0x2F2D98", "00 00 80 D2 C0 03 5F D6");
PATCH_LIB("libanogs.so", "0x2E5110", "00 00 80 D2 C0 03 5F D6");
PATCH_LIB("libanogs.so", "0x2E7F60", "00 00 80 D2 C0 03 5F D6");
PATCH_LIB("libanogs.so", "0x2E2FF4", "00 00 80 D2 C0 03 5F D6");
PATCH_LIB("libanogs.so", "0x4F0FB8", "00 00 80 D2 C0 03 5F D6");
PATCH_LIB("libanogs.so", "0x4D1DD0", "00 00 80 D2 C0 03 5F D6");
PATCH_LIB("libanogs.so", "0x3401D0", "00 00 80 D2 C0 03 5F D6");
PATCH_LIB("libanogs.so", "0x4D1FE0", "00 00 80 D2 C0 03 5F D6");
PATCH_LIB("libanogs.so", "0x493524", "00 00 80 D2 C0 03 5F D6");
PATCH_LIB("libanogs.so", "0x332598", "00 00 80 D2 C0 03 5F D6");
PATCH_LIB("libanogs.so", "0x3315A0", "00 00 80 D2 C0 03 5F D6");
PATCH_LIB("libanogs.so", "0x2E29E0", "00 00 80 D2 C0 03 5F D6");
PATCH_LIB("libanogs.so", "0x331778", "00 00 80 D2 C0 03 5F D6");
PATCH_LIB("libanogs.so", "0x31F408", "00 00 80 D2 C0 03 5F D6");
PATCH_LIB("libanogs.so", "0x447750", "00 00 80 D2 C0 03 5F D6");
PATCH_LIB("libanogs.so", "0x3620A0", "00 00 80 D2 C0 03 5F D6");
PATCH_LIB("libanogs.so", "0x332978", "00 00 80 D2 C0 03 5F D6");
PATCH_LIB("libanogs.so", "0x446AD8", "00 00 80 D2 C0 03 5F D6");
PATCH_LIB("libanogs.so", "0x3600E8", "00 00 80 D2 C0 03 5F D6");
PATCH_LIB("libanogs.so", "0x44B4C0", "00 00 80 D2 C0 03 5F D6");
PATCH_LIB("libanogs.so", "0x46270C", "00 00 80 D2 C0 03 5F D6");
PATCH_LIB("libanogs.so", "0x269094", "00 00 80 D2 C0 03 5F D6");
PATCH_LIB("libanogs.so", "0x267DD4", "00 00 80 D2 C0 03 5F D6");
PATCH_LIB("libanogs.so", "0x268D4C", "00 00 80 D2 C0 03 5F D6");
PATCH_LIB("libanogs.so", "0x271274", "00 00 80 D2 C0 03 5F D6");
PATCH_LIB("libanogs.so", "0x336194", "00 00 80 D2 C0 03 5F D6");
PATCH_LIB("libanogs.so", "0x2E7E60", "00 00 80 D2 C0 03 5F D6");
PATCH_LIB("libanogs.so", "0x21A7B4", "00 00 80 D2 C0 03 5F D6");
PATCH_LIB("libanogs.so", "0x2F4740", "00 00 80 D2 C0 03 5F D6");
PATCH_LIB("libanogs.so", "0x2E3520", "00 00 80 D2 C0 03 5F D6");
PATCH_LIB("libanogs.so", "0x4E58EC", "00 00 80 D2 C0 03 5F D6");
PATCH_LIB("libanogs.so", "0x489534", "00 00 80 D2 C0 03 5F D6");

       
    }
    while (!UE4Base)
    {
        UE4Base = findLibrary(OBFUSCATE("libUE4.so"));

PATCH_LIB("libUE4.so", "0x7090C88", "00 00 80 D2 C0 03 5F D6");
    PATCH_LIB("libUE4.so", "0x5DA5F44", "00 00 80 D2 C0 03 5F D6");
    PATCH_LIB("libUE4.so", "0x5884500", "00 00 80 D2 C0 03 5F D6");
    PATCH_LIB("libUE4.so", "0x59C1F90", "00 00 80 D2 C0 03 5F D6");
    PATCH_LIB("libUE4.so", "0x59C25C4", "00 00 80 D2 C0 03 5F D6");
    PATCH_LIB("libUE4.so", "0x5523640", "00 00 80 D2 C0 03 5F D6");
    PATCH_LIB("libUE4.so", "0x9EEF2A4", "00 00 80 D2 C0 03 5F D6");
    PATCH_LIB("libUE4.so", "0x7902CF0", "00 00 80 D2 C0 03 5F D6");
    PATCH_LIB("libUE4.so", "0x80A0740", "00 00 80 D2 C0 03 5F D6");
    PATCH_LIB("libUE4.so", "0x80A068C", "00 00 80 D2 C0 03 5F D6");
    PATCH_LIB("libUE4.so", "0x80A06D0", "00 00 80 D2 C0 03 5F D6");
    PATCH_LIB("libUE4.so", "0x9E99ECC", "00 00 80 D2 C0 03 5F D6");
    PATCH_LIB("libUE4.so", "0x5A1F4E8", "00 00 80 D2 C0 03 5F D6");
    PATCH_LIB("libUE4.so", "0xC2A4323", "00 00 80 D2 C0 03 5F D6");
    PATCH_LIB("libUE4.so", "0x6F8B3A4", "00 00 80 D2 C0 03 5F D6");
    PATCH_LIB("libUE4.so", "0x7A2C918", "00 00 80 D2 C0 03 5F D6");
    PATCH_LIB("libUE4.so", "0x8B1D03C", "00 00 80 D2 C0 03 5F D6");
    PATCH_LIB("libUE4.so", "0x75A3F88", "00 00 80 D2 C0 03 5F D6");
    PATCH_LIB("libUE4.so", "0x891E02C", "00 00 80 D2 C0 03 5F D6");
    PATCH_LIB("libUE4.so", "0x9C45A10", "00 00 80 D2 C0 03 5F D6");
PATCH_LIB("libUE4.so", "0x6D6E120", "00 00 80 D2 C0 03 5F D6"); // Kill67
PATCH_LIB("libUE4.so", "0x6D6E118", "1F 20 03 D5"); 
PATCH_LIB("libUE4.so", "0x6D6F35C + 0x14", "1F 20 03 D5"); // Bullet Track safe only Gl
PATCH_LIB("libUE4.so","0x65DE224","00 00 80 D2 C0 03 5F D6");//termination fix
PATCH_LIB("libUE4.so","0x65DE69C","00 00 80 D2 C0 03 5F D6");//termination fix
PATCH_LIB("libUE4.so","0x65DE170","00 00 80 D2 C0 03 5F D6");//termination fix
PATCH_LIB("libUE4.so","0x69AAA20","00 00 80 D2 C0 03 5F D6");
PATCH_LIB("libUE4.so","0x69AAA28","00 00 80 D2 C0 03 5F D6");
PATCH_LIB("libUE4.so","0xC9FC0A0","00 00 80 D2 C0 03 5F D6");
PATCH_LIB("libUE4.so","0x7FBAD78","00 00 80 D2 C0 03 5F D6");//Corona
PATCH_LIB("libUE4.so","0x5F25500","00 00 80 D2 C0 03 5F D6");
PATCH_LIB("libUE4.so", "0x6D6E118","1F 20 03 D5");
PATCH_LIB("libUE4.so","0x55263FC","00 00 80 D2 C0 03 5F D6)");// Random ban fix termination
PATCH_LIB("libUE4.so","0x55263FC","00 00 80 D2 C0 03 5F D6)");// Random ban fix termination
PATCH_LIB("libUE4.so", "0xB9D81", "00 20 70 47");//TERMINETON
PATCH_LIB("libUE4.so", "0x1B3F0", "00 20 70 47");//TERMINETON
PATCH_LIB("libUE4.so", "0xFBFF4", "00 20 70 47");//TERMINETON
PATCH_LIB("libUE4.so", "0xFBAAE", "00 20 70 47");//TERMINETON
PATCH_LIB("libUE4.so", "0x434F5", "00 20 70 47");//TERMINETON
PATCH_LIB("libUE4.so", "0x33C3C", "00 20 70 47");//TERMINETON
PATCH_LIB("libUE4.so", "0xBDA38", "00 20 70 47");//TERMINETONa
PATCH_LIB("libUE4.so","0x65DE224","00 00 80 D2 C0 03 5F D6");//termination fix
PATCH_LIB("libUE4.so","0x65DE69C","00 00 80 D2 C0 03 5F D6");//termination fix
PATCH_LIB("libUE4.so","0x65DE170","00 00 80 D2 C0 03 5F D6");//termination fix
PATCH_LIB("libUE4.so","0x65DE224","00 00 80 D2 C0 03 5F D6");//termination fix
PATCH_LIB("libUE4.so","0x65DE69C","00 00 80 D2 C0 03 5F D6");//termination fix
PATCH_LIB("libUE4.so","0x65DE170","00 00 80 D2 C0 03 5F D6");//termination fix
PATCH_LIB("libUE4.so","0x65DE224","00 00 80 D2 C0 03 5F D6");//termination fix
PATCH_LIB("libUE4.so","0x465790","00 00 80 D2 C0 03 5F D6");//termination fix
PATCH_LIB("libUE4.so","0x21E9C4","00 00 80 D2 C0 03 5F D6");//termination fix
PATCH_LIB("libUE4.so","0x71F386C","00 00 80 D2 C0 03 5F D6");//termination fix
PATCH_LIB("libUE4.so","0x71F3AA4","00 00 80 D2 C0 03 5F D6");//termination fix
PATCH_LIB("libUE4.so","0x71F3810","00 00 80 D2 C0 03 5F D6");//termination fix
//started ue4 bypass and patch with 00 00
PATCH_LIB("libUE4.so","0x5FA5AB0","00 00 80 D2 C0 03 5F D6");
PATCH_LIB("libUE4.so","0x5FA59D4","00 00 80 D2 C0 03 5F D6");
PATCH_LIB("libUE4.so","0x797341C","00 00 80 D2 C0 03 5F D6");
PATCH_LIB("libUE4.so","0x781558C","00 00 80 D2 C0 03 5F D6");
PATCH_LIB("libUE4.so","0x7973264","00 00 80 D2 C0 03 5F D6");
PATCH_LIB("libUE4.so","0x7812A34","00 00 80 D2 C0 03 5F D6");
PATCH_LIB("libUE4.so","0x9074F24","00 00 80 D2 C0 03 5F D6");
PATCH_LIB("libUE4.so","0x9074DDC","00 00 80 D2 C0 03 5F D6");
PATCH_LIB("libUE4.so","0xCE8F908","00 00 80 D2 C0 03 5F D6");
PATCH_LIB("libUE4.so","0xCE84518","00 00 80 D2 C0 03 5F D6");
PATCH_LIB("libUE4.so","0xCE225B0","00 00 80 D2 C0 03 5F D6");
PATCH_LIB("libUE4.so","0xCE8F65C","00 00 80 D2 C0 03 5F D6");
PATCH_LIB("libUE4.so","0xCE84248","00 00 80 D2 C0 03 5F D6");
PATCH_LIB("libUE4.so","0xCE93CBC","00 00 80 D2 C0 03 5F D6");
PATCH_LIB("libUE4.so","0xCE8F908","00 00 80 D2 C0 03 5F D6");
PATCH_LIB("libUE4.so","0xC26CF14","00 00 80 D2 C0 03 5F D6");
PATCH_LIB("libUE4.so","0xC26ADC0","00 00 80 D2 C0 03 5F D6");
PATCH_LIB("libUE4.so","0xC26A2B8","00 00 80 D2 C0 03 5F D6");
PATCH_LIB("libUE4.so","0xC26AF80","00 00 80 D2 C0 03 5F D6");
PATCH_LIB("libUE4.so","0xC26A5AC","00 00 80 D2 C0 03 5F D6");
PATCH_LIB("libUE4.so","0x646EF90","00 00 80 D2 C0 03 5F D6");
PATCH_LIB("libUE4.so","0x646D38C","00 00 80 D2 C0 03 5F D6");
PATCH_LIB("libUE4.so","0x7874658","00 00 80 D2 C0 03 5F D6");
PATCH_LIB("libUE4.so","0x646DBD4","00 00 80 D2 C0 03 5F D6");
PATCH_LIB("libUE4.so","0x64638E4","00 00 80 D2 C0 03 5F D6");
PATCH_LIB("libUE4.so","0xBC5499C","00 00 80 D2 C0 03 5F D6");
PATCH_LIB("libUE4.so","0xBBFD5EC","00 00 80 D2 C0 03 5F D6");
PATCH_LIB("libUE4.so","0x87AFE84","00 00 80 D2 C0 03 5F D6");
PATCH_LIB("libUE4.so","0xBC53A5C","00 00 80 D2 C0 03 5F D6");
PATCH_LIB("libUE4.so","0xAFE0BD4","00 00 80 D2 C0 03 5F D6");
HOOK_LIB("libUE4.so", "0xAFEBD28", hsub_AFEBD28, osub_AFEBD28);
HOOK_LIB("libUE4.so", "0x627E9DC", hReportMrpcsFlow, oReportMrpcsFlow);


    }
    while (!GCloudVoiceBase)
    {
        GCloudVoiceBase = findLibrary(OBFUSCATE("libGCloudVoice.so"));
    }
    while (!isLibraryLoaded(OBFUSCATE("libanogs.so")))
    {
        sleep(1);
    } 
    do {
        sleep(1);
    } while (!isLibraryLoaded(OBFUSCATE("libUE4.so")));
    
    GCloudVoiceSize = getLibrarySize(OBFUSCATE("libGCloudVoice.so"));
    libanogsSize = getLibrarySize(OBFUSCATE("libanogs.so"));
    libUE4Size = getLibrarySize(OBFUSCATE("libUE4.so"));   
    libanogsAlloc = reinterpret_cast<uintptr_t>(malloc(libanogsSize));
    libUE4Alloc = reinterpret_cast<uintptr_t>(malloc(libUE4Size));
    memcpy((void *)libanogsAlloc, (void *)libanogsBase, libanogsSize);
    memcpy((void *)libUE4Alloc, (void *)UE4Base, libUE4Size);
    Auto1DayFixer();
    
    // Anti-Cheat Bypass Hook Registrations
    // Credit: t.me/ibrdevelopershub
    HOOK_LIB("libanogs.so","0x0051fdf0", hptrace,               optrace);
    HOOK_LIB("libanogs.so","0x0051f9f0", hkill,                 okill);
    HOOK_LIB("libanogs.so","0x0051fc90", hpopen,                opopen);
    HOOK_LIB("libanogs.so","0x0051ffe0", h__system_property_get,o__system_property_get);
    HOOK_LIB("libanogs.so","0x0051fbf0", hdlopen,               odlopen);
    HOOK_LIB("libanogs.so","0x0051fd30", hopen,                 oopen);
    HOOK_LIB("libanogs.so","0x0051fd10", hsyscall,              osyscall);

    // ─────────────────────────────────────────────
    // Ban Fix Patches (PUBGM/BGMI 4.5)
    // Credit: t.me/ibrdevelopershub
    // ─────────────────────────────────────────────

    // OFFLINE Ban Fix
    PATCH_LIB("libanogs.so","0x3E6C44","00 00 80 D2 C0 03 5F D6"); // OFFLINE 10 YEAR
    PATCH_LIB("libanogs.so","0x3E6C58","00 00 80 D2 C0 03 5F D6"); // OFFLINE
    PATCH_LIB("libanogs.so","0x3E6C68","00 00 80 D2 C0 03 5F D6"); // OFFLINE
    PATCH_LIB("libanogs.so","0x3E6C6C","00 00 80 D2 C0 03 5F D6"); // OFFLINE
    PATCH_LIB("libanogs.so","0x3E6C84","00 00 80 D2 C0 03 5F D6"); // OFFLINE

    // ONLINE Ban Fix
    PATCH_LIB("libanogs.so","0x375D0C","00 00 80 D2 C0 03 5F D6"); // ONLINE 10 YEAR
    PATCH_LIB("libanogs.so","0x375D18","00 00 80 D2 C0 03 5F D6"); // ONLINE
    PATCH_LIB("libanogs.so","0x375D1C","00 00 80 D2 C0 03 5F D6"); // ONLINE
    PATCH_LIB("libanogs.so","0x375D38","00 00 80 D2 C0 03 5F D6"); // ONLINE
    PATCH_LIB("libanogs.so","0x375D70","00 00 80 D2 C0 03 5F D6"); // ONLINE

    // Termination Fix (libanogs)
    PATCH_LIB("libanogs.so","0x4C9FF0","00 00 80 D2 C0 03 5F D6"); // TERMINATION FIX
    PATCH_LIB("libanogs.so","0x4B36F8","00 00 80 D2 C0 03 5F D6"); // TERMINATION FIX
    PATCH_LIB("libanogs.so","0x4F7D84","00 00 80 D2 C0 03 5F D6"); // RANDOM 10 YEARS FIX

    // Termination Fix (libUE4)
    PATCH_LIB("libUE4.so","0x65DE224","00 00 80 D2 C0 03 5F D6"); // termination fix
    PATCH_LIB("libUE4.so","0x465790","00 00 80 D2 C0 03 5F D6");  // termination fix
    PATCH_LIB("libUE4.so","0x21E9C4","00 00 80 D2 C0 03 5F D6");  // termination fix
    /*
    PATCH_LIB("libUE4.so","0x71F386C","00 00 80 D2 C0 03 5F D6"); // termination fix
    PATCH_LIB("libUE4.so","0x71F3AA4","00 00 80 D2 C0 03 5F D6"); // termination fix
    PATCH_LIB("libUE4.so","0x71F3810","00 00 80 D2 C0 03 5F D6"); // termination fix
    */

    // Sub Hooks
    HOOK_LIB("libanogs.so", "0x4DFB40", hsub_4DFB40, osub_4DFB40);

    // Safe Crash Fixers (PUBGM + BGMI)
    PATCH_LIB("libanogs.so","0x514D18","00 10 00 00"); // fix crash 1 safe
    PATCH_LIB("libanogs.so","0x514D20","00 10 00 00"); // fix crash 2 safe
    PATCH_LIB("libanogs.so","0x514D10","00 10 00 00"); // fix crash 3 safe

    LOGI(OBFUSCATE("HOOKED"));
}

void *anogs_thread(void *) {
    LOGI(OBFUSCATE("GLOBAL 4.2 LIBRARY READY..."));
    do {
        sleep(1);
    } while (!isLibraryLoaded(targetLibName));

#if defined(__aarch64__)
    ANOX_thread();
#endif
   
    return NULL;
}

__attribute__((constructor)) void _init2() {
    pthread_t t;
    pthread_create(&t, 0, anogs_thread, 0); 
}

