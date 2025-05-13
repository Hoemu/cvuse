#include "other_page.h"
#include "ui_other_page.h"

OtherPage::OtherPage(QWidget *parent) : QWidget(parent), ui(new Ui::OtherPage)
{
    udp = new ProtocolUDP(this);
    udp->setIP("127.0.0.1");
    udp->setPort(3344);

    ui->setupUi(this);
    group.addButton(ui->btn_test1);
    group.addButton(ui->btn_test2);
}

OtherPage::~OtherPage()
{
    delete ui;
}

void OtherPage::on_btn_udp_test_send_clicked()
{
    QString data = ui->lineEdit_UDP_SEND->text();
    udp->send(data.toLatin1());
}
