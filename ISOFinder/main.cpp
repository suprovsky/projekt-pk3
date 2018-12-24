#include <iostream>
#include "ISOfile.h"
#include "repository.h"
#include "md5.h"
#include <Windows.h>
//19.  Baza p³yt z oprogramowaniem instalacyjnym
//Zadaniem programu jest zarz¹dzanie zbiorem plików z oprogramowaniem instalacyjnym.
//Zarz¹dzanie obejmuje : przeszukiwanie zasobów, dodawanie nowych pozycji, modyfikacje 
//oraz usuwanie istniej¹cych rekordów.
int main() {
	SetConsoleTitle(TEXT("ISOfinder"));
	repository repo;
	std::cout << "testujemy czy github dziala" << std::endl;
	int test;
	std::cin >> test;
	//1st changec
}