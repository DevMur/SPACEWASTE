#ifndef CLASSES_H
#define CLASSES_H
#include <iostream>
#include <vector>
using namespace std;

class Player {
    public:
        string player_name;
        int score;
        int lives;
        vector<Weapon> artillery;

        string get_name(){return player_name; }
        int get_score(){return score; }
        int get_lives(){return lives; }
        Weapon get_weapons(){return artillery; }

        static Player Instansiate();
        void set_name(string p_name);
        void add_score(int points);
        void add_weapon(string weapon_type);
    private:
        Player();
};

class Weapon {
    public:
        vector<string> weapon_type;
        vector<int> speed;
        vector<string> missile_sprite;

        Weapon();
        Weapon get_weapon(int choice);
        string get_weapon_type(int choice);
        int get_weapon_speed(int choice);
        //pew_gun, yeet cannon, battle rattle
        //use sprite somehow someway
};

class Ship {
    public:
        vector<string> ship_type;
        int position;
        Player artillery;
        string ship_sprite;
        int health;

        Ship();
        string get_ship_type(int using);
        int get_ship_position(){return position; }
        string get_weapon(){return get_weapon_type(); }

        //yeet cannon
};

class SpaceBoard {
    public:
        vector<int> stars;
        vector<vector<int>> enemy_position;
        int player_position;

        SpaceBoard();
        void displayBoard();
        void displayPosition(crug num_crug, modem num_modem, hardum num_hardum);
        int get_player_position(){return player_position; }
};

class crug {
    public:
        int easy_power;
        vector<int> trajectory_of_crug;
        string crug_sprite
        bool alive;

        crug();
        int get_trajectory(int direction);
        string get_crug_sprite(){return crug_sprite; }
};

class modem {
    public:
        int medium_power;
        vector<int> location_of_modem;
        string trajectory_of_modem_missile;
        string modem_sprite;
        string modem_missile_sprite;
        bool alive;

        modem();
        void set_trajectory();
        void set_missile_path();
        string get_modem_sprite(){return modem_sprite; }
        string get_modem_missile_sprite(){return modem_missile_sprite; }
};

class hardum {
    public:
        int hard_power;
        vector<int> trajectory_of_hardum;
        string trajectory_of_hardum_missile;
        string hardum_sprite;
        string hardum_missile_sprite;

        hardum();
        int get_trajectory_hardum();
        string get_hardum_sprite();
        //string utilize sprite
};

class mid_boss {
    public:
        vector<string> attacks;
        vector<int> attack_power;
        vector<string> attack_sprites;
        vector<vector<int>> position;
        string mid_boss_sprite;

        mid_boss();
        //unknown utilization of moves
};

class end_boss {
    public:
        vector<string> attacks;
        vector<int> attack_power;
        vector<string> attack_sprites;
        vector<vector<int>> position;
        string end_boss_sprite;

        end_boss();
        //utilize boss animations
};

#endif CLASSES_H