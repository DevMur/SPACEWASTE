#ifndef MYRECT_H
#define MYRECT_H

#include <QGraphicsRectItem>
#include <QObject>


//my player my ship, etc
class MyRect: public QObject, public QGraphicsRectItem{
    Q_OBJECT
public:
    void keyPressEvent(QKeyEvent * event);
public slots:
    void spawn(); //the public slot will go in gamestate for different levels //crugs
    /*
        other spawn functions can be tested here
    */
};

#endif // MYRECT_H
