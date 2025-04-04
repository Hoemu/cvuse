#ifndef OTHER_PAGE_H
#define OTHER_PAGE_H

#include <QButtonGroup>
#include <QWidget>

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

private:
    Ui::OtherPage *ui;

    QButtonGroup group;
};

#endif // OTHER_PAGE_H
