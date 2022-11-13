#ifndef POLYGON_H
#define POLYGON_H

#include "shape.h"

class Polygon : public Shape
{
public:
    Polygon();

    virtual const double CalcPerimeter();
};

#endif // POLYGON_H
