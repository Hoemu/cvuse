#include "main_page.h"
#include <QFileDialog>
#include "ui_main_page.h"

MainPage::MainPage(QWidget *parent) : QWidget(parent), ui(new Ui::MainPage)
{
    ui->setupUi(this);

    group.addButton(ui->btn_fileServer);
    group.addButton(ui->btn_playServer);
}

MainPage::~MainPage()
{
    delete ui;
}

void MainPage::on_btn_playServer_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->page_play);
}

void MainPage::on_btn_fileServer_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->page_file);
}

void MainPage::on_btn_selectFile_clicked()
{
    data.clear();
    QString fileName = QFileDialog::getOpenFileName(this, tr("Open Image"), "/home/jana", tr("Image Files (*.png *.jpg *.bmp *txt)"));

    ui->label_filePathShow->setText(fileName);
    QFile file(fileName);
    if (file.open(QIODevice::ReadOnly))
    {
        // 第二种方式就是一数据流读取文件内容
        // QDataStream in(&file); // 二进制读取
        // QDate data;
        // in >> data;
        data.append(file.readLine());
        qDebug() << file.readLine(); // 字符串形式读取
    }
    else
    {
        qDebug() << file.errorString();
    }
    file.close();
}
