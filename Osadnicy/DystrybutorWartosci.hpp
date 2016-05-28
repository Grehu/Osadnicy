#pragma once
#include <random>
#include <ctime>
#include <vector>
#include "Kostka.hpp"


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
	DystrybutorWartosci(std::vector<Kostka*> kostki, int iloscPol);
	void generujWartosci();
	void generujOdwrotneWartosci();
	int przydzielWartosc();
};