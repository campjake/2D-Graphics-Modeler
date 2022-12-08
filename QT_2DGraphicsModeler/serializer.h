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

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "vector.h"
#include "shape.h"
#include "line.h"
#include "polyline.h"
#include "rectangle.h"
#include "textparser.h"

template<typename T>
void WriteToFile(const vector<T*>& list,
                 QString fileName = "shapes.txt")
{
    ShapeType   shape;
    QColor     color;


    // ASK How are these different? VVVV
    // QString fullPath = QCoreApplication::applicationDirPath();
    QString pathString = QDir::currentPath() + fileName;

    QFile file(pathString);
    QTextStream fout(&file);
    QString     colorString;
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

        QString colorName;
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
            fout << "\nPenWidth: " << list[index]->GetPen().width();

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

        } // END IF

        if(shape != ShapeType::Line && shape != ShapeType::Polyline)
        {
                color = list[index]->GetBrush().color;
        }

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
    }
}



#endif // SERIALIZER_H
