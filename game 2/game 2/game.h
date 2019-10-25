#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define ROW 9
#define COL 9

#define EASY_COUNT 40


#define ROWS ROW+2
#define COLS COL+2

void VoidBoard(char board[ROWS][COLS], int rows, int cols, char set);
void Display(char board[ROWS][COLS], int row, int col);
void BuildMine(char board[ROWS][COLS], int row, int col);
int FindMine(char mine[ROWS][COLS], char show[ROWS][COLS], int x , int y , int row, int col);
void  ReturnBoard(char mine[ROWS][COLS], char show[ROWS][COLS], int x, int y);
void FirstSet(char mine[ROWS][COLS], char print[ROWS][COLS], int x, int y, int row, int col);
int GetMineCount(char board[ROWS][COLS], int x, int y);
int NoCheckboard(char print[ROWS][COLS], int row, int col);
