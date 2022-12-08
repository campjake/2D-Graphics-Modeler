#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "contactus.h"
#include "logindialog.h"
#include "testimonial.h"
#include <QMainWindow>
#include <QGridLayout>
#include <QCheckBox>
#include <QComboBox>
#include <QLabel>
#include <QSpinBox>
#include <QGridLayout>
#include <QDebug>
#include <QObject>
#include "shape.h"
#include "textparser.h"
#include "renderarea.h"
#include "serializer.h"

static QPainter staticQPainter;

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{ friend class LoginDialog;
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void setCredentials(bool admin)
    {
        isAdmin = admin;
    }

private slots:
    void on_actionContact_Us_triggered();

    void on_actionCustomer_Testimonials_triggered();

    void on_actionOpen_File_triggered();



private:
    Ui::MainWindow *ui;
    LoginDialog l;
    RenderArea* createRenderArea();
    QPainter* painter;          // ?
    vector<Shape*>* shapeVector;
    RenderArea *renderArea;
    TextParser *textParser;
    QLabel *shapeLabel;
    QLabel *penWidthLabel;
    QLabel *penStyleLabel;
    QLabel *penCapLabel;
    QLabel *penJoinLabel;
    QLabel *brushStyleLabel;
    QLabel *otherOptionsLabel;
    QComboBox *shapeComboBox;
    QSpinBox *penWidthSpinBox;
    QComboBox *penStyleComboBox;
    QComboBox *penCapComboBox;
    QComboBox *penJoinComboBox;
    QComboBox *brushStyleComboBox;
    QCheckBox *antialiasingCheckBox;
    QCheckBox *transformationsCheckBox;

    bool isAdmin;


private slots:
    void shapeChanged(int);
    void penChanged(int);
    void brushChanged(int);
    void on_addLine_clicked();
    void on_addPolyline_clicked();
};
#endif // MAINWINDOW_H
