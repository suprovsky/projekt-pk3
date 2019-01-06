#ifndef MENU_COKOLWIEK
#define MENU_COKOLWIEK
#include <iostream>
#include "repository.h"
class menu
{
public:
	menu(repository& startRepo);
	static void clearConsole();
	void ChangeRepoLocation(repository& inputRepo);
	void IsRepositorySet(repository& inputRepo);
	void GenerateMainOptions();
	void OpenMain();
	void SyncLocation();
	void FindISOFiles();
	void ThroughSystemName();
	void ThroughFilename();
	void ThroughDescription();
	void AddISOFiles();
	void SaveChanges();
	void Help();
	void About();
	virtual ~menu();
private:
	repository& actualRepo;
};
#endif