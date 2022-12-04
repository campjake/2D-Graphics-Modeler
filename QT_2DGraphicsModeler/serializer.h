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
    QColor      color;

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
                                dimensions[0] = QString::number(shapeObj->Line::getPoint1().x()) + ", ";
                                dimensions[1] = QString::number(shapeObj->Line::getPoint1().y()) + ", ";
                                dimensions[2] = QString::number(shapeObj->Line::getPoint2().x()) + ", ";
                                dimensions[3] = QString::number(shapeObj->Line::getPoint2().y());
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

                                    dimensions[2] = QString::number(shapeObj->Rectangle::getWidth() + ", ");
                                    dimensions[3] = QString::number(shapeObj->Rectangle::getHeight());
            break;

        case ShapeType::Square :    shapeName = "Square";
                                    dimensions.resize(4);
                                    dimensions[0] = QString::number(shapeObj->Shape::GetPos().x() + ", ");
                                    dimensions[1] = QString::number(shapeObj->Shape::GetPos().y() + ", ");

                                    dimensions[2] = QString::number(shapeObj->Rectangle::getWidth() + ", ");
                                    dimensions[3] = QString::number(shapeObj->Rectangle::getHeight());
                                    break;

        case ShapeType::Ellipse :   shapeName = "Ellipse";
                                    dimensions.resize(4);
                                    dimensions[0] = QString::number(shapeObj->GetPos().x() + ", ");
                                    dimensions[1] = QString::number(shapeObj->GetPos().y() + "m ");

                                    dimensions[2] = QString::number(shapeObj->getWidth() + ", ");
                                    dimensions[3] = QString::number(shapeObj->getHeight());
                                    break;

        case ShapeType::Circle :    shapeName = "Circle";
                                    dimensions.resize(4);
                                    dimensions[0] = QString::number(shapeObj->GetPos().x() + ", ");
                                    dimensions[1] = QString::number(shapeObj->GetPos().y() + "m ");

                                    dimensions[2] = QString::number(shapeObj->getWidth() + ", ");
                                    dimensions[3] = QString::number(shapeObj->getWidth());
                                    break;

        case ShapeType::Text :      shapeName = "Text";
                                    dimensions.resize(4);
                                    dimensions[0] = QString::number(shapeObj->GetPos().x() + ", ");
                                    dimensions[1] = QString::number(shapeObj->GetPos().y() + "m ");

                                    dimensions[2] = QString::number(shapeObj->getWidth() + ", ");
                                    dimensions[3] = QString::number(shapeObj->getHeight());
                                    break;

        default : shapeName = "NoShape";
        }

        // Print Text to File
        fout << "\nShapeId: "   << list[index]->GetID();
        fout << "\nShapeType: " << shapeName;
        fout << "\nShapeDimensions: ";
        for(int i = 0; i <= dimensions.size(); i++)
        {
            fout << dimensions[i];
        }
    }
}



#endif // SERIALIZER_H
