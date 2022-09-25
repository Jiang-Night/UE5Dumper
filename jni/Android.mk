LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)

LOCAL_CPPFLAGS += -pie -fPIE -ffunction-sections -fdata-sections -fvisibility=hidden
LOCAL_LDFLAGS += -pie -fPIE -Wl,--gc-sections
LOCAL_CFLAGS := -Wno-error=format-security -fpermissive
LOCAL_CFLAGS += -ffunction-sections -fdata-sections -fvisibility=hidden
LOCAL_CFLAGS += -fno-rtti -fno-exceptions
LOCAL_CFLAGS += -DNDEBUG

ifeq ($(TARGET_ARCH_ABI), arm64-v8a)
    LOCAL_MODULE := ue5dumper64

	LOCAL_SRC_FILES := dumper.cpp \

    LOCAL_CPP_INCLUDES += $(LOCAL_PATH)

endif

ifeq ($(TARGET_ARCH_ABI), armeabi-v7a)
    LOCAL_MODULE := ue5dumper

	LOCAL_SRC_FILES := dumper.cpp \

    LOCAL_CPP_INCLUDES += $(LOCAL_PATH)

endif

LOCAL_LDLIBS += -L$(SYSROOT)/usr/lib -lz -llog

include $(BUILD_EXECUTABLE)




