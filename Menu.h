#ifndef MENU_H
#define MENU_H

#include <QGraphicsRectItem>
#include <QGraphicsSceneMouseEvent>


class Menu: public QGraphicsRectItem{
public:
    Menu(QString name, QGraphicsItem *parent=NULL);

    void mousePressEvent(QGraphicsSceneMouseEvent *event); //press start or quit
    void mouseHoverOnEvent(QGraphicsSceneHoverEvent *event); //aesthetics :)
    void mouseHoverOffEvent(QGraphicsSceneHoverEvent *event);
signals:
    void clicked();
private:
    QGraphicsTextItem *text;
};

#endif // MENU_H
