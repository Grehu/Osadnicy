#include "Pole.hpp"

void Pole::ustawSurowiec(string surowiec)
{
	this->surowiec = surowiec;
}

void Pole::ustawWartosc(int wartosc)
{
	this->wartosc = wartosc;
	this->zlodziej = false;
}


void Pole::ustawZlodzieja()
{
	zlodziej = true;
}

void Pole::zdejmijZlodzieja()
{
	zlodziej = false;
}

string Pole::rodzajSurowca()
{
	return surowiec;
}

int Pole::zbierzSurowce(int ilosc, int wartosc)
{
	if (this->wartosc == wartosc)
		if (!zlodziej) { return ilosc; }
	return 0;
}
