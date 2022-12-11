#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "contactus.h"
#include "logindialog.h"
#include "testimonial.h"
#include "moveshape.h"
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

    void on_actionMove_Shape_triggered();




private:
    Ui::MainWindow *ui;
    LoginDialog l;

    RenderArea* createRenderArea();

    QPainter* painter;          // ?
    vector<Shape*>* shapeVector;
    RenderArea *renderArea;
    TextParser *textParser;
    RenderArea* setRenderArea(RenderArea* rA);

    QLabel *shapeLabel;
    QLabel *penWidthLabel;
    QLabel *penStyleLabel;
    QLabel *penCapLabel;
    QLabel *penJoinLabel;
    QLabel *brushStyleLabel;
    QLabel *otherOptionsLabel;
    QSpinBox *shapeIDBox;
    QSpinBox *penWidthSpinBox;
    QComboBox *penStyleComboBox;
    QComboBox *penCapComboBox;
    QComboBox *penJoinComboBox;
    QComboBox *brushStyleComboBox;
    QCheckBox *antialiasingCheckBox;
    QCheckBox *transformationsCheckBox;
    MoveShape* moveWindow;
    bool isAdmin;


private slots:
    void shapeChanged(int val);
    void penChanged(int val);
    void brushChanged(int val);
    void on_addLine_clicked();
    void on_addPolyline_clicked();
};
#endif // MAINWINDOW_H
