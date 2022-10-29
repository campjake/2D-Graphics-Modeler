// Class definition of the Text class

#include "Shape.h"

class Text : virtual public Shape
{
    public :



    virtual const double CalcPerimeter(); // ? must be overriden in every derived class
};