#pragma once
#include "Osada.hpp"
#include "Towar.hpp"
class Port {
private:
	string surowiec = "";
	Osada * klient1;
	Osada * klient2;

public:
	void dodajKlientow(Osada & klient1, Osada & klient2);
	void ustawSurowiec(string surowiec);
	Towar handel(Towar eksportowany, string zakup);
	

};