#ifndef PLAYER_H
#define PLAYER_H

#include <QGraphicsPixmapItem>
#include <QObject>
#include <QGraphicsItem>
#include <QMediaPlayer>

#include "Score.h"

class Player:public QObject, public QGraphicsPixmapItem{
    Q_OBJECT
public:
    Player(QGraphicsItem * parent=0);

    void keyPressEvent(QKeyEvent * event);
    int getLives(){ return lives; }
    void setScore(int points);
    int ammo_cap = 3;
private:
    int lives;
    int total_points;
    QMediaPlayer * bulletsound;
signals:
    void next_level();
    void dead();
};
//upon spawn a player needs to gain control of their ship (keyboard)
//there are only 3 possible events but bullets collision test should
//also be used here. Impacts are bad.


#endif // PLAYER_H
