#include "Plansza.hpp"

Plansza::Plansza(int szerokosc, int wysokosc)
{
	this->szerokosc = szerokosc;
	this->wysokosc = wysokosc;

	pozycjeHexow = new Vector2f * [szerokosc];
	for (int i = 0; i < wysokosc; i++) { pozycjeHexow[i] = new Vector2f; }
	grafikiHexow = new RysunekComponent * [szerokosc];
	for (int i = 0; i < wysokosc; i++) { grafikiHexow[i] = new RysunekComponent; }
	//polaSurowcow = new PoleSurowca *[szerokosc];
	//for (int i = 0; i < wysokosc; i++) { polaSurowcow[i] = new PoleSurowca; }

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
	//budynki = new Budynek *[szerokosc];
	//for (int i = 0; i < wysokosc; i++) { budynki[i] = new Budynek; }

	pozycjePortow = new Vector2f *[szerokosc];
	for (int i = 0; i < wysokosc; i++) { pozycjePortow[i] = new Vector2f; }
	grafikiPortow = new RysunekComponent *[szerokosc];
	for (int i = 0; i < wysokosc; i++) { grafikiPortow[i] = new RysunekComponent; }
	//porty = new Port *[szerokosc];
	//for (int i = 0; i < wysokosc; i++) { porty[i] = new Port; }


}
