#ifndef LASER_H
#define LASER_H

#include <QGraphicsPixmapItem>
#include <QGraphicsItem>
#include <QObject>

class Laser: public QObject, public QGraphicsPixmapItem {
    Q_OBJECT
public:
    Laser(QGraphicsItem * parent=0);
public slots:
    void move_laser();
};

#endif // LASER_H
