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



ValueChecker::~ValueChecker()
{
}
