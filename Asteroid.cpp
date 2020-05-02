#include <QTimer>
#include <QGraphicsScene>
#include <QList>
#include <stdlib.h>

#include "Asteroid.h"
#include "Game.h"

extern Game * game;

Asteroid::Asteroid(QGraphicsItem *parent){

    if (game->endGame == false)
    {
    //set random x position
    int random_number = rand() % 800;
    setPos(random_number,0);

    setPixmap(QPixmap(":/images/asteroid.jpeg")); //needs a different picture
    setTransformOriginPoint(50,50); //they can either have bigger badder versions
    setRotation(180);
    setScale(0.25);

    // make/connect a timer to move the enemy every so often
    QTimer * timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(move_asteroid()));

    // start the timer
    timer->start(100);
    }
}

void Asteroid::move_asteroid()
{
    QList<QGraphicsItem *> colliding_items = collidingItems();
    for (int i = 0, n = colliding_items.size(); i < n; ++i)
    {
        //qDebug("condition wrong");
        if (typeid(*(colliding_items[i])) == typeid(Player))
        {
            qDebug("BIG HIT");
            game->GameOver();
            scene()->removeItem(this);
            delete this;
            break;
        }
    }

    setPos(x(),y()+1);

    // destroy enemy when it goes out of the screen
    if (pos().y() > 800){
        scene()->removeItem(this);
        delete this;
    }
}

void Asteroid::decreaseHealth()
{
    asteroid_health--;
//    if (this->getHealth() == 0)
//    {
//        if (rand()%5 == 0)
//        {
//            scene()->addItem(spawn_ammo());
//        }
//    }
}




