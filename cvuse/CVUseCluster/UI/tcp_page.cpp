#include "tcp_page.h"
#include "ui_tcp_page.h"

TCPPage::TCPPage(QWidget *parent) : QWidget(parent), ui(new Ui::TCPPage)
{
    ui->setupUi(this);
    isConnect = false;
}

TCPPage::~TCPPage()
{
    delete ui;
}
