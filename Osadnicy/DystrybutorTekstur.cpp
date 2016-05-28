#include "DystrybutorTekstur.hpp"

DystrybutorTekstur::DystrybutorTekstur()
{
	dodajTeksture("board0.png", Etykieta::ramka);
	dodajTeksture("desert0.png", Etykieta::pustynia);
	dodajTeksture("lumber0.png", Etykieta::drewno);
	dodajTeksture("lumber1.png", Etykieta::drewno);
	dodajTeksture("lumber2.png", Etykieta::drewno);
	dodajTeksture("lumber3.png", Etykieta::drewno);
	dodajTeksture("lumber4.png", Etykieta::drewno);
	dodajTeksture("clay0.png", Etykieta::glina);
	dodajTeksture("clay1.png", Etykieta::glina);
	dodajTeksture("clay2.png", Etykieta::glina);
	dodajTeksture("clay3.png", Etykieta::glina);
	dodajTeksture("grain0.png", Etykieta::zboze);
	dodajTeksture("grain1.png", Etykieta::zboze);
	dodajTeksture("grain2.png", Etykieta::zboze);
	dodajTeksture("grain3.png", Etykieta::zboze);
	dodajTeksture("stone0.png", Etykieta::kamien);
	dodajTeksture("stone1.png", Etykieta::kamien);
	dodajTeksture("stone2.png", Etykieta::kamien);
	dodajTeksture("stone3.png", Etykieta::kamien);
	dodajTeksture("stone4.png", Etykieta::kamien);
	dodajTeksture("wool0.png", Etykieta::welna);
	dodajTeksture("wool1.png", Etykieta::welna);
	dodajTeksture("wool2.png", Etykieta::welna);
	dodajTeksture("wool3.png", Etykieta::welna);
	dodajTeksture("city0.png", Etykieta::miasto);
	dodajTeksture("village0.png", Etykieta::wioska);
	dodajTeksture("ship0.png", Etykieta::port);
	dodajTeksture("ship1.png", Etykieta::port);
	dodajTeksture("ship2.png", Etykieta::port);
	dodajTeksture("ship3.png", Etykieta::port);
	dodajTeksture("sea0.png", Etykieta::morze);
	dodajTeksture("sea1.png", Etykieta::morze);
	dodajTeksture("sea2.png", Etykieta::morze);
	dodajTeksture("sea3.png", Etykieta::morze);
	dodajTeksture("sea4.png", Etykieta::morze);
	dodajTeksture("thief0.png", Etykieta::zlodziej);
	dodajTeksture("value0.png", Etykieta::wartosc);
	dodajTeksture("lumberCard0.png", Etykieta::drewnoKarta);
	dodajTeksture("clayCard0.png", Etykieta::glinaKarta);
	dodajTeksture("grainCard0.png", Etykieta::zbozeKarta);
	dodajTeksture("stoneCard0.png", Etykieta::kamienKarta);
	dodajTeksture("woolCard0.png", Etykieta::welnaKarta);
}

Texture * DystrybutorTekstur::pobierzLosowaTeksture(Etykieta etykieta)
{
	srand(time(NULL));
	int numer = rand() % magazyn[etykieta].size();
	return pobierzKonkretnaTeksture(etykieta, numer);
}

Texture * DystrybutorTekstur::pobierzKonkretnaTeksture(Etykieta etykieta, int numer)
{
	return magazyn[etykieta][numer];
}

void DystrybutorTekstur::dodajTeksture(string nazwaPliku, Etykieta etykieta)
{
	Texture * tekstura = new Texture;
	if (tekstura->loadFromFile(nazwaPliku)) {
		tekstura->setSmooth(true);
		magazyn[etykieta].push_back(tekstura);
	}
}
