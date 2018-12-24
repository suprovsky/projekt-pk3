#ifndef MENU_COKOLWIEK
#define MENU_COKOLWIEK
#include <iostream>
#include "repository.h"
class menu
{
public:
	menu();
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
};
#endif