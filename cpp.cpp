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

    private:
    string inv[50];
    int quest;
};

bool player::addItem(int pos,string itemName)
{
    inv[pos] = itemName;
}

bool player::delItem(int pos)
{
    inv[pos] = "";
}

#endif
