#include "textparser.h"

const QMap<ShapeNames, QString> shapeMap = {
    {ShapeNames::LINE, "Line"},
    {ShapeNames::POLYLINE, "Polyline"},
    {ShapeNames::POLYGON, "Polygon"},
    {ShapeNames::RECTANGLE, "Rectangle"},
    {ShapeNames::ELLIPSE, "Ellipse"},
    {ShapeNames::CIRCLE, "Circle"},
    {ShapeNames::TEXT, "Text"}

};

vector<Shape*> TextParser::ReadFile(QString fileName)
{
    vector<Shape*> v_Shapes;

    QString fullPath = QDir::currentPath().split("CS1C_2D_Graphics_Modeler").at(0) + "CS1C_2D_Graphics_Modeler/QTPROJECT/" + fileName;

    qInfo() << fullPath << '\n';

    QFile file{fullPath};

    // Check if Read Permissions & if it's a text file
    // if not, we need to throw an exception with an error msg
    // source: https://www.youtube.com/watch?v=Y1bhgsGZZh8
    if(!file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        QMessageBox::information(0, "file error", file.errorString());

        return v_Shapes; // BUG??
    }
    else
    {
        qInfo() << "ReadFile was successful\n";
    }

    QTextStream fin{&file};

    while(!(fin.atEnd()))
    {
//        Shape* shape = nullptr;

        // QTextStream fcn "readLine() simplifies the reading process
        fin.readLine();

        // Every shape contains an id, a name, and dimensions
        int id = fin.readLine().remove(0, 9).toInt();
        QString typeShape = fin.readLine().remove(0, 11);

        ShapeNames type = shapeMap.key(typeShape);

        switch(type)
        {
            case LINE 		: v_Shapes.push_back(ReadLine(fin, id));
            break;

            case POLYLINE 	: v_Shapes.push_back(ReadPolyline(fin, id));
            break;

            case POLYGON 	: v_Shapes.push_back(ReadPolygon(fin, id));
            break;

            case RECTANGLE 	: v_Shapes.push_back(ReadRectangle(fin, id));
            break;

            case SQUARE		: v_Shapes.push_back(ReadSquare(fin, id));
            break;

            case ELLIPSE 	: v_Shapes.push_back(ReadEllipse(fin, id));
            break;

            case CIRCLE		: v_Shapes.push_back(ReadCircle(fin, id));

            case TEXT 		: v_Shapes.push_back(ReadText(fin, id));
            break;

        }


    }

    qInfo("\nSuccessfully Loaded Vector\n");
    file.close();
    return v_Shapes;
}

Shape* TextParser::ReadLine(QTextStream &fin, int id)
{
    QList<int> points;
    QColor  color;
    int     width;
    Qt::PenStyle penStyle;
    Qt::PenCapStyle capStyle;
    Qt::PenJoinStyle joinStyle;

    // Get all the points for line or polyline
    foreach(QString text, fin.readLine().remove(0, 17).split(", ")) points.append(text.toInt());

    // Now create a QPoint variable
    QPoint front(points[0], points[1]);
    QPoint end(points[2], points[3]);

    // Get color
    color = fin.readLine().remove(0, 10);

    // Get width
    width = fin.readLine().remove(0, 10).toInt();

    // Get Styles
    penStyle = GetPenStyle(fin.readLine().remove(0, 10));
    capStyle = GetCapStyle(fin.readLine().remove(0, 13));
    joinStyle = GetPenJoinStyle(fin.readLine().remove(0, 14));

    Line* line = new Line(id, front, end);
    line->SetPen(color, width, penStyle, capStyle, joinStyle);

    // Note - Line has no Brush, so we can get by with just QColor & no setBrush fcn

    return line;
}


Shape* TextParser::ReadPolyline(QTextStream &fin, int id)
{
    QList<int> points;
    QList<QPoint> pointList;
    QColor  color;
    int     width;
    Qt::PenStyle penStyle;
    Qt::PenCapStyle capStyle;
    Qt::PenJoinStyle joinStyle;

    // Get all the points for line or polyline
    foreach(QString text, fin.readLine().remove(0, 17).split(", ")) points.append(text.toInt());

    // Now create a QPoint variable for each coordinate pair
    bool invalid = true;
    int i = 0;
    int size = points.size();

    do  // while(invalid)
    {
        if(i < size)
        {
            QPoint tempPoint;
            tempPoint.setX(points[i]);
            tempPoint.setY(points[i + 1]);

            pointList.push_back(tempPoint);

            i += 2;
        }
        else
        {
            invalid = false;
        }

    }while(invalid);

    // Get color
    color = fin.readLine().remove(0, 10);

    // Get width
    width = fin.readLine().remove(0, 10).toInt();

    // Get Styles
    penStyle = GetPenStyle(fin.readLine().remove(0, 10));
    capStyle = GetCapStyle(fin.readLine().remove(0, 13));
    joinStyle = GetPenJoinStyle(fin.readLine().remove(0, 14));

    Polyline* polyline = new Polyline(id, pointList);
    polyline->SetPen(color, width, penStyle, capStyle, joinStyle);

    // Note - Polyline has no Brush, so we can get by with just QColor & no setBrush fcn

    return polyline;
}

Shape* TextParser::ReadPolygon(QTextStream &fin, int id)
{
    QList<int> points;
    QList<QPoint>* pointList;
    QColor  color;
    int     width;
    Qt::PenStyle penStyle;
    Qt::PenCapStyle capStyle;
    Qt::PenJoinStyle joinStyle;

    // Get all the points for polygon
    foreach(QString text, fin.readLine().remove(0, 17).split(", ")) points.append(text.toInt());

    // Now create a QPoint variable for each coordinate pair
    bool invalid = true;
    int i = 0;
    int size = points.size();

    do  // while(invalid)
    {
        if(i < size)
        {
            QPoint tempPoint;
            tempPoint.setX(points[i]);
            tempPoint.setY(points[i + 1]);

            pointList->push_back(tempPoint);

            i += 2;
        }
        else
        {
            invalid = false;
        }

    }while(invalid);

    // Get color
    color = fin.readLine().remove(0, 10);

    // Get width
    width = fin.readLine().remove(0, 10).toInt();

    // Get Styles
    penStyle = GetPenStyle(fin.readLine().remove(0, 10));
    capStyle = GetCapStyle(fin.readLine().remove(0, 13));
    joinStyle = GetPenJoinStyle(fin.readLine().remove(0, 14));

    // Brush Properties
    QColor brushColor = fin.readLine().remove(0, 12);
    QString brushStyle = fin.readLine().remove(0, 12);

    Polygon* polygon = new Polygon(id, pointList);
    polygon->SetPen(color, width, penStyle, capStyle, joinStyle);
    polygon->SetBrush(brushColor, GetBrushStyle(brushStyle));

    return polygon;
}
Shape* TextParser::ReadRectangle(QTextStream &fin, int id)
{
    QList<int> points;
    QColor  color;
    int l;
    int w;
    int     penWidth;
    Qt::PenStyle penStyle;
    Qt::PenCapStyle capStyle;
    Qt::PenJoinStyle joinStyle;

    // Get all the points for line or polyline
    foreach(QString text, fin.readLine().remove(0, 17).split(", ")) points.append(text.toInt());

    // Now create a QPoint variable
    QPoint pos(points[0], points[1]);
    l = points[3];
    w = points[4];

    // Get color
    color = fin.readLine().remove(0, 10);

    // Get width
    penWidth = fin.readLine().remove(0, 10).toInt();

    // Get Styles
    penStyle = GetPenStyle(fin.readLine().remove(0, 10));
    capStyle = GetCapStyle(fin.readLine().remove(0, 13));
    joinStyle = GetPenJoinStyle(fin.readLine().remove(0, 14));

    // Brush Properties
    QColor brushColor = fin.readLine().remove(0, 12);
    QString brushStyle = fin.readLine().remove(0, 12);

    Rectangle* rectangle = new Rectangle(id, pos, l, w);
    rectangle->SetPen(color, penWidth, penStyle, capStyle, joinStyle);
    rectangle->SetBrush(brushColor, GetBrushStyle(brushStyle));

    return rectangle;
}
Shape* TextParser::ReadSquare(QTextStream &fin, int id)
{
    QList<int> points;
    QColor  color;
    int l;
    int     penWidth;
    Qt::PenStyle penStyle;
    Qt::PenCapStyle capStyle;
    Qt::PenJoinStyle joinStyle;

    // Get all the points for line or polyline
    foreach(QString text, fin.readLine().remove(0, 17).split(", ")) points.append(text.toInt());

    // Now create a QPoint variable
    QPoint pos(points[0], points[1]);
    l = points[3];

    // Get color
    color = fin.readLine().remove(0, 10);

    // Get width
    penWidth = fin.readLine().remove(0, 10).toInt();

    // Get Styles
    penStyle = GetPenStyle(fin.readLine().remove(0, 10));
    capStyle = GetCapStyle(fin.readLine().remove(0, 13));
    joinStyle = GetPenJoinStyle(fin.readLine().remove(0, 14));

    // Brush Properties
    QColor brushColor = fin.readLine().remove(0, 12);
    QString brushStyle = fin.readLine().remove(0, 12);

    Rectangle* square = new Rectangle(id, pos, l, l);
    square->SetPen(color, penWidth, penStyle, capStyle, joinStyle);
    square->SetBrush(brushColor, GetBrushStyle(brushStyle));

    return square;
}
Shape* TextParser::ReadEllipse(QTextStream &fin, int id)
{
    QList<int> points;
    QColor  color;
    int a;      // major axis
    int b;      // minor axis
    int     penWidth;
    Qt::PenStyle penStyle;
    Qt::PenCapStyle capStyle;
    Qt::PenJoinStyle joinStyle;

    // Get all the points for ellipse or circle
    foreach(QString text, fin.readLine().remove(0, 17).split(", ")) points.append(text.toInt());

    // Now create a QPoint variable
    QPoint pos(points[0], points[1]);
    a = points[3];
    b = points[4];

    // Get color
    color = fin.readLine().remove(0, 10);

    // Get width
    penWidth = fin.readLine().remove(0, 10).toInt();

    // Get Styles
    penStyle = GetPenStyle(fin.readLine().remove(0, 10));
    capStyle = GetCapStyle(fin.readLine().remove(0, 13));
    joinStyle = GetPenJoinStyle(fin.readLine().remove(0, 14));

    // Brush Properties
    QColor brushColor = fin.readLine().remove(0, 12);
    QString brushStyle = fin.readLine().remove(0, 12);

    Ellipse* ellipse = new Ellipse(id, pos, a, b);
    ellipse->SetPen(color, penWidth, penStyle, capStyle, joinStyle);
    ellipse->SetBrush(brushColor, GetBrushStyle(brushStyle));

    return ellipse;
}
Shape* TextParser::ReadCircle(QTextStream &fin, int id)
{
    QList<int> points;
    QColor  color;
    int r;
    int     penWidth;
    Qt::PenStyle penStyle;
    Qt::PenCapStyle capStyle;
    Qt::PenJoinStyle joinStyle;

    // Get all the points for ellipse or circle
    foreach(QString text, fin.readLine().remove(0, 17).split(", ")) points.append(text.toInt());

    // Now create a QPoint variable
    QPoint pos(points[0], points[1]);
    r = points[3];

    // Get color
    color = fin.readLine().remove(0, 10);

    // Get width
    penWidth = fin.readLine().remove(0, 10).toInt();

    // Get Styles
    penStyle = GetPenStyle(fin.readLine().remove(0, 10));
    capStyle = GetCapStyle(fin.readLine().remove(0, 13));
    joinStyle = GetPenJoinStyle(fin.readLine().remove(0, 14));

    // Brush Properties
    QColor brushColor = fin.readLine().remove(0, 12);
    QString brushStyle = fin.readLine().remove(0, 12);

    Ellipse* circle = new Ellipse(id, pos, r, r);
    circle->SetPen(color, penWidth, penStyle, capStyle, joinStyle);
    circle->SetBrush(brushColor, GetBrushStyle(brushStyle));

    return circle;
}

Shape* ReadText(QTextStream &fin, int id)
{
    QString text;
    QColor  color;
    Qt::AlignmentFlag     alignment;
    int     textPointSize;
    QString fontFamily;
    QString fontStyle;
    QString fontWeight;
    QList<int> points;
    int l;
    int w;

    // 1) Get Dimensions
    // Get all the points
    foreach(QString text, fin.readLine().remove(0, 17).split(", ")) points.append(text.toInt());

    // Now create a QPoint variable
    QPoint pos(points[0], points[1]);
    l = points[3];
    w = points[4];

    // Get text string
    text  = fin.readLine().remove(0, 12);

    // Get color
    color = fin.readLine().remove(0, 11);

    // Get alignment
    alignment = GetAlignment(fin.readLine().remove(0, 15));

    // Get point size
    textPointSize = fin.readLine().remove(0, 15).toInt();

    // Get font properties
    fontFamily = fin.readLine().remove(0, 16);
    fontStyle = fin.readLine().remove(0, 15);
    fontWeight = fin.readLine().remove(0, 16);

    // no brush

    // make a new shape
    Text* textObj = new Text(id, TextParser::CreateFont(fontFamily, textPointSize, fontWeight, fontStyle),
                          color, pos, l, w, alignment);

    return textObj;
}

Qt::PenStyle TextParser::GetPenStyle(QString penStyle)
{
    Qt::PenStyle style;

    if(penStyle == "SolidLine")
    {
        style = Qt::PenStyle::SolidLine;
    }
    else
    {
        if(penStyle == "DashLine")
        {
            style = Qt::PenStyle::DashLine;
        }
        else
        {
            if(penStyle == "DotLine")
            {
                style = Qt::PenStyle::DotLine;
            }
            else
            {
                if(penStyle == "DashDotLine")
                {
                    style = Qt::PenStyle::DashDotLine;
                }
                else
                {
                    if(penStyle == "DashDotDotLine")
                    {
                        style = Qt::PenStyle::DashDotDotLine;
                    }
                    else
                    {
                        style = Qt::PenStyle::NoPen;
                    }   // no pen
                }       // dash dot dot
            }           // dash dot
        }               // dot
    }                   // dash

    return style;
}

Qt::PenCapStyle TextParser::GetCapStyle(QString penCap)
{
    Qt::PenCapStyle style;

    if(penCap == "FlatCap")
    {
        style = Qt::PenCapStyle::FlatCap;
    }
    else
    {
        if(penCap == "SquareCap")
        {
            style = Qt::PenCapStyle::SquareCap;
        }
        else
        {
            if(penCap == "RoundCap")
            {
                style = Qt::PenCapStyle::RoundCap;
            }
        }
    }

    return style;

}

Qt::PenJoinStyle TextParser::GetPenJoinStyle(QString penJoin)
{
    Qt::PenJoinStyle style;

    if(penJoin == "MiterJoin")
    {
        style = Qt::PenJoinStyle::MiterJoin;
    }
    else
    {
        if(penJoin == "BevelJoin")
        {
            style = Qt::PenJoinStyle::BevelJoin;
        }
        else
        {
            style = Qt::PenJoinStyle::RoundJoin;
        }
    }

    return style;
}

Qt::BrushStyle TextParser::GetBrushStyle(QString brushStyle)
{
    Qt::BrushStyle style;

    if (brushStyle == "SolidPattern")
        style = Qt::BrushStyle::SolidPattern;
    else if (brushStyle == "Dense1Pattern")
        style = Qt::BrushStyle::Dense1Pattern;
    else if (brushStyle == "Dense2Pattern")
        style = Qt::BrushStyle::Dense2Pattern;
    else if (brushStyle == "Dense3Pattern")
        style = Qt::BrushStyle::Dense3Pattern;
    else if (brushStyle == "Dense4Pattern")
        style = Qt::BrushStyle::Dense4Pattern;
    else if (brushStyle == "Dense5Pattern")
        style = Qt::BrushStyle::Dense5Pattern;
    else if (brushStyle == "Dense6Pattern")
        style = Qt::BrushStyle::Dense6Pattern;
    else if (brushStyle == "Dense7Pattern")
       style = Qt::BrushStyle::Dense7Pattern;
    else if (brushStyle == "HorPattern")
        style = Qt::BrushStyle::HorPattern;
    else if (brushStyle == "VerPattern")
       style = Qt::BrushStyle::VerPattern;
    else if (brushStyle == "CrossPattern")
        style = Qt::BrushStyle::CrossPattern;
    else if (brushStyle == "BDiagPattern")
       style = Qt::BrushStyle::BDiagPattern;
    else if (brushStyle == "FDiagPattern")
        style = Qt::BrushStyle::FDiagPattern;
    else if (brushStyle == "DiagCrossPattern")
       style = Qt::BrushStyle::DiagCrossPattern;
    else if (brushStyle == "LinearGradientPattern")
        style = Qt::BrushStyle::LinearGradientPattern;
    else if (brushStyle == "ConicalGradientPattern")
        style = Qt::BrushStyle::ConicalGradientPattern;
    else if (brushStyle == "RadialGradientPattern")
        style = Qt::BrushStyle::RadialGradientPattern;
    else if (brushStyle == "TexturePattern")
        style = Qt::BrushStyle::TexturePattern;
    else style = Qt::BrushStyle::NoBrush;

    return style;
}

QFont TextParser::CreateFont(QString fam, int size, QString weight, QString style)
{
    QFont font{fam, size};

    // Weight
    if(weight == "Thin")
    {
        font.setWeight(QFont::Weight::Thin);
    }
    else
    {
        if(weight == "Light")
        {
            font.setWeight(QFont::Weight::Light);
        }
        else
        {
            if(weight == "Normal")
            {
                font.setWeight(QFont::Weight::Normal);
            }
            else
            {
                font.setWeight(QFont::Weight::Bold);
            }
        }
    }

    // Style
    if(style == "StyleItalic")
    {
        font.setStyle(QFont::Style::StyleItalic);
    }
    else
    {
        if(style == "StyleOblique")
        {
            font.setStyle(QFont::Style::StyleOblique);
        }
        else
        {
            font.setStyle(QFont::Style::StyleNormal);
        }
    }



    return font;
}

Qt::AlignmentFlag TextParser::GetAlignment(QString align)
{
    if(align == "AlignLeft")
    {
        return Qt::AlignLeft;
    }
    else
    {
        if(align == "AlignRight")
        {
            return Qt::AlignRight;
        }
        else
        {
            if(align == "AlignTop")
            {
                return Qt::AlignTop;
            }
            else
            {
                if(align == "AlignBottom")
                {
                    return Qt::AlignBottom;
                }
                else
                {
                    return Qt::AlignCenter;
                }
            }   // Bottom
        } // Top
    } // Right
} // Left
