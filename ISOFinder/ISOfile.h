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
	virtual ~ISOfile();
	void SetISOname(std::wstring NewISOname);
	std::wstring GetISOname();
	void SetISOfilename(std::wstring NewISOfilename);
	std::wstring GetISOfilename();
	void SetISOdesc(std::wstring NewISOdesc);
	std::wstring GetISOdesc();
	void SetMD5check(std::wstring NewMD5check);
	std::wstring GetMD5check();
	void SetISOlocation(std::wstring NewISOlocation);
	std::wstring GetISOlocation();
private:
	std::wstring ISOname;
	std::wstring ISOfilename;
	std::wstring ISOdescription;
	std::wstring MD5checksum;
	std::wstring ISOlocation;
	//auto ISOmodificationTime;

};
#endif

