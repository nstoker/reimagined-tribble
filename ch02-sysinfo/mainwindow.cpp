#include <QLayout>
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "sysinfo.h"
#include "cpuwidget.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    mCpuWidget(this),
    mMemoryWidget(this)
{
    ui->setupUi(this);
    SysInfo::instance().init();

    // Ok the issue seems to be in the layout()->addWidget code. Sigh.
    ui->centralWidget->layout()->addWidget(&mCpuWidget);
    ui->centralWidget->layout()->addWidget(&mMemoryWidget);
}

MainWindow::~MainWindow()
{
    delete ui;
}
