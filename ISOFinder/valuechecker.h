#ifndef VALUECHECKER
#define VALUECHECKER
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
class ValueChecker
{
public:
	ValueChecker();
	static void IfInt();
	static void DeleteLastCharacter(std::wstring filePath);
	virtual ~ValueChecker();
};
#endif
