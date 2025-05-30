#ifndef UDP_PAGE_H
#define UDP_PAGE_H

#include <QWidget>
#include "remote"

namespace Ui
{
class UDPPage;
}

class UDPPage : public QWidget
{
    Q_OBJECT

public:
    explicit UDPPage(QWidget *parent = nullptr);
    ~UDPPage();

private slots:
    void on_btn_connect_clicked();

    void on_btn_disconnect_clicked();

    void readData(QByteArray data);

    void on_btn_clear_clicked();

    void on_btn_send_clicked();

protected:
    void init();

    void cancelConnect();

private:
    Ui::UDPPage *ui;

    RemoteUDP *server; // 负责接收数据

    RemoteUDP *clinet; // 负责发送数据

    bool isConnect;
};

#endif // UDP_PAGE_H
