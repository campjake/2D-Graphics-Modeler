/********************************************************************************
** Form generated from reading UI file 'moveshape.ui'
**
** Created by: Qt User Interface Compiler version 6.4.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MOVESHAPE_H
#define UI_MOVESHAPE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAbstractButton>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QSplitter>

QT_BEGIN_NAMESPACE

class Ui_MoveShape
{
public:
    QDialogButtonBox *buttonBox;
    QSplitter *splitter_5;
    QSplitter *splitter_4;
    QLabel *label_3;
    QSpinBox *spinBox;
    QSplitter *splitter_3;
    QSplitter *splitter;
    QLabel *label;
    QLineEdit *xLine;
    QSplitter *splitter_2;
    QLabel *label_2;
    QLineEdit *yLine;

    void setupUi(QDialog *MoveShape)
    {
        if (MoveShape->objectName().isEmpty())
            MoveShape->setObjectName("MoveShape");
        MoveShape->resize(566, 240);
        buttonBox = new QDialogButtonBox(MoveShape);
        buttonBox->setObjectName("buttonBox");
        buttonBox->setGeometry(QRect(240, 190, 301, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        splitter_5 = new QSplitter(MoveShape);
        splitter_5->setObjectName("splitter_5");
        splitter_5->setGeometry(QRect(200, 60, 131, 73));
        splitter_5->setOrientation(Qt::Vertical);
        splitter_4 = new QSplitter(splitter_5);
        splitter_4->setObjectName("splitter_4");
        splitter_4->setOrientation(Qt::Horizontal);
        label_3 = new QLabel(splitter_4);
        label_3->setObjectName("label_3");
        splitter_4->addWidget(label_3);
        spinBox = new QSpinBox(splitter_4);
        spinBox->setObjectName("spinBox");
        splitter_4->addWidget(spinBox);
        splitter_5->addWidget(splitter_4);
        splitter_3 = new QSplitter(splitter_5);
        splitter_3->setObjectName("splitter_3");
        splitter_3->setOrientation(Qt::Vertical);
        splitter = new QSplitter(splitter_3);
        splitter->setObjectName("splitter");
        splitter->setOrientation(Qt::Horizontal);
        label = new QLabel(splitter);
        label->setObjectName("label");
        splitter->addWidget(label);
        xLine = new QLineEdit(splitter);
        xLine->setObjectName("xLine");
        splitter->addWidget(xLine);
        splitter_3->addWidget(splitter);
        splitter_2 = new QSplitter(splitter_3);
        splitter_2->setObjectName("splitter_2");
        splitter_2->setOrientation(Qt::Horizontal);
        label_2 = new QLabel(splitter_2);
        label_2->setObjectName("label_2");
        splitter_2->addWidget(label_2);
        yLine = new QLineEdit(splitter_2);
        yLine->setObjectName("yLine");
        splitter_2->addWidget(yLine);
        splitter_3->addWidget(splitter_2);
        splitter_5->addWidget(splitter_3);

        retranslateUi(MoveShape);
        QObject::connect(buttonBox, &QDialogButtonBox::accepted, MoveShape, qOverload<>(&QDialog::accept));
        QObject::connect(buttonBox, &QDialogButtonBox::rejected, MoveShape, qOverload<>(&QDialog::reject));

        QMetaObject::connectSlotsByName(MoveShape);
    } // setupUi

    void retranslateUi(QDialog *MoveShape)
    {
        MoveShape->setWindowTitle(QCoreApplication::translate("MoveShape", "Dialog", nullptr));
        label_3->setText(QCoreApplication::translate("MoveShape", "Shape ID: ", nullptr));
        label->setText(QCoreApplication::translate("MoveShape", "X: ", nullptr));
        label_2->setText(QCoreApplication::translate("MoveShape", "Y: ", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MoveShape: public Ui_MoveShape {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MOVESHAPE_H
