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

void Menu::ChangeRepoLocation()
{
	clearConsole();
	SetConsoleTitle(TEXT("RepoFinder - set new repository location"));
	std::wstring NewLocation = L"-";
	std::wcout << L"The current repository location is: " << actualRepo.GetRepoLocation() << std::endl;
	std::wcout << L"Please enter new repository location and press ENTER." << std::endl;
	std::wcout << L"If you want to cancel repository change, please type \"cancel\" as a value and press ENTER." << std::endl;
	std::getline(std::wcin, NewLocation);
	if (!(NewLocation == L"cancel"))
	{
		actualRepo.SetRepoLocation(NewLocation);
		std::wstring path;
		std::wofstream file;
		path = _wgetenv(L"appdata");
		path += L"\\FileFinder.cfg";
		file.open(path.c_str(), std::ios::out | std::ios::trunc);
		if (file.is_open())
		{
			file << actualRepo.GetRepoLocation();
			file.close();
		}
	}
}

void Menu::IsRepositorySet()
{
	std::wstring defaultRepoLocation = L"-";
	if (actualRepo.GetRepoLocation() == defaultRepoLocation) {
		std::wcout << L"WARNING: repository location is not set" << std::endl << std::endl;
	}
}

void Menu::IsChangesUnsaved()
{
	if (actualManager.changesNotSaved) {
		std::wcout << L"WARNING: there are unsaved changes in the repository" << std::endl << std::endl;
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
	std::wcout << L"├───" << L"(4) Add Repo file" << std::endl;
	std::wcout << L"├───" << L"(5) Delete Repo file" << std::endl;
	std::wcout << L"├───" << L"(6) Edit Repo file" << std::endl;
	std::wcout << L"├───" << L"(7) Save changes into repository" << std::endl;
	std::wcout << L"├───" << L"(8) Help" << std::endl;
	std::wcout << L"├───" << L"(9) About the project" << std::endl;
	std::wcout << L"└───" << L"(0) Exit" << std::endl;
}

void Menu::GenerateSearchOptions()
{
	SetConsoleTitle(TEXT("RepoFinder - how do you want to find files?"));
	std::wcout << L"How do you want to find files?" << std::endl;
	std::wcout << L"|" << std::endl;
	std::wcout << L"├───" << L"(1) Through system file name" << std::endl;
	std::wcout << L"├───" << L"(2) Through description" << std::endl;
	std::wcout << L"├───" << L"(3) Through user defined file name" << std::endl;
	std::wcout << L"├───" << L"(4) Through file location" << std::endl;
	std::wcout << L"└───" << L"(5) Go back to the main menu" << std::endl;
}

void Menu::GenerateDeleteOptions()
{
	SetConsoleTitle(TEXT("RepoFinder - select delete criterion"));
	std::wcout << L"How do you want to find files which are going to be delete?" << std::endl;
	std::wcout << L"|" << std::endl;
	std::wcout << L"├───" << L"(1) Through system file name" << std::endl;
	std::wcout << L"├───" << L"(2) Through description" << std::endl;
	std::wcout << L"├───" << L"(3) Through user defined file name" << std::endl;
	std::wcout << L"├───" << L"(4) Through file location" << std::endl;
	std::wcout << L"├───" << L"(5) Forget about searching, just show me all files" << std::endl;
	std::wcout << L"└───" << L"(6) Go back to the main menu" << std::endl;
}

void Menu::OpenMain()
{
	wchar_t selectedOption = '0';
	do 
	{
		clearConsole();
		IsRepositorySet();
		IsChangesUnsaved();
		GenerateMainOptions();
		selectedOption = getch();
		switch (selectedOption)
		{
		case '1':
			ChangeRepoLocation();
			break;
		case '2':
			ShowAllFiles();
			break;
		case '3':
			FindRepoFiles();
			break;
		case '4':
			AddRepoFile();
			break;
		case '5':
			DeleteRepoFile();
			break;
		case '6':
			EditRepoFile();
			break;
		case '7':
			SaveChanges();
			break;
		case '8':
			Help();
			break;
		case '9':
			About();
			break;
		case '0':
			exit(0);
			break;
		default:
			break;
		}
	} while (selectedOption != '0');
}

void Menu::ShowAllFiles()
{
	SetConsoleTitle(TEXT("RepoFinder - show all files in the repository"));
	clearConsole();
	actualManager.ShowAllFiles();
	std::wcout << L"Press any key to back to main menu.";
	getch();
}

void Menu::FindRepoFiles()
{
	if (actualManager.IsRepoEmpty())
	{
		clearConsole();
		std::wcout << L"The actual list is empty. There is nothing to search." << std::endl;
		std::wcout << std::endl << std::endl << "Press any key to continue.";
		getch();
	}
	else
	{
		wchar_t selectedOption = '0';
		do
		{
			clearConsole();
			GenerateSearchOptions();
			selectedOption = getch();
			switch (selectedOption)
			{
			case '1':
				FindThroughSystemName();
				break;
			case '2':
				FindThroughDescription();
				break;
			case '3':
				FindThroughUserDefinedName();
				break;
			case '4':
				FindThroughLocation();
				break;
			case '5':
				OpenMain();
				break;
			default:
				break;
			}
		} while (selectedOption != '0');
	}
}

void Menu::FindThroughSystemName()
{
	SetConsoleTitle(TEXT("RepoFinder - find files through its system name"));
	clearConsole();
	std::wstring searchPhrase;
	std::wcout << L"Please enter specified file system name to search: ";
	std::getline(std::wcin, searchPhrase);
	clearConsole();
	std::wcout << L"The results are: " << std::endl;
	actualManager.FindInRepoBySystemName(searchPhrase);
	std::wcout << std::endl << L"Please enter any key to continue.";
	getch();
}

void Menu::FindThroughUserDefinedName()
{
	SetConsoleTitle(TEXT("RepoFinder - find files through its user defined name"));
	clearConsole();
	std::wstring searchPhrase;
	std::wcout << L"Please enter specified user defined name to search: ";
	std::getline(std::wcin, searchPhrase);
	clearConsole();
	std::wcout << L"The results are: " << std::endl;
	actualManager.FindInRepoByUserDefinedName(searchPhrase);
	std::wcout << std::endl << L"Please enter any key to continue.";
	getch();
}

void Menu::FindThroughDescription()
{
	SetConsoleTitle(TEXT("RepoFinder - find files through its description"));
	clearConsole();
	std::wstring searchPhrase;
	std::wcout << L"Please enter specified file description to search: ";
	std::getline(std::wcin, searchPhrase);
	clearConsole();
	std::wcout << L"The results are: " << std::endl;
	actualManager.FindInRepoByDesc(searchPhrase);
	std::wcout << std::endl << L"Please enter any key to continue.";
	getch();
}

void Menu::FindThroughLocation()
{
	SetConsoleTitle(TEXT("RepoFinder - find files through its location"));
	clearConsole();
	std::wstring searchPhrase;
	std::wcout << L"Please enter specified file location to search: ";
	std::getline(std::wcin, searchPhrase);
	clearConsole();
	std::wcout << L"The results are: " << std::endl;
	actualManager.FindInRepoByLocation(searchPhrase);
	std::wcout << std::endl << L"Please enter any key to continue.";
	getch();
}

void Menu::AddRepoFile()
{
	SetConsoleTitle(TEXT("RepoFinder - add a new repository file"));
	clearConsole();
	std::wstring fSystemName, fDesc, fUserDefinedName, fLocation;
	std::wcout << L"Insert system file name: ";
	std::getline(std::wcin, fSystemName);
	std::wcout << L"Insert file description: ";
	std::getline(std::wcin, fDesc);
	std::wcout << L"Insert user defined name: ";
	std::getline(std::wcin, fUserDefinedName);
	std::wcout << L"Insert file location: ";
	std::getline(std::wcin, fLocation);
	RepoFile newPosition(fSystemName, fUserDefinedName, fLocation, fDesc);
	actualManager.AddToRepo(newPosition);
	clearConsole();
	std::wcout << L"You have added a new file with following data: " << std::endl;
	std::wcout << newPosition << std::endl;
	std::wcout << L"Press anything to continue.";
	getch();
}

void Menu::DeleteRepoFile()
{
	if (actualManager.IsRepoEmpty())
	{
		clearConsole();
		std::wcout << L"The actual list is empty. There is nothing to delete." << std::endl;
		std::wcout << std::endl << std::endl << "Press any key to continue.";
		getch();
	}
	else
	{
		wchar_t selectedOption = '0';
		do
		{
			clearConsole();
			GenerateDeleteOptions();
			selectedOption = getch();
			switch (selectedOption)
			{
			case '1':
				DeleteThroughSystemName();
				break;
			case '2':
				DeleteThroughDescription();
				break;
			case '3':
				DeleteThroughUserDefinedName();
				break;
			case '4':
				DeleteThroughLocation();
				break;
			case '5':
				ShowAllFilesToDelete();
				break;
			case '6':
				OpenMain();
				break;
			default:
				break;
			}
		} while (selectedOption != '0');
	}

}

void Menu::SaveChanges()
{
	SetConsoleTitle(TEXT("RepoFinder"));
	clearConsole();
	bool saveResult = actualManager.RepoSaveToFile();
	if (saveResult)
	{
		std::wcout << L"Saved successfully!" << std::endl << L"Press any key to go back to the main menu.";
	}
	else
	{
		std::wcout << L"Something went wrong, save unsuccessful." << std::endl << L"Press any key to go back to the main menu.";
	}
	getch();
}

void Menu::Help()
{
	SetConsoleTitle(TEXT("RepoFinder = help"));
	clearConsole();
	std::wcout << L"Head over to the program documentation (SPRAWOZDANIE) to find out how all method used in the program" << std::endl;
	std::wcout << L" works." << std::endl << std::endl;
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

void Menu::DeleteThroughSystemName()
{
	SetConsoleTitle(TEXT("RepoFinder - delete a file through its system name"));
	clearConsole();
	std::wstring searchPhrase;
	std::wcout << L"Please enter specified file system name to delete: ";
	std::getline(std::wcin, searchPhrase);
	clearConsole();
	std::wcout << L"The results are: " << std::endl;
	actualManager.DeleteFromRepoBySystemName(searchPhrase);
	std::wcout << std::endl << L"Please enter any key to continue.";
	getch();
}

void Menu::DeleteThroughDescription()
{
	SetConsoleTitle(TEXT("RepoFinder - delete a file through its description"));
	clearConsole();
	std::wstring searchPhrase;
	std::wcout << L"Please enter specified file description to delete: ";
	std::getline(std::wcin, searchPhrase);
	clearConsole();
	std::wcout << L"The results are: " << std::endl;
	actualManager.DeleteFromRepoByDesc(searchPhrase);
	std::wcout << std::endl << L"Please enter any key to continue.";
	getch();
}

void Menu::DeleteThroughUserDefinedName()
{
	SetConsoleTitle(TEXT("RepoFinder - delete a file through its used defined name"));
	clearConsole();
	std::wstring searchPhrase;
	std::wcout << L"Please enter specified file user defined name to delete: ";
	std::getline(std::wcin, searchPhrase);
	clearConsole();
	std::wcout << L"The results are: " << std::endl;
	actualManager.DeleteFromRepoByUserDefinedName(searchPhrase);
	std::wcout << std::endl << L"Please enter any key to continue.";
	getch();
}

void Menu::DeleteThroughLocation()
{
	SetConsoleTitle(TEXT("RepoFinder - delete a file through its location"));
	clearConsole();
	std::wstring searchPhrase;
	std::wcout << L"Please enter specified file location to delete: ";
	std::getline(std::wcin, searchPhrase);
	clearConsole();
	std::wcout << L"The results are: " << std::endl;
	actualManager.DeleteFromRepoByLocation(searchPhrase);
	std::wcout << std::endl << L"Please enter any key to continue.";
	getch();
}

void Menu::ShowAllFilesToDelete()
{
	SetConsoleTitle(TEXT("RepoFinder - delete a file from a full file list"));
	clearConsole();
	std::wcout << L"The actual file list is: " << std::endl;
	actualManager.DeleteFromRepoWholeList();
	std::wcout << std::endl << L"Please enter any key to continue.";
	getch();
}

void Menu::EditRepoFile()
{
	SetConsoleTitle(TEXT("RepoFinder - edit a file from a full file list"));
	clearConsole();
	std::wcout << L"The actual file list is: " << std::endl;
	actualManager.EditFileFromWholeList();
	std::wcout << std::endl << L"Please enter any key to continue.";
	getch();
}

Menu::~Menu()
{
}
