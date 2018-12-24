#include <iostream>
#include "ISOfile.h"
#include "ISOmanager.h"
#include "repository.h"
#include "md5.h"
#include "menu.h"
#include <Windows.h>
#include <fstream>
#include <string>
#include <filesystem>
//19.  Baza p³yt z oprogramowaniem instalacyjnym
//Zadaniem programu jest zarz¹dzanie zbiorem plików z oprogramowaniem instalacyjnym.
//Zarz¹dzanie obejmuje : przeszukiwanie zasobów, dodawanie nowych pozycji, modyfikacje 
//oraz usuwanie istniej¹cych rekordów.
void mainmenu() {
	std::cout << "Welcome in ISOFinder. What do you want to do today?";
}

int main()
{
	SetConsoleTitle(TEXT("ISOfinder"));
	repository repo;
	repo.firstRun();
	menu NewMenu;
	NewMenu.OpenMain();
	return 0;
}