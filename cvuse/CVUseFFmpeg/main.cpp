/**
 * @brief ffmpeg 程序
 * @author HoeMuiiii
 * @date 2025 年 5 月 13 日
 */

#include <QApplication>
#include "ffmpeg_base_instraction.h"
#include "mainwindow.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    // MainWindow w;
    // w.show();
    FFBaseInstraction ff;
    return a.exec();
}
