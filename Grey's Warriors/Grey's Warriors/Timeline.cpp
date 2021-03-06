#include <iostream>
#include <windows.h>
#include <conio.h>
#include <string>
#include <fstream>
#include <vector>
#include "Menu.h"
#include "SearchEngine.h"
using namespace std;

struct Timeline
{
	string title;
	int date = 0;
	Timeline* next = NULL;
};

Timeline** timelinEvents = new Timeline * [20];
string timeLineTitle[20];
int currentSize = -1;

void timelineSection();

void searchBoxTimeline(int whichYear) // Inputs a year and searches for it in timeline
{
	bool isFound = true;
	for (int i = 0; i <= currentSize; ++i)
	{
		Timeline* temp = *(timelinEvents + i);
		while (temp != NULL)
		{
			if (firstConvert(temp->date) == whichYear)
			{
				cout << " Timeline:	" << timeLineTitle[i] << "->" << temp->title << endl;
				isFound = false;
			}
			temp = temp->next;
		}
	}

	if (isFound)
	{
		cout << " There is no result in Timeline\n";
	}

	cout << endl;
}

void newElementName(Timeline* Head, string value1, int value2)
{
	Timeline* newElement = new Timeline;
	newElement->title = value1;
	newElement->date = value2;
	newElement->next = Head->next;
	Head->next = newElement;
}

string extractInfo(int& i, string info, string line)
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

void inputFromFileTimeline() // Extracts info from Timeline and puts it in EventDataTimeline.txt file
{
	ifstream inputFile; inputFile.open("EventDataTimeline.txt", ios::in | ios::app);

	string title, data, currentN, currentY;
	int i = 2;

	while (getline(inputFile, data))
	{
		currentSize++;
		timeLineTitle[currentSize] = extractInfo(i, title, data);

		currentN = extractInfo(i, currentN, data);
		currentY = extractInfo(i, currentY, data);

		Timeline* temp = new Timeline{ currentN, stoi(currentY), NULL };

		for (int j = 0; j < stoi(data.substr(0, 1)) - 1; j++)
		{
			currentN = extractInfo(i, currentN, data);
			currentY = extractInfo(i, currentY, data);

			newElementName(temp, currentN, stoi(currentY));
		}

		*(timelinEvents + currentSize) = temp;
		i = 2;
	}

	inputFile.close();
}

void Field(int size) 
{
	cout << char(201);

	for (int i = 0; i < size; i++)
	{
		cout << char(205);
	}
}

void linkedListSort(int array[], string arrayS[], int size) // Sorts dates using the bubble sort method
{
	int temp;
	string tempS;
	for (int step = 0; step < size; ++step) 
	{
		for (int i = 0; i < size - step; ++i) 
		{
			if (array[i] >= array[i + 1])
			{
				temp = array[i];
				tempS = arrayS[i];
				array[i] = array[i + 1];
				arrayS[i] = arrayS[i + 1];
				array[i + 1] = temp;
				arrayS[i + 1] = tempS;
			}
		}
	}
}

void drawTimelines();

void drawTimelineInfo(int chosenTimeline) // Prints timeline info
{
	system("cls");
	Timeline* temp = *(timelinEvents + 0);
	string nameArray[8];
	int yearArray[8], i = 0, j = 0, posx;
	char key;

	for (i = 0; i <= currentSize; ++i)
	{
		temp = *(timelinEvents + i);

		if (i + 1 == chosenTimeline)
		{
			break;
		}
	}

	cout << "\n " << timeLineTitle[i] << "\n\n\n\n" << char(195);
	i = 0;

	while (temp != NULL) 
	{
		yearArray[j] = temp->date;
		nameArray[j] = temp->title;
		temp = temp->next;
		j++;
		i++;
	}

	j = 0;

	linkedListSort(yearArray, nameArray, i);

	for(int k = 1; k <= i; k++) 
	{
		for (int i = 0; i < 9; i++)
		{
			cout << char(196);
		}

		if (j % 2 == 0)
		{
			cout << char(217);
		}

		else
		{
			cout << char(191);
		}

		j++;

		color(14);  cout << " " << yearArray[k]; color(7);

		for (int i = 5; i > to_string(yearArray[k]).size(); i--)
		{
			cout << " ";
		}
	}

	for (int i = 0; i < 10; i++)
	{
		cout << char(196);
	}

	for (int k = 1; k <= i; k++)
	{
		switch (k)
		{
		case 1: posx = 12; break; // Sets position with, every position is with 16 bigger than the previous
		case 2: posx = 28; break;
		case 3: posx = 44; break;
		case 4: posx = 60; break;
		case 5: posx = 76; break;
		case 6: posx = 92; break;
		case 7: posx = 108; break;
		}

		if (k % 2 != 0)
		{
			gotoxy(posx - 2, 4);  cout << char(179); color(11); 
			cout << " "; gotoxy(posx, 4); cout << nameArray[k] << " "; color(7);
		}

		else
		{
			gotoxy(posx - 2, 6); cout << char(179); color(11);
			cout << " "; gotoxy(posx, 6); cout << nameArray[k] << " "; color(7);
		}
	}

	drawButton(10, "      Press key to go back      ", 32, 15);

	key = _getch();
	drawTimelines();
}

void drawTimelines() // Prints timelines
{
	system("cls");
	int num, size = 0;
	char key;
	string currentTitle; //Placement in collection

	cout << endl;

	for (int i = 0; i <= currentSize; ++i)
	{
		Timeline* temp = *(timelinEvents + i);
		size = 0;

		while (temp != NULL) 
		{
			temp = temp->next;
			size++;
		}

		cout << "   " << i + 1 << ". ";

		if (timeLineTitle[i].size() > 40) 
		{
			currentTitle = timeLineTitle[i].substr(0,40);
		}

		else 
		{
			currentTitle = timeLineTitle[i];
		}

		color(14); cout << currentTitle; color(7);
		
		for (size_t j = 0; j < (50 - currentTitle.size()); j++)
		{
			cout << ".";
		}

		color(11);  cout << "(" << size << ") \n"; color(7);
	
	}

	drawButton(1, "  Press Enter to open an event  ", 32, 65);
	drawButton(4, "      Press ESC to go back      ", 32, 65);

	int pos = 8;
	string inputMessage = " Enter Timeline's number: ";

	key = _getch();
	
	if (key == '\r') //Enter key
	{
		do {
			gotoxy(65, pos); cout << inputMessage;

			if (pos != 8)
			{
				color(12);
			}

			gotoxy(65, pos + 1); Field(32); cout << endl;
			gotoxy(65, pos + 2); cout << char(186) << " "; 
			color(7); cin >> num;

			pos += 4;
			inputMessage = " Please enter valid number ";
		} while (num <= 0 || num >= size);

		drawTimelineInfo(num);
	}

	if (key == char(27)) 
	{
		timelineSection();
	}
}

void setDateToFileTimeline(Timeline*& temp, bool newLine, string tTitle = " ", int size = 0)
{
	ofstream outData;
	outData.open("EventDataTimeline.txt", ios::out | ios::app);

	if (tTitle != " ") {
		outData << size << "|" << tTitle << "^";
	}

	outData << temp->title << "^" << temp->date << "^";

	if (newLine == true)
	{
		outData << "\n";
	}

	outData.close();
}

void addEventToNote(int repeatment, Timeline* temp) 
{
	string currentN;
	int currentY;
	bool newLine = false;

	for (int i = 0; i < repeatment - 1; i++)
	{
		cin.ignore(256, '\n');
		cout << " " << char(186) << " Enter Event's name: ";

		getline(cin, currentN);

		cout << " " << char(186) << " Enter Event's year: ";

		cin >> currentY;

		cout << endl;

		newElementName(temp, currentN, currentY);

		if (i + 2 == repeatment)
		{
			newLine = true;
		}

		setDateToFileTimeline(temp->next, newLine);
	}

	*(timelinEvents + currentSize) = temp;

	drawTimelines();
}

void startNewNote(int repeat)
{
	system("cls");
	string currentN, timelineT;
	int currentY;

	gotoxy(1, 1); cout << char(201); // Fill message start
	for (int i = 0; i < 45; i++)
	{
		cout << char(205);
	}
	cout << char(187);
	gotoxy(1, 2); cout << char(186) << "     Adding new timeline. Fill all gaps!     " << char(186) << endl;
	gotoxy(1, 3); cout << char(200);
	for (int i = 0; i < 45; i++)
	{
		cout << char(205);
	}
	cout << char(188); // Fill message end

	gotoxy(2, 5); cout << "ADD TIMELINE'S NAME: " << endl;
	gotoxy(1, 6); Field(45);
	cout << endl;
	gotoxy(1, 7); cout << char(186) << " "; getline(std::cin, timelineT);

	timeLineTitle[currentSize] = timelineT;
	cout << endl;

	cout << " " << char(186) << " Enter Event's name: ";
	getline(cin, currentN);
	cout << " " << char(186) << " Enter Event's year: ";
	cin >> currentY;
	cout << endl;

	Timeline* temp = new Timeline{ currentN, currentY, NULL };

	setDateToFileTimeline(temp, false, timelineT, repeat);
	addEventToNote(repeat, temp);

	drawTimelines();
}

void drawSizeButton(int posx, int size) 
{
	gotoxy(posx, 15);  cout << char(201);
	for (int i = 0; i < 9; i++)
	{
		cout << char(205);
	}
	cout << char(187);
	gotoxy(posx, 16); cout << char(186) << "         " << char(186) << endl;
	gotoxy(posx, 17); cout << char(186) << "    " << size << "    " << char(186) << endl;
	gotoxy(posx, 18); cout << char(186) << "         " << char(186) << endl;
	gotoxy(posx, 19); cout << char(200);

	for (int i = 0; i < 9; i++)
	{
		cout << char(205);
	}
	cout << char(188);
}


void numberOfEvents() // Asks the user how many dates he wants to put in the timeline
{
	int SetColor[4] = { 14, 7, 7, 7 };
	int counter = 1, key;

	while (true)
	{
		//Button 4
		color(SetColor[0]);
		drawSizeButton(30, 4);
		color(SetColor[0]);

		//Button 5
		color(SetColor[1]);
		drawSizeButton(45, 5);
		color(SetColor[1]);

		//Button 6
		color(SetColor[2]);
		drawSizeButton(60, 6);
		color(SetColor[2]);

		//Button 7
		color(SetColor[3]);
		drawSizeButton(75, 7);
		color(SetColor[3]);

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
			currentSize += 1;
			if (currentSize != 0)
			{
				cin.ignore(256, '\n');
			}
			if (counter == 1) // If counter is equal to 1 the number of events is 4
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
			currentSize += 1;
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
	system("cls");

	gotoxy(26, 1); cout << "  _____   _____   __  __   _____   _       _____   _   _   _____ " << endl;
	gotoxy(26, 2); cout << " |_   _| |_   _| |  \\/  | |  ___| | |     |_   _| | \\ | | |  ___|" << endl;
	gotoxy(26, 3); cout << "   | |     | |   | .  . | | |__   | |       | |   |  \\| | | |__" << endl;
	gotoxy(26, 4); cout << "   | |     | |   | |\\/| | |  __|  | |       | |   | . ` | |  __|" << endl;
	gotoxy(26, 5); cout << "   | |    _| |_  | |  | | | |___  | |____  _| |_  | |\\  | | |___" << endl;
	gotoxy(26, 6); cout << "   \\_/    \\___/  \\_|  |_/ \\____/  \\_____/  \\___/  \\_| \\_/ \\____/" << endl;

	int time = 0, counter = 1;;
	int SetColor[3] = { 14, 7, 7 }; //Console coloring - 7 is for white, 14 for golden
	int key;

	while (true)
	{
		//Open collection button
		color(SetColor[0]); 
		drawButton(10, "     Collection     ", 20, 15);  
		color(SetColor[2]);
		

		//Add/Edit button
		color(SetColor[1]); 
		drawButton(10, "    Add an event    ", 20, 48);
		color(SetColor[2]);


		//Back to Menu button
		color(SetColor[2]); 
		drawButton(10, "    Back to Menu    ", 20, 81); 
		color(SetColor[2]);
		

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
				if (currentSize >= 0)
				{
					drawTimelines();
				}
				else 
				{
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

		if (key == char(27)) 
		{
			system("CLS");
			Menu();
		}

		SetColor[0] = 7;
		SetColor[1] = 7;
		SetColor[2] = 7;

		if (counter == 1) { SetColor[0] = 14; }
		if (counter == 2) { SetColor[1] = 14; }
		if (counter == 3) { SetColor[2] = 14; }
	}
}