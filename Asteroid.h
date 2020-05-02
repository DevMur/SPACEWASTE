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

public slots:
    void move_asteroid();
};
#endif // ASTEROID_H
