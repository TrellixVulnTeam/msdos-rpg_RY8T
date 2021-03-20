#include "includeme.h"
#define _CRT_SECURE_NO_WARNINGS
#define fin cin
#define fout cout
#pragma comment(lib,"python3.lib")
#pragma comment(lib,"python37.lib")
#pragma comment(lib,"_tkinter.lib")
using namespace std;
using namespace gen;
void GameInit(string);
bool ctrlhandler(DWORD);
void GameExit();
void setPos(int, int);
int randi(int, int);
void rands();
void listQuest();
void intomap();
const int events = 2;
int debugType;
string title = "MSDos-RPG Alpha 0.1.1";
string sen = "��ӭ�������MSDOS��Ϸ!";
player p;
int prdm = 0;	//����Python��
int *ip = NULL; //����item��getAdds��getSpecails
//Json::Reader reader;
//Json::Value root;
PyObject *pMod = NULL;
PyObject *pFunc = NULL;
PyObject *result = NULL;
int main(int argc, char* argv[])
{
	if (argc > 1)
	{
		GameInit(argv[1]);
	}
	else
	{
		GameInit(argv[0]);
	}
	string temps;
	int tempi;
	int stat;
	printf("�����������!\n");
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
		printf("\t��ӭ����%s!\n", title.c_str());
		printf("�������%s\n",p.name.c_str());
		printf("������\n1����������\n2�������ȡ����\n3�������ͼ\n0���˳�\n");
		printf("���������: ");
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
			//�����ļ�
			/*ofstream fout("SAVE.file");
			fout << p.name << endl;
			for (int i = 0; i < 15; i++)
			{
				fout << p.questf(i) << " ";
			}
			fout.close();
			#define fout cout
			exit(0);*/
			release::safeExit(0,debugType);
			GameExit();
		}
		else
		{
			printf("����Ĳ�������\n");
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
		cout << "����ȡ����: " << tempi << ":" << p.questName(tempi) << endl;
		p.checkQuest(tempi);
	}
	else
	{
		cout<<"�㵱ǰ����������������������"<<endl;
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
	printf("-1������\n0������������");
	scanf("%d", &stat);
	if (stat == -1)
	{
		//������Ե�ͼ
		printf("0���˳�\n1��ǰ\n2����\n3����\n4����\n");
		printf("���������");
		scanf("%d", &stat);
		if (stat == 0)
		{
			return;
		}
		else if (!(stat > 4))
		{
			//ˢ��
			srand(time(NULL));
			rdm = rand();
			tempi = rdm % events;
		}
		else
		{
			printf("����Ĳ�������");
		}
	}
	else if (stat == 0)
	{
		system("cls");
		return;
	}
	else
	{
		printf("�޸õ�ͼ��\n");
	}
}

void GameInit(string arg)
{
	using namespace gen;
	if (arg == "--debug")
	{
		debugType = 1;
	}
	logInit();
	ifstream inSets("../settings.ini");
	/*getline(inSets, title);*/
	string temps = "title ";
	temps += title;
	if (debugType == 1)
	{
		temps += " --debug";
	}
	system("mode con cols=100 lines=30");
	system(temps.c_str());
	printf("����������Ϸ...\n");
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
		printf("Control Hanler�����ɹ�!\n");
	}
	else
	{
		MessageBox(NULL,TEXT("\nFatal��������:�޷����ÿؼ��������(Control Handler)\n"), stringToLPCWSTR(title), MB_OK | MB_ICONERROR);
		//msgbox("Fatal��������:�޷����ÿؼ��������(Control Handler)\n", MB_OK | MB_ICONERROR);
		system("pause");
		exit(1);
	}
	Py_Initialize();
	PyRun_SimpleString("import encodings");
	PyRun_SimpleString("import sys");
	PyRun_SimpleString("sys.path.append('./')");
	if (!Py_IsInitialized())
	{
		MessageBox(NULL, TEXT("\nFatal��������:�޷�����Python(Py_Initialize)\n"), stringToLPCWSTR(title), MB_OK | MB_ICONERROR);
		//msgbox("Fatal��������:�޷�����Python(Py_Initialize)\n", MB_OK | MB_ICONERROR);
		system("pause");
		exit(1);
	}
	else
	{
		printf("Python�����ɹ�!\n");
	}
	pMod = PyImport_ImportModule("updateChecker");
	if (!pMod)
	{
		MessageBox(NULL, TEXT("\nFatal��������:�޷��ҵ�Python��(updateChecker)��\n�������°�װ����Խ���������"), stringToLPCWSTR(title), MB_OK | MB_ICONERROR);
		//msgbox("Fatal��������:�޷��ҵ�Python��(updateChecker)��\n�������°�װ����Խ���������\n", MB_OK | MB_ICONERROR);
		system("pause");
		exit(1);
	}
	else
	{
		printf("�ɹ���Python��(updateChecker)!\n");
	}
	pMod = PyImport_ImportModule("jsonReader");
	if (!pMod)
	{
		MessageBox(NULL, TEXT("\nFatal��������:�޷��ҵ�Python��(jsonReader)��\n�������°�װ����Խ���������"), stringToLPCWSTR(title), MB_OK | MB_ICONERROR);
		//msgbox("Fatal��������:�޷��ҵ�Python��(jsonReader)��\n�������°�װ����Խ���������\n", MB_OK | MB_ICONERROR);
		system("pause");
		exit(1);
	}
	else
	{
		printf("�ɹ���Python��(jsonReader)!\n");
	}
	//system("dir");
	/*system("..\\\\libs\\\\python\\\\python.exe jsonReader.py");
	system("..\\\\libs\\\\python\\\\python.exe updateChecker.py");*/
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
		printf("�汾���ɹ���\n");
	}
	else
	{
		isNew = false;
		MessageBox(NULL, TEXT("��ǰ�����°汾��\n��ǰ��Github��Gitee�����°汾��"), stringToLPCWSTR(title), MB_OK | MB_ICONWARNING);
		//msgbox("��ǰ�����°汾��\n��ǰ��Github��Gitee�����°汾��\n", MB_OK | MB_ICONWARNING);
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
		MessageBox(NULL, TEXT("�벻Ҫʹ��Ctrl-C�ر���Ϸ��"), stringToLPCWSTR(title), MB_OK | MB_ICONWARNING);
		//msgbox("�벻Ҫʹ��Ctrl-C�ر���Ϸ��\n", MB_OK | MB_ICONWARNING);
		return false;

	// ctrl-close: confirm that the user wants to exit.
	case CTRL_CLOSE_EVENT:
		//printf( "ctrl-close event\n\n" );
		release::safeExit(1,debugType);
		GameExit();
		return true;

	// pass other signals to the next handler.
	case CTRL_BREAK_EVENT:
		//printf( "ctrl-break event\n\n" );
		//GameExit();
		MessageBox(NULL, TEXT("�벻Ҫǿ���˳���Ϸ��"), stringToLPCWSTR(title), MB_OK | MB_ICONWARNING);
		//msgbox("�벻Ҫǿ���˳���Ϸ��\n", MB_OK | MB_ICONWARNING);
		return false;

	case CTRL_LOGOFF_EVENT:
		//printf( "ctrl-logoff event\n\n" );
		release::safeExit(2, debugType);
		GameExit();
		return false;

	case CTRL_SHUTDOWN_EVENT:
		release::safeExit(2, debugType);
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
		//��ȡ������ַ
		pFunc = PyObject_GetAttrString(pMod, temps.c_str());
		if (pFunc)
		{
			result = PyEval_CallFunction(pFunc, NULL);
		}
		//��������ת��
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

void setPos(int x, int y) //���ù��λ��
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
	MessageBox(NULL, TEXT("�����˳���Ϸ..."), stringToLPCWSTR(title), MB_OK | MB_ICONINFORMATION);
	//msgbox("�����˳���Ϸ...\n", MB_OK | MB_ICONINFORMATION);
	//�����ļ�
	ofstream save("gamefile/SAVE.file");
	save << p.name << endl;
	for (int i = 0; i < 15; i++)
	{
		save << p.questf(i) << " ";
	}
	save.close();
	Py_Finalize();
	exit(0);
}
