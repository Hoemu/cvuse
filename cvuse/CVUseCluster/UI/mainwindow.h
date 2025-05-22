#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "server"

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
    void on_btn_send_clicked();

    void readData(QByteArray data);

    void on_btn_clear_clicked();

    void on_btn_connect_clicked();

    void on_btn_disconnect_clicked();

    void on_btn_UDP_clicked();

    void on_btn_TCP_clicked();

protected:
    void init();

private:
    Ui::MainWindow *ui;

    RemoteUDP *server;

    RemoteUDP *clinet;

    bool isConnect;

    ConfigSetting *conf;
};
#endif // MAINWINDOW_H
