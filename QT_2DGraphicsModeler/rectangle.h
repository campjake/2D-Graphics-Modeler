#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "shape.h"

class Rectangle : public Shape
{
public:
    // Constructor
    Rectangle(QPaintDevice* device, int anID, ShapeType shapeType, int width, int length);

    // Parser Constructor
    Rectangle(int anID, QPoint aPos, int l, int w);
    // Destructor
    virtual ~Rectangle();

    // Copy Operations (delete them)
    Rectangle(const Rectangle& source) = delete;
    Rectangle& operator=(const Rectangle& source) = delete;

    float getWidth()const;

    float getLength()const;

    void setWidth(const float width);

    void setLength(const float length);

    /******************* Pure Virtual Fcns **************************/
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
    int width;
    int length;
};

#endif // RECTANGLE_H
