#include "Plansza.hpp"

Plansza::Plansza(int szerokosc, int wysokosc)
{
	this->szerokosc = szerokosc;
	this->wysokosc = wysokosc;

	pozycjeHexow = new Vector2f * [szerokosc];
	for (int i = 0; i < wysokosc; i++) { pozycjeHexow[i] = new Vector2f; }
	grafikiHexow = new RysunekComponent * [szerokosc];
	for (int i = 0; i < wysokosc; i++) { grafikiHexow[i] = new RysunekComponent; }
	pola = new Pole *[szerokosc];
	for (int i = 0; i < wysokosc; i++) { pola[i] = new Pole; }

	pozycjeDrog = new Vector2f *[szerokosc];
	for (int i = 0; i < wysokosc; i++) { pozycjeDrog[i] = new Vector2f; }
	grafikiDrog = new RysunekComponent *[szerokosc];
	for (int i = 0; i < wysokosc; i++) { grafikiDrog[i] = new RysunekComponent; }
	//drogi = new Droga *[szerokosc];
	//for (int i = 0; i < wysokosc; i++) { drogi[i] = new Droga; }

	pozycjeBudynkow = new Vector2f *[szerokosc];
	for (int i = 0; i < wysokosc; i++) { pozycjeBudynkow[i] = new Vector2f; }
	grafikiBudynkow = new RysunekComponent *[szerokosc];
	for (int i = 0; i < wysokosc; i++) { grafikiBudynkow[i] = new RysunekComponent; }
	//osady = new Osada *[szerokosc];
	//for (int i = 0; i < wysokosc; i++) { osady[i] = new Osada; }

	pozycjePortow = new Vector2f *[szerokosc];
	for (int i = 0; i < wysokosc; i++) { pozycjePortow[i] = new Vector2f; }
	grafikiPortow = new RysunekComponent *[szerokosc];
	for (int i = 0; i < wysokosc; i++) { grafikiPortow[i] = new RysunekComponent; }
	porty = new Port *[szerokosc];
	for (int i = 0; i < wysokosc; i++) { porty[i] = new Port; }


}
Vector2f * Plansza::pobierzPozycjePola(Koordynaty koordynaty)
{
	return &pozycjeHexow[koordynaty.x][koordynaty.y];
}
Vector2f * Plansza::pobierzPozycjeDrogi(Koordynaty koordynaty)
{
	return &pozycjeDrog[koordynaty.x][koordynaty.y];
}
Vector2f * Plansza::pobierzPozycjeBudynku(Koordynaty koordynaty)
{
	return &pozycjeBudynkow[koordynaty.x][koordynaty.y];
}
Vector2f * Plansza::pobierzPozycjePortu(Koordynaty koordynaty)
{
	return &pozycjePortow[koordynaty.x][koordynaty.y];
}
/*
Osada * Plansza::pobierzOsada(int x, int y)
{
	return &osady[x][y];
}

Droga * Plansza::pobierzDroge(int x, int y)
{
	return &drogi[x][y];
}

Port * Plansza::pobierzPort(int x, int y)
{
	return &porty[x][y];
}
*/
/*Pole * Plansza::pobierzPole(int x, int y)
{
	return &pola[x][y];
}*/