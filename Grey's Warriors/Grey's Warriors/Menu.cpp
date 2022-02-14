#include <iostream>
#include <conio.h>
#include <windows.h>
#include "Notebook.h"
#include "Timeline.h"
#include "SearchEngine.h"
using namespace std;

bool consoleOpened = false; //Checks if console is opened now and extracts data from files

void color(int color) //Sets color of the text
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

void gotoxy(int x, int y)  //Get the coordinates inside the console
{
	COORD coord;
	coord.X = x; // x-axis
	coord.Y = y; // y-axis
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void menuArt(int SetColor[]) // ASCII art in main menu
{
	system("cls");
	gotoxy(4, 3); color(SetColor[0]); cout << " ";

	for (int i = 0; i < 110; i++)
	{
		cout << char(205);
	}

	gotoxy(4, 4); color(SetColor[0]); cout << "  _____   _____   _____  __   __  _   _____     _    _    ___    _____   _____   _____   _____   _____   _____ " << endl;
	gotoxy(4, 5); color(SetColor[0]); cout << " |  __ \\ | ___ \\ |  ___| \\ \\ / / ( ) /  ___|   | |  | |  / _ \\  | ___ \\ | ___ \\ |_   _| |  _  | | ___ \\ /  ___| " << endl;
	gotoxy(4, 6); color(SetColor[0]); cout << " | |  \\/ | |_/ / | |__    \\ V /  |/  \\ `--.    | |  | | / /_\\ \\ | |_/ / | |_/ /   | |   | | | | | |_/ / \\ `--. " << endl;
	gotoxy(4, 7); color(SetColor[0]); cout << " | | __  |    /  |  __|    \\ /        `--. \\   | |/\\| | |  _  | |    /  |    /    | |   | | | | |    /   `--. \\ " << endl;
	gotoxy(4, 8); color(SetColor[0]); cout << " | |_\\ \\ | |\\ \\  | |___    | |       /\\__/ /   \\  /\\  / | | | | | |\\ \\  | |\\ \\   _| |_  \\ \\_/ / | |\\ \\  /\\__/ / " << endl;
	gotoxy(4, 9); color(SetColor[0]); cout << "  \\____/ \\_| \\_| \\____/    \\_/       \\____/     \\/  \\/  \\_| |_/ \\_| \\_| \\_| \\_|  \\___/   \\___/  \\_| \\_| \\____/ ";
	gotoxy(4, 11); color(SetColor[0]); cout << " ";

	for (int i = 0; i < 110; i++)
	{
		cout << char(205);
	}
}

void drawButton(int posy, string text, int size, int posx)
{
	gotoxy(posx, posy); cout << char(201);

	for (int i = 0; i < size; i++)
	{
		cout << char(205);
	}

	cout << char(187);
	gotoxy(posx, posy + 1); cout << char(186) << text << char(186) << endl;
	gotoxy(posx, posy + 2); cout << char(200);

	for (int i = 0; i < size; i++)
	{
		cout << char(205);
	}

	cout << char(188);
}

int Menu() //Main menu with three options
{
	if (consoleOpened == false) // Opens the console
	{
		inputFromFileTimeline(); // Extracts the data from EventDataTimeline file
		inputFromFileNotebook(); // Extracts the data from EventDataNotebook file
		consoleOpened = true;
	}

	char key; // Key to be entered
	int SetColor[3] = { 14, 7, 7 };
	int counter = 1;

	menuArt(SetColor);

	while (true) 
	{
		// Button for history notebook section
		color(SetColor[0]);
		drawButton(13, "       1. History Notebook      ", 32, 42); 
		color(SetColor[2]);


		// Button for timeline section
		color(SetColor[1]); 
		drawButton(16, "          2. Timeline           ", 32, 42); 
		color(SetColor[2]);
		

		// Button for Search Engine
		color(SetColor[2]);  
		drawButton(19, "       3. Search Engine         ", 32, 42);
		color(SetColor[2]);
	
		key = _getch();

		if (key == 72 && (counter >= 2 && counter <= 3)) // 72 is the ASCII code for the up arrow
		{
			counter--;
		}

		if (key == 80 && (counter >= 1 && counter <= 2)) // 80 is the ASCII code for the up arrow
		{
			counter++;
		}

		if (key == '\r') // enter key
		{
			if (counter == 1)
			{
				notebookSection();
				break;
			}

			if (counter == 2)
			{
				system("CLS");
				timelineSection();  //The timeline function will be displayed afterwards
				break;
			}

			if (counter == 3)
			{
				searchEngine();
				break;
			}
		}

		SetColor[0] = 7;
		SetColor[1] = 7;
		SetColor[2] = 7;

		if (counter == 1) { SetColor[0] = 14; }
		if (counter == 2) { SetColor[1] = 14; }
		if (counter == 3) { SetColor[2] = 14; }
	}

	return 0;
}