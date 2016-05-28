#pragma once
#include "Osada.hpp"
#include "Towar.hpp"
class Port {
private:
	Surowiec surowiec = Surowiec::nic;
	Osada * klient1;
	Osada * klient2;

public:
	void dodajKlientow(Osada & klient1, Osada & klient2);
	void ustawSurowiec(Surowiec surowiec);
	Towar handel(Towar eksportowany, Surowiec zakup);
	

};