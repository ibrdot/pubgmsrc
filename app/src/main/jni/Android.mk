LOCAL_PATH := $(call my-dir)
MAIN_LOCAL_PATH := $(call my-dir)
include $(CLEAR_VARS)
LOCAL_MODULE            := libdobby
LOCAL_SRC_FILES         := Dobby/libraries/$(TARGET_ARCH_ABI)/libdobby.a
LOCAL_EXPORT_C_INCLUDES := $(LOCAL_PATH)/Dobby/
include $(PREBUILT_STATIC_LIBRARY)
include $(CLEAR_VARS)
LOCAL_MODULE    := ItsMyHubS
LOCAL_CFLAGS := -Wno-error=format-security -fvisibility=hidden -ffunction-sections -fdata-sections -w
LOCAL_CFLAGS += -fno-rtti -fno-exceptions -fpermissive
LOCAL_CPPFLAGS := -Wno-error=format-security -fvisibility=hidden -ffunction-sections -fdata-sections -w -Werror -s -std=c++17
LOCAL_CPPFLAGS += -Wno-error=c++11-narrowing -fms-extensions -fno-rtti -fno-exceptions -fpermissive
LOCAL_LDFLAGS += -Wl,--gc-sections,--strip-all -llog
LOCAL_ARM_MODE := arm
LOCAL_C_INCLUDES += $(MAIN_LOCAL_PATH)
LOCAL_C_INCLUDES += $(MAIN_LOCAL_PATH)/imgui
LOCAL_SRC_FILES := main.cpp \
WOLTAJ/hook.cpp \
WOLTAJ/patch/KittyMemory.cpp \
WOLTAJ/patch/MemoryPatch.cpp \
WOLTAJ/patch/MemoryBackup.cpp \
WOLTAJ/patch/KittyUtils.cpp \
ImGui/imgui.cpp \
ImGui/imgui_draw.cpp \
ImGui/imgui_tables.cpp \
ImGui/imgui_widgets.cpp \
ImGui/imgui_impl_android.cpp \
ImGui/imgui_impl_opengl3.cpp \
SDK/FURKAN_Basic.cpp \
SDK/FURKAN_Basic_functions.cpp \
SDK/FURKAN_CoreUObject_functions.cpp \
SDK/FURKAN_Engine_functions.cpp \
SDK/FURKAN_ShadowTrackerExtra_functions.cpp \
SDK/FURKAN_Client_functions.cpp
LOCAL_CPP_FEATURES := exceptions
LOCAL_LDLIBS := -llog -landroid -lEGL -lGLESv2 -lGLESv3 -lGLESv1_CM -lz
LOCAL_STATIC_LIBRARIES := libdobby
include $(BUILD_SHARED_LIBRARY)
