#ifndef SHAPE_H
#define SHAPE_H


// Definition of Shape class
#include <Qt>
#include <QPainter>
#include <QPaintDevice>
#include <QPoint>
#include "vector.h"


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
    virtual ~Shape(){}

    // Copy Operations (delete them)
    Shape(const Shape& source) = delete;
    Shape& operator=(const Shape& source) = delete;


    // COME BACK AND FIGURE OUT IMPLEMENTATION

////    // Move Operations
////        // Move Ctor
//    Shape(Shape&& otherShape) noexcept;

//        // Move Assignment
//    Shape& operator=(Shape&& otherShape) noexcept;

    /******************* Overloaded Compare Operators *********************/
    // Equality operator
    bool operator==(const Shape& otherShape);
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


    /******************* Pure Virtual Fcns **************************/
    // Draw function
    virtual void Draw(QPainter* painter) = 0;

    // Move function
    virtual void Move(int xCoord, int yCoord) = 0;

    // CalcPerimeter
    virtual double CalcPerimeter() const = 0;

    // CalcArea
    virtual double CalcArea() const = 0;
    /*************************************************************/

  protected : //static
  QPainter* getPainter();

  private :
    QPainter    painter;
    int   id;
    ShapeType   shapeName;
    QPen        shapePen;
    QBrush      shapeBrush;
    QPoint      shapePos;
//    static int  count;      // helps set unique ID

};


#endif // SHAPE_H
