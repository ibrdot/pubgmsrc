#include <jni.h>
#include <errno.h>

#include <string.h>
#include <unistd.h>
#include <stdint.h>
#include <inttypes.h>
#include <iostream>
#include <fstream>
#include <stdio.h>
#include <sstream>
#include <vector>
#include <map>
#include <iomanip>
#include <thread>

#include <sys/types.h>
#include <sys/stat.h>
#include <sys/resource.h>
#include <sys/uio.h>
#include <vector>
#include <string>
#include <chrono>
#include <algorithm>

#include <fcntl.h>
#include <android/log.h>
#include <pthread.h>
#include <dirent.h>
#include <list>
#include <libgen.h>

#include <sys/mman.h>
#include <sys/wait.h>

#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/un.h>

#include <codecvt>
#include <chrono>
#include <queue>

using namespace std::chrono_literals;

#include <EGL/egl.h>
#include <GLES3/gl3.h>

#include <sys/system_properties.h>
#include <WOLTAJ/Helper/android_native_app_glue.h>

#define LOG_TAG "Log Test dbrr"
#define LOGI(...) __android_log_print(ANDROID_LOG_INFO,LOG_TAG,__VA_ARGS__)
#define LOGD(...) __android_log_print(ANDROID_LOG_DEBUG,LOG_TAG,__VA_ARGS__)
#define LOGW(...) __android_log_print(ANDROID_LOG_WARN,LOG_TAG,__VA_ARGS__)
#define LOGE(...) __android_log_print(ANDROID_LOG_ERROR,LOG_TAG,__VA_ARGS__)

#define HOOK(target, hook, original) Tools::Hook((void *)(target), (void *)(hook), (void **)(original))
// Hook / Imgui
#include "imgui/imgui.h"
#include "imgui/backends/imgui_impl_android.h"
#include "imgui/backends/imgui_impl_opengl3.h"
//--------------------------- WOLTAJ/Helper
#include "XorStr.h"
#include "obfuscate.h"
#include "json.hpp"
#include "StrEnc.h"
#include "Mau.h"
#include "Vector3.hpp"
#include "Vector2.hpp"
#include "Tools.h"
#include "Log.h"
#include "../FTools/ImguiPP.h"
#include "font_awesome_6.h"
#include "../FTools/Font.h"
#include "../FTools/Icon.h"
#include "../FTools/FontPC.h"
#include "../imgui/imgui_internal.h"
#include "imgui_notify.h"
#include "fake_dlfcn.h"
#include <math.h>
// Other Nigga
#include "WOLTAJ/Main/ESP/virtual_keyboard.h"
#include "SDK.hpp"
#include "WOLTAJ/Oxorany/oxorany.h"
#include "WOLTAJ/Hook/Utils.h"
#include "WOLTAJ/KittyMemory/MemoryPatch.h"
#include "WOLTAJ/Hook/Utils.h"
#include "WOLTAJ/Hook/Macros.h"
#include "WOLTAJ/Hook/Logger.h"
#include <string.h>
#include "WOLTAJ/shadowhook/shadowhook.h"//shadowhook渲染
#include <vector>
#include <random>
#include <iostream>
#include <cstdio>

#include "Offset.h"
#include "WOLTAJ/Main/ESP/Config.h"
#include "WOLTAJ/Helper/skCrypter.h"
#include "User.h"
#include <cstring>
#include <chrono>
#include <stdio.h>
#include <stdlib.h>
