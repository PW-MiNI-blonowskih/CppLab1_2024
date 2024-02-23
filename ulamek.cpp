#include <iostream>
#include <cmath>
#include "ulamek.h"

Ulamek::Ulamek() {
	licznik = 1;
	mianownik = 1; 
	std::cout << "Error:\tNie podano wartosci inicjalizujacych." << std::endl << "\tMianownik i licznik zainicjalizowane wartością 1 oraz 1" << std::endl;
}

Ulamek::Ulamek(int Licznik , int Mianownik) {
	if (Mianownik != 0) {
		licznik = Licznik;
		mianownik = Mianownik;
	} else {
		licznik = Licznik;
		mianownik = 1;
		std::cout << "Error:\tMianownik nie może być równy 0!" << std::endl << "\tMianownik zainicjalizowany jako 1." << std::endl;
	}
}

void Ulamek::Wypisz() const {
	std::cout << "Ulamek: (" << licznik << ", " << mianownik << ")" << std::endl;
}

void Ulamek::Wczytaj() {
	std::cout << "Podaj licznik: ";
	std::cin >> licznik;
	std::cout << "Podaj mianownik: ";
	std::cin >> mianownik;
}

void Ulamek::Skracaj() {
	if (mianownik < 0) {
		mianownik = mianownik * -1;
		licznik = licznik * -1;
	}
	int div = NWD(std::abs(licznik), std::abs(mianownik));
	licznik = licznik / div;
	mianownik = mianownik / div;
}

Ulamek operator+(const Ulamek& a, const Ulamek& b) {
	Ulamek c(1,1);
	c.mianownik = a.mianownik * b.mianownik;
	c.licznik = a.licznik * b.mianownik + b.licznik * a.mianownik;
	c.Skracaj();
	return c;
}

std::ostream& operator<<(std::ostream& out, const Ulamek& a) {
	return std::cout << "Ulamek: (" << a.licznik << ", " << a.mianownik << ")";
}

std::istream& operator>>(std::istream& in, Ulamek& a) {
	std::cout << "Podaj licznik: ";
	in >> a.licznik;
	std::cout << "Podaj mianownik: ";
	in >> a.mianownik;
	return in;
}

int NWD(int a, int b) {
	int r;
	while (b != 0) {
		r = a % b;
		a = b;
		b = r;
	}
	return a;
}