#include "../head/player.h"
#include<iostream>
#include<cstdio>
using namespace std;
#ifndef _PLAYER_CPP_
#define _PLAYER_CPP_

bool player::addItem(int pos,string itemName)
{
    if(inv[pos] == "")
    {
        inv[pos] = itemName;
        return true;
    }
    else
    {
        return false;
    }
    
    
}

bool player::delItem(int pos)
{
    if(inv[pos] != "")
    {
        inv[pos] = "";
        return true;
    }
    return false;
}

int player::isQuestMax()
{
    for(int i=0;i<15;i++)
    {
        if(quest[i] == 0)
        {
            return i;
        }
    }
    return -1;
}

int player::questf(int pos)
{
    return quest[pos];
}

void player::listQuest()
{
    for(int i=0;i<15;i++)
    {
        cout<<quests[quest[i]]<<endl;
    }
}

string player::questName(int id)
{
    return quests[id];
}

void player::checkQuest(int id)
{
    for(int i=0;i<15;i++)
    {
        if(quest[i] == id)
        {
            delQuest(id);
            return;
        }
    }
    return;
}

bool player::newQuest(int id)
{
    if(isQuestMax() != -1)
    {
        quest[isQuestMax()] = id;
        return true;
    }
    return false;
}

bool player::delQuest(int id)
{
    quest[id] = 0;
    return true;
}

bool player::fnsQuest(int id)
{
        system("cls");
        cout<<"任务已完成: "<<id<<" : "<<quests[id]<<endl;
        system("pause");
}
#endif
