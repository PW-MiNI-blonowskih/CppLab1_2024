#include <iostream>
#include "ulamek.h"

int main(int argc, char const *argv[])
{
	Ulamek a;
	Ulamek b(5,7);
	a.Wypisz();
	std::cout << b << std::endl;
	std::cin >> a;
	std::cout << a << std::endl;
	return 0;
}
