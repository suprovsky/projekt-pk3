#include <iostream>
#include "ISOfile.h"
#include "repository.h"
#include "md5.h"
#include <Windows.h>
//19.��Baza p�yt z oprogramowaniem instalacyjnym
//Zadaniem programu jest zarz�dzanie zbiorem plik�w z oprogramowaniem instalacyjnym.
//Zarz�dzanie obejmuje : przeszukiwanie zasob�w, dodawanie nowych pozycji, modyfikacje 
//oraz usuwanie istniej�cych rekord�w.
int main() {
	SetConsoleTitle(TEXT("ISOfinder"));
	repository repo;
	std::cout << "testujemy czy github dziala" << std::endl;
	int test;
	std::cin >> test;
	//1st changec
}