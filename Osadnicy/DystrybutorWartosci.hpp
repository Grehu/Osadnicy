#pragma once
#include <vector>
#include "Kostka.hpp"
#include "MaszynaLosujaca.hpp"


class DystrybutorWartosci {
private:
	std::vector<int> magazyn;
	int min = 0;
	int max = 0;
	int iloscPol = 0;
	void generuj();
	void generujOdwrotnie();
	void tasuj(int ilosc);
public:
	void inicjalizacja(std::vector<Kostka*> kostki, int iloscPol);
	void generujWartosci();
	void generujOdwrotneWartosci();
	int przydzielWartosc();
};