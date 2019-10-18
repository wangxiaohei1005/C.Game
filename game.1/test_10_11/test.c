#define _CRT_SECURE_NO_WARNINGS 1

#include "game.h"

void menu()
{
	printf("\n");
	printf("****************************************\n");
	printf("***********  ��ӭ����������  ***********\n");
	printf("***********   1.��ʼ��Ϸ   *************\n");
	printf("***********   0.������Ϸ   *************\n");
	printf("****************************************\n");
}

void Game()
{
	char tmp = 0;
	char board[ROW][COL] = { 0 };
	CheckBoard(board, ROW, COL);
	printf("����%d������Ϸ!!!\n",ROW);
	DisplayBoard(board, ROW, COL);
	while (1)
	{
		GamePlayer(board, ROW, COL);
		DisplayBoard(board, ROW, COL);
		tmp = CheckWinner(board, ROW, COL);
		if (tmp != 'c')//��Ϊƽ��
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
			printf("���Ӯ��������\n");
		}
	else if (tmp == '#')
		{
			printf("����Ӯ����������Ϸ������\n");
		}
	if (tmp=='c')
		{
			printf("ƽ�֣�����\n");
		}
}  


void Test()
{
	int Input = 0;
	srand((unsigned int)time(NULL));
	do//��һ����Ҫ��ʾ�˵�  һ�β���do while
	{
		menu();
		printf("���������ѡ��\n");
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
			printf("������������!���������룡\n");
		}
	} while (Input);
	printf("\n");

}

int main()
{
	Test();
	return 0;
}