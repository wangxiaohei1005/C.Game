#define _CRT_SECURE_NO_WARNINGS 1
#include "game.h"
#include <time.h>

void Game()
{
	char mine[ROWS][COLS] = { 0 };//�׵��Ų�
	char show[ROWS][COLS] = { 0 };//�Ų�
	//��ʼ��
	VoidBoard(mine, ROWS, COLS, '0');
	VoidBoard(show, ROWS, COLS, '*');

	Display(show, ROW, COL);
	//������
	BuildMine(mine, ROW, COL);
	Display(mine, ROW, COL);//��ӡ����
	int tmp = FindMine(mine, show, ROW, COL);
	while (1)//ѭ��
	{
		if (tmp == 0)//������0��ʤ��
		{
			Display(show, ROW, COL);
			printf("��ϲ��ϲ������Ӯ�ˣ�����\n");
			break;
		}
		if (tmp == 1)//������1��ʧ��
		{
			Dispaly(mine, ROW, COL);
			printf("����ϲ�㣬��Ϊ�����ˣ�����\n");
			break;
		}
		Display(show, ROW, COL);
	}
}

void Menu()
{
	printf("*****************************************\n");
	printf("************    1.��ʼ��Ϸ   ************\n");
	printf("************    0.�˳���Ϸ   ************\n");
	printf("*****************************************\n");
	printf("*****************************************\n");
}

void Test()
{
	int Input = 0;
	srand((unsigned int)time(NULL));
	do
	{
		Menu();
		printf("��ѡ��\n");
		scanf("%d", &Input);
		switch (Input)
		{
		case 1:
			Game();
			break;
		case 0:
			printf("�˳���Ϸ������\n");
			break;
		default:
			printf("����������������룡����\n");
			break;
		}
	} while (Input);
}

int main()
{
	Test();
		return 0;
}