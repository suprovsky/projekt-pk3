#include <iostream>
#include "repofile.h"
#include "repomanager.h"
#include "repository.h"
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
	_setmode(_fileno(stdout), _O_U16TEXT);//turns on UTF-16 support for wide characters in stdout
	_setmode(_fileno(stderr), _O_U16TEXT);//and in stderr as well
	Repository repo;
	RepoManager firstInstance;
	Menu NewMenu(repo, firstInstance);
	NewMenu.OpenMain();
	return 0;
}