#ifndef HARD_ENEMY_H
#define HARD_ENEMY_H

#include <QGraphicsPixmapItem>
#include <QObject>
#include <QGraphicsItem>

class Hard_Enemy: public QObject,public QGraphicsPixmapItem{
    Q_OBJECT
public:
    Hard_Enemy(QGraphicsItem * parent=0);//medium
    //point value goes here, getter, const value. ugh test
public slots:
    void move_hard();
};
//enemies does the inverse of bullets but they have different spawn requirements.
//move could be renamed.
//TODO points of 1 work for now but increment point shouldn't be called hundreds of times...
//or should it...

#endif // HARD_ENEMY_H
