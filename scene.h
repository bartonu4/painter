#ifndef SCENE_H
#define SCENE_H
#include <QtGui>
#include <shape.h>
#include <zigzag.h>
#include <sector.h>
#include <QColorDialog>
#include <QDomDocument>

class GScene:public QGraphicsScene
{
    Q_OBJECT
public:

    GScene(QMenu *m);
    QMenu *menu;
    enum Mode{InsertItem,SelectedItem};
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
   //void mouseMoveEvent(QGraphicsSceneMouseEvent *event);
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);
    void keyPressEvent(QKeyEvent *event);
    void keyReleaseEvent(QKeyEvent *event);
public slots:
    void setModeSelected();
    void setModeInsert();
    void setOpacity(int op);
    void setLineWidth(int lwidth);
    void setTypeEl();
    void setTypeZig();
    void setTypeSek();
    void deleteItem();
    void setBrushColor(QColor colr);
    void setPenColor(QColor colr);
    void clearAll();
    void flipVer();
    void flipHor();
    void save(QString fileName);
    void open(QString fileName);
    void setSteps(QString st);
    void setStartP(int d);
private:
     bool selects;
    QPointF start,end;
    Shape * item;
    int i;
    Mode mode;
    QList<Shape*> itemss;
    Shape::Type type;
    QColor color;
    QPen pen;
};

#endif // SCENE_H
