#pragma once
#include <SFML/Graphics.hpp>

#include "RysunekComponent.hpp"
#include "PoleLeaf.hpp"
#include "PoleWartosciLeaf.hpp"
#include "RamkaLeaf.hpp"
#include "RysunekComposite.hpp"
#include "BudynekLeaf.hpp"
#include "DrogaLeaf.hpp"
#include "PortLeaf.hpp"

#include "Kostka.hpp"

#include "Pole.hpp"
#include "Osada.hpp"
#include "Droga.hpp"
#include "Zlodziej.hpp"
#include "Port.hpp"

class Plansza {
protected:
	int szerokosc = 7;
	int wysokosc = 7;
	float przesuniêcie = 0.0f;

	Vector2f ** pozycjeHexow;
	RysunekComponent ** grafikiHexow;
	Pole ** pola;

	Vector2f ** pozycjeDrog;
	RysunekComponent ** grafikiDrog;
	Droga ** drogi;

	Vector2f ** pozycjeBudynkow;
	RysunekComponent ** grafikiBudynkow;
	//Osada ** osady;

	Vector2f ** pozycjePortow;
	RysunekComponent ** grafikiPortow;
	Port ** porty;

public:
	Plansza(int szerokosc, int wysokosc);
	Vector2f * pobierzPozycjePola(Koordynaty koordynaty);
	Vector2f * pobierzPozycjeDrogi(Koordynaty koordynaty);
	Vector2f * pobierzPozycjeBudynku(Koordynaty koordynaty);
	Vector2f * pobierzPozycjePortu(Koordynaty koordynaty);
	//Osada * pobierzOsada(int x, int y);
	/*Droga * pobierzDroge(int x, int y);
	Port * pobierzPort(int x, int y);*/
	//Pole * pobierzPole(int x, int y);
};