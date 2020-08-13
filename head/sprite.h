#include<string>
using namespace std;
#ifndef _HEAD_H_
#define _HEAD_H_


class sprite
{
    private:
    int state;
    double health;
    string name;

    public:
    sprite() {}
    ~sprite() {}
    void upHealth(double _health);
    void upState(int _state);
    void upName(string name);
};

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

#endif
