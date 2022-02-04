#include <iostream>
#include <windows.h>
#include <conio.h>
#include <string>
#include <vector>
#include "Menu.h"
using namespace std;

void timelineSection();

struct EventName
{
	string title;
	EventName* next = NULL;
};

struct EventYear
{
	int date = 0;
	EventYear* next = NULL;
};

EventName** HeadN = new EventName * [10];
EventYear** HeadY = new EventYear * [10];
string TimeLineTitle[10];
int coler = -1;

void searchBoxTimeline(int whichYear) {
	bool isFound = true;
	for (int i = 0; i <= coler; ++i)
	{
		EventName* temp = *(HeadN + i);
		EventYear* tempY = *(HeadY + i);
		while (tempY != NULL) {
			if (tempY->date == whichYear) {
				cout << "Timeline:	" << TimeLineTitle[i] << "->" << temp->title << endl;
				isFound = false;
			}
			tempY = tempY->next;
			temp = temp->next;
		}
	}
	if (isFound) {
		cout << "Baby, we couldnt find this year exactly how you couldnt find girlfriend";
	}
}
void drawTimelines()
{
	system("cls");
	int sizeCount;
	for (int i = 0; i <= coler; ++i)
	{
		sizeCount = 0;
		cout << TimeLineTitle[i];
		for (size_t j = 0; j < (50 - TimeLineTitle[i].size()); j++) {
			cout << ".";
		}
		EventName* temp = *(HeadN + i);
		EventYear* tempY = *(HeadY + i);

		cout << i << "-->\t";
		while (temp != NULL) {
			cout << temp->title << " ";
			temp = temp->next;
			sizeCount++;
		}

		cout << '\n' << i << "-->\t";
		while (tempY != NULL) {
			cout << tempY->date << " ";
			tempY = tempY->next;
		}

		cout << sizeCount << endl;
	}

	cout << "\n\n\t Iskash li da se vurnesh nazad?";
	char key;
	key = _getch();
	if (key == char(27)) {
		timelineSection();
	}
}

void newElementName(EventName* Head, string value)
{
	EventName* newElement = new EventName;
	newElement->title = value;
	newElement->next = Head->next;
	Head->next = newElement;
}


void newElementYear(EventYear* Head, int value)
{
	EventYear* newElement = new EventYear;
	newElement->date = value;
	newElement->next = Head->next;
	Head->next = newElement;
}

void addEventToNote(int repeatment, EventName* usedN, EventYear* usedY)
{
	string currentN, outputInfo[3] = { " Enter Event's name: ", " Enter Event's year: " };
	vector <string> info;
	int ind = 0, currentY;

	for (int i = 0; i < repeatment - 1; i++)
	{
		cin.ignore(256, '\n');
		cout << " " << char(179) << outputInfo[0];
		getline(cin, currentN);
		cout << " " << char(179) << outputInfo[1];
		cin >> currentY;
		cout << endl;

		newElementYear(usedY, currentY);
		newElementName(usedN, currentN);

	}
	*(HeadY + coler) = usedY;
	*(HeadN + coler) = usedN;

	drawTimelines();
}


void startNewNote(int repeat)
{
	system("cls");
	string currentN, timelineT, outputInfo[3] = { " Enter Event's name: ", " Enter Event's year: " };
	cin.ignore(256, '\n');
	cout << "ADD TIMELINE'S NAME: ";
	std::getline(std::cin, timelineT);
	TimeLineTitle[coler] = timelineT;
	cout << endl;
	int currentY;
	cout << " " << char(179) << outputInfo[0];
	getline(cin, currentN);
	cout << " " << char(179) << outputInfo[1];
	cin >> currentY;
	cout << endl;
	EventName* usedN = new EventName{ currentN, NULL };
	EventYear* usedY = new EventYear{ currentY, NULL };
	addEventToNote(repeat, usedN, usedY);
	drawTimelines();
}

void numberOfEvents()
{
	//Button 4
	gotoxy(48, 12); cout << char(201);
	for (int i = 0; i < 3; i++)
	{
		cout << char(205);
	}
	cout << char(187);
	gotoxy(48, 13); cout << char(186) << " 4 " << char(186) << endl;
	gotoxy(48, 14); cout << char(200);
	for (int i = 0; i < 3; i++)
	{
		cout << char(205);
	}
	cout << char(188);

	//Button 5
	gotoxy(54, 12); cout << char(201);
	for (int i = 0; i < 3; i++)
	{
		cout << char(205);
	}
	cout << char(187);
	gotoxy(54, 13); cout << char(186) << " 5 " << char(186) << endl;
	gotoxy(54, 14); cout << char(200);
	for (int i = 0; i < 3; i++)
	{
		cout << char(205);
	}
	cout << char(188);

	//Button 6
	gotoxy(60, 12); cout << char(201);
	for (int i = 0; i < 3; i++)
	{
		cout << char(205);
	}
	cout << char(187);
	gotoxy(60, 13); cout << char(186) << " 6 " << char(186) << endl;
	gotoxy(60, 14); cout << char(200);
	for (int i = 0; i < 3; i++)
	{
		cout << char(205);
	}
	cout << char(188);

	//Button 7
	gotoxy(66, 12); cout << char(201);
	for (int i = 0; i < 3; i++)
	{
		cout << char(205);
	}
	cout << char(187);
	gotoxy(66, 13); cout << char(186) << " 7 " << char(186) << endl;
	gotoxy(66, 14); cout << char(200);
	for (int i = 0; i < 3; i++)
	{
		cout << char(205);
	}
	cout << char(188);
}

void timelineSection()
{
	system("cls");

	gotoxy(26, 1); cout << "  _____   _____   __  __   _____   _       _____   _   _   _____ " << endl;
	gotoxy(26, 2); cout << " |_   _| |_   _| |  \\/  | |  ___| | |     |_   _| | \\ | | |  ___|" << endl;
	gotoxy(26, 3); cout << "   | |     | |   | .  . | | |__   | |       | |   |  \\| | | |__" << endl;
	gotoxy(26, 4); cout << "   | |     | |   | |\\/| | |  __|  | |       | |   | . ` | |  __|" << endl;
	gotoxy(26, 5); cout << "   | |    _| |_  | |  | | | |___  | |____  _| |_  | |\\  | | |___" << endl;
	gotoxy(26, 6); cout << "   \\_/    \\___/  \\_|  |_/ \\____/  \\_____/  \\___/  \\_| \\_/ \\____/" << endl;

	int time = 0;
	char choice;

	//Collection button
	int SetColor[3] = { 14, 7, 7 };

	SetColor[0] = 14;
	SetColor[1] = 7;
	SetColor[2] = 7;

	int counter = 1;
	int key;
	while (true)
	{
		gotoxy(30, 8); color(SetColor[0]);  cout << char(201);
		for (int i = 0; i < 14; i++)
		{
			cout << char(205);
		}
		cout << char(187);
		gotoxy(30, 9); cout << char(186) << "  Collection  " << char(186) << endl;
		gotoxy(30, 10); cout << char(200);
		for (int i = 0; i < 14; i++)
		{
			cout << char(205);
		}
		cout << char(188); color(SetColor[2]);

		//Add/Edit button
		gotoxy(51, 8); color(SetColor[1]); cout << char(201);
		for (int i = 0; i < 14; i++)
		{
			cout << char(205);
		}
		cout << char(187);
		gotoxy(51, 9); cout << char(186) << "   Add/Edit   " << char(186) << endl;
		gotoxy(51, 10); cout << char(200);
		for (int i = 0; i < 14; i++)
		{
			cout << char(205);
		}
		cout << char(188); color(SetColor[2]);

		//Back to Menu button
		gotoxy(72, 8); color(SetColor[2]); cout << char(201);
		for (int i = 0; i < 14; i++)
		{
			cout << char(205);
		}
		cout << char(187);
		gotoxy(72, 9); cout << char(186) << " Back to Menu " << char(186) << endl;
		gotoxy(72, 10); cout << char(200);
		for (int i = 0; i < 14; i++)
		{
			cout << char(205);
		}
		cout << char(188); color(SetColor[2]);

		key = _getch();

		if (key == 75 && (counter >= 2 && counter <= 3)) // 75 is the ASCII code for the leftwards arrow
		{
			counter--;
		}
		if (key == 77 && (counter >= 1 && counter <= 2)) // 77 is the ASCII code for rightwards arrow
		{
			counter++;
		}
		if (key == '\r') // enter key
		{
			if (counter == 1)
			{
				if (coler >= 0)
				{
					drawTimelines();
				} else {
					timelineSection();
				}
			}
			if (counter == 2)
			{
				numberOfEvents();
				coler += 1;
				do {
					cin >> time;
					if (time < 3 || time > 7) {
						cout << "must be less than 7 and more than 4";
					}
				} while (time < 3 || time > 7);
				startNewNote(time);
				break;
			}
			if (counter == 3)
			{
				system("CLS");
				Menu();
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


}