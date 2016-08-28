#pragma once
#include <SFML/Graphics/Color.hpp>
#include <vector>
using namespace sf;

class MenagerEfektow {
private:
	//Kolory
	Color aktualnyKolor;
	std::vector<Color> kolory;
	//Indeksy
	int numerKoloru = 0;
	int nastepnyKolor() { return (numerKoloru + 1 < kolory.size()) ? numerKoloru + 1 : 0; }
	//Sk³adowe
	float przyrostR = 0.0f;
	float przyrostG = 0.0f;
	float przyrostB = 0.0f;
	float przyrostA = 0.0f;
	float magazynR = 0.0f;
	float magazynG = 0.0f;
	float magazynB = 0.0f;
	float magazynA = 0.0f;
	//Sterowanie
	float czasPostoju = 100.0f;
	int krokiDoCelu = 1000;
	int licznikKrokow = 0;
	//Flagi
	bool gotowoscDoPrzejscia = false;
	//Funkcje pomocnicze
	void ustawPrzyrosty();
	

	
public:
	MenagerEfektow(Color & poczatkowy, Color & docelowy);
	void dodajKolor(Color & kolor);
	void mieszaj();
	Color pobierzKolor();
};