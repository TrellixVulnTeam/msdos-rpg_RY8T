#include "../head/enemy.h"
#include "player.cpp"
#include<iostream>
#include<cstdio>
using namespace std;
#ifndef _ENEMY_CPP_
#define _ENEMY_CPP_

enemy::enemy(player pl)
{
    upState(1);
    while(getState() == 0)
    {
        if(getHealth() <= 0)
        {
            upState(0);
        }
    }
    if(dead())
    {
        for(int i=0;i<10;i++)
        {
            pl.addItem(pl.emptyPos(),item[i]);
        }
    }
}

bool enemy::dead()
{
    if(getState() == 0)
    {
        return true;
    }
    return false;
}

#endif