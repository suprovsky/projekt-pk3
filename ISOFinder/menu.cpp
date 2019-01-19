#include "menu.h"
#include "repository.h"
#include <iostream>
#include <Windows.h>
#include "repomanager.h"
#include <io.h>
#include <fcntl.h>
#include <conio.h>
#include "repofile.h"

Menu::Menu(Repository& startRepo, RepoManager& startManager) : actualRepo(startRepo), actualManager(startManager)
{
}

void Menu::clearConsole() {
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

void Menu::ChangeRepoLocation(Repository& inputRepo)
{
	clearConsole();
	SetConsoleTitle(TEXT("RepoFinder - set new repository location"));
	std::wstring NewLocation = L"-";
	std::wcout << L"The current repository location is: " << inputRepo.GetRepoLocation() << std::endl;
	std::wcout << L"Please enter new repository location and press ENTER." << std::endl;
	std::wcout << L"If you want to cancel repository change, please type \"cancel\" as a value and press ENTER." << std::endl;
	std::wcin >> NewLocation;
	if (!(NewLocation == L"cancel"))
	{
		inputRepo.SetRepoLocation(NewLocation);
		std::wstring path;
		std::wofstream file;
		path = _wgetenv(L"appdata");
		path += L"\\ISOfinder.cfg";
		file.open(path.c_str(), std::ios::out | std::ios::trunc);
		if (file.is_open())
		{
			file << inputRepo.GetRepoLocation();
			file.close();
		}
	}
}

void Menu::IsRepositorySet(Repository& inputRepo)
{
	std::wstring defaultRepoLocation = L"-";
	if (inputRepo.GetRepoLocation() == defaultRepoLocation) {
		std::wcout << L"WARNING: repository location is not set" << std::endl << std::endl;
	}
}


void Menu::GenerateMainOptions()
{
	SetConsoleTitle(TEXT("RepoFinder - main menu"));
	std::wcout << L"Welcome in Repofinder! Choose desired operation by typing a number:" << std::endl;
	std::wcout << L"|" << std::endl;
	std::wcout << L"├───" << L"(1) Set new repository location" << std::endl;
	std::wcout << L"├───" << L"(2) Show all files in repository" << std::endl;
	std::wcout << L"├───" << L"(3) Find specified Repo file" << std::endl;
	std::wcout << L"├───" << L"(4) Add Repo files manually" << std::endl;
	std::wcout << L"├───" << L"(5) Save changes into repository" << std::endl;
	std::wcout << L"├───" << L"(6) Help" << std::endl;
	std::wcout << L"├───" << L"(7) About the project" << std::endl;
	std::wcout << L"└───" << L"(8) Exit" << std::endl;
}

void Menu::OpenMain()
{
	wchar_t selectedOption = '0';
	do 
	{
		clearConsole();
		IsRepositorySet(actualRepo);
		GenerateMainOptions();
		selectedOption = getch();
		switch (selectedOption)
		{
		case '1':
			ChangeRepoLocation(actualRepo);
			break;
		case '2':
			ShowAllFiles();
			break;
		case '3':
			FindISOFiles();
			break;
		case '4':
			AddRepoFiles();
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

void Menu::ShowAllFiles()
{
	SetConsoleTitle(TEXT("RepoFinder"));
	clearConsole();
	std::wcout << "This is an actual list of files in the repository:" << std::endl;
	actualManager.ShowAllFiles();
	std::wcout << "Press any key to back to main menu.";
	getch();
}

void Menu::FindISOFiles()
{
	SetConsoleTitle(TEXT("RepoFinder"));
	clearConsole();
}

void Menu::ThroughSystemName()
{
	SetConsoleTitle(TEXT("RepoFinder"));
	clearConsole();
}

void Menu::ThroughFilename()
{
	SetConsoleTitle(TEXT("RepoFinder"));
	clearConsole();
}

void Menu::ThroughDescription()
{
	SetConsoleTitle(TEXT("RepoFinder"));
	clearConsole();
}

void Menu::AddRepoFiles()
{
	SetConsoleTitle(TEXT("RepoFinder - add a new repository file"));
	clearConsole();
	std::wstring fName, fDesc, fFilename, fLocation;
	std::wcout << L"Insert filename: ";
	std::wcin >> fFilename;
	std::wcout << L"Insert file description: ";
	std::wcin >> fDesc;
	std::wcout << L"Insert your filename (can contain spaces): ";
	std::wcin >> fName;
	std::wcout << L"Insert file location: ";
	std::wcin >> fLocation;
	RepoFile newPosition(fName, fDesc, fFilename, fLocation);
	actualManager.AddToRepo(newPosition);
	clearConsole();
	std::wcout << L"New file added: " << fFilename << std::endl;
	std::wcout << L"File description: " << fDesc << std::endl;
	std::wcout << L"Full filename: " << fName << std::endl;
	std::wcout << L"File location: " << fLocation << std::endl;
	std::wcout << L"Press anything to continue.";
	getch();
}

void Menu::SaveChanges()
{
	SetConsoleTitle(TEXT("RepoFinder"));
	clearConsole();
}

void Menu::Help()
{
	SetConsoleTitle(TEXT("RepoFinder = help"));
	clearConsole();
	std::wcout << L"TO DO!" << std::endl << std::endl;
	std::wcout << L"Press any key to go back to main menu." << std::endl;
	getch();
}

void Menu::About()
{
	SetConsoleTitle(TEXT("RepoFinder - about the project"));
	clearConsole();
	std::wcout << L"This program was made by Radosław Serba. Generally speaking it is a project for one of my subjects" << std::endl;
	std::wcout << L"called \"computer programming\" on the Silesian University of Technology in Gliwice, Poland." << std::endl << std::endl;
	std::wcout << L"Task description in polish:" << std::endl;
	std::wcout << L"19.  Baza płyt z oprogramowaniem instalacyjnym" << std::endl;
	std::wcout << L"Zadaniem programu jest zarządzanie zbiorem plików z oprogramowaniem instalacyjnym." << std::endl;
	std::wcout << L"Zarządzanie obejmuje : przeszukiwanie zasobów, dodawanie nowych pozycji, modyfikacje" << std::endl;
	std::wcout << L"oraz usuwanie istniejących rekordów." << std::endl << std::endl;
	std::wcout << L"Press any key to go back to main menu." << std::endl;
	getch();
}

Menu::~Menu()
{
}
