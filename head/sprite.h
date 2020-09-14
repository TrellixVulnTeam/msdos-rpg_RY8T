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
    int ATK;
    int DEF;

    public:
    sprite(int _ATK,int _DEF);
    ~sprite();
    void upHealth(double _health);
    void upState(int _state);
    void upName(string name);
    void upATK(int _ATK);
    void upDEF(int _DEF);
    int getHealth();
    int getState();
    int getATK();
    int getDEF();
};

#endif
