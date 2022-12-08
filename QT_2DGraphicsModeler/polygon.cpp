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
}

// Move Function for Polygon should use SetPoints?
void Polygon::Move(int xCoord, int yCoord)
{
    QPoint qPos;
    qPos.setX(xCoord);
    qPos.setY(yCoord);

    polyPoints->replace(0, qPos);
}

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
