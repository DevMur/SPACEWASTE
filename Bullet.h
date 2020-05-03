#ifndef BULLET_H
#define BULLET_H

#include <QGraphicsPixmapItem>
#include <QGraphicsItem>
#include <QObject>

class Bullet: public QObject, public QGraphicsPixmapItem {
    Q_OBJECT
public:
    Bullet(QGraphicsItem * parent=0);

    void spawn_ammo(Bullet* maybe);

    bool for_player = false;

public slots:
    void move_bullet();
};

#endif // BULLET_H
