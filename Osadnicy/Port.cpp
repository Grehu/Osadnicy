#include "Port.hpp"

void Port::dodajKlientow(Osada * klient1, Osada * klient2)
{
	this->klient1 = klient1;
	this->klient2 = klient2;
}

void Port::ustawSurowiec(Surowiec surowiec)
{
	this->surowiec = surowiec;
}

Towar Port::handel(Towar eksportowany, Surowiec zakup)
{
	if (this->surowiec == Surowiec::nic) {
		Towar importowany;
		importowany.ilosc = eksportowany.ilosc / 3;
		importowany.surowiec = zakup;
		return importowany;
	}
	if (eksportowany.surowiec == this->surowiec) {
		Towar importowany;
		importowany.ilosc = eksportowany.ilosc / 2;
		importowany.surowiec = zakup;
		return importowany;
	}
	else {
		Towar blad;
		blad.surowiec = Surowiec::nic;
		blad.ilosc = 0;
		return blad;
	}
}
