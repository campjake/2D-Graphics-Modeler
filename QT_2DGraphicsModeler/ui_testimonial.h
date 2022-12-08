/********************************************************************************
** Form generated from reading UI file 'testimonial.ui'
**
** Created by: Qt User Interface Compiler version 6.4.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TESTIMONIAL_H
#define UI_TESTIMONIAL_H

#include <QtCore/QVariant>
#include <QtWidgets/QAbstractButton>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QTextEdit>

QT_BEGIN_NAMESPACE

class Ui_testimonial
{
public:
    QLabel *label_title;
    QLabel *label_test1;
    QLabel *label_name1;
    QLabel *label_test2;
    QLabel *label_name2;
    QLabel *label_test3;
    QLabel *label_name3;
    QLabel *label_testTitle;
    QDialogButtonBox *button_Save;
    QTextEdit *textEdit;

    void setupUi(QDialog *testimonial)
    {
        if (testimonial->objectName().isEmpty())
            testimonial->setObjectName("testimonial");
        testimonial->resize(640, 480);
        label_title = new QLabel(testimonial);
        label_title->setObjectName("label_title");
        label_title->setGeometry(QRect(190, 10, 281, 71));
        QFont font;
        font.setPointSize(15);
        font.setBold(true);
        font.setUnderline(true);
        label_title->setFont(font);
        label_test1 = new QLabel(testimonial);
        label_test1->setObjectName("label_test1");
        label_test1->setGeometry(QRect(140, 80, 411, 71));
        QFont font1;
        font1.setPointSize(12);
        font1.setItalic(true);
        label_test1->setFont(font1);
        label_name1 = new QLabel(testimonial);
        label_name1->setObjectName("label_name1");
        label_name1->setGeometry(QRect(350, 140, 161, 31));
        label_name1->setFont(font1);
        label_test2 = new QLabel(testimonial);
        label_test2->setObjectName("label_test2");
        label_test2->setGeometry(QRect(100, 150, 511, 71));
        label_test2->setFont(font1);
        label_name2 = new QLabel(testimonial);
        label_name2->setObjectName("label_name2");
        label_name2->setGeometry(QRect(390, 200, 161, 31));
        label_name2->setFont(font1);
        label_test3 = new QLabel(testimonial);
        label_test3->setObjectName("label_test3");
        label_test3->setGeometry(QRect(30, 220, 561, 71));
        label_test3->setFont(font1);
        label_name3 = new QLabel(testimonial);
        label_name3->setObjectName("label_name3");
        label_name3->setGeometry(QRect(400, 280, 181, 31));
        label_name3->setFont(font1);
        label_testTitle = new QLabel(testimonial);
        label_testTitle->setObjectName("label_testTitle");
        label_testTitle->setGeometry(QRect(0, 300, 631, 31));
        QFont font2;
        font2.setPointSize(11);
        font2.setBold(true);
        label_testTitle->setFont(font2);
        button_Save = new QDialogButtonBox(testimonial);
        button_Save->setObjectName("button_Save");
        button_Save->setGeometry(QRect(420, 450, 193, 29));
        button_Save->setStandardButtons(QDialogButtonBox::Save);
        textEdit = new QTextEdit(testimonial);
        textEdit->setObjectName("textEdit");
        textEdit->setGeometry(QRect(10, 330, 601, 111));

        retranslateUi(testimonial);

        QMetaObject::connectSlotsByName(testimonial);
    } // setupUi

    void retranslateUi(QDialog *testimonial)
    {
        testimonial->setWindowTitle(QCoreApplication::translate("testimonial", "Dialog", nullptr));
        label_title->setText(QCoreApplication::translate("testimonial", "Customer Testimonials", nullptr));
        label_test1->setText(QCoreApplication::translate("testimonial", "A great drawing tool that is easy to use!", nullptr));
        label_name1->setText(QCoreApplication::translate("testimonial", "- Random Person", nullptr));
        label_test2->setText(QCoreApplication::translate("testimonial", "I always have good experiences with Shapes R Us!", nullptr));
        label_name2->setText(QCoreApplication::translate("testimonial", "- Random Person", nullptr));
        label_test3->setText(QCoreApplication::translate("testimonial", "10/10 Drawing Program. I am recommending this to everyone!", nullptr));
        label_name3->setText(QCoreApplication::translate("testimonial", "- Random Person", nullptr));
        label_testTitle->setText(QCoreApplication::translate("testimonial", "Write your own testimonial here and send it to us by using the address on our Contact Us", nullptr));
    } // retranslateUi

};

namespace Ui {
    class testimonial: public Ui_testimonial {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TESTIMONIAL_H
