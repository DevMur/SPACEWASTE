#include "classes.hpp"
#include <stdlib.h>
//#include <SFMT/graphics.hpp>

Player::Player()
{
    player_name = "AAA"; //default name of every arcade game ever
    score = 0; //obvious start
    lives = 3; //can be added and deleted based on points and deaths
    artillery.push_back("pew_gun"); //starting gun, basic weak laser
}

void Player::set_name(string p_name) //if highscore is acheived prompt user for name and save it here
{
    player_name = p_name;
}
void Player::add_score(int points) //seconds are worth a point, kills 20, 50, 75, 500, 1000, 10k
{
    score += points; //basic addition
}
void Player::add_weapon(string new_weapon) //when a weapon is acquired its string is added
{
    artillery.push_back(new_weapon);
    //yeet_cannon, Devils_rimjob, Battle_rattle
}

Weapon::Weapon()
{
    weapon_type.push_back("pew_gun");
    speed.push_back(10); //its a badic speed gun with full range
    //enter pew_gun sprite
    weapon_type.push_back("yeet_cannon");
    speed.push_back(25); //slow shot rate high speed higher power
    //enter pew_gun sprite
    weapon_type.push_back("battle_rattle");
    speed.push_back(1); //no range high power
    //enter pew_gun sprite
    weapon_type.push_back("devils_rimjob");
    speed.push_back(3); //low range, medium power
    //enter pew_gun sprite
}
string Weapon::get_weapon_type(int choice) //ideally a rotation based on user inputs
{
    if (weapon_choice[choice] == "pew_gun" || weapon_choice[choice] == "yeet_cannon" || weapon_choice[choice] == "battle_rattle" || weapon_choice[choice] == "devils_rimjob")
    {
        return weapon_type[choice];
    }
    else {return "no"; }
}
string Weapon::get_weapon_speed(int choice) //it will be called only if not no is returned above
{
    return speed[choice];
}
// string Weapon::get_weapon_sprite(int choice)
// {
//     return sprite[choice];
// }

Ship::Ship()
{
    ship_type.push_back("basic");
    position = 50; //percent 
    PLayer abuser;
    artillery = abuser.get_weapons();
    health = 100;
    //sprite = sprite
}
string Ship::get_ship_type(int using)
{
    return ship_type[using];
}

SpaceBoard::SpaceBoard()
{
    for (int i = 0; i < 100; i++)
    {
        stars.push_back(rand()%3);
    }
    player_position = 50; //percent i.e. center
}
void SpaceShip::displayBoard()
{

}
// void SpaceShip::displayPosition(crug num_crug, modem num_modem, hardum num_hardum){}

crug::crug() 
{
    easy_power = 20; //5 shots to kill
    //set health to ships, done
    trajectory_of_crug.push_back(1); //vertical, horizontal, diagonal
    trajectory_of_crug.push_back(2);
    trajectory_of_crug.push_back(3);
    alive = true;
}
int crug::get_trajectory(int direction)
{
    return trajectory_of_crug[direction]; //direction is random
}

modem::modem() 
{
    trajectory_of_modem.push_back(1);
    trajectory_of_modem.push_back(2);
    trajectory_of_modem.push_back(3);
    trajectory_of_modem.push_back(4);
    trajectory_of_modem_missile = "vertical";
    alive = true;
    //set sprite
}

void modem::set_trajectory()
{
    int start = rand()%2;
    if (start == 1)
    {
        //8 levels of height, modems can only be bottom 4
        //enter board on left
        int movement = 0;
        while (alive)
        {
            movement++;

        }
    }
    else
    {

    }
    //set sprite
}


