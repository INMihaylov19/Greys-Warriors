#include <iostream>
#include <windows.h>
#include <conio.h>
#include <string>
#include <vector>
#include "Menu.h"
using namespace std;

void mainGrid();

void art()
{
	gotoxy(2, 5); cout << char(186); gotoxy(5, 5);  cout << "  _   _   _____   _____   _____   _____   _____  __   __  "; cout << char(186) << endl;
	gotoxy(2, 6); cout << char(186); gotoxy(5, 6);  cout << " | | | | |_   _| /  ___| |_   _| |  _  | | ___ \\ \\ \\ / /  "; cout << char(186) << endl;
	gotoxy(2, 7); cout << char(186); gotoxy(5, 7);  cout << " | |_| |   | |   \\ `--.    | |   | | | | | |_/ /  \\ V /   "; cout << char(186) << endl;
	gotoxy(2, 8); cout << char(186); gotoxy(5, 8);  cout << " |  _  |   | |    `--. \\   | |   | | | | |    /    \\ /    "; cout << char(186) << endl;
	gotoxy(2, 9); cout << char(186); gotoxy(5, 9);  cout << " | | | |  _| |_  /\\__/ /   | |   \\ \\_/ / | |\\ \\    | |    "; cout << char(186) << endl;
	gotoxy(2, 10); cout << char(186); gotoxy(5, 10);  cout << " \\_| |_/  \\___/  \\____/    \\_/    \\___/  \\_| \\_|   \\_/    "; cout << char(186) << endl;


	gotoxy(2, 11); cout << char(186); gotoxy(15, 11); cout << "  _____   _____   _____   _   __                "; cout << char(186) << endl;
	gotoxy(2, 12); cout << char(186); gotoxy(15, 12);  cout << " | ___ \\ |  _  | |  _  | | | / /                "; cout << char(186) << endl;
	gotoxy(2, 13); cout << char(186); gotoxy(15, 13);  cout << " | |_/ / | | | | | | | | | |/ /                 "; cout << char(186) << endl;
	gotoxy(2, 14); cout << char(186); gotoxy(15, 14);  cout << " | ___ \\ | | | | | | | | |    \\                 "; cout << char(186) << endl;
	gotoxy(2, 15); cout << char(186); gotoxy(15, 15);  cout << " | |_/ / \\ \\_/ / \\ \\_/ / | |\\  \\                "; cout << char(186) << endl;
	gotoxy(2, 16); cout << char(186); gotoxy(15, 16);  cout << " \\____/   \\___/   \\___/  \\_| \\_/                "; cout << char(186) << endl;
}

struct Title 
{
	//[0] is for title, [1] is for year, [2] is for participants and [3] is for details
	vector<string> event;
	Title* next = NULL;
};

Title* Head = new Title;
int createdBook = true;

void addEventToNotebook();

void drawNotebookContent(bool isAdd) 
{
	system("cls");
	Title* outputHead = Head;
	char key;
	int pageNumber = 1;
	
	while (outputHead != NULL)
	{
		cout << outputHead->event[0];
		for (size_t i = 0; i <= (50 - outputHead->event[0].size()); i++) 
		{
			cout << ".";
		}
		cout << pageNumber << endl;
		pageNumber += 2;
		outputHead = outputHead->next;
	}
	
	
	if(isAdd) {
		cout << "Add new Event";
		key = _getch();
		if (key == '\r')
		{
			addEventToNotebook();
		}
		if (key == char(27))
		{
			createdBook = false;
			mainGrid();
		}
	}
	else {
		key = _getch();
		if (key == char(27))
		{
			createdBook = false;
			mainGrid();
		}
	}
	

}

void newElement(Title* Head, vector<string> value)
{
	Title* newElement = new Title;
	newElement->event = value;
	newElement->next = Head->next;
	Head->next = newElement;
}

void addEventToNotebook()
{
	string eventInformation, outputInfo[4] = { "Enter Event's name: ", "Enter Event's year: ",
	"Enter Event's participants: ", "Enter Event Details: " };
	vector <string> event;

	for (int i = 0; i < 4; i++) 
	{
		cout << outputInfo[i];
		getline(cin, eventInformation);
		event.push_back(eventInformation);
	}

	newElement(Head, event);
	drawNotebookContent(true);
}

void startNewNotebook() 
{
	system("CLS");
	string eventInformation, outputInfo[4] = { "Enter Event's name: ", "Enter Event's year: ",
	"Enter Event's participants: ", "Enter Event Details: " };
	vector <string> event;

	for (int i = 0; i < 4; i++) 
	{
		cout << outputInfo[i];
		getline(cin, eventInformation);
		event.push_back(eventInformation);
	}

	Head = new Title{ event, NULL };
	drawNotebookContent(true);
}

void notebookCover()
{
	gotoxy(63, 2); cout << char(186);
	gotoxy(63, 3); cout << char(186);
	gotoxy(63, 4); cout << char(186);
	gotoxy(63, 17); cout << char(186);
	gotoxy(63, 18); cout << char(186);
	gotoxy(63, 19); cout << char(186);
	gotoxy(63, 20); cout << char(186);
	gotoxy(63, 21); cout << char(186);
	gotoxy(63, 22); cout << char(186);
	gotoxy(63, 23); cout << char(186);
	gotoxy(63, 24); cout << char(186);
	gotoxy(63, 25); cout << char(186);
	gotoxy(63, 26); cout << char(186);
	gotoxy(63, 27); cout << char(186);
	gotoxy(63, 28); cout << char(188);
	gotoxy(2, 2); cout << char(186);
	gotoxy(2, 3); cout << char(186);
	gotoxy(2, 4); cout << char(186);
	gotoxy(2, 17); cout << char(186);
	gotoxy(2, 18); cout << char(186);
	gotoxy(2, 19); cout << char(186);
	gotoxy(2, 20); cout << char(186);
	gotoxy(2, 21); cout << char(186);
	gotoxy(2, 22); cout << char(186);
	gotoxy(2, 23); cout << char(186);
	gotoxy(2, 24); cout << char(186);
	gotoxy(2, 25); cout << char(186);
	gotoxy(2, 26); cout << char(186);
	gotoxy(2, 27); cout << char(186);
	gotoxy(2, 28); cout << char(200);

	for (int i = 0; i < 60; i++)
	{
		cout << char(205);
	}

	gotoxy(2, 1); cout << char(201);
	for (int i = 0; i < 60; i++)
	{
		cout << char(205);
	}
	cout << char(187);
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
		gotoxy(70, 8); color(SetColor[0]); cout << char(201);
		for (int i = 0; i < 20; i++)
		{
			cout << char(205);
		}
		cout << char(187);
		gotoxy(70, 9); cout << char(186) << "      1. Open       " << char(186) << endl;
		gotoxy(70, 10); cout << char(200);
		for (int i = 0; i < 20; i++)
		{
			cout << char(205);
		}
		cout << char(188); color(SetColor[2]);


		gotoxy(70, 11); color(SetColor[1]); cout << char(201);
		for (int i = 0; i < 20; i++)
		{
			cout << char(205);
		}
		cout << char(187);
		gotoxy(70, 12); cout << char(186) << "    2. Add/Edit     " << char(186);
		gotoxy(70, 13); cout << char(200);
		for (int i = 0; i < 20; i++)
		{
			cout << char(205);
		}
		cout << char(188); color(SetColor[2]);


		gotoxy(70, 14); color(SetColor[2]); cout << char(201);
		for (int i = 0; i < 20; i++)
		{
			cout << char(205);
		}
		cout << char(187);
		gotoxy(70, 15); cout << char(186) << "     3. Delete      " << char(186) << endl; color(SetColor[2]);
		gotoxy(70, 16); cout << char(200);
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
			if (counter == 1 && createdBook == false)
			{
				drawNotebookContent(false);
				system("CLS");
				//Open option
				break;
			}
			if (counter == 2)
			{
				if (createdBook) 
				{
					startNewNotebook();
				}
				else 
				{
					drawNotebookContent(true);
				}
				break;
			}
			if (counter == 3)
			{
				//Delete option
			}
		}

		if (key == char(27)) 
		{
			Menu();
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
	system("cls");
	art();
	notebookCover();
	bookMenu();
}

