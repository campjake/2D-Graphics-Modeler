#ifndef RENDERAREA_H
#define RENDERAREA_H

#include <QBrush>
#include <QPen>
#include <QPixmap>
#include <QPainter>
#include <QPainterPath>
#include <QWidget>
#include "textparser.h"
#include "shape.h"
#include "line.h"
#include "polyline.h"
#include "polygon.h"
#include "rectangle.h"
#include "ellipse.h"
#include "text.h"


class RenderArea : public QWidget
{
    Q_OBJECT
public:
    explicit RenderArea(QWidget *parent = nullptr);

    void setData(Shape* data);

    void setVector(vector<Shape*>* vector);

    vector<Shape*>* getVector() const
    {
        return shapeVector;
    }

    Shape* getData() const
    {
        return shape;
    }

public slots:
    void setPen(const QPen &pen);
    void setBrush(const QBrush &brush);
    void setAntialiased(bool antialiased);
    void setTransformed(bool transformed);
    void setMove(QPoint newPos);

protected:
    void paintEvent(QPaintEvent *event) override;
    QPainter* getPainter()
    {
        return &painter;
    }

private:
    QPen pen;
    QBrush brush;
    bool antialiased;
    bool transformed;
    QPixmap pixmap;
    vector<Shape*>* shapeVector;
    QPainter painter;
    Shape*   shape;
};

#endif // RENDERAREA_H
