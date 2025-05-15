#ifndef OTHER_PAGE_H
#define OTHER_PAGE_H

#include <QButtonGroup>
#include <QWidget>
#include <QtProtobuf/QtProtobuf>
#include "../protocol/udp_server.h"

namespace Ui
{
class OtherPage;
}

class OtherPage : public QWidget
{
    Q_OBJECT

public:
    explicit OtherPage(QWidget *parent = nullptr);
    ~OtherPage();

private slots:
    void on_btn_udp_test_send_clicked();

    void on_checkBox_Yes_clicked();

    void on_checkBox_No_clicked();

    void readData(QByteArray data);

private:
    Ui::OtherPage *ui;

    QButtonGroup group;

    QButtonGroup groupUdpServer;

    UDPServer *udp;
};

#endif // OTHER_PAGE_H
