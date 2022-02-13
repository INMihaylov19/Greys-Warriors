#include <iostream>
#include <windows.h>
#include <conio.h>
#include <string>
#include <vector>
#include <fstream>
#include "Menu.h"
#include "SearchEngine.h"
using namespace std;

struct Notebook
{
	vector<string> event; //[0] is for title, [1] is for year, [2] is for participants and [3] is for details
	Notebook* next = NULL;
};

Notebook* Head = new Notebook;
int createdBook = true; //checks if already there is any events in Notebook

void searchBoxNotebook(int whichYear) // Inputs data and searches for it in the Notebook file
{
	Notebook* outputHead = Head;
	char key;
	bool isFound = true; //if there is any matching results

	while (outputHead != NULL)
	{
		if (firstConvert(stoi(outputHead->event[1])) == whichYear) 
		{
			cout << " Notebook:	" << outputHead->event[0] << endl;
			isFound = false;
		}
		outputHead = outputHead->next;
	}

	if (isFound) 
	{
		cout << " There is no result in Notebook\n\n";
	}

	//Get back button
	cout << "\n\n" << char(201);
	for (int i = 0; i < 32; i++)
	{
		cout << char(205);
	}
	cout << char(187) << endl;
	cout << char(186) << "      Press Esc to get back     " << char(186) << endl;
	cout << char(200);
	for (int i = 0; i < 32; i++)
	{
		cout << char(205);
	}
	cout << char(188);

	do { 
		key = _getch();
		if (key == char(27)) // Button to get back -> ESC key
		{
			Menu();
		}
	} while (key != char(27));

}

void notebookSection();

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

void textField(int size = 37) // Creates a textfield for input boxes
{
	cout << char(201);
	for (int i = 0; i < size; i++)
	{
		cout << char(205);
	}
}

void newElement(Notebook* Head, vector<string> value) // Adds new element to the linked list
{
	Notebook* newElement = new Notebook;
	newElement->event = value;
	newElement->next = Head->next;
	Head->next = newElement;
}

string extractInfoNotebook(int& i, std::string info, std::string line) // Separates the data from each other
{
	info = "";

	for (; i < line.size(); i++)
	{
		if (line[i] == '^') // Searches the ^ sign which separates the data
		{
			break;
		}
		info += line[i];
	}
	i++;
	return info;
}

void inputFromFileNotebook() // Uploads the input data in eventDataNotebook file
{
	ifstream inputFile;
	inputFile.open("EventDataNotebook.txt", ios::in | ios::app);
	
	vector<string> inputInfo;
	string data, info;
	int i = 0;
	while (getline(inputFile, data))
	{
		inputInfo.push_back(extractInfoNotebook(i, info, data));
		inputInfo.push_back(extractInfoNotebook(i, info, data));
		inputInfo.push_back(extractInfoNotebook(i, info, data));
		inputInfo.push_back(extractInfoNotebook(i, info, data));
		if (createdBook) {
			Head = new Notebook{ inputInfo, NULL };
			createdBook = false;
		}
		else {
			newElement(Head, inputInfo);
		}
		inputInfo.clear();
		i = 0;
	}
	
	inputFile.close();
}

void setDateToFileNotebook(vector<string> temp, bool del = false) // Gets the data from eventDataNotebook file
{
	ofstream outData;
	if (del) 
	{
		outData.open("EventDataNotebook.txt", ios::out | ios::trunc); // Checks if command is delete and clears the file
	}
	else 
	{
		outData.open("EventDataNotebook.txt", ios::out | ios::app);
	}

	outData << temp[0] << "^" << temp[1] << "^" << temp[2]<< "^" << temp[3]<<endl;

	outData.close();
}

void addEventToNotebook();

void deleteElement(Notebook** Head1, int position) // Deletes node
{
	vector<string> deletedList;

	if (*Head1 == NULL) 
	{
		cout << "List is empty";
	}

	else 
	{
		Notebook* current = *Head1;
		Notebook* previous = *Head1;
		if (position == 1) 
		{
			*Head1 = current->next;
			delete current;
			current = NULL;
		}
		else 
		{
			while (position != 1) {
				previous = current;
				current = current->next;
				position--;
			}
			previous->next = current->next;
			delete current;
			current = NULL;
		}
	}

	Notebook* outputHead = Head;
	bool newFile = true;
	while (outputHead != NULL) 
	{
		deletedList.push_back(outputHead->event[0]);
		deletedList.push_back(outputHead->event[1]);
		deletedList.push_back(outputHead->event[2]);
		deletedList.push_back(outputHead->event[3]);
		outputHead = outputHead->next;
		setDateToFileNotebook(deletedList, newFile);
		newFile = false; // removes the chosen node from the .txt file
	}
}

void drawNotebookContent(bool isAdd, bool isDel, bool isOpen = false);

void drawPageContent(int pageNumber) // Outputs details
{
	system("cls");
	Notebook* outputHead = Head;
	int counter = 1;
	char key;
	while (outputHead != NULL)
	{
		if (counter == pageNumber) {
			break;
		}
		outputHead = outputHead->next;
		counter++;
	}

	if (outputHead != NULL) 
	{
		color(7);  cout << "\n " << char(179); color(11); cout << " THE EVENT:\n" << " ";
		color(7); cout << char(179) << " "; color(14); cout << outputHead->event[0] << "\n\n";
		color(7); cout << " " << char(179); color(11); cout << " YEAR/DATE:\n" << " ";
		color(7); cout << char(179) << " "; color(14); cout << outputHead->event[1] << "\n\n";
		color(7); cout << " " << char(179); color(11); cout << " PARTICIPANTS:\n" << " ";
		color(7); cout << char(179) << " "; color(14); cout << outputHead->event[2] << "\n\n";
		color(7); cout << " " << char(179); color(11); cout << " DETAILS:\n" << " ";
		color(7); cout << char(179) << " "; color(14); cout << outputHead->event[3]; color(7);
	}

	gotoxy(65, 1); cout << char(201); 
	for (int i = 0; i < 32; i++)
	{
		cout << char(205);
	}

	cout << char(187);
	gotoxy(65, 2); cout << char(186) << "      Press Esc to get back     " << char(186) << endl;
	gotoxy(65, 3); cout << char(200);
	for (int i = 0; i < 32; i++)
	{
		cout << char(205);
	}
	cout << char(188);

	key = _getch();

	if (key == char(27))
	{
		drawNotebookContent(false,false,true);
	}
}

void drawNotebookContent(bool isAdd, bool isDel, bool isOpen) //Outputs the content in notebook and checks is it from Add, Delete or Open section
{
	system("cls");
	Notebook* outputHead = Head;
	char key, notebookSize;
	int pageNumber = 1, delNum = 0, openNum = 0;  //Number of each event and variables for deleting or opening an event
	string noteTitle;

	cout << endl;
	if (isDel) 
	{
		for (;;)
		{
			system("cls");
			outputHead = Head;
			cout << endl;
			pageNumber = 1;
			while (outputHead != NULL)
			{
				if (pageNumber == delNum) 
				{
					if (delNum == notebookSize) 
					{
						Head = NULL;
					}
					else {
						outputHead = outputHead->next;
						deleteElement(&Head, delNum);
					}
				}
				if (outputHead == NULL) 
				{
					break;
				}

				if (outputHead->event[0].size() > 40) //checks if the event's title is bigger than content page size
				{
					noteTitle = outputHead->event[0].substr(0, 40); //substracts it to 40 characters
				}

				else 
				{
					noteTitle = outputHead->event[0];
				}

				color(14); cout << "  " << noteTitle; color(7);

				for (size_t i = 0; i <= (50 - noteTitle.size()); i++)
				{
					cout << ".";
				}

				cout << pageNumber << endl;
				pageNumber++;
				outputHead = outputHead->next;
			}
			notebookSize = pageNumber;
			gotoxy(65, 1); cout << char(201); // Button for going back
			for (int i = 0; i < 32; i++)
			{
				cout << char(205);
			}
			cout << char(187);
			gotoxy(65, 2); cout << char(186) << "      Press Esc to get back     " << char(186) << endl;
			gotoxy(65, 3); cout << char(200);
			for (int i = 0; i < 32; i++)
			{
				cout << char(205);
			}
			cout << char(188);

			gotoxy(65, 4); cout << char(201); //Button for deleting an event
			for (int i = 0; i < 32; i++)
			{
				cout << char(205);
			}
			cout << char(187);
			gotoxy(65, 5); cout << char(186) << " Press Enter to delete an event " << char(186) << endl;
			gotoxy(65, 6); cout << char(200);
			for (int i = 0; i < 32; i++)
			{
				cout << char(205);
			}
			cout << char(188);

			key = _getch();
			int pos = 8;
			string inputMessage = " Enter event's number: ";
			if (key == '\r') 
			{
				do {
					gotoxy(65, pos); cout << inputMessage << endl;
					if (pos != 8) 
					{
						color(12);
					}
					gotoxy(64, pos + 1); cout << " "; textField(32); cout << endl;
					gotoxy(65, pos + 2); cout << char(186) << " "; color(7); cin >> delNum;
					pos += 4;
					inputMessage = " Please enter valid number ";
				} while (delNum <= 0 || delNum >= notebookSize);
			}

			if (key == char(27)) 
			{
				notebookSection();
				break;
			}
		}

	}

	else 
	{
		while (outputHead != NULL) // Prints content in Content page
		{
			if (outputHead->event[0].size() > 40) //checks if the event's title is bigger than content page size
			{
				noteTitle = outputHead->event[0].substr(0, 40); //substracts it to 40 characters
			}
			else {
				noteTitle = outputHead->event[0];
			}

			color(14); cout << "  " << noteTitle; color(7);
			for (size_t i = 0; i <= (50 - noteTitle.size()); i++)
			{
				cout << ".";
			}
			cout << pageNumber << endl;
			pageNumber++;
			outputHead = outputHead->next;
		}
		notebookSize = pageNumber;
	}

	gotoxy(65, 1); cout << char(201);
	for (int i = 0; i < 32; i++)
	{
		cout << char(205);
	}
	cout << char(187);
	gotoxy(65, 2); cout << char(186) << "      Press Esc to get back     " << char(186) << endl;
	gotoxy(65, 3); cout << char(200);
	for (int i = 0; i < 32; i++)
	{
		cout << char(205);
	}
	cout << char(188);

	cout << endl;

	if(isOpen) // Add section
	{
		gotoxy(65, 4); cout << char(201);
		for (int i = 0; i < 32; i++)
		{
			cout << char(205);
		}
		cout << char(187);
		gotoxy(65, 5); cout << char(186) << "  Press Enter to open an event  " << char(186) << endl;
		gotoxy(65, 6); cout << char(200);
		for (int i = 0; i < 32; i++)
		{
			cout << char(205);
		}
		cout << char(188);

		key = _getch();
		int pos = 8;
		string inputMessage = " Enter event's number: ";
		if (key == '\r') {
			do {
				gotoxy(66, pos); cout << inputMessage << endl;
				if (pos != 8)
				{
					color(12);
				}
				gotoxy(64, pos + 1); cout << " "; textField(32);  cout << endl;
				gotoxy(65, pos + 2); cout << char(186) << " "; color(7);
				cin >> openNum;
				pos += 4;
				inputMessage = " Please enter valid number ";
			} while (openNum <= 0 || openNum >= notebookSize);
			drawPageContent(openNum);
		}

		if (key == char(27)) 
		{
			notebookSection();
		}
	}

	if (isAdd) 
	{
		//Enter to add new event button
		gotoxy(65, 4); cout << char(201);
		for (int i = 0; i < 32; i++)
		{
			cout << char(205);
		}
		cout << char(187);
		gotoxy(65, 5); cout << char(186) << "  Press Enter to add new event  " << char(186) << endl;
		gotoxy(65, 6); cout << char(200);
		for (int i = 0; i < 32; i++)
		{
			cout << char(205);
		}
		cout << char(188);

		key = _getch();
		if (key == '\r')
		{
			addEventToNotebook();
		}
		if (key == char(27))
		{
			createdBook = false;
			notebookSection();
		}
	}
	else {
		key = _getch();
		if (key == char(27))
		{
			createdBook = false;
			notebookSection();
		}
	}
	
	cout << endl;
}

void addEventToNotebook() // Text field to input information
{
	string eventInformation, outputInfo[4] = { "Enter Event's name: ", "Enter Event's year: ",
	"Enter Event's participants: ", "Enter Event Details: " };
	vector <string> event;
	int position = 9;
	for (int i = 0; i < 4; i++)
	{
		do {
			gotoxy(65, position); cout << outputInfo[i];
			cout << endl;
			gotoxy(65, position + 1); textField(33);
			cout << endl;
			gotoxy(65, position + 2); cout << char(186) << " ";
			getline(cin, eventInformation);
		} while (eventInformation.size() < 1 || eventInformation == " "); //If the user presses only enter or inputs only 1 character
		
		event.push_back(eventInformation);
		cout << endl;
		position += 4;
	}

	setDateToFileNotebook(event);
	newElement(Head, event);
	drawNotebookContent(true, false);
}

void startNewNotebook() 
{
	system("CLS");
	string eventInformation, outputInfo[4] = { " Enter Event's name: ", " Enter Event's year: ",
	" Enter Event's participants: ", "Enter Event Details: " };
	vector <string> event;

	gotoxy(1, 1); cout << char(201); //Fill message start
	for (int i = 0; i < 36; i++)
	{
		cout << char(205);
	}
	cout << char(187);
	gotoxy(1, 2); cout << char(186) << "  Adding new event. Fill all gaps!  " << char(186) << endl;
	gotoxy(1, 3); cout << char(200);
	for (int i = 0; i < 36; i++)
	{
		cout << char(205);
	}
	cout << char(188); //Fill message end
	cout << endl << endl;

	for (int i = 0; i < 4; i++)
	{
		cout << " " << outputInfo[i];
		cout << endl;
		cout << " "; textField();
		cout << endl;
		cout << " " << char(186) << " "; getline(cin, eventInformation);
		event.push_back(eventInformation);
		cout << endl;
	}

	Head = new Notebook{ event, NULL };
	setDateToFileNotebook(event);
	drawNotebookContent(true, false);
}



void notebookCover() // ASCII art in notebook page
{
	gotoxy(63, 2); cout << char(186);
	gotoxy(63, 3); cout << char(186);
	gotoxy(63, 4); cout << char(186);

	for (int i = 17; i <= 28; i++) 
	{
		gotoxy(63, i); cout << char(186);
	}
	gotoxy(63, 28); cout << char(188);
	gotoxy(2, 2); cout << char(186);
	gotoxy(2, 3); cout << char(186);
	gotoxy(2, 4); cout << char(186);

	for (int i = 17; i < 28; i++)
	{
		gotoxy(2, i); cout << char(186);
	}
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

int bookMenu() // Menu in notebook section
{
	int counter = 1;
	char key;
	int SetColor[3] = { 14, 7, 7 };

	SetColor[0] = 14;
	SetColor[1] = 7;
	SetColor[2] = 7;

	while (true)
	{	
		// Open button
		gotoxy(70, 8); color(SetColor[0]); cout << char(201);
		for (int i = 0; i < 20; i++)
		{
			cout << char(205);
		}
		cout << char(187);
		gotoxy(70, 9); cout << char(186) << "        Open        " << char(186) << endl;
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
		// Add button
		gotoxy(70, 12); cout << char(186) << "    Add an event    " << char(186);
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
		// Delete button
		gotoxy(70, 15); cout << char(186) << "       Delete       " << char(186) << endl; color(SetColor[2]);
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
				drawNotebookContent(false, false, true);
				system("CLS");
				//Open option
				break;
			}
			if (counter == 2)
			{
				if (createdBook)
				{
					system("CLS");
					startNewNotebook();
				}
				else
				{
					system("CLS");
					drawNotebookContent(true, false);
				}
				break;
			}
			if (counter == 3 && createdBook == false)
			{
				color(7);
				drawNotebookContent(false, true);
				system("CLS");
				//Open option
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

	return 0;
}

void notebookSection()
{
	system("cls");
	art();
	notebookCover();
	bookMenu();
}

