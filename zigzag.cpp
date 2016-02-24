#include "zigzag.h"

Zigzag::Zigzag(QMenu*m):Shape(m)
{
    angleRot=0;
    type=Shape::Zigzag;
    steps=4;
    dst=0;
}
void Zigzag::paint(QPainter *painter,
                   const QStyleOptionGraphicsItem *option, QWidget *widget)
{



    QPointF bot1=bot;

    double angle=0,ky=0,x,y;
    //    double distance=fabs(sqrt(pow(bot.x()-top.x(),2)
    //                              +pow(bot.y()-top.y(),2)));
    double distance=h;
    bot1.setX(top.x()+distance);
    bot1.setY(top.y()+distance);
    ky=(distance)/(steps*2)+dst;


    if(angleRot==0){
        x=top.x();
        y=top.y()+w;
        points.push_back(QPointF(top.x(),top.y()+w));
        for(int i=2;i<=steps*2;i++)
        {if((x)<(bot.x())){
                x+=ky;
                if(i%2==0 ){


                    y-=w;
                }
                else {

                    y+=w;
                }

            }
            points.append(QPointF(x+dst,y));
        }

        points.append(QPointF(bot.x(),bot.y()));
    }
    if(angleRot==180){
    ky=ky-x*dst;
        x=top.x();
        y=top.y();
        points.push_back(QPointF(top.x(),top.y()+dst));
        for(int i=2;i<=steps*4;i++)
        {if((x)<(bot.x())){
                x+=ky;
                if(i%2==0 ){
                    y+=w;
                }
                else {
                    y-=w;
                }

            }

            points.append(QPointF(x,y));
        }





    }


   // points.at()
    painter->setPen(pen);

    painter->drawPolyline(points);



    points.clear();

}

QRectF Zigzag::boundingRect()
{
    return QRectF(top.x(),points.at(1).y(),fabs(top.x()-bot.x())
                  ,fabs(points.at(1).y()-points.at(2).y()));
}

