#include "menu.h"
#include "repository.h"
#include <iostream>
#include <Windows.h>
#include <io.h>
#include <fcntl.h>
#include <conio.h>

menu::menu(repository& inputRepo) : actualRepo(inputRepo)
{
}

void clearConsole() {
	COORD topLeft = { 0, 0 };
	HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO screen;
	DWORD written;

	GetConsoleScreenBufferInfo(console, &screen);
	FillConsoleOutputCharacterA(
		console, ' ', screen.dwSize.X * screen.dwSize.Y, topLeft, &written
	);
	FillConsoleOutputAttribute(
		console, FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_BLUE,
		screen.dwSize.X * screen.dwSize.Y, topLeft, &written
	);
	SetConsoleCursorPosition(console, topLeft);
}

void menu::ChangeRepoLocation(repository& inputRepo)
{
	clearConsole();
	std::string NewLocation = "-";
	std::cout << "The current repository location is: " << inputRepo.GetRepoLocation() << std::endl;
	std::cout << "Please enter new repository location and press ENTER." << std::endl;
	std::cout << "If you want to cancel repository change, please type \"cancel\" as a value and press ENTER." << std::endl;
	std::cin >> NewLocation;
	if (!(NewLocation == "cancel"))
	{
		inputRepo.SetRepoLocation(NewLocation);
	}
}

void menu::IsRepositorySet(repository& inputRepo)
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

void menu::OpenMain()
{
	wchar_t selectedOption = '0';
	do 
	{
		IsRepositorySet(actualRepo);
		clearConsole();
		GenerateMainOptions();
		selectedOption = getch();
		switch (selectedOption)
		{
		case '1':
			ChangeRepoLocation(actualRepo);
			break;
		case '2':
			SyncLocation();
			break;
		case '3':
			FindISOFiles();
			break;
		case '4':
			AddISOFiles();
			break;
		case '5':
			SaveChanges();
			break;
		case '6':
			Help();
			break;
		case '7':
			About();
			break;
		case '8':
			exit(0);
			break;
		default:
			break;
		}
	} while (selectedOption != '0');
}

void menu::SyncLocation()
{
	clearConsole();
}

void menu::FindISOFiles()
{
	clearConsole();
}

void menu::ThroughSystemName()
{
	clearConsole();
}

void menu::ThroughFilename()
{
	clearConsole();
}

void menu::ThroughDescription()
{
	clearConsole();
}

void menu::AddISOFiles()
{
	clearConsole();
}

void menu::SaveChanges()
{
	clearConsole();
}

void menu::Help()
{
	clearConsole();
	std::wcout << L"TO DO!" << std::endl << std::endl;
	std::wcout << L"Enter any key to go back to main menu." << std::endl;
	getch();
}

void menu::About()
{
	clearConsole();
	std::wcout << L"This program was made by Radosław Serba. Generally speaking it is a project for one of my subjects" << std::endl;
	std::wcout << L"called \"computer programming\" on the Silesian University of Technology in Gliwice, Poland." << std::endl << std::endl;
	std::wcout << L"Task description in polish:" << std::endl;
	std::wcout << L"19.  Baza płyt z oprogramowaniem instalacyjnym" << std::endl;
	std::wcout << L"Zadaniem programu jest zarządzanie zbiorem plików z oprogramowaniem instalacyjnym." << std::endl;
	std::wcout << L"Zarządzanie obejmuje : przeszukiwanie zasobów, dodawanie nowych pozycji, modyfikacje" << std::endl;
	std::wcout << L"oraz usuwanie istniejących rekordów." << std::endl << std::endl;
	std::wcout << L"Enter any key to go back to main menu." << std::endl;
	getch();
}

menu::~menu()
{
}
