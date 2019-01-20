#include "valuechecker.h"



ValueChecker::ValueChecker()
{
}

void ValueChecker::IfInt()
{
	if (std::wcin.fail())
	{
		std::wcout << L"ERROR -- You did not enter an integer" << std::endl;
		std::wcin.clear();
		std::wcin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	}
}

void ValueChecker::DeleteLastCharacter(std::wstring filePath)
{
	std::wifstream editedFile(filePath);
	std::wstringstream buffer;
	buffer << editedFile.rdbuf();
	std::wstring contents = buffer.str();
	editedFile.close();
	contents.pop_back();
	std::wofstream fileOut(filePath, std::ios::trunc);
	fileOut << contents;
	fileOut.close();
}



ValueChecker::~ValueChecker()
{
}
