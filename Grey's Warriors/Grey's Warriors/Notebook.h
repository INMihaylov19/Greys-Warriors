#pragma once

#include <iostream>  
#include <windows.h>
#include <conio.h>

void art();

void searchBoxNotebook(int whichYear);

std::string extractInfoNotebook(int& i, std::string info, std::string line);

void inputFromFileNotebook();

void notebookCover();

void mainGrid();

int bookMenu();