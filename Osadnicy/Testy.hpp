#pragma once
#include "Koordynaty.hpp"
#include "Parowanie.hpp"
#include "PlanszaBuilder.hpp"
#include "LosowaPlanszaBuilder.hpp"
#include <iostream>

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
public:
	void testPrzyporzadkowaniaPortu();
	void testPrzyporzadkowaniaOsady();
	void przypiszOknoWyswietlania(RenderWindow * okno);
	void inicjujTesteraBudowniczych();
	void testBudowaniaPola();
	void testBudowaniaMorza();
	void testBudowaniaPustyni();
	void testWyswietlania();
	Text testDystrybutoraCzcionek();

};