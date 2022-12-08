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
    friend class MainWindow;
public:
    explicit LoginDialog(QWidget *parent = nullptr);
    ~LoginDialog();
    bool getMatch() const
    {
        return match;
    }
    bool adminCredentials() const
    {
        return admin;
    }
    void setAdmin(bool check)
    {
        admin = check;
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
    bool admin;

};

#endif // LOGINDIALOG_H
