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
    int asteroid_hits = 0;
private:
    int lives;
    int total_points;
    QMediaPlayer * bulletsound;
signals:
    void next_level();
    void dead();
};

#endif // PLAYER_H
