#include "moveshape.h"
#include "ui_moveshape.h"

MoveShape::MoveShape(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MoveShape)
{   
    ui->setupUi(this);
    setModal(true);

}


MoveShape::~MoveShape()
{
    delete ui;
}

//void MoveShape::setVector(vector<Shape*>* vec)
//{
//    vShape = vec;
//}

void MoveShape::on_buttonBox_accepted()
{
    x = ui->xLine->text().toInt();
    y = ui->yLine->text().toInt();
    anID = ui->spinBox->value();



//    newPos.setX(x);
//    newPos.setY(y);


    this->close();
}

