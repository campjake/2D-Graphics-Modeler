// Class definition of Line

// Class definition of the Polygon

#include "Shape.h"

class Polyline : virtual public Shape
{
    public :
    // Polyline(QPaintDevice* device = nullptr, int id = -1) : Shape{}...

    void SetPoint(const QPoint& point);


    virtual const double CalcPerimeter(); 

    private :
    // vector<QPoint> points; from lecture
};