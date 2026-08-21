#ifndef LOGGER_H
#define LOGGER_H

#include <stdio.h>
#include <stdarg.h>
#include <string>
#include <time.h>
#include <sys/stat.h>

#define LOG_DIR "/sdcard/Android/data/com.yourgame/logs/"  // Thư mục chứa log

// Tạo thư mục nếu chưa tồn tại
void EnsureLogDirectory() {
    mkdir("/sdcard/Android", 0777);
    mkdir("/sdcard/Android/media", 0777);
    mkdir("/sdcard/Android/medi/com.tencent.ig", 0777);
    mkdir(LOG_DIR, 0777);
}

// Lấy thời gian hiện tại dưới dạng chuỗi
std::string GetCurrentTimestamp() {
    time_t now = time(0);
    struct tm tstruct;
    char buf[20];
    tstruct = *localtime(&now);
    strftime(buf, sizeof(buf), "%Y%m%d-%H%M%S", &tstruct);
    return std::string(buf);
}

// Ghi log với số thứ tự
void WriteLog(int logNumber, const char *format, ...) {
    EnsureLogDirectory();

    // Tạo file log với tên log_x-[timestamp].txt
    std::string filename = LOG_DIR + std::string("log_") + std::to_string(logNumber) + "-" + GetCurrentTimestamp() + ".txt";
    FILE *file = fopen(filename.c_str(), "a");
    if (!file) return;

    va_list args;
    va_start(args, format);
    vfprintf(file, format, args);
    fprintf(file, "\n");
    va_end(args);

    fclose(file);
}

#endif // LOGGER_H
