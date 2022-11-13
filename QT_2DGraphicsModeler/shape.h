#ifndef SHAPE_H
#define SHAPE_H


// Definition of Shape class
#include <Qt>
#include <QPainter>
#include "vector.h"

class Shape
{
  public :
  enum class ShapeType
  {
    NoShape, Line, Polyline, Polygon, Rectangle,
    Ellipse, Text
  };

  // Constructor
  Shape(QPaintDevice* device = nullptr,
        int id = -1, ShapeType shape = ShapeType::NoShape);
  virtual ~Shape() {}

    // Copy Operations (delete them)
    Shape(const Shape& source) = delete;
    Shape& operator=(const Shape& source) = delete;

    virtual void Draw() = 0;
    virtual void Move() = 0;
    virtual const double CalcPerimeter() = 0;
    virtual const double CalcArea() = 0;

  protected :
  QPainter& get_qpainter();

  private :
  QPainter* p_qpainter;
  int id;
  ShapeType shapeName;
  //Need to work on shape dimensions with vector
  Qt::GlobalColor  penColor;
  int			 	 penWidth;
  Qt::PenStyle	 penStyle;
  Qt::PenCapStyle  penCapStyle;
  Qt::PenJoinStyle penJoinStyle;
    Qt::GlobalColor  brushColor;
    Qt::BrushStyle	 brushStyle;
};


#endif // SHAPE_H
