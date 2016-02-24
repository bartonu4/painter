#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "handler.h"
#include "scene.h"
#include <QVBoxLayout>

#include <QFile>
#include <QFileDialog>
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    // void mousePressEvent(QMouseEvent *mouseEvent);

private:
    QColor color;
    QAction *del,*clearAll,*opened,*saved,*imExport;
    QMenu *itemMenu,*fileMenu;
    Ui::MainWindow *ui;
    Handler handl;
    Shape::Type type;
GScene *scene;
void prepareButtons();
void createMenu();
void createActions();
public slots:
    void setSelected();
    void setInserted();
    void setBrushColor();
    void setPenColor();
    void sendToBack();
    void bringToFront();
    void open();
    void save();
    void exportImage();

};

#endif // MAINWINDOW_H
