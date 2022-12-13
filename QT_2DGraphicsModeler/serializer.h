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
//#include "shape.h"
#include "line.h"
#include "polyline.h"
#include "polygon.h"
#include "rectangle.h"
#include "ellipse.h"
#include "text.h"
#include "textparser.h"

template <typename T>
void serializer(vector<T*>* list,
                QString fileName = "out.txt")
{
    // ASK How are these different? VVVV
    // QString fullPath = QCoreApplication::applicationDirPath();
    QDir directory;

    QString fullPath = directory.absoluteFilePath(fileName);

    qInfo() << fullPath << '\n';

    QFile file{fullPath};


    if(!file.open(QIODevice::WriteOnly | QIODevice::Text))
    {
        qDebug() << "Failed to open file";
    }
    else
    {
        qDebug() << "Opened file successfully";
    }

    QTextStream fout(&file);

    // Use file
    for(int index = 0; index < list->size(); index++)
    {
        (*list)[index]->Print(fout);
        fout << '\n';

    }

    // CLOSE FILE
    file.flush();
    file.close();


}



#endif // SERIALIZER_H
