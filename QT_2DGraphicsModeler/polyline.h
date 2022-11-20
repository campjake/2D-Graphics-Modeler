#ifndef POLYLINE_H
#define POLYLINE_H

#include "vector.h"
#include "shape.h"

class Polyline : public Shape
{
public:
    Polyline();
    //constructor without Pen or Brush
    Polyline(QPaintDevice* device = nullptr, int anID = -1, ShapeType shapeType = ShapeType::Polyline);

    //constructor with pen and brush
    Polyline(QPaintDevice* device = nullptr, int anID = -1, ShapeType shapeType = ShapeType::Polyline,
        QPen thatPen = Qt::SolidLine, QBrush thatBrush = Qt::NoBrush);

    virtual ~Polyline() {}

    //Copy functions
    Polyline(const Polyline& source) = delete;
    Polyline& operator = (const Polyline& source) = delete;

    //Abstract functions from base
    void Draw(QPainter* painter);

    //Moves first point
    void Move(int xCoord, int yCoord);

    //calculates line length
    double CalcPerimeter();

    //calculates area
    double CalcArea();

    //Operators

    bool operator == (const Polyline& other);

    bool operator < (const Polyline& other);

    //Class specific functions

    //adds point to QList
    void addPoint(const QPoint& point);

    void SetPoints(QList<QPoint>* points);

    //Moves all points by an offset in x and y
    void moveOffset(int xOffset, int yOffset);

    //deletes a specific point
    void deletePoint(const QPoint& point);


private:
    QList<QPoint>* LinePoints;
};

#endif // POLYLINE_H

