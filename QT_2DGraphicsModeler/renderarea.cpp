#include "renderarea.h"

RenderArea::RenderArea(QWidget *parent) : QWidget(parent)
{
    antialiased = false;
    transformed = false;
//    pixmap.load(":/images/qt-logo.png");

    setBackgroundRole(QPalette::Dark);
    setAutoFillBackground(true);
}

void RenderArea::setData(vector<Shape*> data)
{
    shapeVector = data;
    update();
}

void RenderArea::setPen(const QPen &pen)
{
    this->pen = pen;
    update();
}

void RenderArea::setBrush(const QBrush &brush)
{
    this->brush = brush;
    update();
}

void RenderArea::setAntialiased(bool antialiased)
{
    this->antialiased = antialiased;
    update();
}

void RenderArea::setTransformed(bool transformed)
{
    this->transformed = transformed;
    update();
}

void RenderArea::paintEvent(QPaintEvent *event)
{

    static const QPoint points[4] = {
        QPoint(10, 80),
        QPoint(20, 10),
        QPoint(80, 30),
        QPoint(90, 70)
    };

    QRect rect(10, 20, 80, 60);

    QPainterPath path;
    path.moveTo(20, 80);
    path.lineTo(20, 30);
    path.cubicTo(80, 0, 50, 50, 80, 80);

//    int startAngle = 20 * 16;
//    int arcLength = 120 * 16;

    QPainter painter(this);
    painter.setPen(pen);
    painter.setBrush(brush);    // delete?


    if (antialiased)
        painter.setRenderHint(QPainter::Antialiasing, true);

// DEMO EXAMPLE -- REPLACE BEFORE SUBMITTING

/*****************************************************/
    for (int x = 0; x < width(); x += 100) {
        for (int y = 0; y < height(); y += 100) {
            painter.save();
            painter.translate(x, y);

            if (transformed) {
                painter.translate(50, 50);
                painter.rotate(60.0);
                painter.scale(0.6, 0.9);
                painter.translate(-50, -50);
            }

//            painter.drawLine(5, 3, 200, 200);

            painter.drawLine(rect.bottomLeft(), rect.topRight());

            painter.drawPolyline(points, 4);

            painter.drawPolygon(points, 4);

            painter.drawRect(rect);

           painter.drawEllipse(rect);

            painter.drawText(rect,
                             Qt::AlignCenter,
                             tr("Shapes\nR\nUs"));

            painter.restore();
        }
    }
/***************************************************************/

    // Our implementation doesn't work  :(
//    Shape* shape = new Shape(nullptr, 8, ShapeType::Rectangle,
//                                    4, 4);
//    shapeVector.push_back(recta);
//    shapeVector.resize(1);
//    for(int index = 0; index < shapeVector.size(); index++)
//    {
//        if(shapeVector.size() > 0)
//        {
//            shapeVector[index]->Draw(this);
//        }
//    }

    painter.setRenderHint(QPainter::Antialiasing, false);
    painter.setPen(palette().dark().color());
    painter.setBrush(Qt::NoBrush);
    painter.drawRect(QRect(0, 0, width() - 1, height() - 1));




}