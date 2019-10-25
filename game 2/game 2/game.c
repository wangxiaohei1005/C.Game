#define _CRT_SECURE_NO_WARNINGS 1
#include "game.h"
void VoidBoard(char board[ROWS][COLS], int rows, int cols,char tmp)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < rows; i++)
	{
		for (j = 0; j < cols; j++)
		{
			board[i][j] = tmp;
		}
	}
}
void Display(char board[ROWS][COLS], int row, int col)
{
	int i = 0;
	int j = 0;
	for (i = 0; i <= col; i++)
	{
		printf("%d ", i);
	}
	printf("\n");
	for (i = 1; i <= row; i++)
	{
		printf("%d ", i);
		for (j = 1; j <= col; j++)
		{
			printf("%c ", board[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}
void BuildMine(char board[ROWS][COLS], int row, int col)
{
	int count = EASY_COUNT;
	while (count)
	{
		int x = rand() % row + 1;
		int y = rand() % col + 1;
		if (board[x][y] == '0')
		{
			board[x][y] = '1';
			count--;
		}
	}
}
int NoCheckboard(char print[ROWS][COLS], int row, int col)//数未扫位置
{
	int count = 0;
	int i = 0;
	for (i = 1; i <= row; i++)
	{
		int j = 0;
		for (j = 1; j <= col; j++)
		{
			if (print[i][j] == '*')
			{
				count++;
			}
		}
	}
	return count;
}

int GetMineCount(char board[ROWS][COLS], int x, int y)
{
	return board[x - 1][y] + board[x - 1][y - 1] + board[x][y - 1] + board[x + 1][y - 1] +
		board[x + 1][y] + board[x + 1][y + 1] + board[x][y + 1] + board[x - 1][y + 1] - (8 * '0');
}

int FindMine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col)
{
	int x = 0;
	int y = 0;
	int count = 0;
	int tmp = 0;
	while (1)
	{
		printf("请输入排查的坐标:");
		scanf("%d%d", &x, &y);
		if (x >= 1 && x <= row && y >= 1 && y <= col)
		{
			if (mine[x][y] == '0')//没踩到雷
			{
				count++;//记录扫雷的次数
				char arr = GetMineCount(mine, x, y);//数雷数
				show[x][y] = arr + '0';
				Display(mine,  x, y);
				//Display(mine, row, col);
				Display(show, row, col);
				if (NoCheckboard(show, row, col) == count)
				{
					return 0;
				}
				Display(show, row, col);
			}
			else if (mine[x][y] == '1')//踩到雷
			{
				if (tmp == 0 && count == 0)
				{
					tmp++;
					FirstSet(mine, show, x, y, row, col);
				}
				else
					return 1;
			}
		}
		else
		{
			printf("输入错误!请重新输入\n");
		}
}


void FirstSet(char mine[ROWS][COLS], char show[ROWS][COLS], int x, int y, int row, int col)
{
	char arr = 0;
	int tmp = 1;
	int number = 0;
	if (mine[x][y] == '1')
	{
		mine[x][y] = '0';
		char arr = GetMineCount(mine, x, y);
		show[x][y] = arr + '0';
		ReturnBoard(mine, row, col);
		while (tmp)
		{
			int x = rand() % row + 1;
			int y = rand() % col + 1;
			if (mine[x][y] == '0')
			{
				mine[x][y] = '1';
				Display(mine, ROW, COL);
				tmp--;
				break;
			}
		}
	}
}


void  ReturnBoard(char mine[ROWS][COLS], char show[ROWS][COLS], int x, int y)//运用递归扩展周围
{
	int n = 0;
	n = count_mine(mine, x, y);
	if (n == 0)//当该位置周围雷数为0时扩展
	{
		show[x][y] = ' ';//扩展的位置变为“空格”打印出来
		if (mine[x - 1][y] == '0' && show[x - 1][y] == '@')
		{
			ReturnBoard(mine, show, x - 1, y);//递归
		}
		if (mine[x + 1][y] == '0' && show[x + 1][y] == '@')
		{
			ReturnBoard(mine, show, x + 1, y);
		}
		if (mine[x][y + 1] == '0' && show[x][y + 1] == '@')
		{
			ReturnBoard(mine, show, x, y + 1);
		}
		if (mine[x - 1][y + 1] == '0' && show[x - 1][y + 1] == '@')
		{
			ReturnBoard(mine, show, x - 1, y + 1);
		}
		if (mine[x + 1][y + 1] == '0' && show[x + 1][y + 1] == '@')
		{
			ReturnBoard(mine, show, x + 1, y + 1);
		}
		if (mine[x][y - 1] == '0' && show[x][y - 1] == '@')
		{
			ReturnBoard(mine, show, x, y - 1);
		}
		if (mine[x + 1][y - 1] == '0' && show[x + 1][y - 1] == '@')
		{
			ReturnBoard(mine, show, x + 1, y - 1);
		}
		if (mine[x - 1][y - 1] == '0' &&show[x - 1][y - 1] == '@')
		{
			ReturnBoard(mine, show, x - 1, y - 1);
		}
	}
	else
		show[x][y] = n + '0';
}

