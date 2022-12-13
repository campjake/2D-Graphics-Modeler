#include "polyline.h"

Polyline::Polyline(QPaintDevice* device, int anID, ShapeType shapeType) : Shape(device, anID, shapeType)
{
    SetPen(Qt::SolidLine);
}

//constructor with pen and brush
Polyline::Polyline(QPaintDevice* device, int anID,
                   ShapeType shapeType, QPen thatPen)
    : Shape(device, anID, shapeType),
      LinePoints{new QList<QPoint>}
{
    SetPen(thatPen);

}

// Parser Constructor
Polyline::Polyline(int anID, QList<QPoint> list)
{
    this->SetID(anID);
    SetPoints(list);
}

//Abstract functions from base
void Polyline::Draw(QPainter* painter)
{
    // QPainter doesn't like this list, and wants an array
    int count = GetNumPoints();
    QPoint pointList[count];
    for(int i = 0; i < count; i++)
    {
        pointList[i] = (*LinePoints)[i];
    }

    painter->setPen(GetPen());
    painter->setBrush(GetBrush());
    painter->drawPolyline(pointList, count);

    painter->drawText(pointList[0], QString::number(GetID()));
}

//Moves first point
//void Polyline::Move(int xCoord, int yCoord)
//{
//    QPoint temp(xCoord, yCoord);
//    LinePoints->replace(0, temp);
//}

//calculates line length
double Polyline::CalcPerimeter() const
{
    double distance;
    double perimeter = 0;   // init for += use

    for (int i = 0; i < LinePoints->size(); i++)
    {
        // Until last point
        if (i < LinePoints->size() - 1)
        {
            distance = sqrt(pow(LinePoints->at(i + 1).y() - LinePoints->at(i).y(), 2) +
                pow(LinePoints->at(i + 1).x() - LinePoints->at(i).x(), 2));
        }
        else    // At last point so distance to nothing
        {
            distance = 0;
        }

        perimeter += distance;
    }

    return perimeter;
}

//calculates area
double Polyline::CalcArea() const
{
    //lines dont have area
    return 0;
}

//Operators

bool Polyline::operator == (const Polyline& other)
{
    if (GetID() == other.GetID())
        return true;
    else
        return false;
}

bool Polyline::operator < (const Polyline& other)
{
    if (GetID() < other.GetID())
        return true;
    else
        return false;
}

//Class specific functions

//adds point to QList
void Polyline::addPoint(const QPoint& point)
{
    LinePoints->push_back(point);
}

void Polyline::SetPoints(QList<QPoint> points)
{
    for(int i = 0; i < points.size(); i++)
    {
        LinePoints->push_back(points[i]);
    }
}

//Moves all points by an offset in x and y
//void Polyline::moveOffset(int xOffset, int yOffset)
//{
//    for (QList<QPoint>::iterator it = LinePoints->begin(); it != LinePoints->end(); ++it)
//    {
//        it->setX(it->x() + xOffset);
//        it->setY(it->y() + yOffset);
//    }
//}

//deletes a specific point
void Polyline::deletePoint(const QPoint& point)
{
    //searches for then deletes specific point
    LinePoints->erase(std::remove(LinePoints->begin(), LinePoints->end(), point), LinePoints->end());
}

void Polyline::Print(QTextStream &fout)
{
    vector<QString>  dimensions;
    QString shapeName = "Line";
    QString colorName;
    QString style;

    for(int i = 0; i < LinePoints->size(); i++)
    {
        dimensions.push_back(QString::number((*LinePoints)[i].x()));
        dimensions.push_back(QString::number((*LinePoints)[i].y()));
    }

    // Print Text to File
    fout << "\nShapeId: "   << GetID();
    fout << "\nShapeType: " << shapeName;
    fout << "\nShapeDimensions: ";

    // Print point 1 & 2
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

}
