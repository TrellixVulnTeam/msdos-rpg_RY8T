#include<cstdio>
#include<Windows.h>
using namespace std;
#ifndef _VCMDH_H_
#define _VCMDH_H_
namespace vcmd
{
	void help()
	{
		printf("��ģ��CMD��GLgele��д��ָ����Command.txt�\n");
	}


	void lincense()
	{
		printf("��鿴lincense�ļ���\n");
	}

	void credits()
	{
		printf("Dream Border X \nGLgele \n");
	}

	void copyright()
	{
		printf("(c) 2020 DreamBorderX & GLgele����������Ȩ���� \n");
	}

	void clear()
	{
		system("cls");
	}
};

#endif 
