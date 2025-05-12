#include "ffmpeg_base_instraction.h"
#include <iostream>

FFMpegBaseInstraction::FFMpegBaseInstraction()
{
    test();

    av_log_set_level(AV_LOG_INFO);

    const char *protocol_name;
    void *opaque = NULL;
    int is_output = 0;
    while ((protocol_name = avio_enum_protocols(&opaque, is_output)))
    {
        printf("支持协议: %s\n", protocol_name);
    }
}

void FFMpegBaseInstraction::openDir(const string &Dir)
{
    AVIODirContext *ctx = NULL;
    AVIODirEntry *entry = NULL; // entry 是 64 位的

    // if (access("D:/Software", F_OK) == 0)
    // {
    //     std::cout << "current path is exist." << std::endl;
    //     // 路径存在
    // }

    int ret = avio_open_dir(&ctx, "\\\\?\\D:\\Software", NULL);
    std::cout << ret << std::endl;
    if (ret < 0)
    {
        // av_log(NULL, AV_LOG_ERROR, "Can't read dir:%s\n", ret);
        std::cerr << "error" << ret << std::endl;
        return;
    }

    while (1)
    {
        ret = avio_read_dir(ctx, &entry);
        if (ret < 0)
        {
            std::cerr << "error:read" << ret << std::endl;
            avio_close_dir(&ctx);
            return;
        }
        if (!entry) // 如果读取到目录最后一项
        {
            break;
        }
        std::cout << "info:" << entry->size << " " << entry->name << std::endl;
        avio_free_directory_entry(&entry); // 释放内存
    }

    avio_close_dir(&ctx);
}

void FFMpegBaseInstraction::test()
{
    std::cout << "--------------- TEST BEGIN --------------" << std::endl;

    av_log_set_level(AV_LOG_DEBUG);
    av_log(NULL, AV_LOG_INFO, "hello world!\n");
    openDir("");

    std::cout << "--------------- TEST END --------------" << std::endl;
}
