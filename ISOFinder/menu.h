#ifndef MENU_COKOLWIEK
#define MENU_COKOLWIEK
#include <iostream>
#include "repository.h"
#include "repomanager.h"
class Menu
{
public:
	Menu(Repository& startRepo, RepoManager& startManager);
	static void clearConsole();
	void ChangeRepoLocation(Repository& inputRepo);
	void IsRepositorySet(Repository& inputRepo);
	void GenerateMainOptions();
	void GenerateSearchOptions();
	void OpenMain();
	void ShowAllFiles();
	void FindRepoFiles();
	void ThroughSystemName();
	void ThroughUserDefinedName();
	void ThroughDescription();
	void ThroughLocation();
	void AddRepoFiles();
	void DeleteRepoFiles();
	void SaveChanges();
	void Help();
	void About();
	virtual ~Menu();
private:
	Repository& actualRepo;
	RepoManager& actualManager;

};
#endif