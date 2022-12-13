#include "polygon.h"
#include <cmath>

Polygon::Polygon(QPaintDevice *device,
                 int anID,
                 ShapeType shapeType)
    : Shape{device, anID, shapeType},
      polyPoints{new QList<QPoint>}
{
    SetPen(Qt::SolidLine);
    SetBrush(Qt::black, Qt::BrushStyle::SolidPattern);
}

// Overloaded Ctor
Polygon::Polygon(int anID, QList<QPoint>* pointList)
{
    SetID(anID);
    polyPoints = std::move(pointList);
}

// Move Ctor
//Polygon::Polygon(Polygon&& otherPolygon) noexcept
//    : id{std::move(otherPolygon.id)},
//      polygName{std::move(otherPolygon.polygName)},
//      pen{std::move(otherPolygon.pen)},
//      brush{std::move(otherPolygon.brush)},
//      pos{std::move(otherPolygon.pos)},
//      polyPoints{std::move(otherPolygon.polyPoints)}
//{
//    SetID(std::move(otherPolygon.GetID()));
//    delete [] otherPolygon.polyPoints;
//}

// Overloaded == op
// Pre-conditions - Other shape must be there..
// Post-conditions - Returns a bool if they have the same id?
bool Polygon::operator==(const Polygon& otherPolygon)
{
    if(GetID() == otherPolygon.GetID())
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


/************ BEGIN ACCESSORS / GETTERS ************/

// GetID function
// Pre-Conditions - NONE
// Post-conditions - Returns the Shapes ID
//int Polygon::GetID() const
//{
//    return id;
//}

// GetPolygonType function
// Pre-Conditions - NONE
// Post-conditions - Returns the Polygons Type
//ShapeType Polygon::GetShapeType() const
//{
//    return polygName;
//}

// GetPen function
// Pre-Conditions - NONE
// Post-conditions - Returns the Shapes QPen
//QPen Polygon::GetPen() const
//{
//    return pen;
//}

// GetBrush function
// Pre-Conditions - NONE
// Post-conditions - Returns the Shapes QBrush
//QBrush Polygon::GetBrush() const
//{
//    return brush;
//}

// GetPosition function
// Pre-Conditions - NONE
// Post-conditions - Returns QPoint of shapes position
//QPoint Polygon::GetPos() const
//{
//    return pos;
//}

// GetPoints function
// Pre-Conditions - NONE
// Post-Conditions - Returns a QList of QPoint s
//QList<QPoint>* Polygon::GetPoints() const
//{
//    return polyPoints;
//}

/************ BEGIN MUTATORS / SETTERS **************/

// SetID function
// Pre-Conditions - int id
// Post-conditions - NONE
//void Polygon::SetID(const int theID)
//{
//    id = theID;
//}

// SetShapeType function
// Pre-Conditions - shapetype type
// Post-conditions - NONE
//void Polygon::SetShapeType(const ShapeType type)
//{
//    polygName = type;
//}

// SetPen function
// Pre-Conditions - relevant properties of a QPen
// Post-conditions - NONE
//void Polygon::SetPen(const QColor aColor, const int size,
//                   const Qt::PenStyle penStyle,
//                   const Qt::PenCapStyle capStyle,
//                   const Qt::PenJoinStyle joinStyle)
//{
//    pen.setColor(aColor);
//    pen.setWidth(size);
//    pen.setStyle(penStyle);
//    pen.setCapStyle(capStyle);
//    pen.setJoinStyle(joinStyle);
//}

// Overloaded SetPen function
// Pre-Conditions - a QPen
// Post-conditions - NONE
//void Polygon::SetPen(const QPen thatPen)
//{
//    pen = thatPen;
//}

// Overloaded SetBrush function
// Pre-Conditions - a QBrush
// Post-conditions - NONE
//void Polygon::SetBrush(const QColor aColor,
//                     const Qt::BrushStyle brushStyle)
//{
//    brush.setColor(aColor);
//    brush.setStyle(brushStyle);
//}

//// Overloaded SetPos function
//// Pre-Conditions - a QPoint
//// Post-conditions - NONE
//void Polygon::SetPos(const QPoint thatPos)
//{
//    pos = thatPos;
//}

// SetPoints function uses QList move assignment
// Pre-Conditions - A QList of QPoint variables
// Post-Conditions - Sets new points for the Polygon
void Polygon::SetPoints(QList<QPoint> points)
{
    for(int i = 0; i < points.size(); i++)
    {
        polyPoints->push_back(points[i]);
    }
}

// Draw Function for Polygon
// Pre-conditions - QPaintClass pointer
// Post-Conditions - Draws a Polygon
void Polygon::Draw(QPainter* painter)
{
    // QPainter doesn't like this list, and wants an array
    QPoint pointList[GetPointCount()];
    for(int i = 0; i < GetPointCount(); i++)
    {
        pointList[i] = (*polyPoints)[i];
    }

    painter->setBrush(GetBrush());
    painter->setPen(GetPen());
    painter->drawPolygon(pointList, GetPointCount());

    painter->drawText(pointList[0], QString::number(GetID()));
}

// Move Function for Polygon should use SetPoints?
//void Polygon::Move(int xCoord, int yCoord)
//{
//    QPoint qPos;
//    qPos.setX(xCoord);
//    qPos.setY(yCoord);

//    polyPoints->replace(0, qPos);
//}

// Calc Perimeter Function
// Pre-Conditions - NONE
// Post-Conditions - returns a double of perimeter of polygon
double Polygon::CalcPerimeter() const
{
    //use distance formula
    double distance;
    double perimeter = 0;   // init for += use

    for(int i = 0; i < polyPoints->size(); i++)
    {
        // d = sqrt((x2 - x1)^2 + (y2 - y1)^2)

        // When we are not at the last point
        if(i < polyPoints->size() - 1)
        {
            distance = sqrt(pow(polyPoints->at(i+1).y() - polyPoints->at(i).y(), 2) +
                            pow(polyPoints->at(i+1).x() - polyPoints->at(i).x(), 2));
        }
        else    // we are at the last point (connect to first
        {
            distance = sqrt(pow(polyPoints->first().y() - polyPoints->at(i).y(), 2) +
                            pow(polyPoints->first().x() - polyPoints->at(i).x(), 2));
        }

        perimeter += distance;
    }

    return perimeter;
}

// Calc Area Function
// Pre-Condition - NONE
// Post-Condition - Returns double for polygon area
double Polygon::CalcArea() const
{
    // Source -- Shoelace Formula
    // https://tinyurl.com/mvfjt3np (Wikipedia)

    double area = 0;
    int sizeCopy = GetPointCount() - 1;

    for(int i = 0; i < GetPointCount(); i++)
    {
        area += ((polyPoints->at(sizeCopy).x() + polyPoints->at(i).x()) *
                 (polyPoints->at(sizeCopy).y() + polyPoints->at(i).y()));

        sizeCopy = i;
    }

    area = abs(area / 2.0);

    return area;

}

void Polygon::Print(QTextStream &fout)
{
    vector<QString>  dimensions;
    QString shapeName = "Polygon";
    QString colorName;
    QString style;

    for(int i = 0; i < polyPoints->size(); i++)
    {
        dimensions.push_back(QString::number((*polyPoints)[i].x()));
        dimensions.push_back(QString::number((*polyPoints)[i].y()));
    }


    // Print Text to File
    fout << "\nShapeId: "   << GetID();
    fout << "\nShapeType: " << shapeName;
    fout << "\nShapeDimensions: ";

    // Print point 1 & 2
    for(int i = 0; i < dimensions.size() - 1; i++)
    {
        fout << dimensions[i] << ", ";
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
