#include <iostream>
#include <conio.h>
#include <windows.h>
#include "Notebook.h"
#include "Timeline.h"
#include "SearchEngine.h"
using namespace std;

bool consoleOpened = false; //Checks if console is opened and extracts data from files

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
	gotoxy(4, 11); color(SetColor[0]);
	cout << " ";
	for (int i = 0; i < 110; i++)
	{
		cout << char(205);
	}
}


int Menu() //Main menu
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
	SetColor[0] = 14;
	SetColor[1] = 7;
	SetColor[2] = 7;

	menuArt(SetColor);

	while (true) 
	{
		// Button for history notebook section
		gotoxy(42, 13); color(SetColor[0]); cout << char(201); 
		for (int i = 0; i < 32; i++)
		{
			cout << char(205);
		}
		cout << char(187);
		gotoxy(42, 14); cout << char(186) << "       1. History Notebook      " << char(186) << endl;
		gotoxy(42, 15); cout << char(200);
		for (int i = 0; i < 32; i++)
		{
			cout << char(205);
		}
		cout << char(188); color(SetColor[2]);

		// Button for timeline section
		gotoxy(42, 16); color(SetColor[1]); cout << char(201);
		for (int i = 0; i < 32; i++)
		{
			cout << char(205);
		}
		cout << char(187);
		gotoxy(42, 17); cout << char(186) << "          2. Timeline           " << char(186);
		gotoxy(42, 18); cout << char(200);
		for (int i = 0; i < 32; i++)
		{
			cout << char(205);
		}
		cout << char(188); color(SetColor[2]);

		// Button for search engine
		gotoxy(42, 19); color(SetColor[2]); cout << char(201);
		for (int i = 0; i < 32; i++)
		{
			cout << char(205);
		}
		cout << char(187);
		gotoxy(42, 20); cout << char(186) << "       3. Search Engine         " << char(186) << endl;
		gotoxy(42, 21); cout << char(200);
		for (int i = 0; i < 32; i++)
		{
			cout << char(205);
		}
		cout << char(188); color(SetColor[2]);

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
				mainGrid();
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