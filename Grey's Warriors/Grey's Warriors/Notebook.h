#pragma once
#include <iostream>
#include <windows.h>
#include <conio.h>
#include <string>
#include <vector>
#include <fstream>

void art();

void textField(int size = 37);

struct Notebook
{
	std::vector<std::string> event;
	Notebook* next = NULL;
};

void newElement(Notebook* Head, std::vector<std::string> value);

std::string extractInfoNotebook(int& i, std::string info, std::string line);

void inputFromFileNotebook();

void setDateToFileNotebook(std::vector<std::string> temp, bool del = false);

void addEventToNotebook();

void searchBoxNotebook(int whichYear);

void deleteElement(Notebook** Head1, int position);

void drawPageContent(int pageNumber);

void drawNotebookContent(bool isAdd, bool isDel, bool isOpen = false);

void addEventToNotebook();

void startNewNotebook();

void notebookCover();

int bookMenu();

void notebookSection();