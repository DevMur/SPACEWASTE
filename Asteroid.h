#ifndef ASTEROID_H
#define ASTEROID_H

#include <QGraphicsPixmapItem>
#include <QObject>
#include <QGraphicsItem>

#include "Enemy.h"

class Asteroid: public Enemy{
    Q_OBJECT
public:
    Asteroid(QGraphicsItem * parent=0);

    void decreaseHealth();
    int getHealth();

    //void spawn_ammo();

private:
    int asteroid_health;

public slots:
    void move_asteroid();
    //void move_ammo();
};
#endif // ASTEROID_H
