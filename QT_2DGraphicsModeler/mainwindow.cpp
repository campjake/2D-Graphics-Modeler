#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QApplication>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->actionContact_Us,SIGNAL(triggered()),this,SLOT(on_actionContact_Us_triggered()));
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_actionContact_Us_triggered()
{
    ContactUs *contact;
    contact = new ContactUs();
    contact->exec();
}
