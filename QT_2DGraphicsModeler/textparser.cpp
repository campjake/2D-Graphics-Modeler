#include "textparser.h"


const QMap<ShapeNames, QString> shapeMap = {
    {ShapeNames::LINE, "Line"},
    {ShapeNames::POLYLINE, "Polyline"},
    {ShapeNames::POLYGON, "Polygon"},
    {ShapeNames::RECTANGLE, "Rectangle"},
    {ShapeNames::SQUARE, "Square"},
    {ShapeNames::ELLIPSE, "Ellipse"},
    {ShapeNames::CIRCLE, "Circle"},
    {ShapeNames::TEXT, "Text"}

};

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
            style = Qt::PenCapStyle::RoundCap;
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
}


vector<Shape*>* TextParser::ReadFile(QString fileName,
                                    QPaintDevice* device)
{
    QDir directory;

    QString fullPath = directory.absoluteFilePath(fileName);

    qInfo() << fullPath << '\n';

    QFile file{fullPath};

    // Check if Read Permissions & if it's a text file
    // if not, we need to throw an exception with an error msg
    // source: https://www.youtube.com/watch?v=Y1bhgsGZZh8
    if(!file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        QMessageBox::information(0, "file error", file.errorString());

        return &v_Shapes; // BUG??
    }
    else
    {
        qInfo() << "ReadFile was successful\n";
    }

    QTextStream fin{&file};

    while(!(fin.atEnd()))
    {
//        Shape* shape = nullptr;

        // QTextStream fcn "readLine()" simplifies the reading process
        fin.readLine();

        // Every shape contains an id, a name, and dimensions
        int id = fin.readLine().remove(0, 9).toInt();
        QString typeShape = fin.readLine().remove(0, 11);

        ShapeNames type = shapeMap.key(typeShape);

        switch(type)
        {
            case LINE 		:   qInfo() << "This is where you try to add a line\n";
                                v_Shapes.push_back(ReadLine(fin, id, device));
                                qInfo() << "You added a Line\n";
            break;

            case POLYLINE 	: v_Shapes.push_back(ReadPolyline(fin, id, device));
                                qInfo() << "You added a PolyLine\n";
            break;

            case POLYGON 	: v_Shapes.push_back(ReadPolygon(fin, id, device));
                                qInfo() << "You added a Polygon\n";
            break;

            case RECTANGLE 	: v_Shapes.push_back(ReadRectangle(fin, id, device));
                                qInfo() << "You added a Rect\n";
            break;

            case SQUARE		: v_Shapes.push_back(ReadSquare(fin, id, device));
                                qInfo() << "You added a Square\n";
            break;

            case ELLIPSE 	: v_Shapes.push_back(ReadEllipse(fin, id, device));
                                qInfo() << "You added an Ellipse\n";
            break;

            case CIRCLE		: v_Shapes.push_back(ReadCircle(fin, id, device));
                                qInfo() << "You added a Circle\n";
            break;

            case TEXT 		: v_Shapes.push_back(ReadText(fin, id, device));
                                qInfo() << "You added a TextBox\n";
            break;

        default :     return &v_Shapes;  // hmmm...

        }
        count++;

    }

    qInfo("\nSuccessfully Loaded Vector\n");
    file.close();
    return &v_Shapes;
}

Shape* TextParser::ReadLine(QTextStream &fin, int id,
                            QPaintDevice* device)
{
    QList<int> points;
    QString  col;
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
    col = fin.readLine().remove(0, 10);
    QColor color(col);

    // Get width
    width = fin.readLine().remove(0, 10).toInt();

    // Get Styles
    penStyle = GetPenStyle(fin.readLine().remove(0, 10));
    capStyle = GetCapStyle(fin.readLine().remove(0, 13));
    joinStyle = GetPenJoinStyle(fin.readLine().remove(0, 14));
    QPen pen(Qt::NoBrush, width, penStyle,
             capStyle, joinStyle);
//    qInfo() << "You are about to try to dynamically make a Line\n";

//    Line* line = new Line(id, front, end);
    Line* line = new Line(device, id,
                          ShapeType::Line, pen);
    line->setPoints(front, end);

    line->SetPen(color, width, penStyle, capStyle, joinStyle);

    // Note - Line has no Brush, so we can get by with just QColor & no setBrush fcn

    return line;
}


Shape* TextParser::ReadPolyline(QTextStream &fin, int id,
                                QPaintDevice* device)
{
    QList<int> points;
    QList<QPoint> pointList;
    QString col;
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
//    col = fin.readLine().remove(0, 10);
    col = (fin.readLine().remove(0, 10));
       QColor color( 0, 128, 0);

    // Get width
    width = fin.readLine().remove(0, 10).toInt();

    // Get Styles
    penStyle = GetPenStyle(fin.readLine().remove(0, 10));
    capStyle = GetCapStyle(fin.readLine().remove(0, 13));
    joinStyle = GetPenJoinStyle(fin.readLine().remove(0, 14));

    // Wish this had a more elegant implementation
    QPen pen;

    Polyline* polyline = new Polyline(device, id,
                                      ShapeType::Polyline,
                                      pen);
    polyline->SetPoints(pointList);
    polyline->SetPen(color, width, penStyle, capStyle, joinStyle);

    // Note - Polyline has no Brush, so we can get by with just QColor & no setBrush fcn
//    int numPoint = polyline->GetNumPoints();
    return polyline;
}

Shape* TextParser::ReadPolygon(QTextStream &fin, int id,
                               QPaintDevice* device)
{
    QList<int> points;
    QList<QPoint> pointList;
    QString  col;
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

            pointList.push_back(tempPoint);

            i += 2;
        }
        else
        {
            invalid = false;
        }

    }while(invalid);

    // Get color
    col = fin.readLine().remove(0, 10);
    QColor color(col);
    // Get width
    width = fin.readLine().remove(0, 10).toInt();

    // Get Styles
    penStyle = GetPenStyle(fin.readLine().remove(0, 10));
    capStyle = GetCapStyle(fin.readLine().remove(0, 13));
    joinStyle = GetPenJoinStyle(fin.readLine().remove(0, 14));

    // Brush Properties
    QColor brushColor = fin.readLine().remove(0, 12);
    QString brushStyle = fin.readLine().remove(0, 12);


    Polygon* polygon = new Polygon(device, id,
                                   ShapeType::Polygon);

    polygon->SetPoints(pointList);
    polygon->SetPen(color, width, penStyle, capStyle, joinStyle);
    polygon->SetBrush(brushColor, GetBrushStyle(brushStyle));

    return polygon;
}

Shape* TextParser::ReadRectangle(QTextStream &fin, int id,
                                 QPaintDevice* device)
{
    QList<int> points;
    QString  col;
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
    l = points[2];
    w = points[3];

    // Get color
    col = fin.readLine().remove(0, 10);
    QColor color(col);
    // Get width
    penWidth = fin.readLine().remove(0, 10).toInt();

    // Get Styles
    penStyle = GetPenStyle(fin.readLine().remove(0, 10));
    capStyle = GetCapStyle(fin.readLine().remove(0, 13));
    joinStyle = GetPenJoinStyle(fin.readLine().remove(0, 14));

    // Brush Properties
    QString brushCol = fin.readLine().remove(0, 12);
    QColor brushColor(brushCol);
    QString brushStyle = fin.readLine().remove(0, 12);

    Rectangle* rectangle = new Rectangle(device, id,
                                         ShapeType::Rectangle,
                                         w, l);
    rectangle->SetPos(pos);
    rectangle->SetPen(color, penWidth, penStyle, capStyle, joinStyle);
    rectangle->SetBrush(brushColor, GetBrushStyle(brushStyle));

    return rectangle;
}
Shape* TextParser::ReadSquare(QTextStream &fin, int id,
                              QPaintDevice* device)
{
    QList<int> points;
    QString  col;
    int l;
    int     penWidth;
    Qt::PenStyle penStyle;
    Qt::PenCapStyle capStyle;
    Qt::PenJoinStyle joinStyle;

    // Get all the points for line or polyline
    foreach(QString text, fin.readLine().remove(0, 17).split(", ")) points.append(text.toInt());

    // Now create a QPoint variable
    QPoint pos(points[0], points[1]);
    l = points[2];

    // Get color
    col = fin.readLine().remove(0, 10);
    QColor color(col);
    // Get width
    penWidth = fin.readLine().remove(0, 10).toInt();

    // Get Styles
    penStyle = GetPenStyle(fin.readLine().remove(0, 10));
    capStyle = GetCapStyle(fin.readLine().remove(0, 13));
    joinStyle = GetPenJoinStyle(fin.readLine().remove(0, 14));

    // Brush Properties
    QString brushCol = fin.readLine().remove(0, 12);
    QColor brushColor(brushCol);
    QString brushStyle = fin.readLine().remove(0, 12);

    Rectangle* square = new Rectangle(device, id,
                                      ShapeType::Rectangle,
                                      l, l);
    square->SetPos(pos);
    square->SetPen(color, penWidth, penStyle, capStyle, joinStyle);
    square->SetBrush(brushColor, GetBrushStyle(brushStyle));

    return square;
}
Shape* TextParser::ReadEllipse(QTextStream &fin, int id,
                               QPaintDevice* device)
{
    QList<int> points;
    QString  col;
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
    a = points[2];
    b = points[3];

    // Get color
    col = fin.readLine().remove(0, 10);
    QColor color(col);
    // Get width
    penWidth = fin.readLine().remove(0, 10).toInt();

    // Get Styles
    penStyle = GetPenStyle(fin.readLine().remove(0, 10));
    capStyle = GetCapStyle(fin.readLine().remove(0, 13));
    joinStyle = GetPenJoinStyle(fin.readLine().remove(0, 14));

    // Brush Properties
    QString brushCol   = fin.readLine().remove(0, 12);
    QColor  brushColor(brushCol);
    QString brushStyle = fin.readLine().remove(0, 12);

    Ellipse* ellipse = new Ellipse(device, id,
                                   ShapeType::Ellipse,
                                   a, b);
    ellipse->SetPos(pos);
    ellipse->SetPen(color, penWidth, penStyle, capStyle, joinStyle);
    ellipse->SetBrush(brushColor, GetBrushStyle(brushStyle));

    return ellipse;
}
Shape* TextParser::ReadCircle(QTextStream &fin, int id,
                              QPaintDevice* device)
{
    QList<int> points;
    QString  col;
    int r;
    int     penWidth;
    Qt::PenStyle penStyle;
    Qt::PenCapStyle capStyle;
    Qt::PenJoinStyle joinStyle;

    // Get all the points for ellipse or circle
    foreach(QString text, fin.readLine().remove(0, 17).split(", ")) points.append(text.toInt());

    // Now create a QPoint variable
    QPoint pos(points[0], points[1]);
    r = points[2];

    // Get color
    col = fin.readLine().remove(0, 10);
    QColor color(col);
    // Get width
    penWidth = fin.readLine().remove(0, 10).toInt();

    // Get Styles
    penStyle = GetPenStyle(fin.readLine().remove(0, 10));
    capStyle = GetCapStyle(fin.readLine().remove(0, 13));
    joinStyle = GetPenJoinStyle(fin.readLine().remove(0, 14));

    // Brush Properties
    QString brushCol   = fin.readLine().remove(0, 12);
    QColor brushColor(brushCol);
    QString brushStyle = fin.readLine().remove(0, 12);

    Ellipse* circle = new Ellipse(device, id,
                                  ShapeType::Circle,
                                  r, r);
    circle->SetPos(pos);
    circle->SetPen(color, penWidth, penStyle, capStyle, joinStyle);
    circle->SetBrush(brushColor, GetBrushStyle(brushStyle));

    return circle;
}

Shape* TextParser::ReadText(QTextStream &fin, int id,
                            QPaintDevice* device)
{
    QString text;
    QString  col;
    Qt::AlignmentFlag     alignment;
    int     textPointSize;
    QString fontFamily;
    QString fontStyle;
    QString fontWeight;
    QList<int> points;
    int l;
    int w;
//    TextParser tempObj;

    // 1) Get Dimensions
    // Get all the points
    foreach(QString text, fin.readLine().remove(0, 17).split(", ")) points.append(text.toInt());

    // Now create a QPoint variable
    QPoint pos(points[0], points[1]);
    l = points[2];
    w = points[3];

    // Get text string
    text  = fin.readLine().remove(0, 12);

    // Get color
    col = fin.readLine().remove(0, 11);
    QColor color(col);
    // Get alignment
    alignment = this->GetAlignment(fin.readLine().remove(0, 15));

    // Get point size
    textPointSize = fin.readLine().remove(0, 15).toInt();

    // Get font properties
    fontFamily = fin.readLine().remove(0, 16);
    fontStyle = fin.readLine().remove(0, 15);
    fontWeight = fin.readLine().remove(0, 16);

    // no brush

    // make a new shape
    Text* textObj = new Text(device, id, ShapeType::Text);

    textObj->SetFont(CreateFont(fontFamily, textPointSize,
                                fontWeight, fontStyle));

    textObj->SetTextString(text);
    textObj->SetColor(color);
    textObj->SetAlignment(alignment);
    textObj->SetPos(pos);
    textObj->SetWidth(l);
    textObj->SetHeight(w);


//    Text* textObj = new Text(id, text,
//                             this->CreateFont(fontFamily, textPointSize,
//                                                fontWeight, fontStyle),
//                             color, pos, l, w, alignment);

    return textObj;
}
