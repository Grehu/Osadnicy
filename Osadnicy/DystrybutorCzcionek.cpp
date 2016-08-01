#include "DystrybutorCzcionek.hpp"

DystrybutorCzcionek::DystrybutorCzcionek()
{
	dodajCzcionke("Fonty/Squares Bold Free.otf", PrzeznaczenieFontu::menu);
	dodajCzcionke("Fonty/goodfish.ttf", PrzeznaczenieFontu::opis);
	dodajCzcionke("Fonty/Squares Bold Free.otf", PrzeznaczenieFontu::wartosc);
}

Font * DystrybutorCzcionek::pobierzLosowaCzcionke(PrzeznaczenieFontu etykieta)
{
	int numer = 0;
	if (magazyn.size() > 0) { numer = MaszynaLosujaca::pobierzCalkowita() % magazyn[etykieta].size(); }
	return pobierzKonkretnaCzcionke(etykieta, numer);
}

Font * DystrybutorCzcionek::pobierzKonkretnaCzcionke(PrzeznaczenieFontu etykieta, int numer)
{
	return &magazyn[etykieta][numer];
}

void DystrybutorCzcionek::dodajCzcionke(string nazwaPliku, PrzeznaczenieFontu etykieta)
{
	Font * czcionka = new Font;
	if (czcionka->loadFromFile(nazwaPliku)) {
		magazyn[etykieta].push_back(*czcionka);
	}
	delete czcionka;
}