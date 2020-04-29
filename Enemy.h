#ifndef ENEMY_H
#define ENEMY_H

#include <QGraphicsPixmapItem>
#include <QObject>
#include <QGraphicsItem>

class Enemy: public QObject, public QGraphicsPixmapItem{
    Q_OBJECT
public:
    Enemy(QGraphicsItem * parent=0);//crug
    //point value goes here, getter, const value. ugh test
    int value = 10;
    int attack_pattern;
public slots:
    void move_easy();
};



#endif // ENEMY_H
