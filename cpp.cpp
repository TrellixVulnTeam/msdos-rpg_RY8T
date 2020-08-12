#include "head.h"
using namespace std;
#ifndef _CPP_CPP_
#define _CPP_CPP_

class player : public sprite
{
    public:
    player() {}
    ~player() {}
    string name;
    bool addItem(int pos,string itemName);
    bool delItem(int pos);
    bool newQuest(int id);
    bool fnsQuest(int id);

    private:
    string inv[50];
    int quest[15];
    int isQuestMax();
};

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

bool player::newQuest(int id)
{

}
#endif
