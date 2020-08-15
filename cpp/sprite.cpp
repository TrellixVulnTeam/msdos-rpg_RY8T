#include "../head/sprite.h"
using namespace std;
#ifndef _SPRITE_CPP_
#define _SPRITE_CPP_

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

int sprite::getHealth()
{
    return health;
}

int sprite::getState()
{
    return state;
}
#endif
