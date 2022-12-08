#ifndef LOGINDIALOG_H
#define LOGINDIALOG_H

#include <QDialog>
#include <QObject>
#include <QMessageBox>
#include <QCloseEvent>

namespace Ui {
class LoginDialog;
}

class LoginDialog : public QDialog
{
    Q_OBJECT

public:
    explicit LoginDialog(QWidget *parent = nullptr);
    ~LoginDialog();
    bool adminCredentials()
    {
        return match;
    }

private slots:

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();


private:
    Ui::LoginDialog *ui;
    QMessageBox loginRejected;
    bool match;
    bool locked;
    int count;

};

#endif // LOGINDIALOG_H
