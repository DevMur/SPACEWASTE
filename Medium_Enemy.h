#ifndef MEDIUM_ENEMY_H
#define MEDIUM_ENEMY_H

#include <QGraphicsPixmapItem>
#include <QObject>
#include <QGraphicsItem>

#include "Enemy.h"

class Medium_Enemy: public Enemy{
    Q_OBJECT
public:
    Medium_Enemy(QGraphicsItem * parent=0);
    int value = 25;
public slots:
    void move_medium();
};


#endif // MEDIUM_ENEMY_H
