#include "mainwindow.h"
#include "renderarea.h"
#include "shape.h"
#include "vector.h"
#include "ui_mainwindow.h"
#include <QApplication>
#include <iostream>
#include <algorithm>

static int  count = 9;


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    textParser = new TextParser;
    renderArea = new RenderArea;
    connect(ui->actionContact_Us,SIGNAL(triggered()),this,SLOT(on_actionContact_Us_triggered()));
    connect(ui->actionCustomer_Testimonials,SIGNAL(triggered()),this,SLOT(on_actionCustomer_Testimonials_triggered()));
    connect(ui->actionMove_Shape,SIGNAL(triggered()),this,SLOT(actionMove_Shape_triggered()));

    // Shapes get defined and vector is filled here
    // renderArea is the paintdevice for the shapes painter ptr
    shapeVector = textParser->ReadFile("shapes.txt", renderArea);

    renderArea = createRenderArea();

    // Copy operations were deleted
    // Must use move ctor
     // This is where we pass it the vector
//    renderArea->setData((*shapeVector)[0]);
    renderArea->setVector(std::move(shapeVector));

    // This is where we set the active shape ?
        shapeChanged(shapeIDBox->value());
//        penChanged(shapeIDBox->value());
//        brushChanged(shapeIDBox->value());


    l.show();

}

MainWindow::~MainWindow()
{
    // Keep this format to save in the future not just on quit
//    vector<Shape*> temp;


//    WriteToFile(std::move(shapeVector), "shapes.txt");
    delete ui;
}


void MainWindow::on_actionContact_Us_triggered()
{
    ContactUs *contact;
    contact = new ContactUs();
    contact->exec();
}

void MainWindow::on_actionCustomer_Testimonials_triggered()
{
    testimonial* window;
    window = new testimonial();
    window->exec();
}

void MainWindow::on_actionMove_Shape_triggered()
{
    moveWindow = new MoveShape();
//    moveWindow->setVector(renderArea->getVector());
    moveWindow->exec();
    QPoint point(50, 50);

    renderArea->setMove(point, 1);
    (*shapeVector)[0]->Move(50, 50);
}

void MainWindow::on_actionOpen_File_triggered()
{
    QString path = QCoreApplication::applicationDirPath();
    path += "/";
    QString fileName = QFileDialog::getOpenFileName(this,QObject::tr("choose data file"),path,QObject::tr("(*.txt)"));
    if (fileName.isEmpty())
    {
        QMessageBox::information(this,"tip","Please choose file");
        return;
    }

    shapeVector = textParser->ReadFile(fileName, renderArea);

    for( int i = 0; i < shapeVector->size(); i++)
    {
        qDebug() << "Shape #: " << (*shapeVector)[i]->GetID();
    }

}

RenderArea* MainWindow::createRenderArea()
{

//    renderArea = new RenderArea;
    shapeIDBox = new QSpinBox;
//    shapeIDBox->setWrapping(true);
    shapeIDBox->setRange(1, shapeVector->size());

    //    shapeComboBox->addItem(tr("Line"), ShapeNames::LINE);
//    shapeComboBox->addItem(tr("Polyline"), ShapeNames::POLYLINE);
//    shapeComboBox->addItem(tr("Polygon"), ShapeNames::POLYGON);
//    shapeComboBox->addItem(tr("Rectangle"), ShapeNames::RECTANGLE);
//    shapeComboBox->addItem(tr("Ellipse"), ShapeNames::ELLIPSE);
//    shapeComboBox->addItem(tr("Text"), ShapeNames::TEXT);

    shapeLabel = new QLabel(tr("&ID:"));
    shapeLabel->setBuddy(shapeIDBox);

    penWidthSpinBox = new QSpinBox;
    penWidthSpinBox->setRange(0, 20);
    penWidthSpinBox->setSpecialValueText(tr("0 (cosmetic pen)"));

    penWidthLabel = new QLabel(tr("Pen &Width:"));
    penWidthLabel->setBuddy(penWidthSpinBox);

    penStyleComboBox = new QComboBox;
    penStyleComboBox->addItem(tr("Solid"), static_cast<int>(Qt::SolidLine));
    penStyleComboBox->addItem(tr("Dash"), static_cast<int>(Qt::DashLine));
    penStyleComboBox->addItem(tr("Dot"), static_cast<int>(Qt::DotLine));
    penStyleComboBox->addItem(tr("Dash Dot"), static_cast<int>(Qt::DashDotLine));
    penStyleComboBox->addItem(tr("Dash Dot Dot"), static_cast<int>(Qt::DashDotDotLine));
    penStyleComboBox->addItem(tr("None"), static_cast<int>(Qt::NoPen));

    penStyleLabel = new QLabel(tr("&Pen Style:"));
    penStyleLabel->setBuddy(penStyleComboBox);

    penCapComboBox = new QComboBox;
    penCapComboBox->addItem(tr("Flat"), Qt::FlatCap);
    penCapComboBox->addItem(tr("Square"), Qt::SquareCap);
    penCapComboBox->addItem(tr("Round"), Qt::RoundCap);

    penCapLabel = new QLabel(tr("Pen &Cap:"));
    penCapLabel->setBuddy(penCapComboBox);

    penJoinComboBox = new QComboBox;
    penJoinComboBox->addItem(tr("Miter"), Qt::MiterJoin);
    penJoinComboBox->addItem(tr("Bevel"), Qt::BevelJoin);
    penJoinComboBox->addItem(tr("Round"), Qt::RoundJoin);

    penJoinLabel = new QLabel(tr("Pen &Join:"));
    penJoinLabel->setBuddy(penJoinComboBox);
    brushStyleComboBox = new QComboBox;
//    brushStyleComboBox->addItem(tr("Linear Gradient"),
//            static_cast<int>(Qt::LinearGradientPattern));
//    brushStyleComboBox->addItem(tr("Radial Gradient"),
//            static_cast<int>(Qt::RadialGradientPattern));
//    brushStyleComboBox->addItem(tr("Conical Gradient"),
//            static_cast<int>(Qt::ConicalGradientPattern));
//    brushStyleComboBox->addItem(tr("Texture"), static_cast<int>(Qt::TexturePattern));
    brushStyleComboBox->addItem(tr("Solid"), static_cast<int>(Qt::SolidPattern));
    brushStyleComboBox->addItem(tr("Horizontal"), static_cast<int>(Qt::HorPattern));
    brushStyleComboBox->addItem(tr("Vertical"), static_cast<int>(Qt::VerPattern));
//    brushStyleComboBox->addItem(tr("Cross"), static_cast<int>(Qt::CrossPattern));
//    brushStyleComboBox->addItem(tr("Backward Diagonal"), static_cast<int>(Qt::BDiagPattern));
//    brushStyleComboBox->addItem(tr("Forward Diagonal"), static_cast<int>(Qt::FDiagPattern));
//    brushStyleComboBox->addItem(tr("Diagonal Cross"), static_cast<int>(Qt::DiagCrossPattern));
//    brushStyleComboBox->addItem(tr("Dense 1"), static_cast<int>(Qt::Dense1Pattern));
//    brushStyleComboBox->addItem(tr("Dense 2"), static_cast<int>(Qt::Dense2Pattern));
//    brushStyleComboBox->addItem(tr("Dense 3"), static_cast<int>(Qt::Dense3Pattern));
//    brushStyleComboBox->addItem(tr("Dense 4"), static_cast<int>(Qt::Dense4Pattern));
//    brushStyleComboBox->addItem(tr("Dense 5"), static_cast<int>(Qt::Dense5Pattern));
//    brushStyleComboBox->addItem(tr("Dense 6"), static_cast<int>(Qt::Dense6Pattern));
//    brushStyleComboBox->addItem(tr("Dense 7"), static_cast<int>(Qt::Dense7Pattern));
    brushStyleComboBox->addItem(tr("None"), static_cast<int>(Qt::NoBrush));

    brushStyleLabel = new QLabel(tr("&Brush:"));
    brushStyleLabel->setBuddy(brushStyleComboBox);
    otherOptionsLabel = new QLabel(tr("Options:"));
    antialiasingCheckBox = new QCheckBox(tr("&Antialiasing"));
    transformationsCheckBox = new QCheckBox(tr("&Transformations"));



    connect(shapeIDBox,SIGNAL(QSpinBox::valueChanged(int)),this,SLOT(shapeChanged(int)));

    connect(penWidthSpinBox,SIGNAL(QSpinBox::valueChanged(int)),this,SLOT(penChanged(int)));

    connect(penStyleComboBox,SIGNAL(activated(int)),this,SLOT(penChanged(int)));

    connect(penCapComboBox,SIGNAL(activated(int)),this,SLOT(penChanged(int)));

    connect(penJoinComboBox,SIGNAL(activated(int)),this,SLOT(penChanged(int)));

    connect(brushStyleComboBox,SIGNAL(activated(int)),this,SLOT(brushChanged(int)));

    connect(antialiasingCheckBox,SIGNAL(toggled(bool)),renderArea,SLOT(setAntialiased(bool)));

    connect(transformationsCheckBox,SIGNAL(toggled(bool)),renderArea,SLOT(setTransformed(bool)));

    QGridLayout *mainLayout = new QGridLayout;

    mainLayout->setColumnStretch(0, 1);
    mainLayout->setColumnStretch(3, 1);
    mainLayout->addWidget(renderArea, 0, 0, 1, 4);
    mainLayout->addWidget(shapeLabel, 2, 0, Qt::AlignRight);
    mainLayout->addWidget(shapeIDBox, 2, 1);
    mainLayout->addWidget(penWidthLabel, 3, 0, Qt::AlignRight);
    mainLayout->addWidget(penWidthSpinBox, 3, 1);
    mainLayout->addWidget(penStyleLabel, 4, 0, Qt::AlignRight);
    mainLayout->addWidget(penStyleComboBox, 4, 1);
    mainLayout->addWidget(penCapLabel, 3, 2, Qt::AlignRight);
    mainLayout->addWidget(penCapComboBox, 3, 3);
    mainLayout->addWidget(penJoinLabel, 2, 2, Qt::AlignRight);
    mainLayout->addWidget(penJoinComboBox, 2, 3);
    mainLayout->addWidget(brushStyleLabel, 4, 2, Qt::AlignRight);
    mainLayout->addWidget(brushStyleComboBox, 4, 3);
    mainLayout->addWidget(otherOptionsLabel, 5, 0, Qt::AlignRight);
    mainLayout->addWidget(antialiasingCheckBox, 5, 1, 1, 1, Qt::AlignRight);
    mainLayout->addWidget(transformationsCheckBox, 5, 2, 1, 2, Qt::AlignRight);
//    setLayout(mainLayout);

    QWidget *w = new QWidget;
    w->setLayout(mainLayout);
    this->setCentralWidget(w);


    antialiasingCheckBox->setChecked(true);

    //    setWindowTitle(tr("Basic Drawing"));
    return renderArea;
}

void MainWindow::shapeChanged(int val)
{
    renderArea->setData((*shapeVector)[val]);
}

void MainWindow::penChanged(int val)
{
    int width = penWidthSpinBox->value();
    Qt::PenStyle style = Qt::PenStyle(penStyleComboBox->itemData(
            penStyleComboBox->currentIndex(), Qt::UserRole).toInt());
    Qt::PenCapStyle cap = Qt::PenCapStyle(penCapComboBox->itemData(
            penCapComboBox->currentIndex(), Qt::UserRole).toInt());
    Qt::PenJoinStyle join = Qt::PenJoinStyle(penJoinComboBox->itemData(
            penJoinComboBox->currentIndex(), Qt::UserRole).toInt());

    QPen newPen(renderArea->getData()->GetPen().color(),
                     width, style, cap, join);

    renderArea->setPen(newPen);

    (*shapeVector)[val]->SetPen(newPen);
}

void MainWindow::brushChanged(int val)
{
    Qt::BrushStyle style = Qt::BrushStyle(brushStyleComboBox->itemData(
            brushStyleComboBox->currentIndex(), Qt::UserRole).toInt());

    if (style == Qt::LinearGradientPattern) {
        QLinearGradient linearGradient(0, 0, 100, 100);
        linearGradient.setColorAt(0.0, Qt::white);
        linearGradient.setColorAt(0.2, Qt::green);
        linearGradient.setColorAt(1.0, Qt::black);
        renderArea->setBrush(linearGradient);

        QBrush brush(linearGradient);
        (*shapeVector)[val]->SetBrush(brush);

    } else if (style == Qt::RadialGradientPattern) {
        QRadialGradient radialGradient(50, 50, 50, 70, 70);
        radialGradient.setColorAt(0.0, Qt::white);
        radialGradient.setColorAt(0.2, Qt::green);
        radialGradient.setColorAt(1.0, Qt::black);
        renderArea->setBrush(radialGradient);

        QBrush brush(radialGradient);
        (*shapeVector)[val]->SetBrush(brush);

    } else if (style == Qt::ConicalGradientPattern) {
        QConicalGradient conicalGradient(50, 50, 150);
        conicalGradient.setColorAt(0.0, Qt::white);
        conicalGradient.setColorAt(0.2, Qt::green);
        conicalGradient.setColorAt(1.0, Qt::black);
        renderArea->setBrush(conicalGradient);

        QBrush brush(conicalGradient);
        (*shapeVector)[val]->SetBrush(brush);

    } else if (style == Qt::TexturePattern) {

        QBrush brush(QPixmap(":/images/brick.png"));
        renderArea->setBrush(brush);
        (*shapeVector)[val]->SetBrush(brush);

    } else {
        QBrush brush(Qt::green, style);
        renderArea->setBrush(brush);
        (*shapeVector)[val]->SetBrush(brush);
    }
}

void MainWindow::on_addLine_clicked()
{
    // Add a line to the vector shapeVector
    // Would require a new class AddLine
    // Only for admins



    setCredentials(l.adminCredentials());

    if(isAdmin)
    {
        QPoint front, end;
        front.setX(1); front.setY(1);
        end.setX(500); end.setY(500);
        Line* line = new Line(renderArea, 8, ShapeType::Line, Qt::SolidLine);
        line->setPoint1(front);
        line->setPoint2(end);

        shapeVector->push_back(line);
//        RenderArea();
        renderArea->setVector(shapeVector);

    }
    else
    {
        QMessageBox sorry;
        sorry.warning(this, "Add Line Failed",
                      "Only Admins can add Shapes");
    }


}



void MainWindow::on_addPolyline_clicked()
{
    if(isAdmin)
    {
        QList<QPoint> list;
        QPoint p1, p2, p3, p4;
        p1.setX(50); p1.setY(1);
        p2.setX(1); p2.setY(100);
        p3.setX(33); p3.setY(55);
        p4.setX(187); p4.setY(9);
        list.push_back(p1);
        list.push_back(p2);
        list.push_back(p3);
        list.push_back(p4);
        Polyline* polyline = new Polyline(renderArea, 8, ShapeType::Polyline, Qt::DashLine);
        polyline->SetPoints(list);

        shapeVector->push_back(polyline);
        renderArea->setVector(shapeVector);

//        std::sort(list.begin(), list.end(), Cmp_by_id());
//        std::sort(list.begin(), list.end(), Cmp_by_perimeter());
//        std::sort(list.begin(), list.end(), Cmp_by_area());
    }
    else
    {
        QMessageBox sorry;
        sorry.warning(this, "Add Polyline Failed",
                      "Only Admins can add Shapes");
    }
}

