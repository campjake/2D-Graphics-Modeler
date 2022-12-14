#include "logindialog.h"
#include "ui_logindialog.h"
#include <QPixmap>

LoginDialog::LoginDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::LoginDialog),
    match{false},
    locked{false},
    count{0},
    admin{false}
{
    ui->setupUi(this);

    setWindowFlags(Qt::Widget | Qt::WindowMaximizeButtonHint);
    QPixmap pix("ShapesRUs.jpg");
    ui->label_logo->setPixmap(pix.scaled(1000,1000,Qt::KeepAspectRatio));
}

LoginDialog::~LoginDialog()
{
    delete ui;
}

void LoginDialog::on_pushButton_clicked()
{
    QString username = ui->lineEdit_username->text();
    QString password = ui->lineEdit_password->text();

    if((username == "USER" && password == "12345" && !locked))
    {
        match = true;
        admin = true;
    }
    else
    {
        if(username == "GUEST" && password == "12345" && !locked)
        {
            match = true;
            admin = false;
        }
        else
        {
            if(!locked)
            {
                loginRejected.warning(this, "Login Failed", "Incorrect username and/or password");
                match = false;
                count++;
            }
        }
    }

    if(count > 3 && !match)
    {
        loginRejected.warning(this, "WARNING", "Max login attempts exceeded");
        locked = true;

    }

    if(match)
    {
        this->close();
    }

}


void LoginDialog::on_pushButton_2_clicked()
{
    QCoreApplication::quit();
}




