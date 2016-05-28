#pragma once

#include "Plansza.hpp"
#include "DystrybutorTekstur.hpp"
#include "DystrybutorCzcionek.hpp"
#include "DystrybutorWartosci.hpp"
#include "Parowanie.hpp"
#include <SFML\Graphics.hpp>
#include "Stale.hpp"

class PlanszaBuilder {
protected:
	Plansza * plansza;
	DystrybutorTekstur * tekstury;
	DystrybutorCzcionek * czcionki;
	DystrybutorWartosci * wartosci;
	//Do nawigacji
	Koordynaty wskaznik = { 0,0 };
	//Tworzenie ksztaltow
	virtual Shape * tworzSzescian(Etykieta etykieta) = 0;
	virtual Shape * tworzProstokat(Etykieta etykieta, int orientacja) = 0;
	virtual Shape * tworzKolo(Etykieta etykieta) = 0;
	//Tworzenie tekstow
	virtual Text * tworzTekst(String tresc) = 0;
	//Tworzenie modelow
	virtual Pole tworzObiektPola(Surowiec surowiec) = 0;
	virtual Port tworzObiektPortu(Surowiec surowiec) = 0;
	virtual Droga tworzObiektDrogi() = 0;
	virtual Osada tworzObiektOsady() = 0;
	//Ustalanie wektorow
	virtual Vector2f ustawPozycjePola() = 0;
	virtual Vector2f ustawPozycjeOsady() = 0;
	virtual Vector2f ustawPozycjeDrogi() = 0;
	virtual Vector2f ustawPozycjePortu() = 0;

public:

	void przypiszDystrybutory(DystrybutorTekstur * tekstury, DystrybutorCzcionek * czcionki, DystrybutorWartosci * wartosci);
	void dodajKostke(int iloscScian);

	virtual void budujPlansze() = 0;

	//Budowa komponentow planszy
	virtual void budujMorze() = 0;
	virtual void budujPustynie() = 0;
	virtual void budujObszarMieszkalny() = 0;
	virtual void budujPole() = 0;
	virtual void budujPole(Surowiec surowiec) = 0;
	virtual void budujPortZwykly() = 0;
	virtual void budujPortSpecjalistyczny() = 0;
	virtual void budujPortSpecjalistyczny(Surowiec surowiec) = 0;

	//Nawigacja
	virtual void nastepnaKolumna() { wskaznik.x++; };
	virtual void nastepnyWiersz() { wskaznik.x = 0; wskaznik.y++; };
	virtual void skoczDo(int x, int y) { wskaznik.x = x; wskaznik.y = y; };

	virtual Plansza * zwrocPlansze() { return 0; };
};