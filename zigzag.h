#ifndef ZIGZAG_H
#define ZIGZAG_H
#include "shape.h"
class Zigzag:public Shape
{
public:
    Zigzag(QMenu *m);
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    QRectF boundingRect();
    QPolygonF points;

};

#endif // ZIGZAG_H
