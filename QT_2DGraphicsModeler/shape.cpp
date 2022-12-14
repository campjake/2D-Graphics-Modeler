#include "shape.h"
//#include "mainwindow.h"
#include <QDebug>


// Default Shape Ctor
// Pre-Conditions - NONE since parameters have default values
// Post-Conditions - Constructs a shape object
Shape::Shape(QPaintDevice* device,
             int anID,
             ShapeType shapeType)
    : id{anID},
      shapeName{shapeType}
{
    painter = new QPainter(device);
    shapePen = Qt::SolidLine;
    shapeBrush = Qt::NoBrush;

}

//COPY OPERATIONS DELETED


// Move Operations

// Move Ctor
// Pre-Conditions - R-value casted other shape object
// Post-Conditions - Constructs a Shape object
Shape::Shape(Shape&& otherShape) noexcept
    : painter{std::move(otherShape.painter)},
      id{std::move(otherShape.id)},
      shapeName{std::move(otherShape.shapeName)},
      shapePen{std::move(otherShape.shapePen)},
      shapeBrush{std::move(otherShape.shapeBrush)},
      shapePos{std::move(otherShape.shapePos)}
{
    otherShape.painter = nullptr;
}

//// Move Assignment
//// Pre-Conditions - R-value casted other shape object
//// Post-Conditions - Returns a shape object
Shape& Shape::operator=(Shape&& otherShape) noexcept
{
    delete painter;

    painter = std::move(otherShape.painter);
    otherShape.painter = nullptr;

    id = std::move(otherShape.id);
    shapeName = std::move(otherShape.shapeName);
    shapePen = std::move(otherShape.shapePen);
    shapeBrush = std::move(otherShape.shapeBrush);
    shapePos = std::move(otherShape.shapePos);

    return *this;
}

// Overloaded == op
// Pre-conditions - Other shape must be there..
// Post-conditions - Returns a bool if they have the same id?
bool Shape::operator==(const Shape& otherShape)
{
    if(id == otherShape.id)
    {
        return true;
    }
    else
    {
        return false;
    }
}

// Overloaded < Operator ??
// to be defined later if necessary
bool Shape::operator<(const Shape& otherShape)
{
    return id < otherShape.id;
}

/************ BEGIN ACCESSORS / GETTERS ************/

// GetID function
// Pre-Conditions - NONE
// Post-conditions - Returns the Shapes ID
int Shape::GetID() const
{
    return id;
}

// GetShapeType function
// Pre-Conditions - NONE
// Post-conditions - Returns the Shapes Type
ShapeType Shape::GetShapeType() const
{
    return shapeName;
}

// GetPen function
// Pre-Conditions - NONE
// Post-conditions - Returns the Shapes QPen
QPen Shape::GetPen() const
{
    return shapePen;
}

// GetBrush function
// Pre-Conditions - NONE
// Post-conditions - Returns the Shapes QBrush
QBrush Shape::GetBrush() const
{
    return shapeBrush;
}

// GetPosition function
// Pre-Conditions - NONE
// Post-conditions - Returns QPoint of shapes position
QPoint Shape::GetPos() const
{
    return shapePos;
}

/************ BEGIN MUTATORS / SETTERS **************/

// SetID function
// Pre-Conditions - int id
// Post-conditions - NONE
void Shape::SetID(const int theID)
{
    id = theID;
}

// SetShapeType function
// Pre-Conditions - shapetype type
// Post-conditions - NONE
void Shape::SetShapeType(const ShapeType type)
{
    shapeName = type;
}

// SetPen function
// Pre-Conditions - relevant properties of a QPen
// Post-conditions - NONE
void Shape::SetPen(const QColor aColor, const int size,
                   const Qt::PenStyle penStyle,
                   const Qt::PenCapStyle capStyle,
                   const Qt::PenJoinStyle joinStyle)
{
    shapePen.setColor(aColor);
    shapePen.setWidth(size);
    shapePen.setStyle(penStyle);
    shapePen.setCapStyle(capStyle);
    shapePen.setJoinStyle(joinStyle);
}

// Overloaded SetPen function
// Pre-Conditions - a QPen
// Post-conditions - NONE
void Shape::SetPen(const QPen thatPen)
{
    shapePen = thatPen;
}

// Overloaded SetBrush function
// Pre-Conditions - a QBrush
// Post-conditions - NONE
void Shape::SetBrush(const QColor aColor,
                     const Qt::BrushStyle brushStyle)
{
    shapeBrush.setColor(aColor);
    shapeBrush.setStyle(brushStyle);
}

void Shape::SetBrush(const QBrush thatBrush)
{
    shapeBrush = thatBrush;
}

// Overloaded SetPos function
// Pre-Conditions - a QPoint
// Post-conditions - NONE
void Shape::SetPos(const QPoint thatPos)
{
    shapePos = thatPos;
}

void Shape::Move(int xCoord, int yCoord)
{
    QPoint pos;
    pos.setX(xCoord);
    pos.setY(yCoord);
    this->SetPos(pos);
}

// Our sweet sweet lil protected guy
// Pre-conditions - NONE
// Post-Conditions - Returns a reference to a QPainter Object
QPainter* Shape::getPainter()
{
    return painter;
}


