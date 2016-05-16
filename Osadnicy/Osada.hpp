#pragma once
#include "Pole.hpp"
#include "Koordynaty.hpp"
#include "Dostawa.hpp"

class Osada {
protected:
	Koordynaty pozycja;
	bool blokada = false;
	Pole ** pola;
	int stopienRozwoju = 0;
public:
	void ustawPozycje(Koordynaty pozycja);
	void ustawSasiadow(Pole * pole1, Pole * pole2, Pole * pole3);
	bool zablokowana();
	void rozbuduj();
	Dostawa zbierzSurowce(int wartosc);
};