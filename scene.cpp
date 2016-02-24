#include "scene.h"



GScene::GScene(QMenu *m)
{
    menu=m;
    setSceneRect(0,0,500,500);
    i=0;
    mode=InsertItem;
    type=Shape::Ellipse;
    selects=false;
}

void GScene::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    if(event->button()==Qt::LeftButton&&mode==InsertItem){


        start=event->scenePos();
        if(type==Shape::Ellipse){
            item= new Shape(menu);}
        if(type==Shape::Zigzag){
            item=new Zigzag(menu);
        }
        if(type==Shape::Sector){
            item=new Sector(menu);
        }


    }
    if(event->button()==Qt::RightButton){

        Shape *tempItem=dynamic_cast<Shape*>(itemAt(event->scenePos(),QTransform()));
        if(tempItem!=NULL){

            tempItem->setSelected(true);
        }

    }
    qDebug()<<"scene press"<<event->scenePos();


    if(selects==true){

        Shape * tempItem=dynamic_cast<Shape*>(itemAt(event->scenePos(),QTransform()));
        if(tempItem!=NULL){

            tempItem->setSelected(true);
        }
    }



    ///Restyle
    foreach(QGraphicsItem* it ,selectedItems()){
        Shape* itt= dynamic_cast<Shape*>(it);
        if(it->isSelected())
            itt->setPenStyle(Qt::SolidLine);
        setModeSelected();
    }
    QGraphicsScene::mousePressEvent(event);
}

//void GScene::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
//{

////    foreach(QGraphicsItem* it ,selectedItems()){
////       Shape* itt= dynamic_cast<Shape*>(it);
////  itt->mouseMoveEvent(event);
////    }
////    qDebug()<<"move"<<event->scenePos();

//}

void GScene::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{

    if(mode==InsertItem){
        item->setTop(start.x(),start.y());

        end=event->scenePos();
        item->setBottom(end.x(),end.y());
        item->drawT();
        item->drawB();
        addItem(item);
        qDebug()<<"scene release";

    }

    else{
        QGraphicsScene::mouseReleaseEvent(event);
    }
}

void GScene::keyPressEvent(QKeyEvent *event)
{
    if(event->key()==Qt::Key_Shift){

        selects=true;
    }
}

void GScene::keyReleaseEvent(QKeyEvent *event)
{
    if(event->key()==Qt::Key_Shift){

        selects=false;
    }
}

void GScene::setModeSelected()
{

    mode =SelectedItem;
}

void GScene::setModeInsert()
{
    mode=InsertItem;
}

void GScene::setOpacity(int op)
{
    foreach(QGraphicsItem* it ,selectedItems()){
        Shape* itt= dynamic_cast<Shape*>(it);
        if(it->isSelected()){
            double opac=(double)op/100;
            itt->setOpacity(opac);}
    }
}

void GScene::setLineWidth(int lwidth)
{foreach(QGraphicsItem* it ,selectedItems()){
        Shape* itt= dynamic_cast<Shape*>(it);
        if(it->isSelected())
            itt->pen.setWidth(lwidth+1);
    }
}

void GScene::setTypeEl()
{
    type=Shape::Ellipse;
}



void GScene::deleteItem()
{
    foreach(QGraphicsItem* it ,selectedItems()){
        Shape* itt= dynamic_cast<Shape*>(it);
        if(it->isSelected())
            removeItem(itt);
    }
}

void GScene::setBrushColor(QColor colr)
{
    color=colr;

    foreach(QGraphicsItem* it ,selectedItems()){
        Shape* itt= dynamic_cast<Shape*>(it);
        if(it->isSelected())
            itt->setBrushColor(color);
    }
}

void GScene::setPenColor(QColor colr)
{
    foreach(QGraphicsItem* it ,selectedItems()){
        Shape* itt= dynamic_cast<Shape*>(it);
        if(it->isSelected())
            itt->pen.setColor(colr);
    }
}

void GScene::clearAll()
{
    foreach(QGraphicsItem* it ,items()){
        Shape* itt= dynamic_cast<Shape*>(it);

        removeItem(itt);
    }
}

void GScene::flipVer()
{
    QPointF max,min,center;

    min=dynamic_cast<Shape*>(selectedItems().first())->returnTop();
    max=dynamic_cast<Shape*>(selectedItems().first())->returnTop();
    foreach(QGraphicsItem* it ,selectedItems()){
        Shape* itt= dynamic_cast<Shape*>(it);
        if(min.x()>itt->returnTop().x()){
            min.setX(itt->returnTop().x());
        }
        if(max.x()<itt->returnBot().x()){
            max.setX(itt->returnBot().x());
        }

    }
    center.setX((max.x()+min.x())/2);
    foreach(QGraphicsItem* it ,selectedItems()){
        Shape* itt= dynamic_cast<Shape*>(it);
        itt->setTop(2*center.x()-itt->returnTop().x()-itt->h,itt->returnTop().y());
        itt->setBottom(itt->returnTop().x()+itt->h,itt->returnBot().y());
        itt->drawB();
        itt->drawT();
        itt->rect->setRect(itt->returnTop().x(),itt->returnTop().y(),itt->h,itt->w);
        if(/*itt->type==Shape::Sector||*/itt->type==Shape::Zigzag){
            if(itt->angleRot==0) {itt->angleRot=180;}
            else {itt->angleRot=0;}
        }
    }

}

void GScene::flipHor()
{  QPointF max,min,center;

    min=dynamic_cast<Shape*>(selectedItems().first())->returnTop();
    max=dynamic_cast<Shape*>(selectedItems().first())->returnTop();
    foreach(QGraphicsItem* it ,selectedItems()){
        Shape* itt= dynamic_cast<Shape*>(it);
        if(max.y()>itt->returnTop().y()){
            max.setY(itt->returnTop().y());
        }
        if(min.y()<itt->returnBot().y()){
            min.setY(itt->returnBot().y());
        }

    }
    center.setY((max.y()+min.y())/2);
    foreach(QGraphicsItem* it ,selectedItems()){
        Shape* itt= dynamic_cast<Shape*>(it);
        itt->setTop(itt->returnTop().x(),2*center.y()-itt->returnTop().y()-itt->w);
        itt->setBottom(itt->returnBot().x(),itt->returnTop().y()+itt->w);
        itt->drawB();
        itt->drawT();
        itt->rect->setRect(itt->returnTop().x(),itt->returnTop().y(),itt->h,itt->w);
        if(itt->type==Shape::Sector||itt->type==Shape::Zigzag){
            if(itt->angleRot==0) {itt->angleRot=180;}
            else {itt->angleRot=0;}
        }
    }
}

void GScene::save(QString fileName)
{
    QDomDocument doc;

    QDomElement mainElement = doc.createElement("Scene");
    doc.appendChild(mainElement);
    foreach(QGraphicsItem* it ,items()){
        it->setSelected(true);

    }
    foreach(QGraphicsItem* it ,selectedItems()){
        Shape* itt= dynamic_cast<Shape*>(it);
        QString typeName;
        switch (itt->type){
        case Shape::Ellipse: typeName="Ellipse";
            break;
        case Shape::Zigzag: typeName ="Zigzag";
            break;
        case Shape::Sector: typeName ="Sector";
            break;
        }
        QDomElement element=doc.createElement(typeName);
        QDomElement el=doc.createElement("TopLeft");
        el.setAttribute("x",itt->returnTop().x());
        el.setAttribute("y",itt->returnTop().y());
        element.appendChild(el);

        el=doc.createElement("BottomRight");
        el.setAttribute("x",itt->returnBot().x());
        el.setAttribute("y",itt->returnBot().y());
        element.appendChild(el);

        el=doc.createElement("Pen");
        el.setAttribute("Width",itt->pen.width());
        el.setAttribute("Style",itt->pen.style());
        // QDomElement penCol=doc.createElement("PenCol");
        el.setAttribute("LineColor",itt->pen.color().rgba());
        el.setAttribute("BrushColor",itt->brush.color().rgba());
        el.setAttribute("Opacity",itt->opacity());
        element.appendChild(el);

        el=doc.createElement("AngleRot");
        el.setAttribute("Angle",itt->angleRot);
        element.appendChild(el);
        if(itt->type==Shape::Zigzag){

            el=doc.createElement("Steps");
            el.setAttribute("Steps",itt->steps);
            element.appendChild(el);
        }
        mainElement.appendChild(element);
    }


    QFile file(fileName);
    file.open(QIODevice::WriteOnly);
    QTextStream str(&file);
    //    QDomNode node( doc.createProcessingInstruction( "xml", "version=\"1.0\" standalone=\"no\"" ));
    //    doc.insertBefore( node, doc.firstChild() );
    doc.save(str, 8);
    file.flush();
    file.close();
}

void GScene::open(QString fileName)
{
    clearAll();
    QFile file(fileName);
    if ( ! file.open(QIODevice::ReadOnly |QIODevice::Text)) {
        qDebug() << "error!";
        return;
    }
    QString error;
    int line, col;
    QDomDocument doc;
    if ( ! doc.setContent(&file, &error, &line, &col)) {
        qDebug() << error <<"  "<<line<<"  "<<col;
        return;
    }
    file.close();
    QDomElement mainElement = doc.firstChildElement();


    QDomNodeList items = mainElement.elementsByTagName("Ellipse");
    for (int i=0; i< items.count(); i++)
    {
        QDomNode item = items.at(i);
        if ( ! item.isElement())
            continue;
        QDomElement elem = item.toElement();
        QDomElement topLeft = elem.firstChildElement();
        QDomElement bottomR = elem.elementsByTagName("BottomRight").at(0).toElement();
        Shape *shape=new Shape(menu);
        shape->setTop(topLeft.attribute("x").toDouble(),topLeft.attribute("y").toDouble());
        shape->setBottom(bottomR.attribute("x").toDouble(),bottomR.attribute("y").toDouble());


        QDomElement newPen = elem.elementsByTagName("Pen").at(0).toElement();
        shape->pen.setWidth(newPen.attribute("Width").toInt());
        shape->pen.setStyle(Qt::PenStyle(newPen.attribute("Style").toInt()));
        shape->pen.setColor(QColor(QRgb(newPen.attribute("LineColor").toUInt())));
        shape->brush.setColor(QColor(QRgb(newPen.attribute("BrushColor").toUInt())));
        shape->setOpacity(newPen.attribute("Opacity").toDouble());
        QDomElement angle=elem.elementsByTagName("AngleRot").at(0).toElement();
        shape->angleRot=angle.attribute("Angle").toInt();

        addItem(shape);

    }
    items = mainElement.elementsByTagName("Sector");
    for (int i=0; i< items.count(); i++)
    {
        QDomNode item = items.at(i);
        if ( ! item.isElement())
            continue;
        QDomElement elem = item.toElement();
        QDomElement topLeft = elem.firstChildElement();
        QDomElement bottomR = elem.elementsByTagName("BottomRight").at(0).toElement();
        Shape *shape=new Sector(menu);
        shape->setTop(topLeft.attribute("x").toDouble(),topLeft.attribute("y").toDouble());
        shape->setBottom(bottomR.attribute("x").toDouble(),bottomR.attribute("y").toDouble());


        QDomElement newPen = elem.elementsByTagName("Pen").at(0).toElement();
        shape->pen.setWidth(newPen.attribute("Width").toInt());
        shape->pen.setStyle(Qt::PenStyle(newPen.attribute("Style").toInt()));
        shape->pen.setColor(QColor(QRgb(newPen.attribute("LineColor").toUInt())));
        shape->brush.setColor(QColor(QRgb(newPen.attribute("BrushColor").toUInt())));
        shape->setOpacity(newPen.attribute("Opacity").toDouble());
        QDomElement angle=elem.elementsByTagName("AngleRot").at(0).toElement();
        shape->angleRot=angle.attribute("Angle").toInt();


        addItem(shape);

    }
    items = mainElement.elementsByTagName("Zigzag");
    for (int i=0; i< items.count(); i++)
    {
        QDomNode item = items.at(i);
        if ( ! item.isElement())
            continue;
        QDomElement elem = item.toElement();
        QDomElement topLeft = elem.firstChildElement();
        QDomElement bottomR = elem.elementsByTagName("BottomRight").at(0).toElement();
        Shape *shape=new Zigzag(menu);
        shape->setTop(topLeft.attribute("x").toDouble(),topLeft.attribute("y").toDouble());
        shape->setBottom(bottomR.attribute("x").toDouble(),bottomR.attribute("y").toDouble());


        QDomElement newPen = elem.elementsByTagName("Pen").at(0).toElement();
        shape->pen.setWidth(newPen.attribute("Width").toInt());
        shape->pen.setStyle(Qt::PenStyle(newPen.attribute("Style").toInt()));
        shape->pen.setColor(QColor(QRgb(newPen.attribute("LineColor").toUInt())));
        shape->brush.setColor(QColor(QRgb(newPen.attribute("BrushColor").toUInt())));
        shape->setOpacity(newPen.attribute("Opacity").toDouble());
        QDomElement angle=elem.elementsByTagName("AngleRot").at(0).toElement();
        shape->angleRot=angle.attribute("Angle").toInt();

        QDomElement stepss=elem.elementsByTagName("Steps").at(0).toElement();
        shape->steps=stepss.attribute("Steps").toInt();

        addItem(shape);
    }
}

void GScene::setSteps(QString st)
{
    foreach(QGraphicsItem* it ,selectedItems()){
        Shape* itt= dynamic_cast<Shape*>(it);
        if(itt->type==Shape::Zigzag){

            itt->steps =st.toInt();
        }
    }
}

void GScene::setStartP(int d)
{
    foreach(QGraphicsItem* it ,selectedItems()){
        Shape* itt= dynamic_cast<Shape*>(it);
        if(itt->type==Shape::Zigzag){

            itt->dst =d;
            itt->update();
        }
    }
}

void GScene::setTypeSek()
{
    type=Shape::Sector;
}

void GScene::setTypeZig()
{
    type=Shape::Zigzag;
}
