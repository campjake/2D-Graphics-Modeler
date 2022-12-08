#ifndef SERIALIZER_H
#define SERIALIZER_H          
#include <typeinfo>         //type_info
#include <QColor>
#include <QFile>            // QFile
#include <QFileDialog>
#include <QTextStream>
#include <QCoreApplication>
#include <QString>          // QString, number(num to string)
#include <QMessageBox>

//#include "mainwindow.h"
//#include "ui_mainwindow.h"
#include "vector.h"
#include "shape.h"
#include "line.h"
#include "polyline.h"
#include "rectangle.h"
#include "textparser.h"

template<typename T>
void WriteToFile(const vector<T*> list,
                 QString fileName = "shapes.txt")
{

    ShapeType   shape;
    QColor     color;


    // ASK How are these different? VVVV
    // QString fullPath = QCoreApplication::applicationDirPath();
    QString pathString = QDir::currentPath() + fileName;

    QFile file(pathString);
    QTextStream fout(&file);
    QString     colorName;;
    QString     shapeName;
    QString     style;
    vector<QString>  dimensions;


    if(file.open(QFile::WriteOnly | QFile::Text))
    {
        qDebug() << "Failed to open file";
    }

    // Overwrite Shape File
    for(int index = 0; index < list.size(); index++)
    {
        shape = list[index]->GetShapeType();
        auto shapeObj(list[index]);
//        dimensions.resize(list.size() * 2); // need 2 strings for every point

        // Get Dimensions
        switch(shape)
        {
        case ShapeType::Line :  shapeName = "Line";
                                dimensions.resize(4);
                                dimensions[0] = QString::number(shapeObj->Line::GetPoint1().x()) + ", ";
                                dimensions[1] = QString::number(shapeObj->Line::GetPoint1().y()) + ", ";
                                dimensions[2] = QString::number(shapeObj->Line::GetPoint2().x()) + ", ";
                                dimensions[3] = QString::number(shapeObj->Line::GetPoint2().y());
            break;
        case ShapeType::Polyline :  shapeName = "Polyline";
                                    dimensions.resize(list[index]->Polyline::GetNumPoints());
                                    for(int i = 0; i <= dimensions.size(); i++)
                                    {
                                        if(dimensions.capacity() >= 4)
                                        {
                                            dimensions[i] = QString::number(shapeObj->Polyline::GetLinePoints()->at(i).x()) + ", ";
                                            i++;
                                            dimensions[i] = QString::number(shapeObj->Polyline::GetLinePoints()->at(i).y()) + ", ";
                                        }
                                        else
                                        {
                                            dimensions[i] = QString::number(shapeObj->Polyline::GetLinePoints()->at(i).x()) + ", ";
                                            i++;
                                            dimensions[i] = QString::number(shapeObj->Polyline::GetLinePoints()->at(i).y());
                                        }

                                    }
                                    break;

        case ShapeType::Polygon : shapeName = "Polygon";
                                  dimensions.resize(list[index]->Polygon::GetPointCount());

                                  for(int i = 0; i <= dimensions.size(); i++)
                                  {
                                      if(dimensions.capacity() >= 4)
                                      {
                                          dimensions[i] = QString::number(shapeObj->Polygon::GetPoints()->at(i).x()) + ", ";
                                          i++;
                                          dimensions[i] = QString::number(shapeObj->Polygon::GetPoints()->at(i).y()) + ", ";
                                      }
                                      else
                                      {
                                          dimensions[i] = QString::number(shapeObj->Polygon::GetPoints()->at(i).x()) + ", ";
                                          i++;
                                          dimensions[i] = QString::number(shapeObj->Polygon::GetPoints()->at(i).y());
                                      }
                                  }
                                    break;

        case ShapeType::Rectangle : shapeName = "Rectangle";
                                    dimensions.resize(4);
                                    dimensions[0] = QString::number(shapeObj->Shape::GetPos().x() + ", ");
                                    dimensions[1] = QString::number(shapeObj->Shape::GetPos().y() + ", ");

                                    dimensions[2] = QString::number(shapeObj->Rectangle::GetWidth() + ", ");
                                    dimensions[3] = QString::number(shapeObj->Rectangle::GetHeight());
            break;

        case ShapeType::Square :    shapeName = "Square";
                                    dimensions.resize(4);
                                    dimensions[0] = QString::number(shapeObj->Shape::GetPos().x() + ", ");
                                    dimensions[1] = QString::number(shapeObj->Shape::GetPos().y() + ", ");

                                    dimensions[2] = QString::number(shapeObj->Rectangle::GetWidth() + ", ");
                                    dimensions[3] = QString::number(shapeObj->Rectangle::GetHeight());
                                    break;

        case ShapeType::Ellipse :   shapeName = "Ellipse";
                                    dimensions.resize(4);
                                    dimensions[0] = QString::number(shapeObj->GetPos().x() + ", ");
                                    dimensions[1] = QString::number(shapeObj->GetPos().y() + "m ");

                                    dimensions[2] = QString::number(shapeObj->GetWidth() + ", ");
                                    dimensions[3] = QString::number(shapeObj->GetHeight());
                                    break;

        case ShapeType::Circle :    shapeName = "Circle";
                                    dimensions.resize(4);
                                    dimensions[0] = QString::number(shapeObj->GetPos().x() + ", ");
                                    dimensions[1] = QString::number(shapeObj->GetPos().y() + "m ");

                                    dimensions[2] = QString::number(shapeObj->GetWidth() + ", ");
                                    dimensions[3] = QString::number(shapeObj->GetWidth());
                                    break;

        case ShapeType::Text :      shapeName = "Text";
                                    dimensions.resize(4);
                                    dimensions[0] = QString::number(shapeObj->GetPos().x() + ", ");
                                    dimensions[1] = QString::number(shapeObj->GetPos().y() + "m ");

                                    dimensions[2] = QString::number(shapeObj->GetWidth() + ", ");
                                    dimensions[3] = QString::number(shapeObj->GetHeight());
                                    break;

        default : shapeName = "NoShape";
        }

        // Print Text to File
        fout << "\nShapeId: "   << list[index]->GetID();
        fout << "\nShapeType: " << shapeName;
        fout << "\nShapeDimensions: ";
        for(int i = 0; i <= dimensions.size(); i++)
        {
            fout << dimensions[i] << ", ";
        }



        // text is special, so handle output of other shapes first
        // Handling Pen Data
        if(shape != ShapeType::Text)
        {
            color = list[index]->GetPen().color();

            if(color  == QColor(Qt::red))
            {
                colorName = "red";
            }
            else if(color == QColor(Qt::green))
            {
                colorName = "green";

            }
            else if(color == QColor(Qt::blue))
            {
                colorName = "blue";
            }
            else if(color == QColor(Qt::yellow))
            {
                colorName = "yellow";
            }
            else if(color == QColor(Qt::cyan))
            {
                colorName = "cyan";
            }
            else if(color == QColor(Qt::magenta))
            {
                colorName = "magenta";
            }
            else if(color == QColor(Qt::white))
            {
                colorName = "white";
            }
            else if(color == QColor(Qt::black))
            {
                colorName = "black";
            }
            else if(color == QColor(Qt::gray))
            {
                colorName = "gray";
            }

            fout << "\nPenColor: " << colorName;

            //  CAN ACCESS PEN WIDTH EASILY
            fout << "\nPenWidth: " << list[index]->GetPen().width();

            // SWITCH STATEMENT FOR PEN STYLE
            switch(list[index]->GetPen().style())
              {
                  case 0: style = "NoPen";
                          break;
                  case 1: style = "SolidLine";
                          break;
                  case 2: style = "DashLine";
                          break;
                  case 3: style = "DotLine";
                          break;
                  case 4: style = "DashDotLine";
                          break;
                  case 5: style = "DashDotDotLine";
                          break;
                  case 6: style = "CustomDashLine";
                          break;
                  case 15: style = "MPenStyle";
              }

            fout << "\nPenStyle: " << style;

            // SWITCH STATEMENT FOR PENCAPSTYLE
            switch(list[index]->GetPen().capStyle())
            {
                case 0: style = "FlatCap";
                        break;
                case 16: style = "SquareCap";
                         break;
                case 32: style = "RoundCap";
                         break;
                case 48: style = "MPenCapStyle";
            }

            fout << "\nPenCapStyle: " << style;

            // SWITCH STATEMENT FOR PENJOINSTYLE
            switch(list[index]->GetPen().joinStyle())
            {
                case 0: style = "MiterJoin";
                        break;
                case 64: style = "BevelJoin";
                         break;
                case 128: style = "RoundJoin";
                          break;
                case 256: style = "SvgMiterJoin";
                          break;
                case 448: style = "MPenJoinStyle";
            }

            fout << "\nPenJoinStyle: " << style;


            // Line & Polyline have no Brushes
            if(shape != ShapeType::Line && shape != ShapeType::Polyline)
            {
                    color = list[index]->GetBrush().color;
            }

            // C-STYLE CAST for PENCOLOR

            if(color  == QColor(Qt::red))
            {
                colorName = "red";
            }
                else if(color == QColor(Qt::green))
                {
                    colorName = "green";
                }
                else if(color == QColor(Qt::blue))
                {
                   colorName = "blue";
                }
                else if(color == QColor(Qt::yellow))
                {
                   colorName = "yellow";
                }
                else if(color == QColor(Qt::cyan))
                {
                   colorName = "cyan";
                }
                else if(color == QColor(Qt::magenta))
                {
                   colorName = "magenta";
                }
                else if(color == QColor(Qt::white))
                {
                    colorName = "white";
                }
                else if(color == QColor(Qt::black))
                {
                    colorName = "black";
                }
                else if(color == QColor(Qt::gray))
                {
                    colorName = "gray";
                }

            fout << "\nPenColor: " << colorName;
            fout << "\nPenWidth: " << list[index]->GetPen().width();

            // Switch Statement using enum vals for styles
            switch(list[index]->GetPen().style())
            {
                case 0: style = "NoPen";
                        break;
                case 1: style = "SolidLine";
                        break;
                case 2: style = "DashLine";
                        break;
                case 3: style = "DotLine";
                        break;
                case 4: style = "DashDotLine";
                        break;
                case 5: style = "DashDotDotLine";
                        break;
                case 6: style = "CustomDashLine";
                        break;
                case 15: style = "MPenStyle";
            }

            fout << "\nPenStyle: " << style;

            //Handling PenCapStyle using enum values for capstyle
            switch(list[index]->getPen().capStyle())
            {
                case 0: style = "FlatCap";
                        break;
                case 16: style = "SquareCap";
                         break;
                case 32: style = "RoundCap";
                         break;
                case 48: style = "MPenCapStyle";
            }

            fout << "\nPenCapStyle: " << style;

            // Handling PenJoinStyle
            switch(list[index]->GetPen().joinStyle())
            {
                case 0: style = "MiterJoin";
                        break;
                case 64: style = "BevelJoin";
                         break;
                case 128: style = "RoundJoin";
                          break;
                case 256: style = "SvgMiterJoin";
                          break;
                case 448: style = "MPenJoinStyle";
            }
            fout << "\nPenJoinStyle: " << style;

        }   // END PEN DATA

    // BRUSH DATA
    if(shape != ShapeType::Line &&
       shape != ShapeType::Polyline &&
       shape != ShapeType::Text)
    {
        // COLOR OF BRUSH to STRING

        color = list[index]->GetBrush().color();

        if(color  == QColor(Qt::red))
        {
            colorName = "red";
        }
        else if(color == QColor(Qt::green))
        {
            colorName = "green";

        }
        else if(color == QColor(Qt::blue))
        {
            colorName = "blue";
        }
        else if(color == QColor(Qt::yellow))
        {
            colorName = "yellow";
        }
        else if(color == QColor(Qt::cyan))
        {
            colorName = "cyan";
        }
        else if(color == QColor(Qt::magenta))
        {
            colorName = "magenta";
        }
        else if(color == QColor(Qt::white))
        {
            colorName = "white";
        }
        else if(color == QColor(Qt::black))
        {
            colorName = "black";
        }
        else if(color == QColor(Qt::gray))
        {
            colorName = "gray";
        }
        fout << "BrushColor: "    << colorName;

        switch(list[index]->getBrush().style())
        {
            case 0: style = "NoBrush";
                    break;
            case 1: style = "SolidPattern";
                    break;
            case 2: style = "Dense1Pattern";
                      break;
            case 3: style = "Dense2Pattern";
                    break;
            case 4: style = "Dense3Pattern";
                    break;
            case 5: style = "Dense4Pattern";
                    break;
            case 6: style = "Dense5Pattern";
                     break;
            case 7: style = "Dense6Pattern";
                     break;
            case 8: style = "Dense7Pattern";
                    break;
            case 9: style = "HorPattern";
                    break;
            case 10: style = "VerPattern";
                     break;
            case 11: style = "CrossPattern";
                     break;
            case 12: style = "BDiagPattern";
                     break;
            case 13: style = "FDiagPattern";
                     break;
            case 14: style = "DiagCrossPattern";
                     break;
            case 15: style = "LinearGradientPattern";
                     break;
            case 16: style = "RadialGradientPattern";
                     break;
            case 17: style = "ConicalGradientPattern";
                     break;
            case 24: style = "TexturePattern";
                     break;
        }

        fout << "\nBrushStyle: " << style;
    }
    // NOW HANDLE TEXT OBJECTS
    else if(shape == ShapeType::Text)
    {
        fout << "\nTextString: " << ((Text*)(list[index]))->GetTextString();

        color = list[index]->GetBrush().color();

        if(color  == QColor(Qt::red))
        {
            colorName = "red";
        }
        else if(color == QColor(Qt::green))
        {
            colorName = "green";

        }
        else if(color == QColor(Qt::blue))
        {
            colorName = "blue";
        }
        else if(color == QColor(Qt::yellow))
        {
            colorName = "Yellow";
        }
        else if(color == QColor(Qt::cyan))
        {
            colorName = "Cyan";
        }
        else if(color == QColor(Qt::magenta))
        {
            colorName = "Magenta";
        }
        else if(color == QColor(Qt::white))
        {
            colorName = "White";
        }
        else if(color == QColor(Qt::black))
        {
            colorName = "Black";
        }
        else if(color == QColor(Qt::gray))
        {
            colorName = "Gray";
        }
        fout << "\nTextColor: : " << colorName;

        // Get the Alignment Flags
        switch(((Text*)(list[index]))->GetAlign())
        {
        case 1: style = "AlignLeft";
                break;
        case 2: style = "AlignRight";
                break;
        case 4: style = "AlignHCenter";
                break;
        case 8: style = "AlignJustify";
             break;
        case 16: style = "AlignAbsolute";
                 break;
        case 31: style = "AlignHorizontal_Mask";
                 break;
        case 64: style = "AlignBottom";
                 break;
        case 132: style = "AlignCenter";
                  break;
        case 256: style = "AlignBaseline";
        }

        fout << "\nTextAlignment: " << style;

        // GET FONT DATA

        int pointSize = ((Text*)(list[index]))->GetFont().pointSize();
        // just do it in line next time

        fout << "\nTextPointSize: " << pointSize;
        fout << "\nTextFontFamily: " << ((Text*)(list[index]->GetFont).family);

        // Font style
        switch(((Text*)(list[index]))->GetFont().style())
        {
        case 0: style = "StyleNormal";
                break;
        case 1: style = "StyleItalic";
                break;
        case 2: style = "StyleOblique";
        }

        fout << "\nTextFontStyle: " << style;

        /*  for jake's reference
         *  100 thin
         *  200 ex light
         *  300 light
         *  400 norm
         *  500 med
         *  600 demibold
         *  700 bold
         *  800 ex bold
         *  900 black
         * */

        switch(((Text*)(list[index]))->GetFont().weight())
        {
        case 100: style = "Thin";
                  break;
        case 200: style = "ExtraLight";
                  break;
        case 300: style = "Light";
                  break;
        case 400: style = "Normal";
                  break;
        case 500: style = "Medium";
                  break;
        case 600: style = "DemiBold";
                  break;
        case 700: style = "Bold";
                  break;
        case 800: style = "ExtraBold";
                  break;
        case 900: style = "Black";
        }

        fout << "\nTextFontWeight" << style;
        if(index + 1 < list.size())
        {
            fout << '\n';
        }
        else
        {
            fout << "";
        }

        }   // END TEXT

    }   // END FOR LOOP! :-D

    // CLOSE FILE
    file.flush();
    file.close();
}

#endif // SERIALIZER_H
