#include <QTimer>
#include <QGraphicsScene>
#include <QList>

#include "Bullet.h"
#include "Enemy.h"
#include "Medium_Enemy.h"
#include "Hard_Enemy.h"
#include "Asteroid.h"
#include "Game.h"
#include "Player.h"
#include "Score.h"

extern Game * game; // there is an external global object called game


Bullet::Bullet(QGraphicsItem *parent): QObject(), QGraphicsPixmapItem(parent){

    setPixmap(QPixmap(":/images/PewGun.png"));
    setScale(0.25);
    setRotation(90);

    QTimer * timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(move_bullet()));
    timer->start(50);

    for_player = false;
}


void Bullet::move_bullet(){
    if (this->for_player == false)
    {
        QList<QGraphicsItem *> colliding_items = collidingItems();
        for (int i = 0, n = colliding_items.size(); i < n; ++i)
        {
            if (typeid(*(colliding_items[i])) == typeid(Enemy))
            {
                game->player->ammo_cap++;

                game->score->increase(10);
                game->score->increase_e_kill();

                scene()->removeItem(colliding_items[i]);
                scene()->removeItem(this);

                delete colliding_items[i];
                delete this;

                if (game->score->getScore() >= 20 && game->level == 1)
                {
                    //qDebug("score reached next level1");
                    emit game->player->next_level();
                    game->level = 2;
                }

                return;
            }
            else if (typeid(*(colliding_items[i])) == typeid(Medium_Enemy))
            {
                game->player->ammo_cap++;

                game->score->increase(25);
                game->score->increase_m_kill();

                scene()->removeItem(colliding_items[i]);
                scene()->removeItem(this);

                delete colliding_items[i];
                delete this;

                if (game->score->getScore() >= 100 && game->level == 2)
                {
                    qDebug("score reached next level2");
                    emit game->player->next_level();
                    game->level=3;
                }

                return;
            }
            else if (typeid(*(colliding_items[i])) == typeid(Hard_Enemy) )
            {
                game->player->ammo_cap++;

                game->score->increase(50);
                game->score->increase_h_kill();

                scene()->removeItem(colliding_items[i]);
                scene()->removeItem(this);

                delete colliding_items[i];
                delete this;

                if (game->score->getScore() >= 10000 && game->level == 3)
                {
                    emit game->player->next_level();
                    game->level= 4;
                }

                return;
            }
            else if (typeid(*(colliding_items[i])) == typeid(Asteroid))
            {
                game->player->ammo_cap++;
                game->player->asteroid_hits++;
                if (game->player->asteroid_hits == 3)
                {
                    scene()->removeItem(colliding_items[i]);

                    delete colliding_items[i];
                    game->player->asteroid_hits = 0;

                    this->for_player = true;
                    return;
                }
                else
                {
                    delete this;
                    return;
                }

            }
        }

        setPos(x(),y()-20);

        if (pos().y() < 0)
        {
            scene()->removeItem(this);
            delete this;
            game->player->ammo_cap++;
        }
    }
    else
    {
        QList<QGraphicsItem *> colliding_items = collidingItems();
        for (int i = 0, n = colliding_items.size(); i < n; ++i)
        {
            if (typeid(*(colliding_items[i])) == typeid(Player))
            {
                scene()->removeItem(this);
                delete this;
                game->player->ammo_cap++;
            }
        }
        setPos(x(),y()+2);
        if (pos().y() > 800){
            scene()->removeItem(this);
            delete this;
        }
    }
}
