#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QButtonGroup>
#include <QMainWindow>
#include "a_core.h"

QT_BEGIN_NAMESPACE
namespace Ui
{
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_btn_main_clicked();

    void on_btn_setting_clicked();

    void on_btn_other_clicked();

private:
    Ui::MainWindow *ui;

    QButtonGroup group;

    acore::ACore acoreInit;
};
#endif // MAINWINDOW_H
