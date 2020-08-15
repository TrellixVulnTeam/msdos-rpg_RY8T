#include<string>
using namespace std;
#ifndef _SPRITE_H_
#define _SPRITE_H_


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

#endif
