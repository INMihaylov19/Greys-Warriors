#include <iostream>
#include <conio.h>
#include <windows.h>
#include "Menu.h"
#include "Timeline.h"
#include "Notebook.h"
using namespace std;

int poww(int x, int y)
{
	if (y == 0)
	{
		return 1;
	}

	return x * poww(x, y - 1);
}

int convertThird(long long int n) 
{
	int dec = 0, i = 0, rem;

	while (n != 0) 
	{
		rem = n % 10;
		n /= 10;
		dec += rem * poww(2, i);
		++i;
	}
	return dec;
}

int convertSecond(long long int binary)
{
	int a, b, i = 0;
	long long int gray = 0;
	while (binary != 0)
	{
		a = binary % 10;
		binary = binary / 10;
		b = binary % 10;

		if ((a && !b) || (!a && b)) 
		{
			gray = gray + poww(10, i);
		}

		i++;
	}
	return convertThird(gray);
}

int firstConvert(int n)
{
	long long int bin = 0;
	long long int rem, i = 1;

	while (n != 0) 
	{
		rem = n % 2;
		n /= 2;
		bin += rem * i;
		i *= 10;
	}

	return convertSecond(bin);
}

void searchEngine() // Inputs a year and searches it in the timeline and the notebook sections
{
	system("cls");
	color(7);
	int whichYear;
	cout << "\nEnter a year   ";
	cin >> whichYear;

	system("cls");
	cout << char(218);
	for (int i = 0; i < 12; i++) 
	{
		cout << char(196);
	}

	cout << char(210);
	for (int i = 0; i < 51; i++) 
	{
		cout << char(196);
	}

	cout << char(191) << endl;
	cout << char(179) << "   SEARCH   " << char(186) << " " << whichYear << " -> Gray(" << firstConvert(whichYear) << ")";
	gotoxy(65, 1);  cout << char(179);
	cout << endl;
	whichYear = firstConvert(whichYear);

	cout << char(192);
	for (int i = 0; i < 12; i++) 
	{
		cout << char(196);
	}

	cout << char(208);
	for (int i = 0; i < 51; i++) 
	{
		cout << char(196);
	}

	cout << char(217) << endl;
	color(14); cout << char(218);
	for (int i = 0; i < 12; i++) 
	{
		cout << char(196);
	}

	cout << char(194);
	color(7);
	for (int i = 0; i < 12; i++) 
	{
		cout << char(196);
	}
	cout << char(194);

	for (int i = 0; i < 12; i++) 
	{
		cout << char(196);
	}
	cout << char(194);

	for (int i = 0; i < 12; i++) 
	{
		cout << char(196);
	}
	cout << char(194);

	for (int i = 0; i < 12; i++) 
	{
		cout << char(196);
	}

	color(14); cout << char(191) << endl;
	cout << char(179) << "     ALL    "; color(7);
	cout << char(179) << "    NEWS    ";
	cout << char(179) << "   IMAGES   ";
	cout << char(179) << "   VIDEOS   ";
	cout << char(179) << "    MAPS    ";
	cout << char(179); color(14); cout << endl << char(192);

	for (int k = 0; k < 4; k++) 
	{
		for (int i = 0; i < 12; i++) 
		{
			cout << char(196);
		}

		cout << char(193); color(7);
	}

	for (int i = 0; i < 12; i++) 
	{
		cout << char(196);
	}

	cout << char(217) << endl;

	searchBoxTimeline(whichYear);

	searchBoxNotebook(whichYear);
}