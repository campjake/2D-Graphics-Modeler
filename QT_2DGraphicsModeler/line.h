#ifndef LINE_H
#define LINE_H
#include "shape.h"
#include <cmath>

class Line : virtual public Shape
{
public:
public:
    //Constructor
    Line(QPaintDevice* device = nullptr, int anID = -1, ShapeType shapeType = ShapeType::Polyline);

    //constructor with pen and brush
    Line(QPaintDevice* device = nullptr, int anID = -1, ShapeType shapeType = ShapeType::Polyline,
        QPen thatPen = Qt::SolidLine, QBrush thatBrush = Qt::NoBrush);

    virtual ~Line() {}

    //Copy functions
    Line(const Line& source) = delete;
    Line& operator = (const Line& source) = delete;

    //operators
    bool operator == (const Line& other);

    virtual const double CalcPerimeter();
    bool operator < (const Line& other);

    //Base class pure virtual functions

    //Draws line
    void Draw(QPainter* painter);

    //Moves first point
    void Move(int xCoord, int yCoord);

    //Calculates distance
    double CalcPerimeter();

    //Returns area
    double CalcArea();

    //Class specific functions

    //Moves all points by offset in x and y
    void moveOffset(int offsetX, int offsetY);

    //sets both ends of line
    void setPoints(const QPoint& P1, const QPoint& P2);

    //sets point 1
    void setPoint1(const QPoint& P1);

    //sets point 2
    void setPoint2(const QPoint& P2);

private:
    QPoint point1;
    QPoint point2;
};

#endif // LINE_H
