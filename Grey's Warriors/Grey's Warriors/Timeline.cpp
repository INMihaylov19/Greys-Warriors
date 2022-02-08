#include <iostream>
#include <windows.h>
#include <conio.h>
#include <string>
#include <fstream>
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

std::string extractInfo(int& i, std::string info, std::string line)
{
	info = "";

	for (; i < line.size(); i++)
	{
		if (line[i] == '^')
		{
			break;
		}
		info += line[i];
	}
	i++;
	return info;
}

void inputFromFile() {
	ifstream inputFile;
	inputFile.open("EventData.txt", ios::in | ios::app);

	string title, data, currentN;
	string currentY;
	int i = 2;
	while (getline(inputFile, data)) 
	{
		coler++;
		TimeLineTitle[coler] = extractInfo(i, title, data);

		currentN = extractInfo(i, currentN, data);
		currentY = extractInfo(i, currentY, data);
		/*cout << currentN << " " << currentY << endl;*/
		EventName* usedN = new EventName{ currentN, NULL };
		EventYear* usedY = new EventYear{ stoi(currentY), NULL };

		for (int j = 0; j < stoi(data.substr(0,1)) - 1; j++) {
			currentN = extractInfo(i, currentN, data);
			currentY = extractInfo(i, currentY, data);
			/*cout << currentN << " " << stoi(currentY) << endl;*/
			newElementYear(usedY, stoi(currentY));
			newElementName(usedN, currentN);
		}
		*(HeadY + coler) = usedY;
		*(HeadN + coler) = usedN;
		i = 2;
	}
	inputFile.close();
}

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
		cout<<"There is no result in Timeline";
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

	gotoxy(80, 2); cout << char(201);
	for (int i = 0; i < 32; i++)
	{
		cout << char(205);
	}
	cout << char(187);
	gotoxy(80, 3); cout << char(186) << "      Press ESC to go back      " << char(186) << endl;
	gotoxy(80, 4); cout << char(200);
	for (int i = 0; i < 32; i++)
	{
		cout << char(205);
	}
	cout << char(188);
	char key;
	key = _getch();
	if (key == char(27)) {
		timelineSection();
	}
}

void setDateToFile(EventName*& tempN, EventYear*& tempY,  bool newLine, string tTitle = " ", int size = 0)
{
	ofstream outData;
	outData.open("EventData.txt", ios::out | ios::app);
	if (tTitle != " ") {
		outData << size << "|" << tTitle << "^";
	}
	
	outData << tempN->title << "^" << tempY->date << "^";
	if (newLine == true) 
	{
		outData << "\n";
	}
	outData.close();
} 

void addEventToNote(int repeatment, EventName* usedN, EventYear* usedY)
{
	string currentN, outputInfo[3] = { " Enter Event's name: ", " Enter Event's year: " };
	vector <string> info;
	int ind = 0, currentY;
	bool newLine = false;

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
		if (i + 2 == repeatment)
		{
			newLine = true;
		}
		setDateToFile(usedN->next, usedY->next, newLine);
	}
	*(HeadY + coler) = usedY;
	*(HeadN + coler) = usedN;
	
	drawTimelines();
}

void startNewNote(int repeat)
{
	system("cls");
	string currentN, timelineT, outputInfo[3] = { " Enter Event's name: ", " Enter Event's year: " };
	
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
	setDateToFile(usedN, usedY, false, timelineT, repeat);
	addEventToNote(repeat, usedN, usedY);
	
	drawTimelines();
}

void numberOfEvents()
{
	int SetColor[4] = {14, 7, 7, 7};

	SetColor[0] = 14;
	SetColor[1] = 7;
	SetColor[2] = 7;
	SetColor[3] = 7;

	int counter = 1;
	int key;
	while (true)
	{
		//Button 4
		gotoxy(30, 15); color(SetColor[0]);  cout << char(201);
		for (int i = 0; i < 9; i++)
		{
			cout << char(205);
		}
		cout << char(187);
		gotoxy(30, 16); cout << char(186) << "         " << char(186) << endl;
		gotoxy(30, 17); cout << char(186) << "    4    " << char(186) << endl;
		gotoxy(30, 18); cout << char(186) << "         " << char(186) << endl;
		gotoxy(30, 19); cout << char(200);
		for (int i = 0; i < 9; i++)
		{
			cout << char(205);
		}
		cout << char(188); color(SetColor[0]);

		//Button 5
		gotoxy(45, 15); color(SetColor[1]);  cout << char(201);
		for (int i = 0; i < 9; i++)
		{
			cout << char(205);
		}
		cout << char(187);
		gotoxy(45, 16); cout << char(186) << "         " << char(186) << endl;
		gotoxy(45, 17); cout << char(186) << "    5    " << char(186) << endl;
		gotoxy(45, 18); cout << char(186) << "         " << char(186) << endl;
		gotoxy(45, 19); cout << char(200);
		for (int i = 0; i < 9; i++)
		{
			cout << char(205);
		}
		cout << char(188); color(SetColor[1]);

		//Button 6
		gotoxy(60, 15); color(SetColor[2]);  cout << char(201);
		for (int i = 0; i < 9; i++)
		{
			cout << char(205);
		}
		cout << char(187);
		gotoxy(60, 16); cout << char(186) << "         " << char(186) << endl;
		gotoxy(60, 17); cout << char(186) << "    6    " << char(186) << endl;
		gotoxy(60, 18); cout << char(186) << "         " << char(186) << endl;
		gotoxy(60, 19); cout << char(200);
		for (int i = 0; i < 9; i++)
		{
			cout << char(205);
		}
		cout << char(188); color(SetColor[2]);

		//Button 7
		gotoxy(75, 15); color(SetColor[3]);  cout << char(201);
		for (int i = 0; i < 9; i++)
		{
			cout << char(205);
		}
		cout << char(187);
		gotoxy(75, 16); cout << char(186) << "         " << char(186) << endl;
		gotoxy(75, 17); cout << char(186) << "    7    " << char(186) << endl;
		gotoxy(75, 18); cout << char(186) << "         " << char(186) << endl;
		gotoxy(75, 19); cout << char(200);
		for (int i = 0; i < 9; i++)
		{
			cout << char(205);
		}
		cout << char(188); color(SetColor[3]);

		key = _getch();

		if (key == 75 && (counter >= 2 && counter <= 4)) // 75 is the ASCII code for the leftwards arrow
		{
			counter--;
		}
		if (key == 77 && (counter >= 1 && counter <= 3)) // 77 is the ASCII code for rightwards arrow
		{
			counter++;
		}
		if (key == '\r') // enter key
		{
			coler += 1;
			
			cin.ignore(256, '\n');
			
			if (counter == 1)
			{
				startNewNote(4);
				break;
			}
			if (counter == 2)
			{
				startNewNote(5);
				break;
			}
			if (counter == 3)
			{
				startNewNote(6);
				break;
			}
			if (counter == 4)
			{
				color(7);
				startNewNote(7);
			}
			coler += 1;
		}
		SetColor[0] = 7;
		SetColor[1] = 7;
		SetColor[2] = 7;
		SetColor[3] = 7;

		if (counter == 1) { SetColor[0] = 14; }
		if (counter == 2) { SetColor[1] = 14; }
		if (counter == 3) { SetColor[2] = 14; }
		if (counter == 4) { SetColor[3] = 14; }
	}
}

void timelineSection()
{
	if (coler == -1) {
		inputFromFile();
	}
	
	system("cls");

	gotoxy(26, 1); cout << "  _____   _____   __  __   _____   _       _____   _   _   _____ " << endl;
	gotoxy(26, 2); cout << " |_   _| |_   _| |  \\/  | |  ___| | |     |_   _| | \\ | | |  ___|" << endl;
	gotoxy(26, 3); cout << "   | |     | |   | .  . | | |__   | |       | |   |  \\| | | |__" << endl;
	gotoxy(26, 4); cout << "   | |     | |   | |\\/| | |  __|  | |       | |   | . ` | |  __|" << endl;
	gotoxy(26, 5); cout << "   | |    _| |_  | |  | | | |___  | |____  _| |_  | |\\  | | |___" << endl;
	gotoxy(26, 6); cout << "   \\_/    \\___/  \\_|  |_/ \\____/  \\_____/  \\___/  \\_| \\_/ \\____/" << endl;

	int time = 0;

	//Collection button
	int SetColor[3] = { 14, 7, 7 };

	SetColor[0] = 14;
	SetColor[1] = 7;
	SetColor[2] = 7;

	int counter = 1;
	int key;
	while (true)
	{
		gotoxy(15, 10); color(SetColor[0]);  cout << char(201);
		for (int i = 0; i < 20; i++)
		{
			cout << char(205);
		}
		cout << char(187);
		gotoxy(15, 11); cout << char(186) << "     Collection     " << char(186) << endl;
		gotoxy(15, 12); cout << char(200);
		for (int i = 0; i < 20; i++)
		{
			cout << char(205);
		}
		cout << char(188); color(SetColor[2]);

		//Add/Edit button
		gotoxy(48, 10); color(SetColor[1]); cout << char(201);
		for (int i = 0; i < 20; i++)
		{
			cout << char(205);
		}
		cout << char(187);
		gotoxy(48, 11); cout << char(186) << "      Add/Edit      " << char(186) << endl;
		gotoxy(48, 12); cout << char(200);
		for (int i = 0; i < 20; i++)
		{
			cout << char(205);
		}
		cout << char(188); color(SetColor[2]);

		//Back to Menu button
		gotoxy(81, 10); color(SetColor[2]); cout << char(201);
		for (int i = 0; i < 20; i++)
		{
			cout << char(205);
		}
		cout << char(187);
		gotoxy(81, 11); cout << char(186) << "    Back to Menu    " << char(186) << endl;
		gotoxy(81, 12); cout << char(200);
		for (int i = 0; i < 20; i++)
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