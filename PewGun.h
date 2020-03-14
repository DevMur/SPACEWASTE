#ifndef PEWGUN_H
#define PEWGUN_H

#include <QGraphicsRectItem>
#include <QObject>

//the pew gun shouldn't be a rect, perfect for testing
class PewGun: public QObject, public QGraphicsRectItem{
    Q_OBJECT
public:
    PewGun();
public slots:
    void move();
    //trajectory, may add damage or make it a static
    //because if it has the same damage level as every other
    //gun the movement would be the same
};

#endif // PEWGUN_H
