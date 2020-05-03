#include <QGraphicsScene>
#include <QKeyEvent>

#include "Player.h"
#include "Bullet.h"
#include "Enemy.h"
#include "Medium_Enemy.h"
#include "Hard_Enemy.h"
#include "Score.h"

Player::Player(QGraphicsItem *parent): QGraphicsPixmapItem(parent)
{
    setPixmap(QPixmap(":/images/Spaceship.png"));
    setScale(0.05);
    lives = 3;
    total_points = 0;
}

void Player::keyPressEvent(QKeyEvent *event)
{
    if (event->key() == Qt::Key_Left)
    {
        if (pos().x() > 0)
        setPos(x()-30,y());
    }
    else if (event->key() == Qt::Key_Right)
    {
        if (pos().x() + 100 < 800)
        setPos(x()+30,y());
    }

    else if (event->key() == Qt::Key_Space)
    {
        if (this->ammo_cap > 0)
        {
            Bullet * bullet = new Bullet();
            bullet->setPos(x()+45,y());
            scene()->addItem(bullet);
            this->ammo_cap--;
        }


//        // play bulletsound
//        if (bulletsound->state() == QMediaPlayer::PlayingState)
//        {
//            bulletsound->setPosition(0);
//        }
//        else if (bulletsound->state() == QMediaPlayer::StoppedState)
//        {
//            bulletsound->play();
//        }
    }
}

void Player::setScore(int points){
    total_points = total_points + points;
}

