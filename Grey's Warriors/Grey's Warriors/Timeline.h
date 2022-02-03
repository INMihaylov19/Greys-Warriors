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

void searchBoxTimeline();

void drawTimelines();

void newElementName(EventName* Head, string value);

void newElementYear(EventYear* Head, int value);

void addEventToNote(int repeatment, EventName* usedN, EventYear* usedY);

void startNewNote(int repeat);

void timelineSection();