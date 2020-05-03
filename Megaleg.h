#ifndef MEGALEG_H
#define MEGALEG_H

#include <QGraphicsPixmapItem>
#include <QObject>
#include <QGraphicsItem>

class Megaleg: public QObject, public QGraphicsPixmapItem{
    Q_OBJECT
public:
    Megaleg(QGraphicsItem * parent=0);

    void delay(int time);
public slots:
    void movement();

    void attack_one(int delay);
    void attack_two(int delay);
};

#endif // MEGALEG_H
