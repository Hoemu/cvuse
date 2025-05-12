#ifndef FFMPEG_BASE_INSTRACTION_H
#define FFMPEG_BASE_INSTRACTION_H
#include <string>

extern "C"
{
#include "./libavformat/avio.h"
#include "./libavutil/log.h"
}

using std::string;

typedef class FFMpegBaseInstraction
{
public:
    FFMpegBaseInstraction();

    void openDir(const string &Dir);

    void test();

private:
} FFBaseInstraction;

#endif // FFMPEG_BASE_INSTRACTION_H
