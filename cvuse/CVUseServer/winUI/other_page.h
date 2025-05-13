#ifndef OTHER_PAGE_H
#define OTHER_PAGE_H

#include <QButtonGroup>
#include <QWidget>
#include <QtProtobuf/QtProtobuf>
#include "../protocol/protocol_udp.h"

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

private:
    Ui::OtherPage *ui;

    QButtonGroup group;

    ProtocolUDP *udp;
};

#endif // OTHER_PAGE_H
