#include "mainwindow.h"
#include "logindialog.h"
#include "contactus.h"
#include <QApplication>

int main(int argc, char *argv[])
{

    QApplication a(argc, argv);
    MainWindow w;
    LoginDialog login;
    ContactUs contact;


    login.show();
    w.show();



    return a.exec();

}
