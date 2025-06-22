#ifndef TCP_PAGE_H
#define TCP_PAGE_H

#include <QTcpSocket>
#include <QWidget>
#include "remote"

namespace Ui
{
class TCPPage;
}

class TCPPage : public QWidget
{
    Q_OBJECT

public:
    explicit TCPPage(QWidget *parent = nullptr);
    ~TCPPage();

private:
    Ui::TCPPage *ui;

    bool isConnect;
};

#endif // TCP_PAGE_H
