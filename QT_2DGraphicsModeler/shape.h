#ifndef SHAPE_H
#define SHAPE_H


// Definition of Shape class
#include <Qt>
#include <QPainter>
#include <QPaintDevice>
#include <QPoint>
#include "vector.h"
#include <QTextStream>


// GLOBAL QPAINTER VAR. -- ALL FILES THAT DRAW NEED THIS
//QPainter qpainter;



enum class ShapeType
{
  NoShape, Line, Polyline, Polygon, Rectangle,
  Square, Ellipse, Circle, Text
};

class Shape
{
  public :

    // Constructor
    Shape(QPaintDevice* device = nullptr,
          int anID = -1,
          ShapeType shapeType = ShapeType::NoShape);

    // Destructor
    virtual ~Shape(){delete painter;}

    // Copy Operations (delete them)
    Shape(const Shape& source) = delete;
    Shape& operator=(const Shape& source) = delete;


    // COME BACK AND FIGURE OUT IMPLEMENTATION

//    // Move Operations
//        // Move Ctor
    Shape(Shape&& otherShape) noexcept;

//        // Move Assignment
    Shape& operator=(Shape&& otherShape) noexcept;

    /******************* Overloaded Compare Operators *********************/
    // Equality operator
    bool operator==(const Shape& otherShape);
    bool operator<(const Shape& otherShape);
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

    void Move(int xCoord, int yCoord);

    /******************* Pure Virtual Fcns **************************/
    // Draw function
    virtual void Draw(QPainter* painter) = 0;

    // Move function
//    virtual void Move(int xCoord, int yCoord) = 0;

    // CalcPerimeter
    virtual double CalcPerimeter() const = 0;

    // CalcArea
    virtual double CalcArea() const = 0;

    virtual void Print(QTextStream &fout) = 0;
    /*************************************************************/



  protected : //static
  QPainter* getPainter();

  private :
    QPainter*    painter;
    int   id;
    ShapeType   shapeName;
    QPen        shapePen;
    QBrush      shapeBrush;
    QPoint      shapePos;
//    static int  count;      // helps set unique ID

};


// Equality Comparable Operators

// compare by id
// returns true if lhs shape ID < rhs shape ID
struct Cmp_by_id
{
    bool operator()(const Shape* s1, const Shape* s2) const
    {
        return s1->GetID() < s2->GetID();
    }
};

// compare by perimeter
// returns true if lhs shape perimeter < rhs shape perimeter
struct Cmp_by_perimeter
{
    bool operator()(const Shape* s1, const Shape* s2) const
    {
        return s1->CalcPerimeter() < s2->CalcPerimeter();
    }
};

// compare by area
// returns true if lhs shape area < rhs shape area
struct Cmp_by_area {
    bool operator()(const Shape* s1, const Shape* s2) const
    {
        return s1->CalcArea() < s2->CalcArea();
    }
};


#endif // SHAPE_H
