#define _CRT_SECURE_NO_WARNINGS 1
#include "game.h"



//���̵���ʾ
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

//�����̿�λ���ж�
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
//����������
void GamePlayer(char board[ROW][COL], int row, int col)
{
	int x = 0;
	int y = 0;
	printf("������ߣ�\n");
	while (1)
	{
		printf("���������꣺\n");
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
				printf("�������Ѿ���ռ�����������������룺\n");
			}
		}
		else
		{
			printf("����������Ƿ��������������룺\n");
		}
	}
}
//�����������
void ComputerPlayer(char board[ROW][COL], int row, int col)
{
	int x = 0;
	int y = 0;
	printf("�����ߣ�\n");
	while (1)
	{
		x = rand() % row;//�ж������������
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
//�ж���Ӯ
char CheckWinner(char board[ROW][COL], int row, int col)
{
	int i = 0;
	//�ж���
	for (i = 0; i<row; i++)
	{
		if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != ' ')
		{
			return board[i][0];
		}
	}
	//�ж���
	for (i = 0; i<col; i++)
	{
		if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[0][i] != ' ')
		{
			return board[0][i];
		}
	}

	//�ж�б��
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
		//����
		return 'p';
	}
	//ƽ��
	else
	 return 'c';
}
