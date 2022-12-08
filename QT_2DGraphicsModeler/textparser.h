#ifndef FILEPARSER_H_
#define FILEPARSER_H_

#include <QFile>
#include <QFileDialog>
#include <QCoreApplication>
#include <QMessageBox>
#include <QDebug>
#include <QFont>
#include <QPen>
#include <QColor>
#include <QMap>
#include "vector.h"
//#include "shape.h"
#include "line.h"
#include "polyline.h"
#include "polygon.h"
#include "rectangle.h"
#include "ellipse.h"
#include "text.h"

enum ShapeNames
{
    LINE = 1,
    POLYLINE,
    POLYGON,
    RECTANGLE,
    SQUARE,
    ELLIPSE,
    CIRCLE,
    TEXT
};

// Parser is an abstract class, you should not be able to declare it
class TextParser
{
    public :
    TextParser()
        : count{0}
    {}
    ~TextParser()
    {
        for(int i = 0; i < count; i++)
        {
            delete v_Shapes[i];
        }
    }

    // Mutator - Read file
    // Pre-conditions  : QString file
    // Post-conditions : Reurns a vector of Shape pointer(s)
    vector<Shape*>* ReadFile(QString file = "shapes.txt",
                            QPaintDevice* device = nullptr);

//    private :
    // ReadFile requires several helper functions
    // Make private because they are only called within ReadFile

    Shape* ReadLine(QTextStream &fin, int id,
                    QPaintDevice* device);
    Shape* ReadPolyline(QTextStream &fin, int id,
                        QPaintDevice* device);
    Shape* ReadPolygon(QTextStream &fin, int id,
                       QPaintDevice* device);
    Shape* ReadRectangle(QTextStream &fin, int id,
                         QPaintDevice* device);
    Shape* ReadSquare(QTextStream &fin, int id,
                      QPaintDevice* device);
    Shape* ReadEllipse(QTextStream &fin, int id,
                       QPaintDevice* device);
    Shape* ReadCircle(QTextStream &fin, int id,
                      QPaintDevice* device);
    Shape* ReadText(QTextStream &fin, int id,
                    QPaintDevice* device);

    // Pen Properties

    // getPenStyle casts QString -> enum
    // Pre-conditions: Qstring variable
    // Post-conditions: Returns enum of a Pen Style
    Qt::PenStyle		GetPenStyle(QString penStyle);

    // getCapStyle casts QString -> enum
    // Pre-conditions: Qstring variable
    // Post-conditions: Returns enum of a Pen Cap Style
    Qt::PenCapStyle		GetCapStyle(QString penCap);

    // getPenJoinStyle casts QString -> enum
    // Pre-conditions: Qstring variable
    // Post-conditions: Returns enum of a Pen Join Style
    Qt::PenJoinStyle	GetPenJoinStyle(QString penJoin);

    // Brush Properties

    // getBrushStyle casts QString -> enum
    // Pre-conditions: Qstring variable
    // Post-conditions: Returns enum of a Brush Style
    Qt::BrushStyle		GetBrushStyle(QString brushStyle);

    // Text Properties

    // getBrushStyle casts QString -> enum
    // Pre-conditions: Elements required to construct a Font
    // Post-conditions: Returns QFont object
    QFont CreateFont(QString fam, int size, QString weight, QString style);

    // GetAlignment function
    // Pre-Conditions - Requires a QString
    // Post-Conditions - Returns an alignment flag
    Qt::AlignmentFlag GetAlignment(QString align);

//    virtual void foo() = 0;

private:
//    QPaintDevice* device;
    vector<Shape*> v_Shapes;
    int count;

};

#endif // FILEPARSER_H_
