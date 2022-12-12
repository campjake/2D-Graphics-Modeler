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
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDockWidget>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>
#include "renderarea.h"

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
    QAction *actionLogin;
    QAction *actionMove_Shape;
    QWidget *centralwidget;
    RenderArea *renderArea;
    QMenuBar *menubar;
    QMenu *menuFile;
    QMenu *menuMenu;
    QMenu *menuReports;
    QMenu *menuAccount;
    QMenu *menuShapes;
    QStatusBar *statusbar;
    QDockWidget *dockWidget;
    QWidget *dockWidgetContents;
    QLabel *label;
    QWidget *widget;
    QLabel *label_4;
    QLabel *label_5;
    QPushButton *addText;
    QLabel *label_6;
    QSplitter *splitter_3;
    QComboBox *penStyleCombo;
    QComboBox *capStyleCombo;
    QComboBox *comboBox_5;
    QSplitter *splitter_4;
    QComboBox *addColorCombo_2;
    QComboBox *brushPatternCombo;
    QSplitter *splitter_6;
    QLineEdit *lineEditBox;
    QSplitter *splitter_5;
    QLabel *label_7;
    QSpinBox *textSizeBox;
    QSplitter *splitter_7;
    QComboBox *addShapeCombo;
    QComboBox *addColorCombo;
    QSplitter *splitter_2;
    QLabel *label_3;
    QSpinBox *addWidSpin;
    QSplitter *splitter;
    QLabel *label_2;
    QSpinBox *addIdCombo;
    QSplitter *splitter_10;
    QSplitter *splitter_8;
    QLabel *label_8;
    QSpinBox *xCoordSpin;
    QSplitter *splitter_9;
    QLabel *label_9;
    QSpinBox *yCoordSpin;
    QButtonGroup *buttonGroup;

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
        actionLogin = new QAction(MainWindow);
        actionLogin->setObjectName("actionLogin");
        actionMove_Shape = new QAction(MainWindow);
        actionMove_Shape->setObjectName("actionMove_Shape");
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        renderArea = new RenderArea(centralwidget);
        renderArea->setObjectName("renderArea");
        renderArea->setGeometry(QRect(0, 0, 741, 561));
        renderArea->setCursor(QCursor(Qt::ArrowCursor));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 21));
        menuFile = new QMenu(menubar);
        menuFile->setObjectName("menuFile");
        menuMenu = new QMenu(menubar);
        menuMenu->setObjectName("menuMenu");
        menuReports = new QMenu(menubar);
        menuReports->setObjectName("menuReports");
        menuAccount = new QMenu(menubar);
        menuAccount->setObjectName("menuAccount");
        menuShapes = new QMenu(menubar);
        menuShapes->setObjectName("menuShapes");
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);
        dockWidget = new QDockWidget(MainWindow);
        dockWidget->setObjectName("dockWidget");
        dockWidgetContents = new QWidget();
        dockWidgetContents->setObjectName("dockWidgetContents");
        label = new QLabel(dockWidgetContents);
        label->setObjectName("label");
        label->setGeometry(QRect(20, 0, 51, 16));
        QFont font;
        font.setPointSize(7);
        label->setFont(font);
        widget = new QWidget(dockWidgetContents);
        widget->setObjectName("widget");
        widget->setGeometry(QRect(10, 460, 291, 80));
        label_4 = new QLabel(dockWidgetContents);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(10, 160, 51, 16));
        label_4->setFont(font);
        label_5 = new QLabel(dockWidgetContents);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(10, 250, 51, 16));
        label_5->setFont(font);
        addText = new QPushButton(dockWidgetContents);
        buttonGroup = new QButtonGroup(MainWindow);
        buttonGroup->setObjectName("buttonGroup");
        buttonGroup->addButton(addText);
        addText->setObjectName("addText");
        addText->setGeometry(QRect(30, 400, 31, 24));
        label_6 = new QLabel(dockWidgetContents);
        label_6->setObjectName("label_6");
        label_6->setGeometry(QRect(10, 320, 51, 16));
        label_6->setFont(font);
        splitter_3 = new QSplitter(dockWidgetContents);
        splitter_3->setObjectName("splitter_3");
        splitter_3->setGeometry(QRect(10, 180, 41, 66));
        splitter_3->setOrientation(Qt::Vertical);
        penStyleCombo = new QComboBox(splitter_3);
        penStyleCombo->addItem(QString());
        penStyleCombo->addItem(QString());
        penStyleCombo->addItem(QString());
        penStyleCombo->addItem(QString());
        penStyleCombo->addItem(QString());
        penStyleCombo->setObjectName("penStyleCombo");
        splitter_3->addWidget(penStyleCombo);
        capStyleCombo = new QComboBox(splitter_3);
        capStyleCombo->addItem(QString());
        capStyleCombo->addItem(QString());
        capStyleCombo->addItem(QString());
        capStyleCombo->setObjectName("capStyleCombo");
        splitter_3->addWidget(capStyleCombo);
        comboBox_5 = new QComboBox(splitter_3);
        comboBox_5->addItem(QString());
        comboBox_5->addItem(QString());
        comboBox_5->addItem(QString());
        comboBox_5->setObjectName("comboBox_5");
        splitter_3->addWidget(comboBox_5);
        splitter_4 = new QSplitter(dockWidgetContents);
        splitter_4->setObjectName("splitter_4");
        splitter_4->setGeometry(QRect(10, 270, 41, 44));
        splitter_4->setOrientation(Qt::Vertical);
        addColorCombo_2 = new QComboBox(splitter_4);
        addColorCombo_2->addItem(QString());
        addColorCombo_2->addItem(QString());
        addColorCombo_2->addItem(QString());
        addColorCombo_2->addItem(QString());
        addColorCombo_2->addItem(QString());
        addColorCombo_2->addItem(QString());
        addColorCombo_2->addItem(QString());
        addColorCombo_2->addItem(QString());
        addColorCombo_2->addItem(QString());
        addColorCombo_2->setObjectName("addColorCombo_2");
        splitter_4->addWidget(addColorCombo_2);
        brushPatternCombo = new QComboBox(splitter_4);
        brushPatternCombo->addItem(QString());
        brushPatternCombo->addItem(QString());
        brushPatternCombo->addItem(QString());
        brushPatternCombo->addItem(QString());
        brushPatternCombo->setObjectName("brushPatternCombo");
        splitter_4->addWidget(brushPatternCombo);
        splitter_6 = new QSplitter(dockWidgetContents);
        splitter_6->setObjectName("splitter_6");
        splitter_6->setGeometry(QRect(10, 340, 51, 43));
        splitter_6->setOrientation(Qt::Vertical);
        lineEditBox = new QLineEdit(splitter_6);
        lineEditBox->setObjectName("lineEditBox");
        splitter_6->addWidget(lineEditBox);
        splitter_5 = new QSplitter(splitter_6);
        splitter_5->setObjectName("splitter_5");
        splitter_5->setOrientation(Qt::Horizontal);
        label_7 = new QLabel(splitter_5);
        label_7->setObjectName("label_7");
        splitter_5->addWidget(label_7);
        textSizeBox = new QSpinBox(splitter_5);
        textSizeBox->setObjectName("textSizeBox");
        splitter_5->addWidget(textSizeBox);
        splitter_6->addWidget(splitter_5);
        splitter_7 = new QSplitter(dockWidgetContents);
        splitter_7->setObjectName("splitter_7");
        splitter_7->setGeometry(QRect(10, 20, 51, 86));
        splitter_7->setOrientation(Qt::Vertical);
        addShapeCombo = new QComboBox(splitter_7);
        addShapeCombo->addItem(QString());
        addShapeCombo->addItem(QString());
        addShapeCombo->addItem(QString());
        addShapeCombo->addItem(QString());
        addShapeCombo->addItem(QString());
        addShapeCombo->addItem(QString());
        addShapeCombo->setObjectName("addShapeCombo");
        splitter_7->addWidget(addShapeCombo);
        addColorCombo = new QComboBox(splitter_7);
        addColorCombo->addItem(QString());
        addColorCombo->addItem(QString());
        addColorCombo->addItem(QString());
        addColorCombo->addItem(QString());
        addColorCombo->addItem(QString());
        addColorCombo->addItem(QString());
        addColorCombo->addItem(QString());
        addColorCombo->addItem(QString());
        addColorCombo->addItem(QString());
        addColorCombo->setObjectName("addColorCombo");
        splitter_7->addWidget(addColorCombo);
        splitter_2 = new QSplitter(splitter_7);
        splitter_2->setObjectName("splitter_2");
        splitter_2->setOrientation(Qt::Horizontal);
        label_3 = new QLabel(splitter_2);
        label_3->setObjectName("label_3");
        splitter_2->addWidget(label_3);
        addWidSpin = new QSpinBox(splitter_2);
        addWidSpin->setObjectName("addWidSpin");
        splitter_2->addWidget(addWidSpin);
        splitter_7->addWidget(splitter_2);
        splitter = new QSplitter(splitter_7);
        splitter->setObjectName("splitter");
        splitter->setOrientation(Qt::Horizontal);
        label_2 = new QLabel(splitter);
        label_2->setObjectName("label_2");
        splitter->addWidget(label_2);
        addIdCombo = new QSpinBox(splitter);
        addIdCombo->setObjectName("addIdCombo");
        splitter->addWidget(addIdCombo);
        splitter_7->addWidget(splitter);
        splitter_10 = new QSplitter(dockWidgetContents);
        splitter_10->setObjectName("splitter_10");
        splitter_10->setGeometry(QRect(20, 110, 41, 42));
        splitter_10->setOrientation(Qt::Vertical);
        splitter_8 = new QSplitter(splitter_10);
        splitter_8->setObjectName("splitter_8");
        splitter_8->setOrientation(Qt::Horizontal);
        label_8 = new QLabel(splitter_8);
        label_8->setObjectName("label_8");
        splitter_8->addWidget(label_8);
        xCoordSpin = new QSpinBox(splitter_8);
        xCoordSpin->setObjectName("xCoordSpin");
        splitter_8->addWidget(xCoordSpin);
        splitter_10->addWidget(splitter_8);
        splitter_9 = new QSplitter(splitter_10);
        splitter_9->setObjectName("splitter_9");
        splitter_9->setOrientation(Qt::Horizontal);
        label_9 = new QLabel(splitter_9);
        label_9->setObjectName("label_9");
        splitter_9->addWidget(label_9);
        yCoordSpin = new QSpinBox(splitter_9);
        yCoordSpin->setObjectName("yCoordSpin");
        splitter_9->addWidget(yCoordSpin);
        splitter_10->addWidget(splitter_9);
        dockWidget->setWidget(dockWidgetContents);
        MainWindow->addDockWidget(Qt::LeftDockWidgetArea, dockWidget);

        menubar->addAction(menuFile->menuAction());
        menubar->addAction(menuMenu->menuAction());
        menubar->addAction(menuReports->menuAction());
        menubar->addAction(menuAccount->menuAction());
        menubar->addAction(menuShapes->menuAction());
        menuFile->addAction(actionNew);
        menuFile->addAction(actionOpen_File);
        menuFile->addAction(actionSave);
        menuFile->addAction(actionSave_As);
        menuMenu->addAction(actionContact_Us);
        menuMenu->addAction(actionCustomer_Testimonials);
        menuReports->addAction(actionShape_Area_Listing);
        menuReports->addAction(actionShape_Perimeter_Listing);
        menuAccount->addAction(actionLogin);
        menuShapes->addAction(actionMove_Shape);

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
        actionLogin->setText(QCoreApplication::translate("MainWindow", "Login", nullptr));
        actionMove_Shape->setText(QCoreApplication::translate("MainWindow", "Move Shape", nullptr));
        menuFile->setTitle(QCoreApplication::translate("MainWindow", "File", nullptr));
        menuMenu->setTitle(QCoreApplication::translate("MainWindow", "Menu", nullptr));
        menuReports->setTitle(QCoreApplication::translate("MainWindow", "Reports", nullptr));
        menuAccount->setTitle(QCoreApplication::translate("MainWindow", "Account", nullptr));
        menuShapes->setTitle(QCoreApplication::translate("MainWindow", "Shapes", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Add Shape", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "Pen", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "Brush", nullptr));
        addText->setText(QCoreApplication::translate("MainWindow", "Add", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "Text", nullptr));
        penStyleCombo->setItemText(0, QCoreApplication::translate("MainWindow", "Solid Line", nullptr));
        penStyleCombo->setItemText(1, QCoreApplication::translate("MainWindow", "Dash Line", nullptr));
        penStyleCombo->setItemText(2, QCoreApplication::translate("MainWindow", "Dot Line", nullptr));
        penStyleCombo->setItemText(3, QCoreApplication::translate("MainWindow", "Dash Dot Line", nullptr));
        penStyleCombo->setItemText(4, QCoreApplication::translate("MainWindow", "Dash Dot Dot Line", nullptr));

        capStyleCombo->setItemText(0, QCoreApplication::translate("MainWindow", "Flat Cap", nullptr));
        capStyleCombo->setItemText(1, QCoreApplication::translate("MainWindow", "Square Cap", nullptr));
        capStyleCombo->setItemText(2, QCoreApplication::translate("MainWindow", "Round Cap", nullptr));

        comboBox_5->setItemText(0, QCoreApplication::translate("MainWindow", "Miter", nullptr));
        comboBox_5->setItemText(1, QCoreApplication::translate("MainWindow", "Bevel", nullptr));
        comboBox_5->setItemText(2, QCoreApplication::translate("MainWindow", "Round", nullptr));

        addColorCombo_2->setItemText(0, QCoreApplication::translate("MainWindow", "White", nullptr));
        addColorCombo_2->setItemText(1, QCoreApplication::translate("MainWindow", "Black", nullptr));
        addColorCombo_2->setItemText(2, QCoreApplication::translate("MainWindow", "Red", nullptr));
        addColorCombo_2->setItemText(3, QCoreApplication::translate("MainWindow", "Green", nullptr));
        addColorCombo_2->setItemText(4, QCoreApplication::translate("MainWindow", "Blue", nullptr));
        addColorCombo_2->setItemText(5, QCoreApplication::translate("MainWindow", "Cyan", nullptr));
        addColorCombo_2->setItemText(6, QCoreApplication::translate("MainWindow", "Magenta", nullptr));
        addColorCombo_2->setItemText(7, QCoreApplication::translate("MainWindow", "Yellow", nullptr));
        addColorCombo_2->setItemText(8, QCoreApplication::translate("MainWindow", "Gray", nullptr));

        brushPatternCombo->setItemText(0, QCoreApplication::translate("MainWindow", "No Brush", nullptr));
        brushPatternCombo->setItemText(1, QCoreApplication::translate("MainWindow", "Solid", nullptr));
        brushPatternCombo->setItemText(2, QCoreApplication::translate("MainWindow", "Horizontal", nullptr));
        brushPatternCombo->setItemText(3, QCoreApplication::translate("MainWindow", "Vertical", nullptr));

        label_7->setText(QCoreApplication::translate("MainWindow", "Sz", nullptr));
        addShapeCombo->setItemText(0, QCoreApplication::translate("MainWindow", "Line", nullptr));
        addShapeCombo->setItemText(1, QCoreApplication::translate("MainWindow", "Polyline", nullptr));
        addShapeCombo->setItemText(2, QCoreApplication::translate("MainWindow", "Polygon", nullptr));
        addShapeCombo->setItemText(3, QCoreApplication::translate("MainWindow", "Rectangle", nullptr));
        addShapeCombo->setItemText(4, QCoreApplication::translate("MainWindow", "Ellipse", nullptr));
        addShapeCombo->setItemText(5, QCoreApplication::translate("MainWindow", "Text Box", nullptr));

        addColorCombo->setItemText(0, QCoreApplication::translate("MainWindow", "white", nullptr));
        addColorCombo->setItemText(1, QCoreApplication::translate("MainWindow", "black", nullptr));
        addColorCombo->setItemText(2, QCoreApplication::translate("MainWindow", "red", nullptr));
        addColorCombo->setItemText(3, QCoreApplication::translate("MainWindow", "green", nullptr));
        addColorCombo->setItemText(4, QCoreApplication::translate("MainWindow", "blue", nullptr));
        addColorCombo->setItemText(5, QCoreApplication::translate("MainWindow", "cyan", nullptr));
        addColorCombo->setItemText(6, QCoreApplication::translate("MainWindow", "magenta", nullptr));
        addColorCombo->setItemText(7, QCoreApplication::translate("MainWindow", "yellow", nullptr));
        addColorCombo->setItemText(8, QCoreApplication::translate("MainWindow", "gray", nullptr));

        label_3->setText(QCoreApplication::translate("MainWindow", "W", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "ID", nullptr));
        label_8->setText(QCoreApplication::translate("MainWindow", "X", nullptr));
        label_9->setText(QCoreApplication::translate("MainWindow", "Y", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
