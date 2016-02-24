/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QVBoxLayout *verticalLayout_6;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButton_4;
    QPushButton *pushButton_3;
    QPushButton *pushButton_2;
    QPushButton *pushButton;
    QPushButton *colorButton;
    QPushButton *lineColor;
    QPushButton *toFront;
    QPushButton *sendBack;
    QPushButton *flipV;
    QPushButton *flipH;
    QVBoxLayout *verticalLayout_3;
    QLabel *label_2;
    QSlider *opacitySlider;
    QVBoxLayout *verticalLayout_5;
    QLabel *label_6;
    QSlider *startSlider;
    QVBoxLayout *verticalLayout_2;
    QLabel *label;
    QComboBox *lineBox;
    QGraphicsView *graphicsView;
    QWidget *widget;
    QVBoxLayout *verticalLayout_4;
    QLabel *label_3;
    QLineEdit *zigLine;
    QLabel *label_4;
    QLineEdit *zigLine_2;
    QLabel *label_5;
    QLineEdit *zigLine_3;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->setWindowModality(Qt::ApplicationModal);
        MainWindow->resize(1764, 1031);
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(1);
        sizePolicy.setVerticalStretch(1);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(centralWidget->sizePolicy().hasHeightForWidth());
        centralWidget->setSizePolicy(sizePolicy1);
        verticalLayoutWidget = new QWidget(centralWidget);
        verticalLayoutWidget->setObjectName(QStringLiteral("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(140, 0, 1611, 931));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setSizeConstraint(QLayout::SetNoConstraint);
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setSpacing(6);
        verticalLayout_6->setObjectName(QStringLiteral("verticalLayout_6"));

        verticalLayout->addLayout(verticalLayout_6);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        pushButton_4 = new QPushButton(verticalLayoutWidget);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));
        QIcon icon;
        icon.addFile(QStringLiteral(":/images/pointer.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_4->setIcon(icon);
        pushButton_4->setIconSize(QSize(32, 32));

        horizontalLayout->addWidget(pushButton_4);

        pushButton_3 = new QPushButton(verticalLayoutWidget);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/images/ellipse.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_3->setIcon(icon1);
        pushButton_3->setIconSize(QSize(32, 32));

        horizontalLayout->addWidget(pushButton_3);

        pushButton_2 = new QPushButton(verticalLayoutWidget);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        QIcon icon2;
        icon2.addFile(QStringLiteral("images/zig.jpg"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_2->setIcon(icon2);
        pushButton_2->setIconSize(QSize(32, 32));

        horizontalLayout->addWidget(pushButton_2);

        pushButton = new QPushButton(verticalLayoutWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/images/sec.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton->setIcon(icon3);
        pushButton->setIconSize(QSize(32, 32));

        horizontalLayout->addWidget(pushButton);

        colorButton = new QPushButton(verticalLayoutWidget);
        colorButton->setObjectName(QStringLiteral("colorButton"));
        QIcon icon4;
        icon4.addFile(QStringLiteral(":/images/floodfill.png"), QSize(), QIcon::Normal, QIcon::Off);
        colorButton->setIcon(icon4);
        colorButton->setIconSize(QSize(32, 32));

        horizontalLayout->addWidget(colorButton);

        lineColor = new QPushButton(verticalLayoutWidget);
        lineColor->setObjectName(QStringLiteral("lineColor"));
        lineColor->setMouseTracking(false);
        QIcon icon5;
        icon5.addFile(QStringLiteral(":/images/linecolor.png"), QSize(), QIcon::Normal, QIcon::Off);
        lineColor->setIcon(icon5);
        lineColor->setIconSize(QSize(32, 32));

        horizontalLayout->addWidget(lineColor);

        toFront = new QPushButton(verticalLayoutWidget);
        toFront->setObjectName(QStringLiteral("toFront"));
        QIcon icon6;
        icon6.addFile(QStringLiteral(":/images/bringtofront.png"), QSize(), QIcon::Normal, QIcon::Off);
        toFront->setIcon(icon6);
        toFront->setIconSize(QSize(32, 32));

        horizontalLayout->addWidget(toFront);

        sendBack = new QPushButton(verticalLayoutWidget);
        sendBack->setObjectName(QStringLiteral("sendBack"));
        QIcon icon7;
        icon7.addFile(QStringLiteral(":/images/sendtoback.png"), QSize(), QIcon::Normal, QIcon::Off);
        sendBack->setIcon(icon7);
        sendBack->setIconSize(QSize(32, 32));

        horizontalLayout->addWidget(sendBack);

        flipV = new QPushButton(verticalLayoutWidget);
        flipV->setObjectName(QStringLiteral("flipV"));
        QIcon icon8;
        icon8.addFile(QStringLiteral(":/images/flipV.png"), QSize(), QIcon::Normal, QIcon::Off);
        flipV->setIcon(icon8);
        flipV->setIconSize(QSize(32, 32));

        horizontalLayout->addWidget(flipV);

        flipH = new QPushButton(verticalLayoutWidget);
        flipH->setObjectName(QStringLiteral("flipH"));
        QIcon icon9;
        icon9.addFile(QStringLiteral(":/images/flipH.png"), QSize(), QIcon::Normal, QIcon::Off);
        flipH->setIcon(icon9);
        flipH->setIconSize(QSize(32, 32));

        horizontalLayout->addWidget(flipH);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        label_2 = new QLabel(verticalLayoutWidget);
        label_2->setObjectName(QStringLiteral("label_2"));

        verticalLayout_3->addWidget(label_2);

        opacitySlider = new QSlider(verticalLayoutWidget);
        opacitySlider->setObjectName(QStringLiteral("opacitySlider"));
        opacitySlider->setEnabled(true);
        opacitySlider->setSliderPosition(50);
        opacitySlider->setOrientation(Qt::Horizontal);

        verticalLayout_3->addWidget(opacitySlider);


        horizontalLayout->addLayout(verticalLayout_3);

        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setSpacing(6);
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        label_6 = new QLabel(verticalLayoutWidget);
        label_6->setObjectName(QStringLiteral("label_6"));

        verticalLayout_5->addWidget(label_6);

        startSlider = new QSlider(verticalLayoutWidget);
        startSlider->setObjectName(QStringLiteral("startSlider"));
        startSlider->setEnabled(true);
        startSlider->setMinimum(-10);
        startSlider->setMaximum(10);
        startSlider->setPageStep(1);
        startSlider->setValue(0);
        startSlider->setSliderPosition(0);
        startSlider->setOrientation(Qt::Horizontal);

        verticalLayout_5->addWidget(startSlider);


        horizontalLayout->addLayout(verticalLayout_5);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        label = new QLabel(verticalLayoutWidget);
        label->setObjectName(QStringLiteral("label"));

        verticalLayout_2->addWidget(label);

        lineBox = new QComboBox(verticalLayoutWidget);
        QIcon icon10;
        icon10.addFile(QStringLiteral(":/images/line1.png"), QSize(), QIcon::Normal, QIcon::Off);
        lineBox->addItem(icon10, QString());
        QIcon icon11;
        icon11.addFile(QStringLiteral(":/images/line2.png"), QSize(), QIcon::Normal, QIcon::Off);
        lineBox->addItem(icon11, QString());
        QIcon icon12;
        icon12.addFile(QStringLiteral(":/images/line3.png"), QSize(), QIcon::Normal, QIcon::Off);
        lineBox->addItem(icon12, QString());
        lineBox->setObjectName(QStringLiteral("lineBox"));
        lineBox->setIconSize(QSize(50, 20));

        verticalLayout_2->addWidget(lineBox);


        horizontalLayout->addLayout(verticalLayout_2);


        verticalLayout->addLayout(horizontalLayout);

        graphicsView = new QGraphicsView(verticalLayoutWidget);
        graphicsView->setObjectName(QStringLiteral("graphicsView"));

        verticalLayout->addWidget(graphicsView);

        widget = new QWidget(centralWidget);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(20, 100, 121, 281));
        verticalLayout_4 = new QVBoxLayout(widget);
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setContentsMargins(11, 11, 11, 11);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        verticalLayout_4->setContentsMargins(0, 0, 0, 0);
        label_3 = new QLabel(widget);
        label_3->setObjectName(QStringLiteral("label_3"));

        verticalLayout_4->addWidget(label_3);

        zigLine = new QLineEdit(widget);
        zigLine->setObjectName(QStringLiteral("zigLine"));

        verticalLayout_4->addWidget(zigLine);

        label_4 = new QLabel(widget);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setEnabled(false);

        verticalLayout_4->addWidget(label_4);

        zigLine_2 = new QLineEdit(widget);
        zigLine_2->setObjectName(QStringLiteral("zigLine_2"));
        zigLine_2->setEnabled(false);

        verticalLayout_4->addWidget(zigLine_2);

        label_5 = new QLabel(widget);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setEnabled(false);

        verticalLayout_4->addWidget(label_5);

        zigLine_3 = new QLineEdit(widget);
        zigLine_3->setObjectName(QStringLiteral("zigLine_3"));
        zigLine_3->setEnabled(false);

        verticalLayout_4->addWidget(zigLine_3);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1764, 21));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        mainToolBar->addSeparator();

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
#ifndef QT_NO_TOOLTIP
        pushButton_4->setToolTip(QApplication::translate("MainWindow", "None", 0));
#endif // QT_NO_TOOLTIP
        pushButton_4->setText(QString());
#ifndef QT_NO_TOOLTIP
        pushButton_3->setToolTip(QApplication::translate("MainWindow", "Ellipse", 0));
#endif // QT_NO_TOOLTIP
        pushButton_3->setText(QString());
#ifndef QT_NO_TOOLTIP
        pushButton_2->setToolTip(QApplication::translate("MainWindow", "ZiGZAG", 0));
#endif // QT_NO_TOOLTIP
        pushButton_2->setText(QString());
#ifndef QT_NO_TOOLTIP
        pushButton->setToolTip(QApplication::translate("MainWindow", "Sector", 0));
#endif // QT_NO_TOOLTIP
        pushButton->setText(QString());
#ifndef QT_NO_TOOLTIP
        colorButton->setToolTip(QApplication::translate("MainWindow", "Brush Color", 0));
#endif // QT_NO_TOOLTIP
        colorButton->setText(QString());
#ifndef QT_NO_TOOLTIP
        lineColor->setToolTip(QApplication::translate("MainWindow", "Line Color", 0));
#endif // QT_NO_TOOLTIP
        lineColor->setText(QString());
#ifndef QT_NO_TOOLTIP
        toFront->setToolTip(QApplication::translate("MainWindow", "Bring to Front", 0));
#endif // QT_NO_TOOLTIP
        toFront->setText(QString());
#ifndef QT_NO_TOOLTIP
        sendBack->setToolTip(QApplication::translate("MainWindow", "Send to Back", 0));
#endif // QT_NO_TOOLTIP
        sendBack->setText(QString());
        flipV->setText(QString());
        flipH->setText(QString());
        label_2->setText(QApplication::translate("MainWindow", "Opacity", 0));
        label_6->setText(QApplication::translate("MainWindow", "Start", 0));
        label->setText(QApplication::translate("MainWindow", "Line Width", 0));
        lineBox->setItemText(0, QString());
        lineBox->setItemText(1, QString());
        lineBox->setItemText(2, QString());

        label_3->setText(QApplication::translate("MainWindow", "Zigzag steps", 0));
        label_4->setText(QApplication::translate("MainWindow", "Angle Begin", 0));
        label_5->setText(QApplication::translate("MainWindow", "Angle End", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
