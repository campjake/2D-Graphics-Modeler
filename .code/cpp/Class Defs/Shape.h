// Definition of Shape class
#include <Qt>
#include <Qpainter>
#include <vector.h>

class Shape
{
    enum ShapeType
    {
    	Line, Polyline, Polygon, Rectangle,
    	Ellipse, Text
		//Square, //[rectangle, l=w]
		//Circle //[ellipse, a=b]
    };

    public :
    virtual void Draw() = 0;
    virtual void Move() = 0;
    virtual const double CalcPerimeter() = 0;
    virtual const double CalcArea() = 0;

    private :
    // QPainter* p_qpainter;   // use composition
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
