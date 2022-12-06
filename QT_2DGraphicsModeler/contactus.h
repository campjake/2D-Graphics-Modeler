#ifndef CONTACTUS_H
#define CONTACTUS_H

#include <QDialog>
#include <QWidget>


namespace Ui {
    class ContactUs;
}

class ContactUs : public QDialog
{
    Q_OBJECT

public:
    ContactUs();
    ~ContactUs();

private slots:
    void on_pushButton_clicked();

private:
    Ui::ContactUs *ui;
};
#endif // CONTACTUS_H
