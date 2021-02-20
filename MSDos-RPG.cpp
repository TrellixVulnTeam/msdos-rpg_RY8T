//#include "includeme.h"
#include<windows.h>
#include<string>
#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<cmath>
#include<ctime>
#include<fstream>
#include<algorithm>
#include<list>
#include<stack>
#include<queue>
#include<map>
#include<random>
//#include<Python.h>
//#include "libs/python/include/Python.h"
//#include "libs/jsoncpp/include/json/json.h"
#include<Python.h>
#include<json/json.h>
#include "head/sprite.h"
#include "head/item.h"
#include "head/map.h"
#include "head/player.h"
#include "head/enemy.h"

#define _CRT_SECURE_NO_WARNINGS
#define fin cin
#define fout cout
#pragma comment(lib,"python3.lib")
#pragma comment(lib,"python37.lib")
#pragma comment(lib,"_tkinter.lib")
using namespace std;
void GameInit();
bool ctrlhandler(DWORD);
void GameExit();
void setPos(int, int);
LPCWSTR stringToLPCWSTR(string);
int randi(int, int);
void rands();
void listQuest();
void intomap();
const int events = 2;
string title = "MSDos-RPG Alpha 0.1";
string sen = "欢迎来到这个MSDOS游戏!";
player p;
int prdm = 0;	//调用Python用
int *ip = NULL; //调用item的getAdds和getSpecails
//Json::Reader reader;
//Json::Value root;
PyObject *pMod = NULL;
PyObject *pFunc = NULL;
PyObject *result = NULL;
int main()
{
	GameInit();
	string temps;
	int tempi;
	int stat;
	printf("请输入玩家名!\n");
	getline(cin, temps);
	//p.setName(temps);
	p.name = temps;
	ifstream fin("gamefile/SAVE.file");
	getline(fin, temps);
	p.name = temps;
	//p.setName(temps);
	while (fin >> tempi)
	{
		p.newQuest(tempi);
	}
	fin.close();
#define fin cin
	system("cls");
	setPos(32, 32);
	for (int i = 0; i < sen.length(); i++)
	{
		cout << sen[i];
		Sleep(100);
	}
	setPos(32, 25);
	system("pause");
	system("cls");
	while (true)
	{
		p.setState(1);
		setPos(32, 0);
		printf("\t欢迎来到%s!\n", title.c_str());
		printf("玩家名：%s\n",p.name.c_str());
		printf("操作：\n1、任务中心\n2、随机领取任务\n3、进入地图\n0、退出\n");
		printf("请输入操作: ");
		scanf("%d", &stat);
		if (stat == 1)
		{
			listQuest();
		}
		else if (stat == 2)
		{
			rands();
		}
		else if (stat == 3)
		{
			intomap();
		}
		else if (stat == 0)
		{
			//保存文件
			/*ofstream fout("SAVE.file");
			fout << p.name << endl;
			for (int i = 0; i < 15; i++)
			{
				fout << p.questf(i) << " ";
			}
			fout.close();
			#define fout cout
			exit(0);*/
			GameExit();
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
	/*
	unsigned rdm;
	int tempi = 1;
	srand(time(NULL));
	rdm = rand();
	//cout << rand() << endl;
	//p.newQuest(1);
	//cout<< rdm <<endl;
	tempi = rdm % 10;
	*/
	if (p.isQuestMax() < 1)
	{
		int tempi = randi(1, 10);
		p.newQuest(tempi);
		cout << "已领取任务: " << tempi << ":" << p.questName(tempi) << endl;
		p.checkQuest(tempi);
	}
	else
	{
		cout<<"你当前已有任务！请先完成你的任务"<<endl;
	}
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
	int tempi;
	unsigned rdm;
	enemy monster(p);
	system("cls");
	printf("-1、测试\n0、返回主界面");
	scanf("%d", &stat);
	if (stat == -1)
	{
		//进入测试地图
		printf("0、退出\n1、前\n2、后\n3、左\n4、右\n");
		printf("请输入操作");
		scanf("%d", &stat);
		if (stat == 0)
		{
			return;
		}
		else if (!(stat > 4))
		{
			//刷怪
			srand(time(NULL));
			rdm = rand();
			tempi = rdm % events;
		}
		else
		{
			printf("错误的操作符！");
		}
	}
	else if (stat == 0)
	{
		system("cls");
		return;
	}
	else
	{
		printf("无该地图！\n");
	}
}

void GameInit()
{
	ifstream inSets("../settings.ini");
	/*getline(inSets, title);*/
	string temps = "title ";
	temps += title;
	system("mode con cols=100 lines=30");
	system(temps.c_str());
	printf("正在启动游戏...\n");
	Sleep(500);
	if (SetConsoleCtrlHandler((PHANDLER_ROUTINE)ctrlhandler, true))
	{
		/*
        printf( "\nthe control handler is installed.\n" ); 
        printf( "\n -- now try pressing ctrl+c or ctrl+break, or" ); 
        printf( "\n try logging off or closing the console...\n" ); 
        printf( "\n(...waiting in a loop for events...)\n\n" );
        */
		/*while( 1 ){ Sleep(100);}*/
		printf("Control Hanler启动成功!\n");
	}
	else
	{
		MessageBox(NULL,TEXT("\nFatal致命错误:无法设置控件处理程序(Control Handler)\n"), stringToLPCWSTR(title), MB_OK | MB_ICONERROR);
		system("pause");
		exit(1);
	}
	/*Py_Initialize();
	PyRun_SimpleString("import encodings");
	PyRun_SimpleString("import sys");
	PyRun_SimpleString("sys.path.append('./')");
	if (!Py_IsInitialized())
	{
		MessageBox(NULL, TEXT("\nFatal致命错误:无法启动Python(Py_Initialize)\n"), stringToLPCWSTR(title), MB_OK | MB_ICONERROR);
		system("pause");
		exit(1);
	}
	else
	{
		printf("Python启动成功!\n");
	}
	pMod = PyImport_ImportModule("json");
	if (!pMod)
	{
		MessageBox(NULL, TEXT("\nFatal致命错误:无法找到Python库(json)\n"), stringToLPCWSTR(title), MB_OK | MB_ICONERROR);
		system("pause");
		exit(1);
	}
	else
		printf("成功打开Python库!\n");*/
	//system("dir");
	system("..\\\\libs\\\\python\\\\python.exe jsonReader.py");
	system("..\\\\libs\\\\python\\\\python.exe updateChecker.py");
	ifstream pf("python.file");
	string verp;
	string ver;
	bool isNew;
	getline(pf, verp);
	//cout << verp << endl;
	pf.close();
	getline(inSets, ver);
	//cout << ver << endl;
	if (verp == ver)
	{
		isNew = true;
		printf("版本检查成功！\n");
	}
	else
	{
		isNew = false;
		MessageBox(NULL, TEXT("当前存在新版本！\n请前往Github或Gitee下载新版本！"), stringToLPCWSTR(title), MB_OK | MB_ICONWARNING);
	}
	//cout << isNew << endl;
	//system("pause");
	Sleep(300);
	inSets.close();
	system("cls");
}

bool ctrlhandler(DWORD fdwctrltype)
{
	switch (fdwctrltype)
	{
	// handle the ctrl-c signal.
	case CTRL_C_EVENT:
		//printf( "ctrl-c event\n\n" );
		//GameExit();
		MessageBox(NULL, TEXT("请不要使用Ctrl-C关闭游戏！"), stringToLPCWSTR(title), MB_OK | MB_ICONWARNING);
		return false;

	// ctrl-close: confirm that the user wants to exit.
	case CTRL_CLOSE_EVENT:
		//printf( "ctrl-close event\n\n" );
		GameExit();
		return true;

	// pass other signals to the next handler.
	case CTRL_BREAK_EVENT:
		//printf( "ctrl-break event\n\n" );
		//GameExit();
		MessageBox(NULL, TEXT("请不要强制退出游戏！"), stringToLPCWSTR(title), MB_OK | MB_ICONWARNING);
		return false;

	case CTRL_LOGOFF_EVENT:
		//printf( "ctrl-logoff event\n\n" );
		GameExit();
		return false;

	case CTRL_SHUTDOWN_EVENT:
		//printf( "ctrl-shutdown event\n\n" );
		GameExit();
		return false;

	default:
		return false;
	}
}

/*void randi(int a, int b)
{
	string temps = "rnd(";
	temps += a;
	temps += ",";
	temps += b;
	temps += ")";
	if (pMod)
	{
		//获取函数地址
		pFunc = PyObject_GetAttrString(pMod, temps.c_str());
		if (pFunc)
		{
			result = PyEval_CallFunction(pFunc, NULL);
		}
		//换回类型转换
		PyArg_Parse(result, "i", &prdm);
	}
}*/

int randi(int a, int b)
{
	int t = abs(a - b) + 1;
	unsigned rdm;
	int tempi = 1;
	srand(time(NULL));
	rdm = rand();
	tempi = rdm % t;
	return tempi;
}

void setPos(int x, int y) //设置光标位置
{
	COORD pos;
	HANDLE hOutput;
	pos.X = x;
	pos.Y = y;
	hOutput = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hOutput, pos);
}

LPCWSTR stringToLPCWSTR(string orig)
{
	size_t origsize = orig.length() + 1;
	const size_t newsize = 100;
	size_t convertedChars = 0;
	wchar_t* wcstring = (wchar_t*)malloc(sizeof(wchar_t) * (orig.length() - 1));
	mbstowcs_s(&convertedChars, wcstring, origsize, orig.c_str(), _TRUNCATE);

	return wcstring;
}

void GameExit()
{
	MessageBox(NULL, TEXT("正在退出游戏..."), stringToLPCWSTR(title), MB_OK | MB_ICONINFORMATION);
	//保存文件
	ofstream fout("gamefile/SAVE.file");
	fout << p.name << endl;
	for (int i = 0; i < 15; i++)
	{
		fout << p.questf(i) << " ";
	}
	fout.close();
#define fout cout
	Py_Finalize();
	exit(0);
}
