#include <QApplication>
#include <iostream>
extern "C"
{
#include "./libavutil/log.h"
}
#include "mainwindow.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    // MainWindow w;
    // w.show();
    std::cout << "--------------- BEGIN --------------" << std::endl;

    av_log_set_level(AV_LOG_DEBUG);

    av_log(NULL, AV_LOG_INFO, "hello world!");

    std::cout << "--------------- END --------------" << std::endl;

    return a.exec();
}
