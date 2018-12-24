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

void menu::ChangeRepoLocation(repository inputRepo)
{
	system("cls");
	std::string NewLocation = "-";
	std::cout << "The current repository location is: " << inputRepo.GetRepoLocation() << std::endl;
	std::cout << "Please enter new repository location and press ENTER." << std::endl;
	std::cout << "If you want to cancel repository change, please type \"cancel\" as a value and press ENTER." << std::endl;
	std::cin >> NewLocation;
	if (NewLocation == "cancel")
	{
		 OpenMain(inputRepo);
	}
	else
	{
		inputRepo.SetRepoLocation(NewLocation);
		OpenMain(inputRepo);
	}
	
}

void menu::IsRepositorySet(repository inputRepo)
{
	std::string defaultRepoLocation = "-";
	if (inputRepo.GetRepoLocation() == defaultRepoLocation) {
		std::wcout << L"WARNING: repository location is not set" << std::endl << std::endl;
	}
}


void menu::GenerateMainOptions()
{
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

void menu::OpenMain(repository inputRepo)
{
	system("cls");
	IsRepositorySet(inputRepo);
	GenerateMainOptions();
	wchar_t c = '0';
	int result = 0;
	do {
		c = getch();
	} while ((c != 49 && c != 50 && c != 51 && c != 52 && c != 53 && c != 54 && c != 55 && c != 56));
	result = (int)c - 48;
	if (result == 1) {
		c = 0;
		ChangeRepoLocation(inputRepo);
	}
	else if (result == 2) {
		c = 0;
		SyncLocation(inputRepo);
	}
	else if (result == 3) {
		c = 0;
		FindISOFiles(inputRepo);
	}
	else if (result == 4) {
		c = 0;
		AddISOFiles(inputRepo);
	}
	else if (result == 5) {
		c = 0;
		SaveChanges(inputRepo);
	}
	else if (result == 6) {
		c = 0;
		Help(inputRepo);
	}
	else if (result == 7) {
		c = 0;
		About(inputRepo);
	}
	else if (result == 8) {
		c = 0;
		exit(0);
	}
}

void menu::SyncLocation(repository inputRepo)
{
	system("cls");
}

void menu::FindISOFiles(repository inputRepo)
{
	system("cls");
}

void menu::ThroughSystemName(repository inputRepo)
{
	system("cls");
}

void menu::ThroughFilename(repository inputRepo)
{
	system("cls");
}

void menu::ThroughDescription(repository inputRepo)
{
	system("cls");
}

void menu::AddISOFiles(repository inputRepo)
{
	system("cls");
}

void menu::SaveChanges(repository inputRepo)
{
	system("cls");
}

void menu::Help(repository inputRepo)
{
	system("cls");
	std::wcout << L"TO DO!" << std::endl << std::endl;
	std::wcout << L"Enter any key to go back to main menu." << std::endl;
	getch();
	OpenMain(inputRepo);
}

void menu::About(repository inputRepo)
{
	system("cls");
	std::wcout << L"This program was made by Radosław Serba. Generally speaking it is a project for one of my subjects" << std::endl;
	std::wcout << L"called \"computer programming\" on the Silesian University of Technology in Gliwice, Poland." << std::endl << std::endl;
	std::wcout << L"Task description in polish:" << std::endl;
	std::wcout << L"19.  Baza płyt z oprogramowaniem instalacyjnym" << std::endl;
	std::wcout << L"Zadaniem programu jest zarządzanie zbiorem plików z oprogramowaniem instalacyjnym." << std::endl;
	std::wcout << L"Zarządzanie obejmuje : przeszukiwanie zasobów, dodawanie nowych pozycji, modyfikacje" << std::endl;
	std::wcout << L"oraz usuwanie istniejących rekordów." << std::endl << std::endl;
	std::wcout << L"Enter any key to go back to main menu." << std::endl;
	getch();
	OpenMain(inputRepo);
}

menu::~menu()
{
}
