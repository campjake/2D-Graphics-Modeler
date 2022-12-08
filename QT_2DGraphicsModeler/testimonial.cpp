#include "testimonial.h"
#include "ui_testimonial.h"
#include <QFileDialog>
#include <QMessageBox>
testimonial::testimonial(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::testimonial)
{
    ui->setupUi(this);
}

testimonial::~testimonial()
{
    delete ui;
}





void testimonial::on_button_Save_accepted()
{
    QString fileName = QString("testimonial.txt");
    QFile file(fileName);
    if(!file.open(QFile::ReadWrite | QFile::Truncate | QFile::Text))
    {
        QMessageBox::warning(this, "Warning","Cannot Save File" +file.errorString());
        return;
    }
    setWindowTitle(fileName);
    QTextStream out(&file);
    QString text = ui->textEdit->toPlainText();
    out << text;

    file.close();
}

