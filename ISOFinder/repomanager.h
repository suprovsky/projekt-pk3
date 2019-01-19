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
	void FindInRepoByName(std::wstring inputName);
	void FindInRepoByDesc(std::wstring inputDesc);
	void FindInRepoByFileName(std::wstring inputFileName);
	void RepoLoadFromFile();
	void RepoSaveToFile();
protected:
	std::list<RepoFile> repoList;
	std::list<RepoFile>::iterator repoIter;
};
#endif
