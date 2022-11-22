#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "contactus.h"
#include "logindialog.h"
#include "testimonial.h"
#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
private slots:
    void on_actionContact_Us_triggered();

    void on_actionCustomer_Testimonials_triggered();

private:
    Ui::MainWindow *ui;

};
#endif // MAINWINDOW_H
