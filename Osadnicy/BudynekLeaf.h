#pragma once
#include <SFML\Graphics.hpp>
#include "RysunekComponent.hpp"

class BudynekLeaf : public RysunekComponent {
private:
	bool zbudowane = false;
	Color kolor;
public:
	void zbuduj();
	void ustawKolor(Color kolor);
	virtual void rysuj(RenderWindow & okno);
};