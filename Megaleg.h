#ifndef MEGALEG_H
#define MEGALEG_H

#include <QGraphicsPixmapItem>
#include <QObject>
#include <QGraphicsItem>

class Megaleg: public QObject, public QGraphicsPixmapItem{
    Q_OBJECT
public:
    Megaleg(QGraphicsItem * parent=0);

    void delay();
public slots:
    void movement();

    void attack_one();
};

#endif // MEGALEG_H
