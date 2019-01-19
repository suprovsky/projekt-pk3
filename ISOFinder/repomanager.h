#ifndef MANAGER_COKOLWIEK
#define MANAGER_COKOLWIEK
#include "repository.h"
#include "repofile.h"
#include <list>
#include <string>
#include <iterator>
#include <algorithm>
class RepoManager : public Repository
{
public:
	RepoManager();
	virtual ~RepoManager();
	void AddToRepo(RepoFile& inputRepoFile);
	void DeleteFromRepo(RepoFile& inputRepoFile);
	void ShowAllFiles();
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
protected:
	std::list<RepoFile> repoList;
};
#endif
