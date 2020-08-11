#include "cpp.cpp"
#include<windows.h>
using namespace std;
string sen = "欢迎来到这个MSDOS游戏!";
int main()
{
    string temp;
    printf("请输入玩家名!");
    getline(cin,temp);
    player p;
    p.upName(temp);
    system("cls");
    for(int i=0;i<sen.length();i++)
    {
        cout<<sen[i];
        Sleep(100);
    }
    return 0;
}
