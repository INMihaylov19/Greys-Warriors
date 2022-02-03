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
	EventName* next;
};

struct EventYear
{
	int date;
	EventYear* next = NULL;
};

EventName** HeadN = new EventName * [10];
EventYear** HeadY = new EventYear * [10];
string TimeLineTitle[10];
int coler = -1;


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

		//cout << i << "-->\t";
		while (temp != NULL) {
			//cout << temp->title << " ";
			temp = temp->next;
			sizeCount++;
		}

		/*cout << '\n' << i << "-->\t";
		while (tempY != NULL) {
			cout << tempY->date << " ";
			tempY = tempY->next;
		}*/

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