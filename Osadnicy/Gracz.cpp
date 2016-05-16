#include "Gracz.hpp"

int Gracz::liczbaGraczy = 0;

Gracz::Gracz(string kolor)
{
	liczbaGraczy++;
	ID = liczbaGraczy;
	this->kolor = kolor;
	surowce["drewno"] = 0;
	surowce["glina"] = 0;
	surowce["kamien"] = 0;
	surowce["welna"] = 0;
	surowce["zboze"] = 0;

	kartyRozwoju["rycerz"] = 0;
	kartyRozwoju["monopol"] = 0;
	kartyRozwoju["droga"] = 0;
	kartyRozwoju["urodzaj"] = 0;
	kartyRozwoju["zwyciestwo"] = 0;
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
