

#include <string>
#include <vector>
#include <unistd.h>
#include <android/log.h>
#include <sys/system_properties.h>
#include <dirent.h>


int (*MessageBoxExt)(unsigned int, const char16_t *, const char16_t *);
 
std::u16string convertToUtf16(const std::string &utf8str)
{
    std::wstring_convert<std::codecvt_utf8_utf16<char16_t>, char16_t> convert;
    return convert.from_bytes(utf8str);
}


bool IsPackageInstalled(const char* packageName) {
    std::string cmd = "pm list packages | grep ";
    cmd += packageName;
    FILE* pipe = popen(cmd.c_str(), "r");
    if (!pipe) return false;

    char buffer[128];
    std::string result = "";
    while (fgets(buffer, sizeof buffer, pipe) != NULL) {
        result += buffer;
    }
    pclose(pipe);
    return !result.empty();
}

bool IsRooted() {
    const char* paths[] = {
        "/system/app/Superuser.apk",
        "/sbin/su",
        "/system/bin/su",
        "/system/xbin/su",
        "/data/local/xbin/su",
        "/data/local/bin/su",
        "/system/sd/xbin/su",
        "/system/bin/failsafe/su",
        "/data/local/su",
        "/su/bin/su"
    };
    for (const auto& path : paths) {
        if (access(path, F_OK) == 0)
            return true;
    }
    return false;
}

void RootAndToolCheck() {
   uintptr_t CMessageBoxExt_address = Data::Cheat::UE4;
  auto CMessageBoxExt = reinterpret_cast<int(*)(int, const char16_t*, const char16_t*)>(CMessageBoxExt_address);

    std::vector<std::string> dangerousTools = {
        "com.topjohnwu.magisk",
        "com.noshufou.android.su",
        "eu.chainfire.supersu",
        "com.koushikdutta.rommanager",
        "com.dimonvideo.luckypatcher",
        "com.chelpus.lackypatch",
        "com.termux",
        "org.kali.nethunter",
        "com.guoshi.httpcanary",
        "catch_.me_.if_.you_.can_",  // GG
        "com.frida.server",
        "re.frida.server",
        "org.mozilla.fenix", // canary firefox
        "com.jakting.rns",  // Root Navigation
        "com.ghidra", "com.jadx", "com.bin.mt", "com.mt.helper"
    };

    std::string detectedTool = "";

    for (const auto& pkg : dangerousTools) {
        if (IsPackageInstalled(pkg.c_str())) {
            detectedTool = pkg;
            break;
        }
    }

    if (IsRooted()) {
        detectedTool = "ROOT ACCESS";
    }

    if (!detectedTool.empty()) {
        std::u16string msg = u"RAT INJECTING BECAUSE YOU TRYING TO CRACK OR DUMP\nTool: ";
        msg += std::u16string(detectedTool.begin(), detectedTool.end());
        msg += u"\nPehle delete kar warna teri details leak";

        CMessageBoxExt(0, msg.c_str(), u"warning !! mat panga le");
        *(int*)0 = 0;
    }
}

#include <dirent.h>
#include <unistd.h>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>

std::vector<std::string> SuspiciousProcessNames = {
    "frida-server", "frida", "gg", "gameguardian",
    "termux", "canary", "httpcanary", "su", "magisk", "sqlite", "tcpdump"
};

bool IsProcessSuspicious() {
    DIR* proc = opendir("/proc");
    if (!proc) return false;

    struct dirent* ent;
    while ((ent = readdir(proc)) != NULL) {
        if (ent->d_type == DT_DIR) {
            std::string pid = ent->d_name;
            if (!std::all_of(pid.begin(), pid.end(), ::isdigit))
                continue;

            std::string cmdlinePath = "/proc/" + pid + "/cmdline";
            std::ifstream cmdFile(cmdlinePath);
            std::string line;
            if (std::getline(cmdFile, line)) {
                for (const auto& name : SuspiciousProcessNames) {
                    if (line.find(name) != std::string::npos) {
                        closedir(proc);
                        return true;
                    }
                }
            }
        }
    }
    closedir(proc);
    return false;
}
bool HasToolBinary() {
    std::vector<std::string> toolPaths = {
        "/data/local/tmp/frida-server",
        "/data/data/com.termux/",
        "/storage/emulated/0/Download/gg", 
        "/data/local/tmp/gg", 
        "/data/local/tmp/magisk", 
        "/system/bin/frida-server",
        "/system/xbin/su", 
        "/data/local/tmp/su",
    };

for (const auto& path : toolPaths) {
        if (access(path.c_str(), F_OK) == 0)
            return true;
    }
    return false;
}


void ToolScanAndCrash() {
   uintptr_t CMessageBoxExt_address = Data::Cheat::UE4;
   auto CMessageBoxExt = reinterpret_cast<int(*)(int, const char16_t*, const char16_t*)>(CMessageBoxExt_address);

    if (IsProcessSuspicious() || HasToolBinary()) {
        CMessageBoxExt(0, u" RAT INJECTING IN YOUR DEVICE BECAUSE TRY TO CRACK OR DUMP!", u"RAT INJECTING IN YOUR DEVICE BECAUSE TRY TO CRACK OR DUMP");

        *(int*)0 = 0;
    }
}


