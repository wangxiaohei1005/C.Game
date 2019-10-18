#ifndef GAME_H
#define GAME_H
#define ROW 3
#define COL 3

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void CheckBoard(char board[ROW][COL], int row, int col);
void DisplayBoard(char board[ROW][COL], int row, int col);
void GamePlayer(char board[ROW][COL], int row, int col);
void ComputerPlayer(char board[ROW][COL], int row, int col);
char CheckWinner(char board[ROW][COL], int row, int col);

#endif