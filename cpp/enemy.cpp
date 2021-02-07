#include "../head/enemy.h"
#include "../cpp/player.cpp"
#include<iostream>
#include<cstdio>
using namespace std;
#ifndef _ENEMY_CPP_
#define _ENEMY_CPP_

enemy::enemy(player &pl)
{
    setState(1);
    while(getState() == 0)
    {
        if(getHealth() <= 0)
        {
            setState(0);
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

enemy::~enemy()
{

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