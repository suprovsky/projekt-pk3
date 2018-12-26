#ifndef MENU_COKOLWIEK
#define MENU_COKOLWIEK
#include <iostream>
#include "repository.h"
void clearConsole();
class menu
{
public:
	menu(repository& startRepo);
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