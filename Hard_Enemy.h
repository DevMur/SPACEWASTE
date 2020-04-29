#ifndef HARD_ENEMY_H
#define HARD_ENEMY_H

#include <QGraphicsPixmapItem>
#include <QObject>
#include <QGraphicsItem>

class Hard_Enemy: public QObject,public QGraphicsPixmapItem{
    Q_OBJECT
public:
    Hard_Enemy(QGraphicsItem * parent=0);
    int value = 50;
    int switcher = 0;
    int left = -1;
public slots:
    void move_hard();
};

#endif // HARD_ENEMY_H
