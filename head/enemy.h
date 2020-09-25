#include "../cpp/sprite.cpp"
#include "../cpp/player.cpp"
using namespace std;
#ifndef _ENEMY_H_
#define _ENEMY_H_

class enemy : public sprite
{
    public:
    enemy(player);
    ~enemy();
    bool dead();

    private:
    string item[10];
    string armor[10];
};

#endif