#ifndef GAME_H
#define GAME_H

#include <QGraphicsView>
#include <QWidget>
#include <QGraphicsScene>

#include "Player.h"
#include "Score.h"
#include "Health.h"

class Game: public QGraphicsView{
    Q_OBJECT
public:
    Game(QWidget * parent=0);

    void DisplayMenu();

    QGraphicsScene * scene;
    Player * player;
    Score * score;
    Health * health;
    int level = 1;

    bool endGame = false;
    void GameOver();

public slots:
    void Level1();
    void Level2();
    void Level3();

    void Boss_Fight();
    void Spawn_Boss();

    void spawn();
    void spawn2();
    void spawn3();

    void spawn_asteroid();
};

#endif // GAME_H
