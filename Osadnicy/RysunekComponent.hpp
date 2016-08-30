#pragma once
#include <SFML/Graphics.hpp>
#include "Stale.hpp"
#include "MenagerEfektow.hpp"

using namespace sf;

class RysunekComponent {
protected: 
	Shape * ksztalt;
	Vector2f pozycja;
	MenagerEfektow * me = nullptr;

public:
	void aktywujMenagerEfektow();
	void ustawPozycje(Vector2f pozycja);
	void ustawKsztalt(Shape  * ksztalt);
	virtual void rysuj(RenderWindow & okno, Vector2f * przewijanie);
	void czyscWskazniki();
	
};