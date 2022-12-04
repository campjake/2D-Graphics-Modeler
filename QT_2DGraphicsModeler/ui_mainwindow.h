/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.4.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionNew;
    QAction *actionOpen_File;
    QAction *actionSave;
    QAction *actionSave_As;
    QAction *actionContact_Us;
    QAction *actionCustomer_Testimonials;
    QAction *actionShape_Area_Listing;
    QAction *actionShape_Perimeter_Listing;
    QWidget *centralwidget;
    QMenuBar *menubar;
    QMenu *menuFile;
    QMenu *menuMenu;
    QMenu *menuReports;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(800, 600);
        actionNew = new QAction(MainWindow);
        actionNew->setObjectName("actionNew");
        actionOpen_File = new QAction(MainWindow);
        actionOpen_File->setObjectName("actionOpen_File");
        actionSave = new QAction(MainWindow);
        actionSave->setObjectName("actionSave");
        actionSave_As = new QAction(MainWindow);
        actionSave_As->setObjectName("actionSave_As");
        actionContact_Us = new QAction(MainWindow);
        actionContact_Us->setObjectName("actionContact_Us");
        actionCustomer_Testimonials = new QAction(MainWindow);
        actionCustomer_Testimonials->setObjectName("actionCustomer_Testimonials");
        actionCustomer_Testimonials->setCheckable(false);
        actionCustomer_Testimonials->setShortcutContext(Qt::WindowShortcut);
        actionShape_Area_Listing = new QAction(MainWindow);
        actionShape_Area_Listing->setObjectName("actionShape_Area_Listing");
        actionShape_Perimeter_Listing = new QAction(MainWindow);
        actionShape_Perimeter_Listing->setObjectName("actionShape_Perimeter_Listing");
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 17));
        menuFile = new QMenu(menubar);
        menuFile->setObjectName("menuFile");
        menuMenu = new QMenu(menubar);
        menuMenu->setObjectName("menuMenu");
        menuReports = new QMenu(menubar);
        menuReports->setObjectName("menuReports");
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        menubar->addAction(menuFile->menuAction());
        menubar->addAction(menuMenu->menuAction());
        menubar->addAction(menuReports->menuAction());
        menuFile->addAction(actionNew);
        menuFile->addAction(actionOpen_File);
        menuFile->addAction(actionSave);
        menuFile->addAction(actionSave_As);
        menuMenu->addAction(actionContact_Us);
        menuMenu->addAction(actionCustomer_Testimonials);
        menuReports->addAction(actionShape_Area_Listing);
        menuReports->addAction(actionShape_Perimeter_Listing);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "Shapes R Us", nullptr));
        actionNew->setText(QCoreApplication::translate("MainWindow", "New...", nullptr));
        actionOpen_File->setText(QCoreApplication::translate("MainWindow", "Open File...", nullptr));
        actionSave->setText(QCoreApplication::translate("MainWindow", "Save...", nullptr));
        actionSave_As->setText(QCoreApplication::translate("MainWindow", "Save As...", nullptr));
        actionContact_Us->setText(QCoreApplication::translate("MainWindow", "Contact Us", nullptr));
        actionCustomer_Testimonials->setText(QCoreApplication::translate("MainWindow", "Customer Testimonials", nullptr));
        actionShape_Area_Listing->setText(QCoreApplication::translate("MainWindow", "Shape Area Listing", nullptr));
        actionShape_Perimeter_Listing->setText(QCoreApplication::translate("MainWindow", "Shape Perimeter Listing", nullptr));
        menuFile->setTitle(QCoreApplication::translate("MainWindow", "File", nullptr));
        menuMenu->setTitle(QCoreApplication::translate("MainWindow", "Menu", nullptr));
        menuReports->setTitle(QCoreApplication::translate("MainWindow", "Reports", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
