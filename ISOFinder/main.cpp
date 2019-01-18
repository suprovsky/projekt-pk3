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
#include <conio.h>

int main()
{
	_setmode(_fileno(stdout), _O_U16TEXT);
	repository repo;
	repo.RepoStartup();
	Menu NewMenu(repo);
	NewMenu.OpenMain();
	return 0;
}