#ifndef POLYGON_H
#define POLYGON_H

#include "shape.h"

class Polygon : public Shape
{
public:
    Polygon(QPaintDevice* device = nullptr,
            int id = -1,
            ShapeType shapeType = ShapeType::Polygon);

    virtual ~Polygon() {}

    // Delete Copy Operations
    Polygon(const Polygon& source) = delete;
    Polygon& operator=(const Polygon& source) = delete;

    // COME BACK LATER AND FIGURE OUT THIS IMPLEMENTATION

//    // Move Operations
//    Polygon(Polygon&& otherPolygon) noexcept;
//    Polygon& operator=(Polygon&& otherPolygon) noexcept;

    /******************* Overloaded Compare Operators *********************/
    // Equality operator
    bool operator==(const Polygon& otherPolygon);
//    bool operator<(const Shape& otherShape);  DO WE NEED THIS?
    /********************************************************************/

    // ACCESSORS / GETTERS

    // Get Unique ID for Shape Object
    int GetID() const;

    // Get Shape Type (convert ShapeType to string in implementation)
    ShapeType GetShapeType() const;

    // Get Pen Properties
    QPen GetPen() const;

    // Get Brush Properties
    QBrush GetBrush() const;

    // Get Position on X, Y Plane
    QPoint GetPos() const;

    // Get List of Points of Polygon
    QList<QPoint>* GetPoints() const;

    int GetPointCount() const;

    // MUTATORS / SETTERS

    // Set Unique ID for Shape Object
    void SetID(const int theID);

    // Set Shape Type
    void SetShapeType(const ShapeType type);

    // Set Pen Properties
    void SetPen(const QColor color, const int size,
                const Qt::PenStyle penStyle,
                const Qt::PenCapStyle capStyle,
                const Qt::PenJoinStyle joinStyle);

    // Overloaded SetPen incase its already defined?
    void SetPen(const QPen thatPen);

    // Set Brush Properties
    void SetBrush(const QColor aColor, const Qt::BrushStyle brushStyle);

    // Overloaded Set Brush?
    void SetBrush(const QBrush thatBrush);

    // Set Position on X, Y Plane
    void SetPos(const QPoint thatPos);

    // Set QList of Points for Polygone Shape
    void SetPoints(QList<QPoint>* points);

    /******************* OVERRIDE Pure Virtual Fcns ********************/
    // Draw function
    virtual void Draw(QPainter* painter);

    // Move function
    virtual void Move(int xCoord, int yCoord);

    // CalcPerimeter
    virtual double CalcPerimeter() const;

    // CalcArea
    virtual double CalcArea() const;
    /*************************************************************/


private :

    QPainter qpainter;
    int id;
    ShapeType polygName = {ShapeType::Polygon};
    QPen pen;
    QBrush brush;
    QPoint pos;
    QList<QPoint>* polyPoints;

};

#endif // POLYGON_H
