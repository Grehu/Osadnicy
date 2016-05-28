#include "Plansza.hpp"

int Plansza::losuj()
{
	int wynik = 0;
	for (int i = 0; i < kostki.size(); i++) {
		wynik += kostki[i]->losujLiczbe();
	}
	return wynik;
}

int Plansza::ileKostek()
{
	return kostki.size();
}

Obszar<Pole> * Plansza::pobierzPole(const Koordynaty & koordynaty)
{
	if (pola.size() > koordynaty.x && pola[koordynaty.x].size() > koordynaty.y) {
		return &pola[koordynaty.x][koordynaty.y];
	}
	else { return nullptr; }
}

Obszar<Droga>* Plansza::pobierzDroge(const Koordynaty & koordynaty)
{
	if (drogi.size() > koordynaty.x && drogi[koordynaty.x].size() > koordynaty.y) {
		return &drogi[koordynaty.x][koordynaty.y];
	}
	else { return nullptr; }
}

Obszar<Osada>* Plansza::pobierzOsade(const Koordynaty & koordynaty)
{
	if (osady.size() > koordynaty.x && osady[koordynaty.x].size() > koordynaty.y) {
		return &osady[koordynaty.x][koordynaty.y];
	}
	else { return nullptr; }
}

Obszar<Port>* Plansza::pobierzPort(const Koordynaty & koordynaty)
{
	if (porty.size() > koordynaty.x && porty[koordynaty.x].size() > koordynaty.y) {
		return &porty[koordynaty.x][koordynaty.y];
	}
	else { return nullptr; }
}

void Plansza::dodajKostke(int iloscScian)
{
	Kostka * kostka = new Kostka(iloscScian);
	kostki.push_back(kostka);
}
