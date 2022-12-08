#include "mainwindow.h"
#include "logindialog.h"
#include "contactus.h"
#include <QApplication>

int main(int argc, char *argv[])
{

    QApplication a(argc, argv);    
//    LoginDialog login;

    ContactUs contact;


//    login.show();

    MainWindow w;
    w.showMaximized();



    return a.exec();

}
