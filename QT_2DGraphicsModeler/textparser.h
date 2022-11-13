#ifndef FILEPARSER_H_
#define FILEPARSER_H_

#include <Qt>
#include <QString>
#include <QFile>
#include <QFileDialog>
#include <QCoreApplication>
#include <QMessageBox>
#include <QDebug>
#include <QPoint>
#include <QFont>
#include <QPen>
#include <QColor>
#include <QMap>
#include "vector.h"
#include "shape.h"
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

    // Make it abstract by declaring a pure virtual dummy function
    virtual void foo() = 0;

    // Accept defaults of ctor, dtor, copy, move operations

    // Mutator - Read file
    // Pre-conditions  : QString file
    // Post-conditions : Reurns a vector of Shape pointer(s)
    projectStd::vector<Shape*> ReadFile(QString file = "shapes.txt");

    private :
    // ReadFile requires several helper functions
    // Make private because they are only called within ReadFile

    Shape* ReadLine(QTextStream &fin, int id);
    Shape* ReadPolyline(QTextStream &fin, int id);
    Shape* ReadPolygon(QTextStream &fin, int id);
    Shape* ReadRectangle(QTextStream &fin, int id);
    Shape* ReadSquare(QTextStream &fin, int id);
    Shape* ReadEllipse(QTextStream &fin, int id);
    Shape* ReadCircle(QTextStream &fin, int id);
    Shape* ReadText(QTextStream &fin, int id);

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
};

#endif // FILEPARSER_H_
