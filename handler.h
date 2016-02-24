#ifndef HANDLER_H
#define HANDLER_H

#include <QObject>
#include <QDebug>
#include <QCursor>
#include <QMouseEvent>

class Handler : public QObject
{
    Q_OBJECT
public:
    explicit Handler(QObject *parent = 0);
    void getCursorPos();

signals:

public slots:
    
};

#endif // HANDLER_H
