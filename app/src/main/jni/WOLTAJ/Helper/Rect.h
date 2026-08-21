//
// Created by aimar on 1/13/2020.
//

#ifndef MENU_RECT_H
#define MENU_RECT_H

#include <jni.h>

#include "Const.h"

class Rect {
private:
    jfieldID leftId, topId, rightId, bottomId;
public:
    JNIEnv *env;
    jobject m_Rect;

    Rect(JNIEnv *env)
    {
        this->env = env;

        jclass rectClass = env->FindClass("android/graphics/Rect");
        jmethodID init = env->GetMethodID(rectClass, "<init>", "()V");
        this->m_Rect = env->NewGlobalRef(env->NewObject(rectClass, init));

        leftId = env->GetFieldID(rectClass, "left", "I");
        topId = env->GetFieldID(rectClass, "top", "I");
        rightId = env->GetFieldID(rectClass, "right", "I");
        bottomId = env->GetFieldID(rectClass, "bottom", "I");

        env->DeleteLocalRef(rectClass);
    }

    int getLeft();
    int getRight();
    int getTop();
    int getBottom();

    int getWidth();
    int getHeight();

    void Cleanup();
};


class Rect2 {
public:
    float x;
    float y;
    float width;
    float height;

    Rect2() {
        this->x = 0;
        this->y = 0;
        this->width = 0;
        this->height = 0;
    }

    Rect2(float x, float y, float width, float height) {
        this->x = x;
        this->y = y;
        this->width = width;
        this->height = height;
    }

    bool operator==(const Rect2 &src) const {
        return (src.x == this->x && src.y == this->y && src.height == this->height &&
                src.width == this->width);
    }

    bool operator!=(const Rect2 &src) const {
        return (src.x != this->x && src.y != this->y && src.height != this->height &&
                src.width != this->width);
    }
};
#endif //MENU_RECT_H
