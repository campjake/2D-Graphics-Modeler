#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "shape.h"

class Rectangle : public Shape
{
public:
    // Constructor
    Rectangle(QPaintDevice* device, int anID, ShapeType shapeType, float width, float length);

    // Destructor
    virtual ~Rectangle();

    // Copy Operations (delete them)
    Rectangle(const Rectangle& source) = delete;
    Rectangle& operator=(const Rectangle& source) = delete;


    // COME BACK AND FIGURE OUT IMPLEMENTATION

//    // Move Operations
//        // Move Ctor
//    Shape(Shape&& otherShape) noexcept;

//        // Move Assignment
//    Shape& operator=(Shape&& otherShape) noexcept;

    /******************* Overloaded Compare Operators *********************/
    // Equality operator
    bool operator==(const Rectangle& otherRectangle);
//    bool operator<(const Shape& otherShape);  DO WE NEED THIS?
    /********************************************************************/

    float getWidth()const;

    float getLength()const;

    void setWidth(const float width);

    void setLength(const float length);

    /******************* Pure Virtual Fcns **************************/
    // Draw function
    virtual void Draw(QPainter* painter);

    // Move function
    virtual void Move(QPoint pos);

    // CalcPerimeter
    virtual double CalcPerimeter();

    // CalcArea
    virtual double CalcArea();
    /*************************************************************/

  private :
    float width;
    float length;
};

#endif // RECTANGLE_H
