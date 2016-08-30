#include "Plansza.hpp"
#include <iostream>

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

void Plansza::wyswietlPola(RenderWindow & okno, Vector2f & przewijanie)
{
	std::cout << "Rozmiar X: " << pola.size() << std::endl;
	for (int i = 0; i < pola.size(); i++) {
		std::cout << "Rozmiar Y: " <<pola[i].size() << std::endl;
		for (int j = 0; j < pola[i].size(); j++) {
			pola[i][j].grafika->rysuj(okno, &przewijanie);
		}
	}
}
void Plansza::wyswietlPlansze(RenderWindow & okno, Vector2f & przewijanie)
{
	for (int i = 0; i < pola.size(); i++) {
		for (int j = 0; j < pola[i].size(); j++) {
			pola[i][j].grafika->rysuj(okno, &przewijanie);
//			osady[i][j].grafika->rysuj(okno, &przewijanie);
//			porty[i][j].grafika->rysuj(okno, &przewijanie);
		}
	}
	for (int i = 0; i < drogi.size(); i++) {
		for (int j = 0; j < drogi[i].size(); j++) {
			if(drogi[i][j].odmiana==Odmiana::miejsceDostepne) drogi[i][j].grafika->rysuj(okno, &przewijanie);
			//			osady[i][j].grafika->rysuj(okno, &przewijanie);
			//			porty[i][j].grafika->rysuj(okno, &przewijanie);
		}
	}
	for (int i = 0; i < osady.size(); i++) {
		for (int j = 0; j < osady[i].size(); j++) {
			if (osady[i][j].odmiana == Odmiana::miejsceDostepne) osady[i][j].grafika->rysuj(okno, &przewijanie);
			//			osady[i][j].grafika->rysuj(okno, &przewijanie);
			//			porty[i][j].grafika->rysuj(okno, &przewijanie);
		}
	}
	for (int i = 0; i < porty.size(); i++) {
		for (int j = 0; j < porty[i].size(); j++) {
			if (porty[i][j].odmiana == Odmiana::wybrzeze) porty[i][j].grafika->rysuj(okno, &przewijanie);
			//			osady[i][j].grafika->rysuj(okno, &przewijanie);
			//			porty[i][j].grafika->rysuj(okno, &przewijanie);
		}
	}
}

void Plansza::pobierzOpis()
{
	cout << "Plansza zawiera: " << endl;
	cout << "Pola: " << endl;
	cout << "- wiersze: " << pola.size() << endl;
	if (!pola.empty()) { cout << "- kolumny: " << pola[0].size() << endl; }
	/*cout << "Drogi: " << endl;
	cout << "- wiersze: " << drogi.size() << endl;
	if (!pola.empty()) { cout << "- kolumny: " << drogi[0].size() << endl; }
	cout << "Osady: " << endl;
	cout << "- wiersze: " << osady.size() << endl;
	if (!pola.empty()) { cout << "- kolumny: " << osady[0].size() << endl; }
	cout << "Porty: " << endl;
	cout << "- wiersze: " << porty.size() << endl;
	if (!pola.empty()) { cout << "- kolumny: " << porty[0].size() << endl; }*/
}

void Plansza::wstawPole(Obszar<Pole> pole)
{
	if (pola.empty()) {
		vector<Obszar<Pole>> nowy;
		pola.push_back(nowy);
	}
	pola[pola.size() - 1].push_back(pole);
}

void Plansza::wstawDroge(Obszar<Droga> droga)
{
	if (drogi.empty()) {
		vector<Obszar<Droga>> nowy;
		drogi.push_back(nowy);
	}
	drogi[drogi.size() - 1].push_back(droga);
}

void Plansza::wstawOsade(Obszar<Osada> osada)
{
	if (osady.empty()) {
		vector<Obszar<Osada>> nowy;
		osady.push_back(nowy);
	}
	osady[osady.size() - 1].push_back(osada);
}

void Plansza::wstawPort(Obszar<Port> port)
{
	if (porty.empty()) {
		vector<Obszar<Port>> nowy;
		porty.push_back(nowy);
	}
	porty[porty.size() - 1].push_back(port);
}



void Plansza::dodajKostke(int iloscScian)
{
	Kostka * kostka = new Kostka(iloscScian);
	kostki.push_back(kostka);
}
