#include "ellipse.h"
#define _USE_MATH_DEFINES

#include <cmath>

// Constructor
Ellipse::Ellipse(QPaintDevice* device, int anID,
                 ShapeType shapeType, int a, int b)
    : Shape{device, anID, shapeType}, a{a}, b{b}
{

}

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

    QPoint offsetPos;
    if(GetPos().x() > GetPos().y())
    {
        offsetPos.setX(GetPos().x() - a );
        offsetPos.setY(GetPos().y() - b );
    }
    else
    {
        if(GetPos().x() < GetPos().y())
        {
            offsetPos.setX(GetPos().x() - b );
            offsetPos.setY(GetPos().y() - a );
        }
        else
        {
            offsetPos.setX(GetPos().x() - a );
            offsetPos.setY(GetPos().y() - a );
        }
    }

    painter->drawText(offsetPos, QString::number(GetID()));

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

//Print
void Ellipse::Print(QTextStream &fout)
{
    vector<QString>  dimensions;
    QString shapeName;
    if(a == b)
    {
        shapeName = "Circle";
    }
    else
    {
        shapeName = "Ellipse";
    }

    QString colorName;
    QString style;

    dimensions.resize(4);
    dimensions[0] = QString::number(GetPos().x()) + ", ";
    dimensions[1] = QString::number(GetPos().y()) + ", ";

    dimensions[2] = QString::number(getA()) + ", ";
    dimensions[3] = QString::number(getB());

    // Print Text to File
    fout << "\nShapeId: "   << GetID();
    fout << "\nShapeType: " << shapeName;
    fout << "\nShapeDimensions: ";

    // Print Position, A, B
    for(int i = 0; i <= dimensions.size(); i++)
    {
        fout << dimensions[i] << ", ";
    }

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
/*************************************************************/
