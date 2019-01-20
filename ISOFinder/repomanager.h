#ifndef MANAGER
#define MANAGER
#include "repository.h"
#include "repofile.h"
#include "valuechecker.h"
#include <list>
#include <string>
#include <iterator>
#include <algorithm>
#include <iostream>
#include <conio.h>
class RepoManager : public Repository
{
public:
	RepoManager();
	virtual ~RepoManager();
	void AddToRepo(RepoFile& inputRepoFile);
	void ShowAllFiles();
	bool IsRepoEmpty();
	void FindInRepoBySystemName(std::wstring inputName);
	void FindInRepoByDesc(std::wstring inputDesc);
	void FindInRepoByUserDefinedName(std::wstring inputFileName);
	void FindInRepoByLocation(std::wstring inputLocation);
	void RepoLoadFromFile();
	bool RepoSaveToFile();
	void DeleteFromRepoBySystemName(std::wstring inputName);
	void DeleteFromRepoByDesc(std::wstring inputDesc);
	void DeleteFromRepoByUserDefinedName(std::wstring inputFileName);
	void DeleteFromRepoByLocation(std::wstring inputLocation);
	void DeleteFromRepoWholeList();
	void EditFileFromWholeList();
	bool changesNotSaved;
protected:
	std::list<RepoFile> repoList;
	std::wstring listPath;
	void ChangeSelectedValueInsideList(std::list<RepoFile>::iterator inputIterator);

};
#endif
