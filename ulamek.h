#pragma once 

class Ulamek
{
private:
	int licznik, mianownik;
	void Skracaj();

public:
	Ulamek();
	Ulamek(int Licznik, int Mianownik);

	void Wypisz() const;
	void Wczytaj();

	friend Ulamek operator+(const Ulamek& a, const Ulamek& b);
	friend std::ostream& operator<<(std::ostream& out, const Ulamek& a);
	friend std::istream& operator>>(std::istream& in, Ulamek& a);
};

int NWD(int a, int b);