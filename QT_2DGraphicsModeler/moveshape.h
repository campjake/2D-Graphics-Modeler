#ifndef MOVESHAPE_H
#define MOVESHAPE_H

#include <QDialog>
#include "renderarea.h"
#include "shape.h"

namespace Ui {
class MoveShape;
}

class MoveShape : public QDialog
{
    Q_OBJECT

public:
    explicit MoveShape(QWidget *parent = nullptr);
    ~MoveShape();
    void setVector(vector<Shape*>* vec);
    // not really meant to be secret?
    int x;
    int y;
    int anID;

private slots:
    void on_buttonBox_accepted();

//    void on_MoveShape_finished(int result);

//    void on_buttonBox_destroyed(QObject *arg1);

private:
    Ui::MoveShape *ui;
//    vector<Shape*>* vShape;
//    Shape* shape;

};

#endif // MOVESHAPE_H
