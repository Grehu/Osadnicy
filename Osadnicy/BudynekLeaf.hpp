#pragma once
#include <SFML\Graphics.hpp>
#include "RysunekComponent.hpp"

using namespace sf;

class BudynekLeaf : public RysunekComponent {
protected:
	bool podswietlone;
	Color * kolorWlasciciela;
	double rozjasnienie = 0.0f;
public:
	void rysuj(RenderWindow & okno, Vector2f * przewijanie);
	void ustawKolorRamki(Color * kolor);
	bool sprawdzPunkt(RenderWindow & okno);
};