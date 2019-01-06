#include "ISOfile.h"



ISOfile::ISOfile()
{
}

ISOfile::ISOfile(const std::wstring NewISOlocation = L"./") : ISOlocation(NewISOlocation)
{
}


ISOfile::~ISOfile()
{
}

void ISOfile::SetISOname(std::wstring NewISOname)
{
	ISOname = NewISOname;
}

std::wstring ISOfile::GetISOname()
{
	return ISOname;
}

void ISOfile::SetISOfilename(std::wstring NewISOfilename)
{
	ISOfilename = NewISOfilename;
}

std::wstring ISOfile::GetISOfilename()
{
	return ISOfilename;
}

void ISOfile::SetISOdesc(std::wstring NewISOdesc)
{
	ISOdescription = NewISOdesc;
}

std::wstring ISOfile::GetISOdesc()
{
	return ISOdescription;
}

void ISOfile::SetMD5check(std::wstring NewMD5check)
{
}

std::wstring ISOfile::GetMD5check()
{
	return std::wstring();
}

void ISOfile::SetISOlocation(std::wstring NewISOlocation)
{
}

std::wstring ISOfile::GetISOlocation()
{
	return std::wstring();
}
