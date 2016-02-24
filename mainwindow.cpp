#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    createMenu();
    scene=new GScene(itemMenu);
    createActions();


    ui->graphicsView->setRenderHint(QPainter::Antialiasing);
    ui->graphicsView->setScene(scene);
    prepareButtons();



}

MainWindow::~MainWindow()
{
    delete ui;
    delete scene;
}


void  MainWindow::prepareButtons(){

    connect(ui->pushButton_4,SIGNAL(clicked()),this,SLOT(setSelected()));

    connect(ui->pushButton,SIGNAL(clicked()),this,SLOT(setInserted()));
    connect(ui->pushButton_2,SIGNAL(clicked()),this,SLOT(setInserted()));
    connect(ui->pushButton_3,SIGNAL(clicked()),this,SLOT(setInserted()));

    connect(ui->pushButton_3,SIGNAL(clicked()),scene,SLOT(setTypeEl()));
    connect(ui->pushButton_2,SIGNAL(clicked()),scene,SLOT(setTypeZig()));
    connect(ui->pushButton,SIGNAL(clicked()),scene,SLOT(setTypeSek()));
    connect(ui->colorButton,SIGNAL(clicked()),this,SLOT(setBrushColor()));
    connect(ui->lineColor,SIGNAL(clicked()),this,SLOT(setPenColor()));
    connect(ui->toFront,SIGNAL(clicked()),this,SLOT(bringToFront()));
    connect(ui->sendBack,SIGNAL(clicked()),this,SLOT(sendToBack()));
    connect(ui->opacitySlider,SIGNAL(valueChanged(int)),scene,SLOT(setOpacity(int)));
    connect(ui->lineBox,SIGNAL(activated(int)),scene,SLOT(setLineWidth(int)));
    connect(ui->lineBox,SIGNAL(currentIndexChanged(int)),scene,SLOT(setLineWidth(int)));
    connect(ui->flipH,SIGNAL(clicked()),scene,SLOT(flipHor()));
    connect(ui->flipV,SIGNAL(clicked()),scene,SLOT(flipVer()));
 connect(ui->startSlider,SIGNAL(valueChanged(int)),scene,SLOT(setStartP(int)));
}

void MainWindow::createMenu()
{   fileMenu=menuBar()->addMenu(tr("File"));
    itemMenu=menuBar()->addMenu(tr("Item"));


}
void MainWindow::createActions()
{
    del=new QAction(tr("Delete"),this);
    clearAll=new QAction(tr("Clear all"),this);
    opened=new QAction(tr("Open"),this);
    saved=new QAction(tr("Save"),this);
    imExport=new QAction(tr("Export"),this);
    connect(del,SIGNAL(triggered()),scene,SLOT(deleteItem()));
    connect(clearAll,SIGNAL(triggered()),scene,SLOT(clearAll()));
    connect(saved,SIGNAL(triggered()),this,SLOT(save()));
    connect(opened,SIGNAL(triggered()),this,SLOT(open()));
    connect(imExport,SIGNAL(triggered()),this,SLOT(exportImage()));
    connect(ui->zigLine,SIGNAL(textChanged(QString)),scene,SLOT(setSteps(QString)));

    itemMenu->addAction(del);
    itemMenu->addAction(clearAll);
    fileMenu->addAction(opened);
    fileMenu->addAction(saved);
    fileMenu->addAction(imExport);
}

void MainWindow::setSelected(){
    scene->setModeSelected();
}
void MainWindow::setInserted(){
    scene->setModeInsert();
}

void MainWindow::setBrushColor()
{color=QColorDialog::getColor( Qt::red, this);
    scene->setBrushColor(color);
}

void MainWindow::setPenColor()
{color=QColorDialog::getColor( Qt::red, this);
    scene->setPenColor(color);
}

void MainWindow::bringToFront(){
    if (scene->selectedItems().isEmpty())
        return;

    QGraphicsItem *selectedItem = scene->selectedItems().first();
    QList<QGraphicsItem *> overlapItems = selectedItem->collidingItems();

    qreal zValue = 0;
    foreach (QGraphicsItem *item, overlapItems) {
        if (item->zValue() >= zValue )
            zValue = item->zValue() + 0.1;
    }
    selectedItem->setZValue(zValue);
}
void MainWindow::sendToBack(){

    if (scene->selectedItems().isEmpty())
        return;

    QGraphicsItem *selectedItem = scene->selectedItems().first();
    QList<QGraphicsItem *> overlapItems = selectedItem->collidingItems();

    qreal zValue = 0;
    foreach (QGraphicsItem *item, overlapItems) {
        if (item->zValue() <= zValue )
            zValue = item->zValue() - 0.1;
    }
    selectedItem->setZValue(zValue);

}
void MainWindow::save(){
    QString fileName=QFileDialog::getSaveFileName(this,tr("Save File"),
                                                  "scene",tr("*.xml"));

  scene->save(fileName);



}
void MainWindow::open(){
    QString fileName=QFileDialog::getOpenFileName(this,tr("Open File"),
                                                  "",tr("*.xml"));
scene->open(fileName);
}
void MainWindow::exportImage(){
    QString fileName=QFileDialog::getSaveFileName(this,tr("Export File"),
                                                  "export",tr("*.png"));
    qDebug()<<fileName;
    QImage image(500,500,
                 QImage::Format_ARGB32_Premultiplied);
    QPainter painter(&image);
    scene->render(&painter);
    image.save(fileName);





}
