LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)

LOCAL_SRC_FILES += native-lib.cpp

LOCAL_CFLAGS += -frtti -fexceptions -std=c++11
LOCAL_CPPFLAGS += -std=c++11
LOCAL_LDLIBS += -llog

LOCAL_MODULE := native-lib

include $(BUILD_SHARED_LIBRARY)