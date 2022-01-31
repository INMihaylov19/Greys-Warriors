#include <iostream>
#include <windows.h>
#include <conio.h>
#include "Menu.h"
using namespace std;

void art()
{
	gotoxy(3, 5); cout << "  _   _   _____   _____   _____   _____   _____  __   __" << endl;
	gotoxy(3, 6); cout << " | | | | |_   _| /  ___| |_   _| |  _  | | ___ \\ \\ \\ / /" << endl;
	gotoxy(3, 7); cout << " | |_| |   | |   \\ `--.    | |   | | | | | |_/ /  \\ V /" << endl;
	gotoxy(3, 8); cout << " |  _  |   | |    `--. \\   | |   | | | | |    /    \\ /" << endl;
	gotoxy(3, 9); cout << " | | | |  _| |_  /\\__/ /   | |   \\ \\_/ / | |\\ \\    | |" << endl;
	gotoxy(3, 10); cout << " \\_| |_/  \\___/  \\____/    \\_/    \\___/  \\_| \\_|   \\_/" << endl;


	gotoxy(13, 11); cout << "  _____   _____   _____   _   __" << endl;
	gotoxy(13, 12); cout << " | ___ \\ |  _  | |  _  | | | / /" << endl;
	gotoxy(13, 13); cout << " | |_/ / | | | | | | | | | |/ /" << endl;
	gotoxy(13, 14); cout << " | ___ \\ | | | | | | | | |    \\" << endl;
	gotoxy(13, 15); cout << " | |_/ / \\ \\_/ / \\ \\_/ / | |\\  \\" << endl;
	gotoxy(13, 16); cout << " \\____/   \\___/   \\___/  \\_| \\_/ " << endl;
}

void noteBook()
{
	gotoxy(2, 1);cout << char(201);	
	for (int i = 0; i < 60; i++)
	{
		cout << char(205);
	}
	for (int i = 0; i < 20; i++)
	{
		cout << "  " << char(186) << endl;
	}


	

}

int bookMenu()
{
	int counter = 1;
	char key;
	int SetColor[3] = { 14, 7, 7 };

	SetColor[0] = 14;
	SetColor[1] = 7;
	SetColor[2] = 7;

	while (true)
	{
		gotoxy(60, 8); color(SetColor[0]); cout << char(201);
		for (int i = 0; i < 20; i++)
		{
			cout << char(205);
		}
		cout << char(187);
		gotoxy(60, 9); cout << char(186) << "      1. Open       " << char(186) << endl;
		gotoxy(60, 10); cout << char(200);
		for (int i = 0; i < 20; i++)
		{
			cout << char(205);
		}
		cout << char(188); color(SetColor[2]);


		gotoxy(60, 11); color(SetColor[1]); cout << char(201);
		for (int i = 0; i < 20; i++)
		{
			cout << char(205);
		}
		cout << char(187);
		gotoxy(60, 12); cout << char(186) << "    2. Add/Edit     " << char(186);
		gotoxy(60, 13); cout << char(200);
		for (int i = 0; i < 20; i++)
		{
			cout << char(205);
		}
		cout << char(188); color(SetColor[2]);


		gotoxy(60, 14); color(SetColor[2]); cout << char(201);
		for (int i = 0; i < 20; i++)
		{
			cout << char(205);
		}
		cout << char(187);
		gotoxy(60, 15); cout << char(186) << "     3. Delete      " << char(186) << endl; color(SetColor[2]);
		gotoxy(60, 16); cout << char(200);
		for (int i = 0; i < 20; i++)
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
				system("CLS");
				//Open option
				break;
			}
			if (counter == 2)
			{
				system("CLS");
				//Add/Edit option
				break;
			}
			if (counter == 3)
			{
				//Delete option
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



void mainGrid()
{
	art();
	noteBook();
	gotoxy(4, 2); bookMenu();
}

