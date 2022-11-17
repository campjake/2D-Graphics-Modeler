#include "contactus.h"
#include "ui_contactus.h"

ContactUs::ContactUs() :
    QDialog(nullptr),
    ui(new Ui::ContactUs)
{
    ui->setupUi(this);
    setWindowFlags(Qt::Widget | Qt::MSWindowsFixedSizeDialogHint);
}

AboutUs::~AboutUs()
{
    delete ui;
}
