#pragma once

#include<stdio.h> 
#include<Windows.h> 
#include<conio.h> 
#include<stdlib.h> 
#include<time.h> 

#define WIDTH 10   // ���� ��
#define HEIGHT 20  // ���� ��
#define Y 0 
#define X 1 
#define NULL 0  // �����
#define WALL 1  // ��
#define PLAYER 2 // �����
#define STAR 3  // ��
//#define false 0 
//#define true 1 

int player[2];
int run = 1;
int score_s = 0;

void StarGame();
char gamemenu_s();
void Init(int map[][WIDTH]);
void StarCreate(int map[HEIGHT][WIDTH]);
void MakeWall(int map[][WIDTH]);
void MapDraw(int map[][WIDTH]);
void Star_Update(int map[HEIGHT][WIDTH]);
int cheak_hit(int map[][WIDTH]);
void PlayerMove(int map[][WIDTH]);