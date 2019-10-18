#define _CRT_SECURE_NO_WARNINGS 1
#include "game.h"



//棋盘的显示
void DisplayBoard(char board[ROW][COL], int row, int col)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			printf(" %c ", board[i][j]);
			if (j < col )
			{
				printf("|");
			}
		}
		printf("\n");
		if (i < row - 1)
		{

			for (j = 0; j < col; j++)
			{
				printf("---");
				if (i<col-1)
				{
					printf("|");
				}
			}
			printf("\n");
		}
	}
}

//对棋盘空位的判断
void CheckBoard(char board[ROW][COL], int row, int col)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			board[i][j] = ' ';
		}
	}

}
//玩家走棋操作
void GamePlayer(char board[ROW][COL], int row, int col)
{
	int x = 0;
	int y = 0;
	printf("玩家请走：\n");
	while (1)
	{
		printf("请输入坐标：\n");
		scanf("%d%d", &x, &y);
		if (x >= 1 && x <= row && y >= 1 && y <= col)
		{
			if (board[x - 1][y - 1] == ' ')
			{
				board[x-1][y-1] = '*';
				break;
			}
			else
			{
				printf("该坐标已经被占用啦，请您重新输入：\n");
			}
		}
		else
		{
			printf("该坐标输入非法，请您重新输入：\n");
		}
	}
}
//电脑走棋操作
void ComputerPlayer(char board[ROW][COL], int row, int col)
{
	int x = 0;
	int y = 0;
	printf("电脑走：\n");
	while (1)
	{
		x = rand() % row;//判断五子棋的区域
		y = rand() % col;
		if (board[x][y] == ' ')
		{
			board[x][y] = '#';
			break;
		}
	}
}
static int Isfull(char board[ROW][COL], int row, int col)

{
	int i = 0;
	int j = 0;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			if (board[i][j] == ' ')
			{
				return 0;
			}
		}
	}
	return 1;
}
//判断输赢
char CheckWinner(char board[ROW][COL], int row, int col)
{
	int i = 0;
	//判断行
	for (i = 0; i<row; i++)
	{
		if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != ' ')
		{
			return board[i][0];
		}
	}
	//判断列
	for (i = 0; i<col; i++)
	{
		if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[0][i] != ' ')
		{
			return board[0][i];
		}
	}

	//判断斜向
	if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[1][1] != ' ')
	{
		return board[1][1];
	}
	if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[1][1] != ' ')
	{
		return board[1][1];
	}
	if (Isfull(board, row, col))
	{
		//继续
		return 'p';
	}
	//平局
	else
	 return 'c';
}
