#include <iostream>
#include "ISOfile.h"
#include "ISOmanager.h"
#include "repository.h"
#include "md5.h"
#include "menu.h"
#include <Windows.h>
#include <fstream>
#include <io.h>
#include <fcntl.h>
#include <string>
#include <filesystem>

int main()
{
	SetConsoleTitle(TEXT("ISOfinder"));
	_setmode(_fileno(stdout), _O_U16TEXT);
	repository repo;
	repo.firstRun();
	menu NewMenu(repo);
	NewMenu.OpenMain();
	return 0;
}