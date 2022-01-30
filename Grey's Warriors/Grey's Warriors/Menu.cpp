#include <iostream>
#include <conio.h>
#include <windows.h>

using namespace std;

int SetColor[3] = { 8, 7, 7 };

void color(int color)
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

void gotoxy(int x, int y)
{ //get the coordinates inside the console
    COORD coord;
    coord.X = x; //character's X cordinates
    coord.Y = y; //character's Y cordinates
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void menuArt()
{
    gotoxy(4, 3); color(SetColor[0]); cout << " ==============================================================================================================";
    gotoxy(4, 4); color(SetColor[0]); cout << "  _____   _____   _____  __   __  _   _____     _    _    ___    _____   _____   _____   _____   _____   _____ " << endl;
    gotoxy(4, 5); color(SetColor[0]); cout << " |  __ \\ | ___ \\ |  ___| \\ \\ / / ( ) /  ___|   | |  | |  / _ \\  | ___ \\ | ___ \\ |_   _| |  _  | | ___ \\ /  ___| " << endl;
    gotoxy(4, 6); color(SetColor[0]); cout << " | |  \\/ | |_/ / | |__    \\ V /  |/  \\ `--.    | |  | | / /_\\ \\ | |_/ / | |_/ /   | |   | | | | | |_/ / \\ `--. " << endl;
    gotoxy(4, 7); color(SetColor[0]); cout << " | | __  |    /  |  __|    \\ /        `--. \\   | |/\\| | |  _  | |    /  |    /    | |   | | | | |    /   `--. \\ " << endl;
    gotoxy(4, 8); color(SetColor[0]); cout << " | |_\\ \\ | |\\ \\  | |___    | |       /\\__/ /   \\  /\\  / | | | | | |\\ \\  | |\\ \\   _| |_  \\ \\_/ / | |\\ \\  /\\__/ / " << endl;
    gotoxy(4, 9); color(SetColor[0]); cout << "  \\____/ \\_| \\_| \\____/    \\_/       \\____/     \\/  \\/  \\_| |_/ \\_| \\_| \\_| \\_|  \\___/   \\___/  \\_| \\_| \\____/ " << endl;
    gotoxy(4, 11); color(SetColor[0]); cout << " ==============================================================================================================";
}

int Menu()
{
    int counter = 1;
    char key;

    SetColor[0] = 14;
    SetColor[1] = 7;
    SetColor[2] = 7;

    menuArt();


    while (true)
    {
        gotoxy(46, 13); color(SetColor[0]); cout << "1. Book with dates "; color(SetColor[2]);

        gotoxy(46, 14); color(SetColor[1]); cout << "2. Timeline "; color(SetColor[2]);

        gotoxy(46, 15); color(SetColor[2]); cout << "3. Exit " << endl; color(SetColor[2]);

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
            if (counter == 1)
            {
                system("CLS");
                //The book function will be executed afterwards
                break;
            }
            if (counter == 2)
            {
                system("CLS");
                //The timeline function will be displayed afterwards
                break;
            }
            if (counter == 3)
            {
                return 0;
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