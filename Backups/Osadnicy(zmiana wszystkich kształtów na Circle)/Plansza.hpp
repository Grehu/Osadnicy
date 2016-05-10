#pragma once
#include <SFML/Graphics.hpp>
#include "RysunekComponent.hpp"

class Plansza {
protected:
	int szerokosc = 7;
	int wysokosc = 7;

	Vector2f ** pozycjeHexow;
	RysunekComponent ** grafikiHexow;
	//TODO PoleSurowca ** polaSurowcow;

	Vector2f ** pozycjeDrog;
	RysunekComponent ** grafikiDrog;
	//TODO Droga ** drogi;

	Vector2f ** pozycjeBudynkow;
	RysunekComponent ** grafikiBudynkow;
	//TODO Budynek ** budynki;

	Vector2f ** pozycjePortow;
	RysunekComponent ** grafikiPortow;
	//TODO Port ** porty;

public:
	Plansza(int szerokosc, int wysokosc);
};