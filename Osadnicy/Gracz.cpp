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
