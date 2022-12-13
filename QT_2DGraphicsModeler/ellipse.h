#ifndef ELLIPSE_H
#define ELLIPSE_H

#include "shape.h"
#define PI 3.14

// Class Definition of an Ellipse
class Ellipse : public Shape
{
    public :
    // Constructor
    Ellipse(QPaintDevice* device, int anID,
            ShapeType shapeType, int a, int b);

    // Parser Constructor
    Ellipse(int anID, QPoint qPos, int a, int b);

    // Destructor
    virtual ~Ellipse();

    // Copy Operations (delete them)
    Ellipse(const Ellipse& source) = delete;
    Ellipse& operator=(const Ellipse& source) = delete;


    int getWidth()const;

    int getHeight()const;

    int getA() const {return a;}
    int getB() const {return b;}

    void setWidth(const int width);

    void setHeight(const int height);

    /******************* Pure Virtual Fcns **************************/
    // Draw function
    virtual void Draw(QPainter* painter);

    // Move function
//    virtual void Move(int xCoor, int yCoord);

    // CalcPerimeter
    virtual double CalcPerimeter() const;

    // CalcArea
    virtual double CalcArea() const;

    virtual void Print(QTextStream &fout);
    /*************************************************************/

  private :
    int width;
    int height;
    int a;      // Ellipse major axis
    int b;      // Ellipse minor axis
};

#endif // ELLIPSE_H
