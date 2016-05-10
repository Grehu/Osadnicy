#include "BudynekComposite.hpp"

void BudynekComposite::zbuduj()
{
	zbudowane = true;
}

void BudynekComposite::ustawKolor(Color kolor)
{
	this->kolor = kolor;
}

void BudynekComposite::ustawBudynek(RysunekComponent & budynek)
{
	this->budynek = &budynek;
}

void BudynekComposite::ustawRamke(RysunekComponent & ramka)
{
	this->ramka = &ramka;
}

void BudynekComposite::rysuj(RenderWindow & okno)
{
	budynek->ustawPozycje(*pozycja);
	ramka->ustawPozycje(*pozycja);

	budynek->rysuj(okno);
	ramka->rysuj(okno);
	
}
