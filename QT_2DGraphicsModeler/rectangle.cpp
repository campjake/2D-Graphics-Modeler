#include "rectangle.h"

Rectangle::Rectangle(QPaintDevice* device, int anID, ShapeType shapeType, float width, float length)
    : Shape{device, anID, shapeType}, width{width}, length{length}{}

// Destructor
Rectangle::~Rectangle(){}


// COME BACK AND FIGURE OUT IMPLEMENTATION

//    // Move Operations
//        // Move Ctor
//    Shape(Shape&& otherShape) noexcept;

//        // Move Assignment
//    Shape& operator=(Shape&& otherShape) noexcept;

float Rectangle::getWidth()const
{
    return width;
}

float Rectangle::getLength()const
{
    return length;
}

void Rectangle::setWidth(const float width)
{
    this->width = width;
}

void Rectangle::setLength(const float length)
{
    this->length = length;
}

/******************* Pure Virtual Fcns **************************/
// Draw function
void Rectangle::Draw(QPainter* painter)
{
    painter->drawRect(0, 0, width, length);
}

// Move function
void Rectangle::Move(QPoint pos)
{
    this->SetPos(pos);
}

// CalcPerimeter
double Rectangle::CalcPerimeter()
{
    return (width + length)*2;
}

// CalcArea
double Rectangle::CalcArea()
{
    return width*length;
}
