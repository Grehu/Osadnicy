#include "DystrybutorTekstur.hpp"

DystrybutorTekstur::DystrybutorTekstur()
{
	
}

Texture * DystrybutorTekstur::pobierzLosowaTeksture(string etykieta)
{
	srand(time(NULL));
	int numer = rand();
	return pobierzKonkretnaTeksture(etykieta, numer);
}

Texture * DystrybutorTekstur::pobierzKonkretnaTeksture(string etykieta, int numer)
{
	return magazyn[etykieta][numer];
}

void DystrybutorTekstur::dodajTeksture(string nazwaPliku, string etykieta)
{
	Texture * tekstura = new Texture;
	if (tekstura->loadFromFile(nazwaPliku)) {
		tekstura->setSmooth(true);
		magazyn[etykieta].push_back(tekstura);
	}
}
