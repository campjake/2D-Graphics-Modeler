#ifndef POLYLINE_H
#define POLYLINE_H

#include "shape.h"

class Polyline : public Shape
{
public:
    Polyline();
    //constructor without Pen or Brush
    Polyline(QPaintDevice* device = nullptr, int anID = -1, ShapeType shapeType = ShapeType::Polyline);

    //constructor with pen and brush
    Polyline(QPaintDevice* device = nullptr, int anID = -1, ShapeType shapeType = ShapeType::Polyline,
        QPen thatPen = Qt::SolidLine);

    // Parser Constructor
    Polyline(int anID, QList<QPoint> list);

    virtual ~Polyline() {}

    //Copy functions
    Polyline(const Polyline& source) = delete;
    Polyline& operator = (const Polyline& source) = delete;

    //Abstract functions from base
    void Draw(QPainter* painter);

    //Moves first point
    void Move(int xCoord, int yCoord);

    //calculates line length
    double CalcPerimeter() const;

    //calculates area
    double CalcArea() const;

    //Operators

    bool operator == (const Polyline& other);

    bool operator < (const Polyline& other);

    //Class specific functions

    //adds point to QList
    void addPoint(const QPoint& point);

    void SetPoints(QList<QPoint> points);

    //Moves all points by an offset in x and y
    void moveOffset(int xOffset, int yOffset);

    //deletes a specific point
    void deletePoint(const QPoint& point);

    int GetNumPoints() const
    {
        return LinePoints->size();
    }

    QList<QPoint>* GetLinePoints() const
    {
        return LinePoints;
    }


private:
    QList<QPoint>* LinePoints;
};

#endif // POLYLINE_H

