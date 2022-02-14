#pragma once
#include <iostream>
#include <conio.h>
#include <windows.h>

void color(int color); 

void gotoxy(int x, int y);

void menuArt(int SetColor[]);

void drawButton(int posy, std::string text, int size, int posx);

void searchEngine();

int Menu();