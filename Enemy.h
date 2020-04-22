#ifndef ENEMY_H
#define ENEMY_H

#include <QGraphicsPixmapItem>
#include <QObject>
#include <QGraphicsItem>

class Enemy: public QObject,public QGraphicsPixmapItem{
    Q_OBJECT
public:
    Enemy(QGraphicsItem * parent=0);//crug
    //point value goes here, getter, const value. ugh test
public slots:
    void move_easy();
};
//Crug does the inverse of bullets but they have different spawn requirements.
//move could be renamed.
//TODO points of 1 work for now but increment point shouldn't be called hundreds of times...
//or should it...


#endif // ENEMY_H
