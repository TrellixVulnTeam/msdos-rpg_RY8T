#include "../head/enemy.h"
#include<iostream>
#include<cstdio>
using namespace std;
#ifndef _ENEMY_CPP_
#define _ENEMY_CPP_

enemy::enemy()
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
            player::addItem(item[i]);
        }
    }
}

bool enemy::dead()
{
    if(state == 0)
    {
        return true;
    }
    return false;
}

#endif