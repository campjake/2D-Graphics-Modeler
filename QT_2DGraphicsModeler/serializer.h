#ifndef SERIALIZER_H
#define SERIALIZER_H          
#include <typeinfo>         //type_info
#include <QColor>
#include <QFile>
#include <QFileDialog>
#include <QMap>
#include <QTextStream>
#include <QCoreApplication>
#include <QString>
#include <QMessageBox>

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "vector.h"
#include "shape.h"
#include "textparser.h"

void WriteToFile(const vector<Shape*>& list,
                 QString fileName = "shapes.txt")
{
    ShapeType   shape;
    QColor      color;

//    FIX THIS vvvvv
//    QString fullPath

    QFile file;
    QTextStream fout(&file);
    QString     colorString;
    QString     shapeName;
    QString     style;
    QString     dimensions;

    if(file.open(QFile::WriteOnly | QFile::Text))
    {
        qDebug() << "Failed to open file";
    }

    // Overwrite Shape File
    for(int index = 0; index < list.size(); index++)
    {
        shape = list[index]->GetShapeType();
        auto shapeObj = list[index];

        // Print to File
        switch(shape)
        {
        case ShapeType::Line : shapeName = "Line";
            break;
        case ShapeType::Polyline : shapeName = "Polyline";
            break;
        case ShapeType::Polygon : shapeName = "Polygon";
            break;

        case ShapeType::Rectangle : shapeName = "Rectangle";
            break;
        case ShapeType::Square : shapeName = "Square";
            break;

        case ShapeType::Ellipse : shapeName = "Ellipse";
            break;
        case ShapeType::Circle : shapeName = "Circle";
            break;

        case ShapeType::Text : shapeName = "Text";
            break;
        default : shapeName = "NoShape";
        }
    }
}

#endif // SERIALIZER_H
