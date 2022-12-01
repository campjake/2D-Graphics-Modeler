#include "ellipse.h"

// Constructor
Ellipse::Ellipse(QPaintDevice* device, int anID,
                 ShapeType shapeType, int width, int height)
    : Shape{device, anID, shapeType}, width{width}, height{height}
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
    painter->drawEllipse(a, b, width, height);
}

// Move function
void Ellipse::Move(int xCoord, int yCoord)
{
    QPoint pos;
    pos.setX(xCoord);
    pos.setY(yCoord);
    this->SetPos(pos);
}

// CalcPerimeter
double Ellipse::CalcPerimeter() const
{
    return (width + height)/2*PI;
}

// CalcArea
double Ellipse::CalcArea() const
{
    return (width*height)/4*PI;
}
/*************************************************************/
