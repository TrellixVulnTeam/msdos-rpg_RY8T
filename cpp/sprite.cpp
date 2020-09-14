#include "../head/sprite.h"
using namespace std;
#ifndef _SPRITE_CPP_
#define _SPRITE_CPP_

sprite::sprite(int _ATK,int _DEF)
{
    upState(1);
    upATK(_ATK);
    upDEF(_DEF);
    while(getState() == 0)
    {
        if(getHealth() <= 0)
        {
            upState(0);
        }
    }
}

sprite::~sprite()
{
    
}

void sprite::upName(string _name)
{
    name = _name;
}

void sprite::upHealth(double _health)
{
    health = _health;
}

void sprite::upState(int _state)
{
    state = _state;
}

void sprite::upATK(int _ATK)
{
    ATK = _ATK;
}

void sprite::upDEF(int _DEF)
{
    DEF = _DEF;
}

int sprite::getHealth()
{
    return health;
}

int sprite::getState()
{
    return state;
}

int sprite::getATK()
{
    return ATK;
}

int sprite::getDEF()
{
    return DEF;
}

#endif
