#include <iostream>
#include <windows.h>
#include <conio.h>
#include <string>
#include <vector>
#include "Menu.h"
using namespace std;

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

void searchBoxTimeline(int whichYear);

void Field(int size);

void drawTimelines();

void newElementName(EventName* Head, string value);

void newElementYear(EventYear* Head, int value);

std::string extractInfo(int& i, std::string info, std::string line);

void inputFromFile();

void addEventToNote(int repeatment, EventName* usedN, EventYear* usedY);

void numberOfEvents();

void startNewNote(int repeat);

void timelineSection();