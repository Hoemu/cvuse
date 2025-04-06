#ifndef BUTTON_TEXT_GROUP_H
#define BUTTON_TEXT_GROUP_H

#include <QWidget>
#include "../../tool/qss_tool.h"

namespace Ui
{
class ButtonTextGroup;
}

class ButtonTextGroup : public QWidget
{
    Q_OBJECT

public:
    explicit ButtonTextGroup(QWidget *parent = nullptr);
    ~ButtonTextGroup();

    void setStyleSheet(const QString &styleSheet);

signals:
    void checked(bool ischecked);

    void checked();

private:
    Ui::ButtonTextGroup *ui;

    QSSTool qssTool;
};

#endif // BUTTON_TEXT_GROUP_H
