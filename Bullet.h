#ifndef BULLET_H
#define BULLET_H

#include <QGraphicsPixmapItem>
#include <QGraphicsItem>
#include <QObject>

class Bullet: public QObject, public QGraphicsPixmapItem {
    Q_OBJECT
public:
    Bullet(QGraphicsItem * parent=0);

    void spawn_ammo();

public slots:
    void move_bullet();
    void move_ammo();
};
//Pretty straight forward. A bullet with a shape gets created.
//it's only job is to move
//while moving it may come in contact with something or reach EOF
//it needs rules to it's movement and rules for destruction

//INQUIRED ABOUT: stack bullet items into 4 parallel

#endif // BULLET_H
