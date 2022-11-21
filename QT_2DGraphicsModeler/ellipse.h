#ifndef ELLIPSE_H
#define ELLIPSE_H

#include "shape.h"
#define PI 3.14

// Class Definition of an Ellipse
class Ellipse : public Shape
{
    public :
    // Constructor
    Ellipse(QPaintDevice* device, int anID, ShapeType shapeType, float width, float height);

    // Destructor
    virtual ~Ellipse();

    // Copy Operations (delete them)
    Ellipse(const Ellipse& source) = delete;
    Ellipse& operator=(const Ellipse& source) = delete;


    float getWidth()const;

    float getHeight()const;

    void setWidth(const float width);

    void setHeight(const float height);

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
    float height;
};

#endif // ELLIPSE_H
