#include "Gracz.hpp"

int Gracz::liczbaGraczy = 0;

Gracz::Gracz(string kolor)
{
	liczbaGraczy++;
	ID = liczbaGraczy;
	this->kolor = kolor;
	surowce[Surowiec::drewno] = 0;
	surowce[Surowiec::glina] = 0;
	surowce[Surowiec::kamien] = 0;
	surowce[Surowiec::welna] = 0;
	surowce[Surowiec::zboze] = 0;

	kartyRozwoju[Rozwoj::rycerz] = 0;
	kartyRozwoju[Rozwoj::monopol] = 0;
	kartyRozwoju[Rozwoj::droga] = 0;
	kartyRozwoju[Rozwoj::urodzaj] = 0;
	kartyRozwoju[Rozwoj::zwyciestwo] = 0;
}

void Gracz::zbierzSurowce(int wartosc)
{
	for (int i = 0; i < osady.size(); i++) {
		Dostawa nowa = osady[i]->zbierzSurowce(wartosc);
		for (int j = 0; j < 3; j++) {
			surowce[nowa.nazwa[j]] += nowa.ilosc[j];
		}
	}
}

void Gracz::dodajOsade(Osada * osada)
{
	osady.push_back(osada);
}

void Gracz::dodajDroge(Droga * droga)
{
	drogi.push_back(droga);
}
