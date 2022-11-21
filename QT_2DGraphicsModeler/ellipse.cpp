#include "ellipse.h"

// Constructor
Ellipse::Ellipse(QPaintDevice* device, int anID, ShapeType shapeType, float width, float height)
    : Shape{device, anID, shapeType}, width{width}, height{height}{}

// Destructor
Ellipse::~Ellipse(){}

float Ellipse::getWidth()const
{
    return width;
}

float Ellipse::getHeight()const
{
    return height;
}

void Ellipse::setWidth(const float width)
{
    this->width = width;
}

void Ellipse::setHeight(const float height)
{
    this->height = height;
}

/******************* Pure Virtual Fcns **************************/
// Draw function
void Ellipse::Draw(QPainter* painter)
{
    painter->drawEllipse(0, 0, width, height);
}

// Move function
void Ellipse::Move(QPoint pos)
{
    this->SetPos(pos);
}

// CalcPerimeter
double Ellipse::CalcPerimeter()
{
    return (width + height)/2*PI;
}

// CalcArea
double Ellipse::CalcArea()
{
    return (width*height)/4*PI;
}
/*************************************************************/
