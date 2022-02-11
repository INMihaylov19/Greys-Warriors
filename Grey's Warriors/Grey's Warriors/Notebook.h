#pragma once
#include <iostream>
#include <windows.h>
#include <conio.h>
#include <string>
#include <vector>
#include <fstream>
using namespace std;

void mainGrid();

void art();

void textField(int size = 37);

struct Title
{

	vector<string> event;
	Title* next = NULL;
};

void newElement(Title* Head, vector<string> value);

string extractInfoNotebook(int& i, std::string info, std::string line);

void inputFromFileNotebook();

void setDateToFileNotebook(vector<string> temp, bool del = false);


void addEventToNotebook();

void searchBoxNotebook(int whichYear);

void del_pos(struct Title** Head1, int position);

void drawPageContent(int pageNumber);

void drawNotebookContent(bool isAdd, bool isDel, bool isOpen = false);

void addEventToNotebook();

void startNewNotebook();



void notebookCover();

int bookMenu();

void mainGrid();