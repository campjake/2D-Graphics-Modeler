#include "mainwindow.h"
#include "logindialog.h"
#include "contactus.h"
#include <QApplication>
#include "textparser.h"

int main(int argc, char *argv[])
{
    TextParser parser;
    QApplication a(argc, argv);
    MainWindow w;
    LoginDialog login;
    ContactUs contact;
    login.show();
    w.show();



    return a.exec();

}
