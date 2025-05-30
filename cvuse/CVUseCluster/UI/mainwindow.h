#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "remote"

QT_BEGIN_NAMESPACE
namespace Ui
{
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_btn_UDP_clicked();

    void on_btn_TCP_clicked();

private:
    Ui::MainWindow *ui;

    ConfigSetting *conf;
};
#endif // MAINWINDOW_H
