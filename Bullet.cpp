#include "Bullet.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QList>
#include "Enemy.h"
#include "Game.h"

extern Game * game; // there is an external global object called game

Bullet::Bullet(QGraphicsItem *parent): QObject(), QGraphicsPixmapItem(parent){
    // draw graphics
    setPixmap(QPixmap(":/images/PewGun.png"));
    setScale(0.25); //it's too big
    setRotation(90);//it's sideways


    //connect a timer to move() the bullet every so often
    QTimer * timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));

    //after review the speed stays.
    timer->start(50);
}

void Bullet::move(){

    QList<QGraphicsItem *> colliding_items = collidingItems();// get a list of all the items currently colliding with this bullet

    for (int i = 0, n = colliding_items.size(); i < n; ++i)// if one of the colliding items is an Enemy, destroy both the bullet and the enemy
    {
        if (typeid(*(colliding_items[i])) == typeid(Enemy))
        {
            game->score->increase();// increase the score

            scene()->removeItem(colliding_items[i]);// still on heap so remove, best practice?
            scene()->removeItem(this);

            delete colliding_items[i]; // delete them from the heap to save memory
            delete this;

            return;
        }
    }

    // if there was no collision with an Enemy, move the bullet forward
    setPos(x(),y()-10);
    // if the bullet is off the screen, destroy it
    if (pos().y() < 0){
        scene()->removeItem(this);
        delete this;
    }
}
