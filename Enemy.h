#ifndef ENEMY_H
#define ENEMY_H

#include <QObject>
#include <QGraphicsRectItem>
//include crug sprite here

class Enemy: public QObject, public QGraphicsRectItem{
    Q_OBJECT
public:
    Enemy(); //crug
    //point value goes here, getter, const value.
public slots:
    void move();
};
#endif // ENEMY_H
