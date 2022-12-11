#include "rectangle.h"

Rectangle::Rectangle(QPaintDevice* device, int anID,
                     ShapeType shapeType, int width, int length)
    : Shape{device, anID, shapeType}, width{width}, length{length}{}

// Parser Constructor
Rectangle::Rectangle(int anID, QPoint aPos, int l, int w)
    : width{w}, length{l}
{
    this->SetID(anID);
    this->SetPos(aPos);
}

// Destructor
Rectangle::~Rectangle(){}


// COME BACK AND FIGURE OUT IMPLEMENTATION

//    // Move Operations
//        // Move Ctor
//    Shape(Shape&& otherShape) noexcept;

//        // Move Assignment
//    Shape& operator=(Shape&& otherShape) noexcept;
Rectangle::Rectangle(Rectangle&& otherRectangle) noexcept
: Shape(Shape&& otherRectangle) noexcept
{
    width = std::move(otherRectangle.width);
    length = std::move(otherRectangle.length);
}

//// Move Assignment
//// Pre-Conditions - R-value casted other shape object
//// Post-Conditions - Returns a shape object
Rectangle& Rectangle::operator=(Rectangle&& otherRectangle) noexcept
{
    *this = std::move(Shape(otherRectangle));
    width = std::move(otherRectangle.width);
    length = std::move(otherRectangle.length);

    return *this;
}

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
    painter->drawRect(GetPos().x(), GetPos().y(), width, length);

    painter->drawText(GetPos(), QString::number(GetID()));
}

// Move function
//void Rectangle::Move(int xCoord, int yCoord)
//{
//    QPoint pos;
//    pos.setX(xCoord);
//    pos.setY(yCoord);
//    this->SetPos(pos);
//}

// CalcPerimeter
double Rectangle::CalcPerimeter() const
{
    return (width + length)*2;
}

// CalcArea
double Rectangle::CalcArea() const
{
    return width*length;
}
