#ifndef GAME_H
#define GAME_H

#include <QGraphicsView>
#include <QWidget>
#include <QGraphicsScene>
#include "Player.h"
#include "Score.h"
#include "Health.h"

class Game: public QGraphicsView{
public:
    Game(QWidget * parent=0);

    QGraphicsScene * scene;
    Player * player;
    Score * score;
    Health * health;

};
//An option here is to give it private Game methods which ARE the levels.
//private current level code.
//EX: private:
//      int level_code
//      int level_1(level_code);
//      int level_2(level_code);
//      ...
//      void level_X(level_code); end of game credits.

#endif // GAME_H
