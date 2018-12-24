#include "menu.h"
#include "repository.h"
#include <iostream>
#include <Windows.h>
#include <io.h>
#include <fcntl.h>
#include <conio.h>
menu::menu()
{
}

void IsRepositorySet()
{

}


void GenerateMainOptions()
{
	system("cls");
	_setmode(_fileno(stdout), _O_U16TEXT);
	std::wcout << L"Welcome in ISOfinder! Choose desired operation by typing a number:" << std::endl;
	std::wcout << L"|" << std::endl;
	std::wcout << L"├───" << L"(1) Set new repository location" << std::endl;
	std::wcout << L"├───" << L"(2) Sync repository location" << std::endl;
	std::wcout << L"├───" << L"(3) Find specified ISO file" << std::endl;
	std::wcout << L"├───" << L"(4) Add ISO files manually" << std::endl;
	std::wcout << L"├───" << L"(5) Save changes into repository" << std::endl;
	std::wcout << L"├───" << L"(6) Help" << std::endl;
	std::wcout << L"├───" << L"(7) About the project" << std::endl;
	std::wcout << L"└───" << L"(8) Exit" << std::endl;
}

void menu::OpenMain()
{
	GenerateMainOptions();
	wchar_t c = '0';
	int result = 0;
	do {
		c = getch();
	} while ((c != 49 && c != 50 && c != 51 && c != 52 && c != 53 && c != 54 && c != 55 && c != 56));
	result = (int)c - 48;
	if (result == 1) {
		c = 0;
	}
	else if (result == 2) {
		c = 0;
		SyncLocation();
	}
	else if (result == 3) {
		c = 0;
		FindISOFiles();
	}
	else if (result == 4) {
		c = 0;
		AddISOFiles();
	}
	else if (result == 5) {
		c = 0;
		SaveChanges();
	}
	else if (result == 6) {
		c = 0;
		Help();
	}
	else if (result == 7) {
		c = 0;
		About();
	}
	else if (result == 8) {
		c = 0;
		exit(0);
	}
}

void menu::SyncLocation()
{
	system("cls");
}

void menu::FindISOFiles()
{
	system("cls");
}

void menu::ThroughSystemName()
{
	system("cls");
}

void menu::ThroughFilename()
{
	system("cls");
}

void menu::ThroughDescription()
{
	system("cls");
}

void menu::AddISOFiles()
{
	system("cls");
}

void menu::SaveChanges()
{
	system("cls");
}

void menu::Help()
{
	system("cls");
	std::wcout << L"TO DO!" << std::endl << std::endl;
	std::wcout << L"Enter any key to go back to main menu." << std::endl;
	getch();
	OpenMain();
}

void menu::About()
{
	system("cls");
	std::wcout << L"This program was made by Radosław Serba. Generally speaking it is a project for one of my subjects" << std::endl;
	std::wcout << L"called \"computer programming\" on the Silesian University of Technology in Gliwice, Poland." << std::endl << std::endl;
	std::wcout << L"Enter any key to go back to main menu." << std::endl;
	getch();
	OpenMain();
}

menu::~menu()
{
}
