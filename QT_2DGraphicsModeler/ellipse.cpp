#include "ellipse.h"
#define _USE_MATH_DEFINES

#include <cmath>

// Constructor
Ellipse::Ellipse(QPaintDevice* device, int anID,
                 ShapeType shapeType, int a, int b)
    : Shape{device, anID, shapeType}, a{a}, b{b}
{}

// Parser Constructor
Ellipse::Ellipse(int anID, QPoint qPos, int a, int b)
    : a{a}, b{b}
{
    this->SetID(anID);
    this->SetPos(qPos);
}

// Destructor
Ellipse::~Ellipse(){}

int Ellipse::getWidth()const
{
    return width;
}

int Ellipse::getHeight()const
{
    return height;
}

void Ellipse::setWidth(const int width)
{
    this->width = width;
}

void Ellipse::setHeight(const int height)
{
    this->height = height;
}

/******************* Pure Virtual Fcns **************************/
// Draw function
void Ellipse::Draw(QPainter* painter)
{
    painter->setPen(GetPen());
    painter->setBrush(GetBrush());
    painter->drawEllipse(GetPos(), a, b);
}

// Move function
//void Ellipse::Move(int xCoord, int yCoord)
//{
//    QPoint pos;
//    pos.setX(xCoord);
//    pos.setY(yCoord);
//    this->SetPos(pos);
//}

// CalcPerimeter
double Ellipse::CalcPerimeter() const
{
    if(a == b)
    {
        return 2 * (M_PI * (double)a);
    }

    // approximation

    return 2 * M_PI * sqrt((double)((a*a) + (b  * b)) /
                           2 );
}

// CalcArea
double Ellipse::CalcArea() const
{
    return (double)(a*b)*M_PI;
}
/*************************************************************/
