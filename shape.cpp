#include "shape.h"

Shape::Shape(QMenu *imenu)
{

    menu=imenu;

    setFlag(ItemIsSelectable,true);
    setFlag(ItemIsFocusable,true);

    setFlag(ItemSendsGeometryChanges, true);
    elB =new QGraphicsEllipseItem(this);
    elT =new QGraphicsEllipseItem(this);
    rect=new QGraphicsRectItem(this);
    setCursor(Qt::PointingHandCursor);
    setAcceptHoverEvents(true);
    setAcceptDrops(true);
    type=Ellipse;
    setFocus(Qt::MouseFocusReason);
    move=false;
    scaleB=false;
    setOpacity(0.5);
    brush.setColor(Qt::lightGray);
    steps=0;
    angleRot=0;

}

void Shape::drawT()
{
    elT->setRect(top.x(),top.y(),8,8);
    //->setBrush(QBrush(Qt::green));
}

void Shape::drawB()
{
    elB->setRect(bot.x()-8,bot.y()-8,8,8);
    //elB->setBrush(QBrush(Qt::green));
}


void Shape::setTop(int x,int y){
    top.setX(x);
    top.setY(y);
    setTransformOriginPoint(top.x(),top.y());

}

void Shape::setBottom(int x, int y)
{
    bot.setX(x);
    bot.setY(y);
    h=abs(top.x()-bot.x());
    w=abs(top.y()-bot.y());
    dh=h;
    dw=w;
//    if(top.x()>bot.x()||top.y()>bot.y()){
//        QPointF temp(top);

//        top.setX(bot.x());
//        top.setY(bot.y());
//        bot.setX(temp.x());
//        bot.setY(temp.y());
//    }

}



void Shape::paint(QPainter *painter,
                  const QStyleOptionGraphicsItem *option, QWidget *widget){

    pen.setCapStyle(Qt::SquareCap);
    painter->setPen(Qt::DashLine);

    painter->drawRect(bounds);
    painter->setPen(pen);
    if(type==Ellipse){

        painter->setBrush(QBrush(brush.color()));
        painter->drawEllipse(top.x(),top.y(),h,w);

    }








}

void Shape::setType(Shape::Type t)
{
    type=t;
}
QRectF Shape::boundingRect() const{

    return QRectF(top.x(),top.y(),h,w);
}



void Shape::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    prepareGeometryChange();
    event->accept();

    //if(bot.x()<event->scenePos().x()+5&&bot.y()<event->scenePos().y()+5){
    if(scaleB==true){
        setFlag(QGraphicsItem::ItemIsMovable,false);
        h=abs(top.x()-event->scenePos().x());
        w=abs(top.y()-event->scenePos().y());
        qDebug()<<top<<h<<w<<bot;
        rect->setRect(top.x(),top.y(),h,w);
        bot.setX(top.x()+h);
        bot.setY(top.y()+w);


        elB->setRect(bot.x()-8,bot.y()-8,8,8);


    }
    if(scaleT){
        h=abs(bot.x()-event->scenePos().x());
        w=abs(bot.y()-event->scenePos().y());
        qDebug()<<top<<h<<w<<bot;
        rect->setRect(top.x(),top.y(),h,w);
        top.setX(bot.x()-h);
        top.setY(bot.y()-w);

         elT->setRect(top.x(),top.y(),8,8);
        elB->setRect(bot.x()-8,bot.y()-8,8,8);
    }
    if(move==true){


//        setFlag(QGraphicsItem::ItemIsMovable,true);

                top.setX(mpos.x()-npos.x()+event->scenePos().x());
                top.setY(mpos.y()-npos.y()+event->scenePos().y());
                bot.setX(top.x()+h);
                bot.setY(top.y()+w);
                elT->setRect(top.x(),top.y(),8,8);
                elB->setRect(bot.x()-8,bot.y()-8,8,8);
                rect->setRect(top.x(),top.y(),h,w);


    }
    QGraphicsItem::mouseMoveEvent(event);
}


void Shape::mousePressEvent(QGraphicsSceneMouseEvent *event){
    event->accept();
    QGraphicsItem::mousePressEvent(event);
    if(event->button()==Qt::LeftButton){
        prepareGeometryChange();

        if(elB->contains(event->pos()))
        {
            scaleB=true;
            scaleT=false;
            move=false;
            qDebug()<<scaleB;
        }

        if(elT->contains(event->pos())){
                scaleT=true;
                scaleB=false;
                move=false;
        }

        if(!elB->contains(event->pos())&&!elT->contains(event->pos()))
        {
            scaleT=false;
            scaleB=false;
            move=true;
            npos=event->scenePos();

            mpos=top;
        }
        if(isSelected()){pen.setStyle(Qt::DashLine);}

    }


}

void Shape::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{


}

void Shape::hoverEnterEvent(QGraphicsSceneHoverEvent *event)
{
    QGraphicsItem::hoverEnterEvent(event);
    event->accept();
    elT->setVisible(true);
    elB->setVisible(true);

}

void Shape::hoverLeaveEvent(QGraphicsSceneHoverEvent *event)
{
    QGraphicsItem::hoverEnterEvent(event);
    event->accept();
        elT->setVisible(false);
        elB->setVisible(false);
}

void Shape::contextMenuEvent(QGraphicsSceneContextMenuEvent *event)
{

    menu->exec(event->screenPos());
}

void Shape::setPenStyle(Qt::PenStyle style)
{
    pen.setStyle(style);
}

void Shape::setBrushColor(QColor color)
{
    brush.setColor(color);
}

void Shape::setPenColor(QColor color)
{
    pen.setBrush(color);
}

void Shape::flipVer()
{


}

void Shape::flipHor()
{double newW,newH;

}

QVariant Shape::itemChange(GraphicsItemChange change,
                           const QVariant &value)
{
    if(change==ItemPositionChange){

        npos=value.toPointF();

        rect->setRect(top.x(),top.y(),h,w);
        qDebug()<<"change";

        return npos;

    }
    if(change==ItemSelectedHasChanged){
        qDebug()<<value;
        if(value.toBool()==1
                ){

            rect->setRect(top.x(),top.y(),h,w);
            rect->setPen(QPen(Qt::DashLine));
            rect->setVisible(true);

        }
        else{rect->setVisible(false);}

    }
    return QGraphicsItem::itemChange(change, value);
}

