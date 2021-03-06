#pragma once
#include "Koordynaty.hpp"
#include "Parowanie.hpp"
#include "PlanszaBuilder.hpp"
#include "LosowaPlanszaBuilder.hpp"
#include <iostream>
#include "Konwerter.hpp"
#include "Ustawienia.hpp"
#include "PanelPrzewijania.hpp"
#include "HUD.hpp"
#include "MenagerEfektow.hpp"

class Test {
private:
	void porownaj(Koordynaty port, Koordynaty poprawne1, Koordynaty poprawne2);
	void porownaj(Koordynaty osada, Koordynaty poprawne1, Koordynaty poprawne2, Koordynaty poprawne3);
	RenderWindow * okno;
	PlanszaBuilder * builder;
	DystrybutorCzcionek * czcionki;
	DystrybutorTekstur * tekstury;
	DystrybutorWartosci * wartosci;
	Plansza * plansza;
	HUD * hud;
	MenagerEfektow * me;
	vector<CircleShape*> dzialki;
	vector<RectangleShape*> drozki;
public:
	void testPrzyporzadkowaniaPortu();
	void testPrzyporzadkowaniaOsady();
	void przypiszOknoWyswietlania(RenderWindow * okno);
	void inicjujTesteraBudowniczych();
	void testBudowaniaPola();
	void testBudowaniaMorza();
	void inicjalizacjaInterfejsu();
	void testOdtwarzaniaSchematu();
	void testBudowaniaPustyni();
	void testWyswietlania();
	Text testDystrybutoraCzcionek();
	void inicjujTestLokalizacjiOsad();
	void wyswietlOsady();
	void inicjujTestLokalizacjiDrog();
	void wyswietlDrogi();
	void inicjujTestLokalizacjiPortow();

};