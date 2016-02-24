#ifndef SECTOR_H
#define SECTOR_H
#include "shape.h"
#define PI 3.1415926535897932384626433832795
class Sector : public Shape
{
    double angleBegin,angleEnd;
    QPointF lt,rt,center;
    QGraphicsEllipseItem *elipseRt,*elipseLt;
    bool conl,conr;

public:

    Sector(QMenu *m);
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    void calculatePoints();
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event);
    void mousePressEvent(QGraphicsSceneMouseEvent *event);

};

#endif // SECTOR_H
