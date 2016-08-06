#include "Konwerter.hpp"

void Konwerter::przypiszBudowniczego(PlanszaBuilder & budowniczy)
{
	this->budowniczy = &budowniczy;
}

void Konwerter::przypiszBudowniczego(PlanszaBuilder * budowniczy)
{
	this->budowniczy = budowniczy;
}

void Konwerter::wczytajSchemat(string & schemat)
{
	this->schemat = schemat;
}

void Konwerter::wczytajSchemat(string * schemat)
{
	this->schemat = *schemat;
}

void Konwerter::przetworzSchemat()
{
	if (plansza != nullptr) {
		delete plansza;
	}
	budowniczy->budujPlansze();
	char znak;
	for (int i = 0; i < schemat.length(); i++) {
		znak = schemat[i];
		switch (znak) {
		case 'N': budowniczy->nastepnaKolumna(); break;
		case '-': budowniczy->nastepnyWiersz(); break;
		case 'M': budowniczy->budujMorze(); budowniczy->nastepnaKolumna(); break;
		case 'D': budowniczy->budujPole(Surowiec::drewno); budowniczy->nastepnaKolumna(); break;
		case 'G': budowniczy->budujPole(Surowiec::glina); budowniczy->nastepnaKolumna(); break;
		case 'Z': budowniczy->budujPole(Surowiec::zboze); budowniczy->nastepnaKolumna(); break;
		case 'K': budowniczy->budujPole(Surowiec::kamien); budowniczy->nastepnaKolumna(); break;
		case 'W': budowniczy->budujPole(Surowiec::welna); budowniczy->nastepnaKolumna(); break;
		case 'P': budowniczy->budujPustynie(); budowniczy->nastepnaKolumna(); break;
		}
	}
	plansza = budowniczy->zwrocPlansze();
}

Plansza * Konwerter::zwrocPlansze()
{
	return plansza;
}
