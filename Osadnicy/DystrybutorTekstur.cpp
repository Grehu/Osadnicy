#include "DystrybutorTekstur.hpp"
#include <iostream>

DystrybutorTekstur::DystrybutorTekstur()
{
	dodajTeksture("Grafiki/board0.png", Etykieta::ramka);
	dodajTeksture("Grafiki/desert0.png", Etykieta::pustynia);
	dodajTeksture("Grafiki/lumber0.png", Etykieta::drewno);
	dodajTeksture("Grafiki/lumber1.png", Etykieta::drewno);
	dodajTeksture("Grafiki/lumber2.png", Etykieta::drewno);
	dodajTeksture("Grafiki/lumber3.png", Etykieta::drewno);
	dodajTeksture("Grafiki/lumber4.png", Etykieta::drewno);
	dodajTeksture("Grafiki/clay0.png", Etykieta::glina);
	dodajTeksture("Grafiki/clay1.png", Etykieta::glina);
	dodajTeksture("Grafiki/clay2.png", Etykieta::glina);
	dodajTeksture("Grafiki/clay3.png", Etykieta::glina);
	dodajTeksture("Grafiki/grain0.png", Etykieta::zboze);
	dodajTeksture("Grafiki/grain1.png", Etykieta::zboze);
	dodajTeksture("Grafiki/grain2.png", Etykieta::zboze);
	dodajTeksture("Grafiki/grain3.png", Etykieta::zboze);
	dodajTeksture("Grafiki/stone0.png", Etykieta::kamien);
	dodajTeksture("Grafiki/stone1.png", Etykieta::kamien);
	dodajTeksture("Grafiki/stone2.png", Etykieta::kamien);
	dodajTeksture("Grafiki/stone3.png", Etykieta::kamien);
	dodajTeksture("Grafiki/stone4.png", Etykieta::kamien);
	dodajTeksture("Grafiki/wool0.png", Etykieta::welna);
	dodajTeksture("Grafiki/wool1.png", Etykieta::welna);
	dodajTeksture("Grafiki/wool2.png", Etykieta::welna);
	dodajTeksture("Grafiki/wool3.png", Etykieta::welna);
	dodajTeksture("Grafiki/city0.png", Etykieta::miasto);
	dodajTeksture("Grafiki/village0.png", Etykieta::wioska);
	dodajTeksture("Grafiki/ship0.png", Etykieta::port);
	dodajTeksture("Grafiki/ship1.png", Etykieta::port);
	dodajTeksture("Grafiki/ship2.png", Etykieta::port);
	dodajTeksture("Grafiki/ship3.png", Etykieta::port);
	dodajTeksture("Grafiki/sea0.png", Etykieta::morze);
	dodajTeksture("Grafiki/sea1.png", Etykieta::morze);
	dodajTeksture("Grafiki/sea2.png", Etykieta::morze);
	dodajTeksture("Grafiki/sea3.png", Etykieta::morze);
	dodajTeksture("Grafiki/sea4.png", Etykieta::morze);
	dodajTeksture("Grafiki/thief0.png", Etykieta::zlodziej);
	dodajTeksture("Grafiki/value0.png", Etykieta::wartosc);
	dodajTeksture("Grafiki/lumberCard.png", Etykieta::drewnoKarta);
	dodajTeksture("Grafiki/clayCard.png", Etykieta::glinaKarta);
	dodajTeksture("Grafiki/grainCard.png", Etykieta::zbozeKarta);
	dodajTeksture("Grafiki/stoneCard.png", Etykieta::kamienKarta);
	dodajTeksture("Grafiki/woolCard.png", Etykieta::welnaKarta);
}

Texture * DystrybutorTekstur::pobierzLosowaTeksture(Etykieta etykieta)
{
	//srand(time(NULL));
	int numer = 0;
	if (magazyn[etykieta].size()>0) {numer = MaszynaLosujaca::pobierzCalkowita() % magazyn[etykieta].size(); }
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
	else {
		std::cout << "Blad ladowania tekstury!" << endl;
	}
}
