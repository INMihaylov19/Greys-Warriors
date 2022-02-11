#pragma once
#include <iostream>
#include <windows.h>
#include <conio.h>
#include <string>
#include <fstream>
#include <vector>

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

void newElementName(EventName* Head, string value);

void newElementYear(EventYear* Head, int value);

std::string extractInfo(int& i, std::string info, std::string line);

void inputFromFileTimeline();

void searchBoxTimeline(int whichYear);

void Field(int size);

void bubbleSort(int array[], string arrayS[], int size);

void drawTimelineInfo(int numTimel);

void drawTimelines();

void setDateToFileTimeline(EventName*& tempN, EventYear*& tempY, bool newLine, string tTitle = " ", int size = 0);

void addEventToNote(int repeatment, EventName* usedN, EventYear* usedY);

void startNewNote(int repeat);

void numberOfEvents();

void timelineSection();