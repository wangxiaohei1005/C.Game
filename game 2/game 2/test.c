#define _CRT_SECURE_NO_WARNINGS 1
#include "game.h"
#include <time.h>

void Game()
{
	char mine[ROWS][COLS] = { 0 };//雷的排布
	char show[ROWS][COLS] = { 0 };//排查
	//初始化
	VoidBoard(mine, ROWS, COLS, '0');
	VoidBoard(show, ROWS, COLS, '*');

	Display(show, ROW, COL);
	//布置雷
	BuildMine(mine, ROW, COL);
	Display(mine, ROW, COL);//打印雷盘
	int tmp = FindMine(mine, show, ROW, COL);
	while (1)//循环
	{
		if (tmp == 0)//若返回0则胜利
		{
			Display(show, ROW, COL);
			printf("恭喜恭喜，阁下赢了！！！\n");
			break;
		}
		if (tmp == 1)//若返回1则失败
		{
			Dispaly(mine, ROW, COL);
			printf("不恭喜你，因为你输了！！！\n");
			break;
		}
		Display(show, ROW, COL);
	}
}

void Menu()
{
	printf("*****************************************\n");
	printf("************    1.开始游戏   ************\n");
	printf("************    0.退出游戏   ************\n");
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
		printf("请选择：\n");
		scanf("%d", &Input);
		switch (Input)
		{
		case 1:
			Game();
			break;
		case 0:
			printf("退出游戏！！！\n");
			break;
		default:
			printf("输入错误，请重新输入！！！\n");
			break;
		}
	} while (Input);
}

int main()
{
	Test();
		return 0;
}