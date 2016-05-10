#pragma once
#include <SFML\Graphics.hpp>
#include "RysunekComponent.hpp"

class BudynekComposite : public RysunekComponent {
private:
	bool zbudowane = false;
	Color kolor;
	RysunekComponent * budynek;
	RysunekComponent * ramka;
public:
	void zbuduj();
	void ustawKolor(Color kolor);
	void ustawBudynek(RysunekComponent & budynek);
	void ustawRamke(RysunekComponent & ramka);
	virtual void rysuj(RenderWindow & okno);
};