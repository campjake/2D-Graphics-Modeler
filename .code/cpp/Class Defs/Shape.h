// Definition of Shape class
class Shape
{
    enum ShapeType
    {
        
    };
    public :


    virtual const double CalcPerimeter() = 0;

    private :
    // QPainter* p_qpainter;   // use composition
    int id;
    ShapeType shapeName;

};