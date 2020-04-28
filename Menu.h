#ifndef MENU_H
#define MENU_H

#include <QGraphicsRectItem>
#include <QGraphicsSceneMouseEvent>


class Menu: public QObject, public QGraphicsRectItem{
    Q_OBJECT
public:
    Menu(QString name, QGraphicsItem *parent=NULL);

    void mousePressEvent(QGraphicsSceneMouseEvent *event); //press start or quit
    void hoverEnterEvent(QGraphicsSceneHoverEvent *event); //aesthetics :)
    void hoverLeaveEvent(QGraphicsSceneHoverEvent *event); //built in so it took like 5 mins to get working
signals:
    void clicked();
private:
    QGraphicsTextItem *text;
};

#endif // MENU_H
