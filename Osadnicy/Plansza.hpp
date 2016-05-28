#pragma once
#include <SFML/Graphics.hpp>
#include <vector>

#include "Kostka.hpp"

#include "Obszar.hpp"

class Plansza {
protected:
	vector<Kostka*> kostki;
	vector<vector<Obszar<Pole>>> pola;
	vector<vector<Obszar<Droga>>> drogi;
	vector<vector<Obszar<Osada>>> osady;
	vector<vector<Obszar<Port>>> porty;
public:
	void dodajKostke(int iloscScian);
	int losuj();
	int ileKostek();
	Obszar<Pole> * pobierzPole(const Koordynaty & koordynaty);
	Obszar<Droga> * pobierzDroge(const Koordynaty & koordynaty);
	Obszar<Osada> * pobierzOsade(const Koordynaty & koordynaty);
	Obszar<Port> * pobierzPort(const Koordynaty & koordynaty);
};