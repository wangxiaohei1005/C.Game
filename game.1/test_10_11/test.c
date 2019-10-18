#define _CRT_SECURE_NO_WARNINGS 1

#include "game.h"

void menu()
{
	printf("\n");
	printf("****************************************\n");
	printf("***********  欢迎来到五子棋  ***********\n");
	printf("***********   1.开始游戏   *************\n");
	printf("***********   0.结束游戏   *************\n");
	printf("****************************************\n");
}

void Game()
{
	char tmp = 0;
	char board[ROW][COL] = { 0 };
	CheckBoard(board, ROW, COL);
	printf("进入%d子棋游戏!!!\n",ROW);
	DisplayBoard(board, ROW, COL);
	while (1)
	{
		GamePlayer(board, ROW, COL);
		DisplayBoard(board, ROW, COL);
		tmp = CheckWinner(board, ROW, COL);
		if (tmp != 'c')//不为平局
		{
			break;
		}
		ComputerPlayer(board, ROW, COL);
		DisplayBoard(board, ROW, COL);
		tmp = CheckWinner(board, ROW, COL);
		if (tmp != 'c')
		{
			break;
		}
	}
	if (tmp  == '*')
		{
			printf("玩家赢啦！！！\n");
		}
	else if (tmp == '#')
		{
			printf("电脑赢，请认真游戏！！！\n");
		}
	if (tmp=='c')
		{
			printf("平局！！！\n");
		}
}  


void Test()
{
	int Input = 0;
	srand((unsigned int)time(NULL));
	do//第一次需要显示菜单  一次采用do while
	{
		menu();
		printf("请输入你的选择：\n");
		scanf("%d", &Input);
		switch (Input)
		{
		case 1:
			Game();
			break;
		case 0:
			printf("See you!!!");
			break;
		default:
			printf("您的输入有误!请重新输入！\n");
		}
	} while (Input);
	printf("\n");

}

int main()
{
	Test();
	return 0;
}