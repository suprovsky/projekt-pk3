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
	_setmode(_fileno(stdout), _O_U16TEXT);
	Repository repo;
	RepoManager firstInstance;
	repo.RepoStartup();
	Menu NewMenu(repo, firstInstance);
	NewMenu.OpenMain();

	return 0;
}