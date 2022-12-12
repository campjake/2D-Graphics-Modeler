#include "mainwindow.h"
#include "renderarea.h"
#include "shape.h"
#include "vector.h"
#include "ui_mainwindow.h"
#include <QApplication>
#include <iostream>
#include <algorithm>

//static int  count = 9; // use for unique IDs?


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    l.show();

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
//        shapeChanged(shapeIDBox->value());
//        penChanged(shapeIDBox->value());
//        brushChanged(shapeIDBox->value());




}

MainWindow::~MainWindow()
{
    // Keep this format to save in the future not just on quit
//    vector<Shape*> temp;


//    Serializer(shapeVector, "shapes.txt");
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

//    renderArea->setMove(point, 1);
//    (*shapeVector)[0]->Move(50, 50);
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

    xmoveShapeSpinBox = new QSpinBox;
    ymoveShapeSpinBox = new QSpinBox;

    xmoveShapeSpinBox->setRange(0, 1000);
    ymoveShapeSpinBox->setRange(0, 1000);

    xmoveShapeLabel = new QLabel(tr("&Move X:"));
    xmoveShapeLabel->setBuddy(xmoveShapeSpinBox);
    ymoveShapeLabel = new QLabel(tr("&Move Y:"));
    ymoveShapeLabel->setBuddy(ymoveShapeSpinBox);

    shapeIDBox = new QSpinBox;
//    shapeIDBox->setWrapping(true);

    // find highest ID and don't let them look at uninit values above it
    int highID = 0;
    for(int i = 0; i < shapeVector->size(); i++)
    {
        if((*shapeVector)[i]->GetID() >= highID)
        {
            highID = (*shapeVector)[i]->GetID();
        }
    }

    shapeIDBox->setRange(1, highID);

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
    brushStyleComboBox->addItem(tr("None"), static_cast<int>(Qt::NoBrush));
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

    connect(xmoveShapeSpinBox,SIGNAL(QSpinBox::valueChanged(int)),this,SLOT(moveChanged(int)));

    connect(ymoveShapeSpinBox,SIGNAL(QSpinBox::valueChanged(int)),this,SLOT(moveChanged(int)));

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
    mainLayout->addWidget(xmoveShapeLabel, 4, 4, Qt::AlignRight);
    mainLayout->addWidget(xmoveShapeSpinBox, 4, 5);
    mainLayout->addWidget(ymoveShapeLabel, 5, 4, Qt::AlignRight);
    mainLayout->addWidget(ymoveShapeSpinBox, 5, 5);
    mainLayout->addWidget(otherOptionsLabel, 5, 0, Qt::AlignRight);
    mainLayout->addWidget(antialiasingCheckBox, 5, 1, 1, 1, Qt::AlignRight);
    mainLayout->addWidget(transformationsCheckBox, 5, 2, 1, 2, Qt::AlignRight);
//    setLayout(mainLayout);

    QWidget *w = new QWidget;
    w->setLayout(mainLayout);
    this->setCentralWidget(w);


    antialiasingCheckBox->setChecked(true);

    setCredentials(l.adminCredentials());
    if(!isAdmin)
    {
        shapeIDBox->setEnabled(false);
        penWidthSpinBox->setEnabled(false);
        penStyleComboBox->setEnabled(false);
        penCapComboBox->setEnabled(false);
        penJoinComboBox->setEnabled(false);
        brushStyleComboBox->setEnabled(false);
        antialiasingCheckBox->setEnabled(false);
        transformationsCheckBox->setEnabled(false);
    }

    return renderArea;
}

void MainWindow::shapeChanged(int)
{
//    Shape* shape(renderArea, (*shapeVector)[shapeIDBox->value()],
//                 (*shapeVector)[shapeIDBox->value()]->GetShapeType());
    renderArea->setData((*shapeVector)[shapeIDBox->value() - 1]);

}

void MainWindow::penChanged(int)
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

    (*shapeVector)[shapeIDBox->value() - 1]->SetPen(newPen);
}

void MainWindow::brushChanged(int)
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
        (*shapeVector)[shapeIDBox->value() - 1]->SetBrush(brush);

    } else if (style == Qt::RadialGradientPattern) {
        QRadialGradient radialGradient(50, 50, 50, 70, 70);
        radialGradient.setColorAt(0.0, Qt::white);
        radialGradient.setColorAt(0.2, Qt::green);
        radialGradient.setColorAt(1.0, Qt::black);
        renderArea->setBrush(radialGradient);

        QBrush brush(radialGradient);
        (*shapeVector)[shapeIDBox->value() - 1]->SetBrush(brush);

    } else if (style == Qt::ConicalGradientPattern) {
        QConicalGradient conicalGradient(50, 50, 150);
        conicalGradient.setColorAt(0.0, Qt::white);
        conicalGradient.setColorAt(0.2, Qt::green);
        conicalGradient.setColorAt(1.0, Qt::black);
        renderArea->setBrush(conicalGradient);

        QBrush brush(conicalGradient);
        (*shapeVector)[shapeIDBox->value() - 1]->SetBrush(brush);

    } else if (style == Qt::TexturePattern) {

        QBrush brush(QPixmap(":/images/brick.png"));
        renderArea->setBrush(brush);
        (*shapeVector)[shapeIDBox->value() - 1]->SetBrush(brush);

    } else {
        QBrush brush(Qt::green, style);
        renderArea->setBrush(brush);
        (*shapeVector)[shapeIDBox->value() - 1]->SetBrush(brush);
    }
}

void MainWindow::moveChanged(int)
{
    QPoint newPos;
    newPos.setX(xmoveShapeSpinBox->value());
    newPos.setY(ymoveShapeSpinBox->value());
    renderArea->setMove(newPos);
    (*shapeVector)[shapeIDBox->value() - 1]->SetPos(newPos);


}

//void MainWindow::on_addLine_clicked()
//{
//    // Add a line to the vector shapeVector
//    // Would require a new class AddLine
//    // Only for admins



//    setCredentials(l.adminCredentials());

//    if(isAdmin)
//    {
//        QPoint front, end;
//        front.setX(1); front.setY(1);
//        end.setX(500); end.setY(500);
//        Line* line = new Line(renderArea, 8, ShapeType::Line, Qt::SolidLine);
//        line->setPoint1(front);
//        line->setPoint2(end);

//        shapeVector->push_back(line);
////        RenderArea();
//        renderArea->setVector(shapeVector);

//    }
//    else
//    {
//        QMessageBox sorry;
//        sorry.warning(this, "Add Line Failed",
//                      "Only Admins can add Shapes");
//    }


//}



//void MainWindow::on_addPolyline_clicked()
//{
//    if(isAdmin)
//    {
//        QList<QPoint> list;
//        QPoint p1, p2, p3, p4;
//        p1.setX(50); p1.setY(1);
//        p2.setX(1); p2.setY(100);
//        p3.setX(33); p3.setY(55);
//        p4.setX(187); p4.setY(9);
//        list.push_back(p1);
//        list.push_back(p2);
//        list.push_back(p3);
//        list.push_back(p4);
//        Polyline* polyline = new Polyline(renderArea, 8, ShapeType::Polyline, Qt::DashLine);
//        polyline->SetPoints(list);

//        shapeVector->push_back(polyline);
//        renderArea->setVector(shapeVector);

////        std::sort(list.begin(), list.end(), Cmp_by_id());
////        std::sort(list.begin(), list.end(), Cmp_by_perimeter());
////        std::sort(list.begin(), list.end(), Cmp_by_area());
//    }
//    else
//    {
//        QMessageBox sorry;
//        sorry.warning(this, "Add Polyline Failed",
//                      "Only Admins can add Shapes");
//    }
//}


//void MainWindow::on_addShapeCombo_currentIndexChanged(int index)
//{
//    if(index == 1 ||
//       )
//}


void MainWindow::on_addShapeCombo_activated(int index)
{
    switch(ui->addShapeCombo->currentIndex())
    {
    case 0 :    ui->addColorCombo_2->setEnabled(false);
                ui->brushPatternCombo->setEnabled(false);
                ui->lineEditBox->setEnabled(false);
                ui->textSizeBox->setEnabled(false);
                break;
    case 1 :    ui->addColorCombo_2->setEnabled(false);
                ui->brushPatternCombo->setEnabled(false);
                ui->lineEditBox->setEnabled(false);
                ui->textSizeBox->setEnabled(false);
                break;
    case 2 :    ui->lineEditBox->setEnabled(false);
                ui->textSizeBox->setEnabled(false);
                break;
    case 3 :    ui->lineEditBox->setEnabled(false);
                ui->textSizeBox->setEnabled(false);
                break;
    case 4 :    ui->lineEditBox->setEnabled(false);
                ui->textSizeBox->setEnabled(false);
                break;
    case 5:     ui->addColorCombo_2->setEnabled(false);
                ui->brushPatternCombo->setEnabled(false);
                break;
    }
    int highID = 0;
    for(int i = 0; i < shapeVector->size(); i++)
    {
        if((*shapeVector)[i]->GetID() >= highID)
        {
            highID = (*shapeVector)[i]->GetID();
        }
    }
    ui->addIdCombo->setRange(1, highID + 1);
    ui->xCoordSpin->setRange(0, 1000);
    ui->yCoordSpin->setRange(0, 1000);
    ui->addWidSpin->setRange(0, 20);
}


void MainWindow::on_addText_clicked()
{
    setCredentials(l.adminCredentials());

    //BUG -- If ID is higher than vector size, we crash :(

    // Check if admin
    if(!isAdmin)
    {
        QMessageBox addRejected;
        addRejected.warning(this, "REJECTED", "Only admins can add shapes");
    }
    else
    {
        // Check for unique IDs
        for(int i = 0; i < shapeVector->size(); i++)
        {
            if(ui->addIdCombo->value() == (*shapeVector)[i]->GetID())
            {
                QMessageBox addRejected;
                addRejected.warning(this, "Add Failed!", "A shape with this ID already exists");
                return;
            }
        }
        // Add the Shape
        switch(ui->addShapeCombo->currentIndex())
        {
        case 0:{    // LINE SHAPE
                    // Pen Attributes COPY/PASTE (use textParser fcns)
                    QColor color(ui->addColorCombo->currentText());
                    QPen pen;
                    pen.setColor(color);
                    pen.setStyle(textParser->GetPenStyle(ui->penStyleCombo->currentText()));
                    pen.setCapStyle(textParser->GetCapStyle(ui->capStyleCombo->currentText()));
                    pen.setJoinStyle(textParser->GetPenJoinStyle(ui->comboBox_5->currentText()));
                    // end copy paste

                    // Line, Polyline, TextBox have no brush
                    pen.setBrush(Qt::NoBrush);

                    // Hard Code end point? :[
                    QPoint front, end;
                    front.setX(ui->xCoordSpin->value());
                    front.setY(ui->yCoordSpin->value());

                    //
                    end.setX(100); end.setY(100);

                    // Create & Define Line
                    Line* line = new Line(renderArea, ui->addIdCombo->value(), ShapeType::Line, Qt::SolidLine);
                    line->setPoint1(front);
                    line->setPoint2(end);
                    line->SetPos(front);
                    line->SetPen(color, ui->addWidSpin->value(),
                                 pen.style(), pen.capStyle(),
                                 pen.joinStyle());

                    shapeVector->push_back(line);

                    // not sure if next line is necessary
//                    renderArea->setData(line);
//                    renderArea->setVector(std::move(shapeVector));
                    renderArea = new RenderArea;
                    renderArea->setData(line);
                    renderArea->setPen(line->GetPen());
                    renderArea->setBrush(Qt::NoBrush);
                    renderArea->setVector(std::move(shapeVector));
                    renderArea = createRenderArea();


               }
                    break;
        case 1:{    // POLYLINE SHAPE
                    // Pen Attributes COPY/PASTE (use textParser fcns)
                    QColor color(ui->addColorCombo->currentText());
                    QPen pen;
                    pen.setColor(color);
                    pen.setStyle(textParser->GetPenStyle(ui->penStyleCombo->currentText()));
                    pen.setCapStyle(textParser->GetCapStyle(ui->capStyleCombo->currentText()));
                    pen.setJoinStyle(textParser->GetPenJoinStyle(ui->comboBox_5->currentText()));
                    // end copy paste

                    // Line, Polyline, TextBox have no brush
                    pen.setBrush(Qt::NoBrush);

                    // Hard Code points? :[
                    QList<QPoint> list;
                    QPoint front, mid, end;
                    front.setX(ui->xCoordSpin->value());
                    front.setY(ui->yCoordSpin->value());

                    mid.setX(33); mid.setY(50);
                    end.setX(100); end.setY(100);

                    list.append(front);
                    list.append(mid);
                    list.append(end);

                    // Create and Define Polyline

                    Polyline* polyline = new Polyline(renderArea, ui->addIdCombo->value(),
                                                      ShapeType::Polyline, pen);
                    polyline->SetPos(front);
                    polyline->SetPoints(list);

                    shapeVector->push_back(polyline);

                    // not sure if next line is necessary
                    renderArea->setData(polyline);
//                    renderArea->setVector(std::move(shapeVector));
                    renderArea = new RenderArea;
                    renderArea->setData(polyline);
                    renderArea->setPen(polyline->GetPen());
                    renderArea->setBrush(Qt::NoBrush);
                    renderArea->setVector(std::move(shapeVector));
                    renderArea = createRenderArea();



               }
            break;
        case 2:{    // POLYGON SHAPE
                    // Pen Attributes COPY/PASTE (use textParser fcns)
                    QColor color(ui->addColorCombo->currentText());
                    QPen pen;
                    pen.setColor(color);
                    pen.setStyle(textParser->GetPenStyle(ui->penStyleCombo->currentText()));
                    pen.setCapStyle(textParser->GetCapStyle(ui->capStyleCombo->currentText()));
                    pen.setJoinStyle(textParser->GetPenJoinStyle(ui->comboBox_5->currentText()));
                    // end copy paste

                    // Brush Attributes COPY/PASTE (use textParser fcns)
                    // Time constraints - only color & style options
                    QColor bColor(ui->addColorCombo_2->currentText());
                    QBrush brush(bColor);
                    brush.setStyle(textParser->GetBrushStyle(ui->brushPatternCombo->currentText()));
                    // end copy/paste

                    // Hard Code points? :[
                    QList<QPoint> list;
                    QPoint front, mid, end;
                    front.setX(ui->xCoordSpin->value());
                    front.setY(ui->yCoordSpin->value());

                    mid.setX(33); mid.setY(50);
                    end.setX(100); end.setY(100);

                    list.append(front);
                    list.append(mid);
                    list.append(end);

                    Polygon* polygon = new Polygon(renderArea, ui->addIdCombo->value(),
                                                   ShapeType::Polygon);
                    polygon->SetPos(front);
                    polygon->SetPoints(list);
                    polygon->SetBrush(brush);
                    polygon->SetPen(pen);

                    shapeVector->push_back(polygon);

                    // not sure if this is necessary
                    renderArea->setData(polygon);
//                    renderArea->setVector(std::move(shapeVector));
                    renderArea = new RenderArea;
                    renderArea->setData(polygon);

                    renderArea->setVector(std::move(shapeVector));
                    createRenderArea();
                    renderArea->setBrush(polygon->GetBrush());



               }
            break;
        case 3:
            break;
        case 4:
            break;
        case 5:
            break;
        default :  QMessageBox addRejected;
                   addRejected.warning(this, "REJECTED", "Only admins can add shapes");

        }

        QMessageBox addAccepted;
        addAccepted.warning(this, "SUCCESS", "The shape was added to the canvas");
    }
}

