#include <string>
#include <jni.h>

#include <android/log.h>

#ifdef __cplusplus
extern "C" {
#endif

void CallException();

JNIEXPORT jstring
JNICALL
Java_net_maytrue_simplecpptest_MainActivity_stringFromJNI(
        JNIEnv *env,
        jobject /* this */) {
    std::string hello = "Hello from C++";
    __android_log_print(ANDROID_LOG_INFO, "cpp", "Hello from cplus cplus");

/*
    char *p = new char[10];
    p[10] = 0;
    delete[] p;
    p = NULL;*/
    try {
        CallException();
    } catch (const std::invalid_argument& exception) {
       __android_log_print(ANDROID_LOG_INFO, "cpp", "catch expetion");
    }

    return env->NewStringUTF(hello.c_str());
}

void CallException()
{
    throw std::invalid_argument( "received negative value" );
}

#ifdef __cplusplus
}
#endif

