#include "rectangle.h"

Rectangle::Rectangle(QPaintDevice* device, int anID,
                     ShapeType shapeType, int width, int length)
    : Shape{device, anID, shapeType}, width{width}, length{length}
{
    SetPen(Qt::SolidLine);
    SetBrush(Qt::black, Qt::BrushStyle::SolidPattern);
}

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
//Rectangle::Rectangle(Rectangle&& otherRectangle) noexcept
//: Shape(Shape&& otherRectangle) noexcept
//{
//    width = std::move(otherRectangle.width);
//    length = std::move(otherRectangle.length);
//}

////// Move Assignment
////// Pre-Conditions - R-value casted other shape object
////// Post-Conditions - Returns a shape object
//Rectangle& Rectangle::operator=(Rectangle&& otherRectangle) noexcept
//{
//    *this = std::move(Shape(otherRectangle));
//    width = std::move(otherRectangle.width);
//    length = std::move(otherRectangle.length);

//    return *this;
//}

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
    painter->setBrush(GetBrush());
    painter->setPen(GetPen());
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

void Rectangle::Print(QTextStream &fout)
{
    vector<QString>  dimensions;
    QString shapeName;
    if(length == width)
    {
        shapeName = "Square";
    }
    else
    {
        shapeName = "Rectangle";
    }

    QString colorName;
    QString style;

    dimensions.resize(4);
    dimensions[0] = QString::number(GetPos().x()) + ", ";
    dimensions[1] = QString::number(GetPos().y()) + ", ";

    dimensions[2] = QString::number(getWidth()) + ", ";
    dimensions[3] = QString::number(getLength());

    // Print Text to File
    fout << "\nShapeId: "   << GetID();
    fout << "\nShapeType: " << shapeName;
    fout << "\nShapeDimensions: ";

    // Print Position, A, B
    for(int i = 0; i < dimensions.size() - 1; i++)
    {
        fout << dimensions[i];
    }

    fout << dimensions[dimensions.size() - 1];

    // Print Pen Color
    if(GetPen().color()  == QColor(Qt::red))
    {
        colorName = "red";
    }
    else if(GetPen().color() == QColor(Qt::green))
    {
        colorName = "green";

    }
    else if(GetPen().color() == QColor(Qt::blue))
    {
        colorName = "blue";
    }
    else if(GetPen().color() == QColor(Qt::yellow))
    {
        colorName = "yellow";
    }
    else if(GetPen().color() == QColor(Qt::cyan))
    {
        colorName = "cyan";
    }
    else if(GetPen().color() == QColor(Qt::magenta))
    {
        colorName = "magenta";
    }
    else if(GetPen().color() == QColor(Qt::white))
    {
        colorName = "white";
    }
    else if(GetPen().color() == QColor(Qt::black))
    {
        colorName = "black";
    }
    else if(GetPen().color() == QColor(Qt::gray))
    {
        colorName = "gray";
    }

    fout << "\nPenColor: " << colorName;

    // Print Pen Width
    fout << "\nPenWidth: " << GetPen().width();

    // Get Pen Style
    switch(GetPen().style())
      {
          case 0: style = "NoPen";
                  break;
          case 1: style = "SolidLine";
                  break;
          case 2: style = "DashLine";
                  break;
          case 3: style = "DotLine";
                  break;
          case 4: style = "DashDotLine";
                  break;
          case 5: style = "DashDotDotLine";
                  break;
          case 6: style = "CustomDashLine";
                  break;
          case 15: style = "MPenStyle";
      }

    fout << "\nPenStyle: " << style;

    //Handling PenCapStyle using enum values for capstyle
    switch(GetPen().capStyle())
    {
        case 0: style = "FlatCap";
                break;
        case 16: style = "SquareCap";
                 break;
        case 32: style = "RoundCap";
                 break;
        case 48: style = "MPenCapStyle";
    }

    fout << "\nPenCapStyle: " << style;

    // Pen Join Style
    switch(GetPen().joinStyle())
    {
        case 0: style = "MiterJoin";
                break;
        case 64: style = "BevelJoin";
                 break;
        case 128: style = "RoundJoin";
                  break;
        case 256: style = "SvgMiterJoin";
                  break;
        case 448: style = "MPenJoinStyle";
    }

    fout << "\nPenJoinStyle: " << style;

    // BRUSH DATA

    if(GetPen().color() == QColor(Qt::red))
    {
        colorName = "red";
    }
    else if(GetPen().color() == QColor(Qt::green))
    {
        colorName = "green";

    }
    else if(GetPen().color() == QColor(Qt::blue))
    {
        colorName = "blue";
    }
    else if(GetPen().color() == QColor(Qt::yellow))
    {
        colorName = "yellow";
    }
    else if(GetPen().color() == QColor(Qt::cyan))
    {
        colorName = "cyan";
    }
    else if(GetPen().color() == QColor(Qt::magenta))
    {
        colorName = "magenta";
    }
    else if(GetPen().color() == QColor(Qt::white))
    {
        colorName = "white";
    }
    else if(GetPen().color() == QColor(Qt::black))
    {
        colorName = "black";
    }
    else if(GetPen().color() == QColor(Qt::gray))
    {
        colorName = "gray";
    }
    fout << "BrushColor: "  << colorName;

    switch(GetBrush().style())
    {
        case 0: style = "NoBrush";
                break;
        case 1: style = "SolidPattern";
                break;
        case 2: style = "Dense1Pattern";
                  break;
        case 3: style = "Dense2Pattern";
                break;
        case 4: style = "Dense3Pattern";
                break;
        case 5: style = "Dense4Pattern";
                break;
        case 6: style = "Dense5Pattern";
                 break;
        case 7: style = "Dense6Pattern";
                 break;
        case 8: style = "Dense7Pattern";
                break;
        case 9: style = "HorPattern";
                break;
        case 10: style = "VerPattern";
                 break;
        case 11: style = "CrossPattern";
                 break;
        case 12: style = "BDiagPattern";
                 break;
        case 13: style = "FDiagPattern";
                 break;
        case 14: style = "DiagCrossPattern";
                 break;
        case 15: style = "LinearGradientPattern";
                 break;
        case 16: style = "RadialGradientPattern";
                 break;
        case 17: style = "ConicalGradientPattern";
                 break;
        case 24: style = "TexturePattern";
                 break;
    }

    fout << "\nBrushStyle: " << style;
}
