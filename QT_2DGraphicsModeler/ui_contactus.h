/********************************************************************************
** Form generated from reading UI file 'contactus.ui'
**
** Created by: Qt User Interface Compiler version 6.4.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CONTACTUS_H
#define UI_CONTACTUS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_ContactUs
{
public:
    QPushButton *pushButton;
    QGroupBox *groupBox;
    QLabel *lebel_title;
    QLabel *label_email;
    QLabel *label_logo;

    void setupUi(QDialog *ContactUs)
    {
        if (ContactUs->objectName().isEmpty())
            ContactUs->setObjectName("ContactUs");
        ContactUs->resize(649, 490);
        pushButton = new QPushButton(ContactUs);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(520, 440, 93, 29));
        groupBox = new QGroupBox(ContactUs);
        groupBox->setObjectName("groupBox");
        groupBox->setGeometry(QRect(30, 10, 601, 431));
        lebel_title = new QLabel(groupBox);
        lebel_title->setObjectName("lebel_title");
        lebel_title->setGeometry(QRect(210, 10, 191, 81));
        QFont font;
        font.setFamilies({QString::fromUtf8("Segoe UI")});
        font.setPointSize(20);
        font.setBold(true);
        font.setUnderline(true);
        lebel_title->setFont(font);
        label_email = new QLabel(groupBox);
        label_email->setObjectName("label_email");
        label_email->setGeometry(QRect(30, 80, 261, 41));
        QFont font1;
        font1.setPointSize(15);
        font1.setBold(true);
        label_email->setFont(font1);
        label_logo = new QLabel(groupBox);
        label_logo->setObjectName("label_logo");
        label_logo->setGeometry(QRect(0, 180, 601, 241));
        label_logo->setPixmap(QPixmap(QString::fromUtf8("../../../../Pictures/qt pic/ShapesRUs.jpg")));
        label_logo->setScaledContents(true);
        label_logo->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        label_logo->setWordWrap(false);
        label_logo->setMargin(0);

        retranslateUi(ContactUs);

        QMetaObject::connectSlotsByName(ContactUs);
    } // setupUi

    void retranslateUi(QDialog *ContactUs)
    {
        ContactUs->setWindowTitle(QCoreApplication::translate("ContactUs", "Dialog", nullptr));
        pushButton->setText(QCoreApplication::translate("ContactUs", "Ok", nullptr));
        groupBox->setTitle(QString());
        lebel_title->setText(QCoreApplication::translate("ContactUs", "Contact Us", nullptr));
        label_email->setText(QCoreApplication::translate("ContactUs", "Email: shapesruscs1c@gmail.com", nullptr));
        label_logo->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class ContactUs: public Ui_ContactUs {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CONTACTUS_H
