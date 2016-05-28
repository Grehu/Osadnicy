#include "DystrybutorCzcionek.hpp"

DystrybutorCzcionek::DystrybutorCzcionek()
{
	dodajCzcionke("Squares Bold Free.otf", PrzeznaczenieFontu::menu);
	dodajCzcionke("goodfish.ttf", PrzeznaczenieFontu::opis);
	dodajCzcionke("Squares Bold Free.otf", PrzeznaczenieFontu::wartosc);
}

Font DystrybutorCzcionek::pobierzLosowaCzcionke(PrzeznaczenieFontu etykieta)
{
	srand(time(NULL));
	int numer = rand()%magazyn[etykieta].size();
	return pobierzKonkretnaCzcionke(etykieta, numer);
}

Font DystrybutorCzcionek::pobierzKonkretnaCzcionke(PrzeznaczenieFontu etykieta, int numer)
{
	return magazyn[etykieta][numer];
}

void DystrybutorCzcionek::dodajCzcionke(string nazwaPliku, PrzeznaczenieFontu etykieta)
{
	Font * czcionka = new Font;
	if (czcionka->loadFromFile(nazwaPliku)) {
		magazyn[etykieta].push_back(*czcionka);
	}
	delete czcionka;
}