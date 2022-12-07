#include "line.h"
#include <QDebug>

//Constructor
Line::Line(QPaintDevice* device, int anID, ShapeType shapeType)
    : Shape{device, anID, shapeType}
{
    SetPen(Qt::SolidLine);
//    SetBrush(Qt::NoBrush);
}

//constructor with pen and brush
Line::Line(QPaintDevice* device, int anID,
           ShapeType shapeType, QPen thatPen)
    : Shape(device, anID, shapeType)
{
    SetPen(thatPen);
//    SetBrush(Qt::NoBrush);

}

// Parser Constructor
Line::Line(int anID, QPoint first, QPoint last)
    : point1{first}, point2{last}
{
    this->SetID(anID);
    this->SetShapeType(ShapeType::Line);
    qInfo() << "You constructed a Line\n";
}
//operators
bool Line::operator == (const Line& other)
{
    if (GetID() == other.GetID())
        return true;
    else
        return false;
}

bool Line::operator < (const Line& other)
{
    if (GetID() < other.GetID())
        return true;
    else
        return false;
}

//Base class pure virtual functions

//Draws line
void Line::Draw(QPainter* painter)
{
    // let global qpainter "painter" do the drawing
    // ^^ so we don't need the parameter?

    painter->setPen(GetPen());
//    painter->setBrush(GetBrush());
    painter->drawLine(point1, point2);
//    this->getPainter()->setPen(GetPen());
//    this->getPainter()->setBrush(GetBrush());
//    this->getPainter()->drawLine(point1, point2);

}

//Moves first point
void Line::Move(int xCoord, int yCoord)
{
    point1.setX(xCoord);
    point1.setY(yCoord);
}

//Calculates distance
double Line::CalcPerimeter() const
{
    return sqrt(pow((point1.x() - point2.x()), 2) + pow((point1.y() - point2.y()), 2));
}

//Returns area
double Line::CalcArea() const
{
    return 0;
}

//Class specific functions

//Moves all points by offset in x and y
void Line::moveOffset(int offsetX, int offsetY)
{
    point1.setX(point1.x() + offsetX);
    point1.setY(point1.y() + offsetY);

    point2.setX(point2.x() + offsetX);
    point2.setY(point2.y() + offsetY);
}

//sets both ends of line
void Line::setPoints(const QPoint& P1, const QPoint& P2)
{
    point1 = P1;
    point2 = P2;
}

//sets point 1
void Line::setPoint1(const QPoint& P1) {
    point1 = P1;
}

//sets point 2
void Line::setPoint2(const QPoint& P2) {
    point2 = P2;
}

QPoint Line::getPoint1() const
{
    return point1;
}

QPoint Line::getPoint2() const
{
    return point2;
}
