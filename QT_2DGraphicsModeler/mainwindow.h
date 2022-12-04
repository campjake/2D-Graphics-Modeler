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
#include "shape.h"
#include "textparser.h"
#include "renderarea.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
private slots:
    void on_actionContact_Us_triggered();

    void on_actionCustomer_Testimonials_triggered();

    void on_actionOpen_File_triggered();

private:
    Ui::MainWindow *ui;

    vector<Shape*> shapeVector;
    TextParser *textParser;
    RenderArea *renderArea;
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

private:
    void createRenderArea();

private slots:
    void shapeChanged(int);
    void penChanged(int);
    void brushChanged(int);
};
#endif // MAINWINDOW_H
