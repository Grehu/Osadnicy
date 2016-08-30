#pragma once
#include <SFML/Graphics.hpp>
#include <vector>

#include "Kostka.hpp"

#include "Obszar.hpp"

#include "RysunekComposite.hpp"
#include "PortLeaf.hpp"
#include "DrogaLeaf.hpp"
#include "BudynekLeaf.hpp"

class Plansza {
protected:
	
	vector<Kostka*> kostki;
	vector<vector<Obszar<Pole>>> pola;
	vector<vector<Obszar<Droga>>> drogi;
	vector<vector<Obszar<Osada>>> osady;
	vector<vector<Obszar<Port>>> porty;
public:
	friend class PlanszaBuilder;
	friend class LosowaPlanszaBuilder;
	void dodajKostke(int iloscScian);
	int losuj();
	int ileKostek();
	Obszar<Pole> * pobierzPole(const Koordynaty & koordynaty);
	Obszar<Droga> * pobierzDroge(const Koordynaty & koordynaty);
	Obszar<Osada> * pobierzOsade(const Koordynaty & koordynaty);
	Obszar<Port> * pobierzPort(const Koordynaty & koordynaty);
	void wyswietlPola(RenderWindow & okno, Vector2f & przewijanie);
	void wyswietlPlansze(RenderWindow & okno, Vector2f & przewijanie);
	void pobierzOpis();

	void wstawPole(Obszar<Pole> pole);
	void wstawDroge(Obszar<Droga> droga);
	void wstawOsade(Obszar<Osada> osada);
	void wstawPort(Obszar<Port> port);
};