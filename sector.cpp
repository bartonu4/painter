#include "sector.h"

Sector::Sector(QMenu *m):Shape(m)
{
    menu= m;

    elipseRt=new QGraphicsEllipseItem(this);
    elipseLt=new QGraphicsEllipseItem(this);
    type=Shape::Sector;
    angleRot=0;
}

void Sector::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{

calculatePoints();

painter->setPen(pen);
painter->setBrush(QBrush(brush.color()));
//        painter->drawLine(center,rt);
//        painter->drawLine(center,lt);
//        painter->drawArc(top.x(),top.y(),h,w,45*16,90*16);
double th,tw;

painter->drawPie(top.x(),top.y(),h,w,(angleBegin+angleRot)*16,(angleEnd-angleBegin)*16);

}

void Sector::calculatePoints()
{

    lt.setX(top.x());
    lt.setY(top.y());
    rt.setX(bot.x());
    rt.setY(top.y());

    center.setX((top.x()+bot.x())/2);
    center.setY((top.y()+bot.y())/2);
    double catL,catP,hipP,hipL,sinnP,sinnL;
    catL=fabs(lt.y()-center.y());
     hipL=sqrt(pow(lt.x()-center.x(),2)+pow(lt.y()-center.y(),2));
     sinnL=catL/hipL;
     angleBegin =asin(sinnL)*180/PI;

     catP=fabs(rt.y()-center.y());
     hipP=sqrt(pow(rt.x()-center.x(),2)+pow(rt.y()-center.y(),2));
     sinnP=catP/hipP;
     angleEnd =180-asin(sinnP)*180/PI;

}

void Sector::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{

//    if(conl){

//    rt=event->scenePos();
//bounds.setRect(lt.x(),lt.y(),h,w);
//    }
//    if(conr){
//    lt=event->scenePos();
//    bounds.setRect(lt.x(),lt.y(),fabs(rt.x()-lt.x()),fabs(lt.y()-rt.y()));
//    }
//    else{
Shape::mouseMoveEvent(event);}
//}

void Sector::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    if(elipseRt->contains(event->pos())){
    conr=true;
    }
    if(elipseLt->contains(event->pos())){
    conl=true;
    }
    if(!elipseLt->contains(event->pos())&&!elipseRt->contains(event->pos()))
         {
             conl=false;
             conr=false;
             Shape::mousePressEvent(event);
    }
}


