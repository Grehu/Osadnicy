#include "DystrybutorWartosci.hpp"

void DystrybutorWartosci::generuj()
{
	int wartosc = 0;
	int srodek = (min + max) / 2;
	bool symetria = iloscPol % 2;
	int i = 0;
	while (iloscPol > 0) {
		i++;
		if (srodek + i <= max) {
			wartosc = srodek + i;
			magazyn.push_back(wartosc);
			iloscPol--;
		}
		if (srodek - i >= min && (symetria || iloscPol > 0)) {
			wartosc = srodek - i;
			magazyn.push_back(wartosc);
			iloscPol--;
		}
		if (srodek + i > max && srodek - i < min) {
			i = 0;
		}
	}
}

void DystrybutorWartosci::generujOdwrotnie()
{
	int wartosc = 0;
	int srodek = (min + max) / 2;
	bool symetria = iloscPol % 2;
	int i = 0;
	while (iloscPol > 0) {
		
		if (min + i < srodek) {
			wartosc = min + i;
			magazyn.push_back(wartosc);
			iloscPol--;
		}
		if (max - i > srodek && (symetria || iloscPol > 0)) {
			wartosc = max - i;
			magazyn.push_back(wartosc);
			iloscPol--;
		}
		i++;
		if ((min + i) >= srodek && (max - i) <= srodek) {
			i = 0;
		}
	}
}

void DystrybutorWartosci::tasuj(int ilosc)
{//Fisher–Yates shuffle
	int j = 0;
	int tmp = 0;
	for (ilosc; ilosc > 0; ilosc--) {
		for (int i = magazyn.size() - 1; i > 0; i--) {
			j = MaszynaLosujaca::pobierzCalkowita() % (i + 1);
			tmp = magazyn[j];
			magazyn[j] = magazyn[i];
			magazyn[i] = tmp;
		}
	}
}

void DystrybutorWartosci::inicjalizacja(std::vector<Kostka*> kostki, int iloscPol)
{
	this->min = kostki.size();
	for (int i = 0; i < kostki.size(); i++) {
		this->max += kostki[i]->policzSciany();
	}
	this->iloscPol = iloscPol;
}

void DystrybutorWartosci::generujWartosci() {
	magazyn.clear();
	generuj();
	tasuj(10);
}

void DystrybutorWartosci::generujOdwrotneWartosci()
{
	magazyn.clear();
	generujOdwrotnie();
	tasuj(10);
}

int DystrybutorWartosci::przydzielWartosc()
{
	if (!magazyn.empty()) {
		int temp = magazyn.back();
		magazyn.pop_back();
		return temp;
	}
	else {
		return -1;
	}
}
