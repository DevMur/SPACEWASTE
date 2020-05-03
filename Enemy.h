#ifndef ENEMY_H
#define ENEMY_H

#include <QGraphicsPixmapItem>
#include <QObject>
#include <QGraphicsItem>

class Enemy: public QObject, public QGraphicsPixmapItem{
    Q_OBJECT
public:
    Enemy(QGraphicsItem * parent=0);

    int value = 10;
    int attack_pattern;
    int for_boss = false;
public slots:
    void move_easy();
};



#endif // ENEMY_H
