#ifndef MEGALEG_H
#define MEGALEG_H

#include <QGraphicsPixmapItem>
#include <QObject>
#include <QGraphicsItem>

class Megaleg: public QObject, public QGraphicsPixmapItem{
    Q_OBJECT
public:
    Megaleg(QGraphicsItem * parent=0);
public slots:
    void movement();
    //void attack();
};

#endif // MEGALEG_H
