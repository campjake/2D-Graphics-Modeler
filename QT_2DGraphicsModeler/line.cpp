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


    painter->drawText(point1,  QString::number(GetID()));

}

//Moves first point
//void Line::Move(int xCoord, int yCoord)
//{
//    point1.setX(xCoord);
//    point1.setY(yCoord);
//}

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
//void Line::moveOffset(int offsetX, int offsetY)
//{
//    point1.setX(point1.x() + offsetX);
//    point1.setY(point1.y() + offsetY);

//    point2.setX(point2.x() + offsetX);
//    point2.setY(point2.y() + offsetY);
//}

//sets both ends of line
void Line::setPoints(const QPoint& P1, const QPoint& P2)
{
    point1 = P1;
    point2 = P2;

    SetPos(point1);
}

//sets point 1
void Line::setPoint1(const QPoint& P1) {
    point1 = P1;
    SetPos(P1);
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

void Line::Print(QTextStream &fout)
{
    vector<QString>  dimensions;
    QString shapeName = "Line";
    QString colorName;
    QString style;

    dimensions.resize(4);
    dimensions[0] = QString::number(getPoint1().x()) + ", ";
    dimensions[1] = QString::number(getPoint1().y()) + ", ";

    dimensions[2] = QString::number(getPoint2().x()) + ", ";
    dimensions[3] = QString::number(getPoint2().y());

    // Print Text to File
    fout << "\nShapeId: "   << GetID();
    fout << "\nShapeType: " << shapeName;
    fout << "\nShapeDimensions: ";

    // Print point 1 & 2
    for(int i = 0; i < dimensions.size(); i++)
    {
        fout << dimensions[i];
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
}
