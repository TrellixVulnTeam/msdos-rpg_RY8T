#include "includeme.h"
#define fin cin
#define fout cout
using namespace std;
void rands();
void listQuest();
void intomap();
string sen = "欢迎来到这个MSDOS游戏!";
player p;
int* ip = NULL;		//调用item的getAdds和getSpecails
int main()
{
	string temps;
	int tempi;
	int stat;
	printf("请输入玩家名!\n");
	getline(cin,temps);
	//p.setName(temps);
	p.name = temps;
	ifstream fin("SAVE.file");
	getline(fin,temps);
	p.name = temps;
	//p.setName(temps);
	while(fin>>tempi)
	{
		p.newQuest(tempi);
	}
	fin.close();
	#define fin cin
	system("cls");
	for(int i=0; i<sen.length(); i++)
	{
		cout<<sen[i];
		Sleep(100);
	}
	system("cls");
	while(true)
	{
		p.setState(1);
		printf("\t欢迎来到DOS-RPG!\n");
		cout<<"玩家名:"<<p.name<<endl;
		printf("操作：\n1、任务中心\n2、随机领取任务\n3、进入地图\n0、退出\n");
		printf("请输入操作: ");
		scanf("%d",&stat);
		if(stat == 1)
		{
			listQuest();
		}
		else if(stat == 2)
		{
			rands();
		}
		else if(stat == 3)
		{
			intomap();
		}
		else if(stat == 0)
		{
			//保存文件
			ofstream fout("SAVE.file");
			fout<<p.name<<endl;
			for(int i=0;i<15;i++)
			{
				fout<<p.questf(i)<<" ";
			}
			fout.close();
			#define fout cout
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

void rands()
{
	unsigned rdm;
	int tempi = 1;
	srand(time(NULL));
	rdm = rand();
	//cout << rand() << endl; 
	//p.newQuest(1);
	//cout<< rdm <<endl;
	tempi = rdm%10;
	p.newQuest(tempi);
	cout<<"已领取任务: "<<tempi<<":"<<p.questName(tempi)<<endl;
	p.checkQuest(tempi);
	system("pause");
	system("cls");
	return;
}

void listQuest()
{
	p.listQuest();
	system("pause");
	system("cls");
	return;
}

void intomap()
{
	int stat;
	system("cls");
	printf("-1、测试\n0、返回主界面");
	scanf("%d",&stat);
	if(stat == -1)
	{
		//进入测试地图
	}
	else if(stat == 0)
	{
		system("cls");
		return;
	}
	else
	{
		printf("无该地图！\n");
	}
}