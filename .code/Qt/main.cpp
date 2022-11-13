#include "loginWindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    loginWindow login;                                     // create login-widget    // connect to mainwindow show()
    login.show();                                          // show login-window instead of
                                                       // mainwindow at start
    return a.exec();
}
