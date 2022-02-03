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

void timelineSection()
{
	system("cls");
	int time = 0;
	char choice;
	cout << "\t\tCollection\t\t\t\tAdd/Edit\n";

	choice = _getch();
	if (choice == char(27))
	{
		Menu();
	}
	if (choice == '2') {
		cout << "\n\t 4\t5\t6\t7 - ";
		coler += 1;
		do {
			cin >> time;
			if (time < 3 || time > 7) {
				cout << "must be less than 7 and more than 4";
			}
		} while (time < 3 || time > 7);
		startNewNote(time);
	}
	if (choice == '1' && coler >= 0) {
		drawTimelines();
	}
	else {
		timelineSection();
	}


}