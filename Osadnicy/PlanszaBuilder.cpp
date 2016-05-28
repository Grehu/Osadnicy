#include "PlanszaBuilder.hpp"

void PlanszaBuilder::przypiszDystrybutory(DystrybutorTekstur * tekstury, DystrybutorCzcionek * czcionki, DystrybutorWartosci * wartosci)
{
	this->tekstury = tekstury;
	this->czcionki = czcionki;
	this->wartosci = wartosci;
}

void PlanszaBuilder::dodajKostke(int iloscScian)
{
	plansza->dodajKostke(iloscScian);
}


