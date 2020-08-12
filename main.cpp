#include "cpp.cpp"
#include<Windows.h>
#include<cstring>
#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<cmath>
using namespace std;
string sen = "欢迎来到这个MSDOS游戏!";
int main()
{
	string temp;
	int stat;
	printf("请输入玩家名!\n");
	getline(cin,temp);
	player p;
	p.upName(temp);
	system("cls");
	for(int i=0; i<sen.length(); i++)
	{
		cout<<sen[i];
		Sleep(100);
	}
	system("cls");
	while(true)
	{
		printf("\t欢迎来到DOS-RPG!\n");
		printf("操作：\n1、随机领取任务\n2、任务中心\n0、退出\n");
		scanf("%d",&stat);
		if(stat == 1)
		{

		}
		else if(stat == 2)
		{

		}
		else if(stat == 0)
		{
			//保存文件
			exit(0);
		}
		else
		{
			printf("错误的操作符！\n"); 
			system("pause"); 
			system("cls");
		}
	}
	return 0;
}
