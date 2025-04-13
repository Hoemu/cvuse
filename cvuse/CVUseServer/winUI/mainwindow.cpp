#ifdef SPDLOG_DEF
#include <spdlog/sinks/basic_file_sink.h>
#include <spdlog/sinks/stdout_color_sinks.h>
#include <spdlog/spdlog.h>
#endif

#include "./ui_mainwindow.h"
#include "QOpenGLFunctions"
#include "mainwindow.h"
#define DEBUG

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
#ifndef DEBUG
    spdlog::set_default_logger(spdlog::basic_logger_mt("console", "../logs/app.log"));
#endif
    // spdlog::info("Welcome to CVUseServer");
    this->setWindowTitle("WinServer");
    // acoreLog = new acore::ACore;

    group.addButton(ui->btn_main);
    group.addButton(ui->btn_other);
    group.addButton(ui->btn_setting);

    acoreLog.loadFileSetting()->setFilePathVector({ "../Log/info_test.log" });
    acoreLog.loadConfig()->setImplement(true);
    acoreLog.getLogController()->start();
    // acoreLog.getLogController()->setConsoleCondition(false);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_btn_main_clicked()
{
    LOG_INFO("fdas %d", count_index++);
    // LOG_INFO("main %", "main load");
    ui->stackedWidget->setCurrentWidget(ui->page_main);
}

void MainWindow::on_btn_setting_clicked()
{
    LOG_DEBUG("btn setting %s", "btn");
    ui->stackedWidget->setCurrentWidget(ui->page_setting);
}

void MainWindow::on_btn_other_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->page_other);
}
