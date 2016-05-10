#pragma once
#include <SFML\Graphics.hpp>
#include "RysunekComponent.hpp"

using namespace sf;

class BudynekLeaf : public RysunekComponent {
protected:
	bool podswietlone;
	Color kolorWlasciciela;
public:
	void rysuj(RenderWindow & okno);
	void ustawKolorRamki(Color kolor);
	bool sprawdzPunkt(RenderWindow & okno);
};