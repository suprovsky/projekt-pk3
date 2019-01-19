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
	void ChangeRepoLocation();
	void IsRepositorySet();
	void IsChangesUnsaved();
	void GenerateMainOptions();
	void GenerateSearchOptions();
	void GenerateDeleteOptions();
	void OpenMain();
	void ShowAllFiles();
	void FindRepoFiles();
	void FindThroughSystemName();
	void FindThroughUserDefinedName();
	void FindThroughDescription();
	void FindThroughLocation();
	void AddRepoFile();
	void DeleteRepoFile();
	void SaveChanges();
	void Help();
	void About();
	void DeleteThroughSystemName();
	void DeleteThroughDescription();
	void DeleteThroughUserDefinedName();
	void DeleteThroughLocation();
	void ShowAllFilesToDelete();
	virtual ~Menu();
private:
	Repository& actualRepo;
	RepoManager& actualManager;

};
#endif