#include "line.h"

Line::Line(int anID, QPoint point1, QPoint point2) : point1 { point1 }, point2 { point2 }
{
    SetID(anID);
}

//Constructor
Line::Line(QPaintDevice* device, int anID, ShapeType shapeType, QPoint point1, QPoint point2) :
    Shape(device, anID, shapeType), point1 {point1}, point2 {point2}
{
    SetPen(Qt::SolidLine);
    SetBrush(Qt::NoBrush);
}

//constructor with pen and brush
Line::Line(QPaintDevice* device, int anID, ShapeType shapeType, QPen thatPen, QBrush thatBrush, QPoint point1, QPoint point2) :
    Shape(device, anID, shapeType), point1 {point1}, point2 {point2}
{
    SetPen(thatPen);
    SetBrush(thatBrush);
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
    painter->setPen(GetPen());
    painter->setBrush(GetBrush());
    painter->drawLine(point1, point2);
}

//Moves first point
void Line::Move(int xCoord, int yCoord)
{
    point1.setX(xCoord);
    point1.setY(yCoord);
}

//Calculates distance
double Line::CalcPerimeter()
{
    return sqrt(pow((point1.x() - point2.x()), 2) + pow((point1.y() - point2.y()), 2));
}

//Returns area
double Line::CalcArea()
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

