#ifndef MENU_COKOLWIEK
#define MENU_COKOLWIEK
#include <iostream>
#include "repository.h"
class menu
{
public:
	menu();
	void ChangeRepoLocation(repository inputRepo);
	void IsRepositorySet(repository inputRepo);
	void GenerateMainOptions();
	void OpenMain(repository inputRepo);
	void SyncLocation(repository inputRepo);
	void FindISOFiles(repository inputRepo);
	void ThroughSystemName(repository inputRepo);
	void ThroughFilename(repository inputRepo);
	void ThroughDescription(repository inputRepo);
	void AddISOFiles(repository inputRepo);
	void SaveChanges(repository inputRepo);
	void Help(repository inputRepo);
	void About(repository inputRepo);
	virtual ~menu();
};
#endif