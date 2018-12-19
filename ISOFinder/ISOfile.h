#ifndef ISOFILE_COKOLWIEK
#define ISOFILE_COKOLWIEK
#include "repository.h"
#include <filesystem>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <chrono>
class ISOfile :
	public repository
{
public:
	ISOfile();
	ISOfile(std::wstring NewISOlocation);
	ISOfile(std::string SomeISOdata);
	virtual ~ISOfile();
	std::string SetISOname(std::string NewISOname);
	std::string GetISOname();
	std::string SetISOfilename(std::string NewISOfilename);
	std::string GetISOfilename();
	std::string SetISOdesc(std::string NewISOdesc);
	std::string GetISOdesc();
	std::string SetMD5check(std::string NewMD5check);
	std::string GetMD5check();
	std::wstring SetISOlocation(std::wstring NewISOlocation);
	std::wstring GetISOlocation();
private:
	std::string ISOname;
	std::string ISOfilename;
	std::string ISOdescription;
	std::string MD5checksum;
	std::wstring ISOlocation;
	//auto ISOmodificationTime;

};
#endif

