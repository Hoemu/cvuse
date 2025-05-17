#ifndef MAIN_PAGE_H
#define MAIN_PAGE_H

#include <QButtonGroup>
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

private slots:
    void on_btn_playServer_clicked();

    void on_btn_fileServer_clicked();

    void on_btn_selectFile_clicked();

private:
    Ui::MainPage *ui;

    QButtonGroup group;

    QString data;
};

#endif // MAIN_PAGE_H
