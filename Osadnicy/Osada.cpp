#include "Osada.hpp"



void Osada::ustawPozycje(Koordynaty pozycja)
{
	this->pozycja.x = pozycja.x;
	this->pozycja.y = pozycja.y;
}

void Osada::ustawSasiadow(Pole * pole1, Pole * pole2, Pole * pole3)
{
	pola = new Pole*[3];
	pola[0] = pole1;
	pola[1] = pole2;
	pola[2] = pole3;
}

bool Osada::zablokowana()
{
	return (blokada || stopienRozwoju!=0);
}

void Osada::rozbuduj()
{
	if (!blokada || stopienRozwoju != 0) { if (stopienRozwoju < 2) { stopienRozwoju++; } }
}

Dostawa Osada::zbierzSurowce(int wartosc)
{
	Dostawa zPol;
	for (int i = 0; i < 3; i++) {
		zPol.nazwa[i] = pola[i]->rodzajSurowca();
		zPol.ilosc[i] = pola[i]->zbierzSurowce(stopienRozwoju, wartosc);
	}
	return zPol;
}
