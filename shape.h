#ifndef PAINTING_H
#define PAINTING_H

#include <QWidget>

#include<QPainter>
#include <QGraphicsScene>
#include <QGraphicsSceneMouseEvent>
#include <QGraphicsItem>
#include <QGraphicsEllipseItem>
#include <QDebug>
#include <QMenu>
#include <math.h>
enum points {t,b};
class Shape :public QObject, public QGraphicsItem

{
    Q_OBJECT
    Q_INTERFACES(QGraphicsItem)
protected: QGraphicsEllipseItem *elT,*elB;

    int dh,dw,mx,my,angle;
    QPointF top,bot;
    QPointF npos,mpos;
    QMenu *menu;


    QRectF bounds;
public:
    Shape(QMenu *imenu);
    enum Type {Ellipse,Zigzag,Sector};
    void drawT();
    void drawB();
    void setTop(int x, int y);
    void setBottom(int x,int y);
    QRectF boundingRect() const ;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event);
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);
    void hoverEnterEvent(QGraphicsSceneHoverEvent *event);
    void hoverLeaveEvent(QGraphicsSceneHoverEvent *event);
    void contextMenuEvent(QGraphicsSceneContextMenuEvent *event);
    void setPenStyle(Qt::PenStyle style);
    void setBrushColor(QColor color);
    void setPenColor(QColor color);
    void flipVer();
    void flipHor();
    QPointF returnTop(){return top;}
    QPointF returnBot(){return bot;}
    QVariant itemChange(GraphicsItemChange change, const QVariant &value);
    Type type;

    bool selected,move,scaleB,scaleT;
    QPen pen;
    QBrush brush;
    double angleRot;
    int h,w;
     QGraphicsRectItem *rect;
     int steps,dst;

signals:
    
public slots:
    void setType(Type t);

};

#endif // PAINTING_H
