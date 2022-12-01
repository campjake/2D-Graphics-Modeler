#include "polyline.h"

Polyline::Polyline(QPaintDevice* device, int anID, ShapeType shapeType) : Shape(device, anID, shapeType)
{
    SetPen(Qt::SolidLine);
}

//constructor with pen and brush
Polyline::Polyline(QPaintDevice* device, int anID,
                   ShapeType shapeType, QPen thatPen)
    : Shape(device, anID, shapeType)
{
    SetPen(thatPen);
}

// Parser Constructor
Polyline::Polyline(int anID, QList<QPoint>* list)
{
    this->SetID(anID);
    SetPoints(list);
}

//Abstract functions from base
void Polyline::Draw(QPainter* painter)
{
    painter->setPen(GetPen());
    painter->setBrush(GetBrush());
    painter->drawPolyline(LinePoints->begin(), LinePoints->count());
}

//Moves first point
void Polyline::Move(int xCoord, int yCoord)
{
    QPoint temp(xCoord, yCoord);
    LinePoints->replace(0, temp);
}

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

void Polyline::SetPoints(QList<QPoint>* points)
{
    LinePoints = std::move(points);
}

//Moves all points by an offset in x and y
void Polyline::moveOffset(int xOffset, int yOffset)
{
    for (QList<QPoint>::iterator it = LinePoints->begin(); it != LinePoints->end(); ++it)
    {
        it->setX(it->x() + xOffset);
        it->setY(it->y() + yOffset);
    }
}

//deletes a specific point
void Polyline::deletePoint(const QPoint& point)
{
    //searches for then deletes specific point
    LinePoints->erase(std::remove(LinePoints->begin(), LinePoints->end(), point), LinePoints->end());
}
