#include "contactus.h"
#include "ui_contactus.h"
#include <QPixmap>

ContactUs::ContactUs() :
    QDialog(nullptr),
    ui(new Ui::ContactUs)
{
    ui->setupUi(this);
    setWindowFlags(Qt::Widget | Qt::MSWindowsFixedSizeDialogHint);
    QPixmap pix("ShapesRUs.jpg");
    ui->label_logo->setPixmap(pix.scaled(1000,1000,Qt::KeepAspectRatio));

}

ContactUs::~ContactUs()
{
    delete ui;
}




void ContactUs::on_pushButton_clicked()
{
    this->close();
}

