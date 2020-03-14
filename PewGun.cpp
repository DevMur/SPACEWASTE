#include <QTimer>
#include <QGraphicsScene>
#include <QList>
#include "PewGun.h"
#include "Enemy.h"

PewGun::PewGun(){
    //draw the bullet, to be edited/cleaned
    setRect(20, 0, 10, 50);

    //connect to ship
    QTimer * gun_timer = new QTimer();
    PewGun::connect(gun_timer, SIGNAL(timeout()), this, SLOT(move()));

    gun_timer->start(50); //rates to be edited based on play testing and how it looks
}

void PewGun::move(){
    //destroy enemies
    QList<QGraphicsItem *> colliding_items = collidingItems(); //houses all items the bullet item is colliding with
    for (int i = 0, collisions_min_found = colliding_items.size(); i < collisions_min_found; i++)
    {
        if (typeid (*colliding_items[i]) == typeid(Enemy))
        {
            scene()->removeItem(colliding_items[i]); //must also add points here
            scene()->removeItem(this);
            //delete from memory? stackoverflow says this is standard;
            delete colliding_items[i];
            delete this;
            return;
        }
    }

    //let the bullet fly, rate tbd on testing and games vibe
    setPos(x(), y()-10);
    if (pos().y() + rect().height() < 0)
    {
        scene()->removeItem(this);
        delete this;
        //qDebug() << "bullet off screen";
    }

    /*
        add function to delay the rate at which pew bullets can fly
        also       
            combine with input lag/one input dominating others.
    */
}
