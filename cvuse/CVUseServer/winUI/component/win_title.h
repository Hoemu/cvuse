#ifndef WIN_TITLE_H
#define WIN_TITLE_H

#include <QWidget>

namespace Ui
{
class WinTitle;
}

class WinTitle : public QWidget
{
    Q_OBJECT

public:
    explicit WinTitle(QWidget *parent = nullptr);
    ~WinTitle();

private:
    Ui::WinTitle *ui;
};

#endif // WIN_TITLE_H
