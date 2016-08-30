#include "Konwerter.hpp"

void Konwerter::przypiszBudowniczego(PlanszaBuilder & budowniczy)
{
	this->budowniczy = &budowniczy;
}

void Konwerter::przypiszBudowniczego(PlanszaBuilder * budowniczy)
{
	this->budowniczy = budowniczy;
}

void Konwerter::wczytajSchematS(string & schemat)
{
	this->schematS = schemat;
}

void Konwerter::wczytajSchematS(string * schemat)
{
	this->schematS = *schemat;
}

void Konwerter::przetworzSchemat()
{
	if (plansza != nullptr) {
		delete plansza;
	}
	budowniczy->budujPlansze();
	char znak;
	for (int i = 0; i < schematS.length(); i++) {
		znak = schematS[i];
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
	budowniczy->skoczDo(0, 0);
	
	for (int i = 0; i < schematD.length(); i++) {
			znak = schematD[i];
			switch (znak) {
			case 'N': budowniczy->budujDroge(true); budowniczy->nastepnaKolumna(); break;
			case 'D': budowniczy->budujDroge(false); budowniczy->nastepnaKolumna(); break;
			case '-': budowniczy->nastepnyWiersz(); break;
		}
	}

	budowniczy->skoczDo(0, 0);

	for (int i = 0; i < schematO.length(); i++) {
		znak = schematO[i];
		switch (znak) {
		case 'N': budowniczy->budujObszarMieszkalny(true); budowniczy->nastepnaKolumna(); break;
		case 'O': budowniczy->budujObszarMieszkalny(false); budowniczy->nastepnaKolumna(); break;
		case '-': budowniczy->nastepnyWiersz(); break;
		}
	}

	budowniczy->skoczDo(0, 0);

	for (int i = 0; i < schematP.length(); i++) {
		znak = schematP[i];
		switch (znak) {
		case 'N': budowniczy->budujFejkPort(); budowniczy->nastepnaKolumna(); break;
		case 'P': budowniczy->budujPortZwykly(); budowniczy->nastepnaKolumna(); break;
		case 'Z': budowniczy->budujPortSpecjalistyczny(Surowiec::zboze); budowniczy->nastepnaKolumna(); break;
		case 'G': budowniczy->budujPortSpecjalistyczny(Surowiec::glina); budowniczy->nastepnaKolumna(); break;
		case 'D': budowniczy->budujPortSpecjalistyczny(Surowiec::drewno); budowniczy->nastepnaKolumna(); break;
		case 'K': budowniczy->budujPortSpecjalistyczny(Surowiec::kamien); budowniczy->nastepnaKolumna(); break;
		case 'W': budowniczy->budujPortSpecjalistyczny(Surowiec::welna); budowniczy->nastepnaKolumna(); break;
		case '-': budowniczy->nastepnyWiersz(); break;
			
		}
	}
	plansza = budowniczy->zwrocPlansze();

}

Plansza * Konwerter::zwrocPlansze()
{
	return plansza;
}
