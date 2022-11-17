#include "contactus.h"
#include "ui_contactUs.h"
#include <QPixmap>

ContactUs::ContactUs() :
    QDialog(nullptr),
    ui(new Ui::ContactUs)
{
    ui->setupUi(this);
    setWindowFlags(Qt::Widget | Qt::MSWindowsFixedSizeDialogHint);
   // QPixmap pix("C:/Users/chinm/Pictures/qt pic/ShapesRUs.jpg");
   // int w = ui->label_logo->width();
    //int h = ui->label_logo->height();
    //ui->label_logo->setPixmap(pix.scaled(100,100,Qt::KeepAspectRatio));
}

ContactUs::~ContactUs()
{
    delete ui;
}
