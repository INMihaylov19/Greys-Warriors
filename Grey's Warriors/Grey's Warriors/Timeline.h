#pragma once
#include <iostream>
#include <windows.h>
#include <conio.h>
#include <string>
#include <fstream>
#include <vector>

void timelineSection();

struct Timeline
{
	string title;
	int date;
	Timeline* next = NULL;
};

void newElementName(Timeline* Head, string value1, int value2);

std::string extractInfo(int& i, std::string info, std::string line);

void inputFromFileTimeline();

void searchBoxTimeline(int whichYear);

void Field(int size);

void bubbleSort(int array[], string arrayS[], int size);

void drawTimelineInfo(int numTimel);

void drawTimelines();

void setDateToFileTimeline(Timeline*& tempN, bool newLine, string tTitle = " ", int size = 0);

void addEventToNote(int repeatment, Timeline* usedN);

void startNewNote(int repeat);

void numberOfEvents();

void timelineSection();