#include "repomanager.h"



RepoManager::RepoManager()
{
}


RepoManager::~RepoManager()
{
	repoList.clear();
}

void RepoManager::AddToRepo(RepoFile& inputRepoFile)
{
	repoList.push_back(inputRepoFile);
}

void RepoManager::DeleteFromRepo(RepoFile& inputRepoFile)
{
}

void RepoManager::ShowAllFiles()
{
	for (auto x : repoList)
	{
		std::wcout << "File name: " << x.GetISOname() << std::endl;
		std::wcout << "File description: " << x.GetISOdesc() << std::endl;
		std::wcout << "Full filename: " << x.GetISOfilename() << std::endl;
		std::wcout << "File location: " << x.GetISOlocation() << std::endl << std::endl;
	}
}

void RepoManager::FindInRepoByName(std::wstring inputName)
{
	RepoFile findExample;
	findExample.SetISOname(inputName);
	//std::list<RepoFile>::iterator findIter = std::find(repoList.begin(), repoList.end(), findExample);
	//std::wcout << "File name: " << findIter->GetISOname() << std::endl;
	//std::wcout << "File description: " << findIter->GetISOdesc() << std::endl;
	//std::wcout << "Full filename: " << findIter->GetISOfilename() << std::endl;
	//std::wcout << "File location: " << findIter->GetISOlocation() << std::endl << std::endl;
}

void RepoManager::FindInRepoByDesc(std::wstring inputDesc)
{
}

void RepoManager::FindInRepoByFileName(std::wstring inputFileName)
{
}

void RepoManager::RepoLoadFromFile()
{
}

void RepoManager::RepoSaveToFile()
{
}
