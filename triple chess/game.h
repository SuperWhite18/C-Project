#ifndef __GAEM_H__
#define __GAME_H__

#include<stdio.h>
#include<windows.h>
#include<time.h>//随机数
#pragma warning (disable:4996)
//宏定义放在头文件
#define ROW 3
#define COL 3
#define Player_C 'X'
#define Computer_C 'O'
#define INIT  ' '
//在game.c里实现
void InitBoard(char board[][COL], int row, int col);//行可以省略，列不可以
void ShowBoard(char board[][COL], int row, int col);
void ComputerMove(char board[][COL], int row, int col);
char Judge(char board[][COL], int row, int col);


void Game();

#endif
