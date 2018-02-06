#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QInputDialog>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->addTaskButton, &QPushButton::clicked, this, &MainWindow::addTask);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::addTask()
{
    bool ok;
    QString name = QInputDialog::getText(this, tr("Add task"), tr("Task name"),
                                         QLineEdit::Normal, tr("Untitled task"), &ok);
    if(ok && !name.isEmpty()){
        qDebug() << "addTask clicked.";
        Task* task = new Task("Untitled task");
        connect(task, &Task::removed, this, &MainWindow::removeTask);
        mTasks.append(task);
        ui->tasksLayout->addWidget(task);
    }
}

void MainWindow::removeTask(Task *task)
{
    mTasks.removeOne(task);
    ui->tasksLayout->removeWidget(task);
    task->setParent(0);
    delete task;
}
