#include "RysunekComposite.hpp"


void RysunekComposite::ustawPole(PoleLeaf & pole)
{
	this->pole = &pole;
}

void RysunekComposite::ustawWartosc(PoleWartosciLeaf & poleWartosci)
{
	this->poleWartosci = &poleWartosci;
}

void RysunekComposite::ustawRamke(RamkaLeaf & ramka)
{
	this->ramka = &ramka;
}


void RysunekComposite::rysuj(RenderWindow & okno, Vector2f * przewijanie)
{
	/*
	pole->ustawPozycje(*pozycja);
	poleWartosci->ustawPozycje(*pozycja);
	ramka->ustawPozycje(*pozycja);
	*/
	pole->rysuj(okno, przewijanie);
	ramka->rysuj(okno, przewijanie);
	poleWartosci->rysuj(okno, przewijanie);
}
