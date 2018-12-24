#include "ISOfile.h"



ISOfile::ISOfile()
{
}

ISOfile::ISOfile(const std::wstring NewISOlocation = L"./") : ISOlocation(NewISOlocation)
{
}

ISOfile::ISOfile(std::string SomeISOdata)
{
}


ISOfile::~ISOfile()
{
}

std::string ISOfile::SetISOname(std::string NewISOname)
{
	return std::string();
}

std::string ISOfile::GetISOname()
{
	return std::string();
}

std::string ISOfile::SetISOfilename(std::string NewISOfilename)
{
	return std::string();
}

std::string ISOfile::GetISOfilename()
{
	return std::string();
}

std::string ISOfile::SetISOdesc(std::string NewISOdesc)
{
	return std::string();
}

std::string ISOfile::GetISOdesc()
{
	return std::string();
}

std::string ISOfile::SetMD5check(std::string NewMD5check)
{
	return std::string();
}

std::string ISOfile::GetMD5check()
{
	return std::string();
}

std::wstring ISOfile::SetISOlocation(std::wstring NewISOlocation)
{
	return std::wstring();
}

std::wstring ISOfile::GetISOlocation()
{
	return std::wstring();
}
