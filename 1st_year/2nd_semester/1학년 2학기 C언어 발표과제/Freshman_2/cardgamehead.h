#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

int arrayAnimal[4][5];
int checkAnimal[4][5];
char* strAnimal[10];
int totalScore = 200;

int AnimalMainRole();
void initAnimalArray();
void initAnimalName();
void shuffleAnimal();
int getEmptyPosition();
int conv_pos_x(int x);
int conv_pos_y(int y);
void printAnimal();
void printQuestion();
int foundAllAnimal();