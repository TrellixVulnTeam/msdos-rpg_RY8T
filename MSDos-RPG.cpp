#include "includeme.h"
#define fin cin
#define fout cout
using namespace std;
void GameInit();
bool ctrlhandler(DWORD);
void GameExit();
void setPos(int, int);
void rands();
void listQuest();
void intomap();
const int events = 2;
string title;
string sen = "欢迎来到这个MSDOS游戏!";
player p;
int *ip = NULL; //调用item的getAdds和getSpecails
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
		printf("\t欢迎来到%s!\n",title.c_str());
		cout << "玩家名:" << p.name << endl;
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
	unsigned rdm;
	int tempi = 1;
	srand(time(NULL));
	rdm = rand();
	//cout << rand() << endl;
	//p.newQuest(1);
	//cout<< rdm <<endl;
	tempi = rdm % 10;
	p.newQuest(tempi);
	cout << "已领取任务: " << tempi << ":" << p.questName(tempi) << endl;
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
	ifstream inSets("settings.ini");
	getline(inSets,title);
	string temps="title ";
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
		Sleep(300);
		system("cls");
	}
	else
	{
		MessageBox(NULL, TEXT("\nFatal致命错误:无法设置控件处理程序(Control Handler)\n"), TEXT(title.c_str()), MB_OK | MB_ICONERROR);
		system("pause");
		exit(1);
	}
}

bool ctrlhandler(DWORD fdwctrltype)
{
	switch (fdwctrltype)
	{
	// handle the ctrl-c signal.
	case CTRL_C_EVENT:
		//printf( "ctrl-c event\n\n" );
		//GameExit();
		MessageBox(NULL, TEXT("请不要使用Ctrl-C关闭游戏！"), TEXT(title.c_str()), MB_OK | MB_ICONWARNING);
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
		MessageBox(NULL, TEXT("请不要强制退出游戏！"), TEXT(title.c_str()), MB_OK | MB_ICONWARNING);
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

void setPos(int x, int y) //设置光标位置
{
	COORD pos;
	HANDLE hOutput;
	pos.X = x;
	pos.Y = y;
	hOutput = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hOutput, pos);
}

void GameExit()
{
	MessageBox(NULL, TEXT("正在退出游戏..."), TEXT(title.c_str()), MB_OK | MB_ICONINFORMATION);
	//保存文件
	ofstream fout("gamefile/SAVE.file");
	fout << p.name << endl;
	for (int i = 0; i < 15; i++)
	{
		fout << p.questf(i) << " ";
	}
	fout.close();
#define fout cout
	exit(0);
}
