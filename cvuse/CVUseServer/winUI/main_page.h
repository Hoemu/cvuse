#ifndef MAIN_PAGE_H
#define MAIN_PAGE_H

#include <QWidget>

namespace Ui
{
class MainPage;
}

class MainPage : public QWidget
{
    Q_OBJECT

public:
    explicit MainPage(QWidget *parent = nullptr);
    ~MainPage();

private:
    Ui::MainPage *ui;
};

#endif // MAIN_PAGE_H
