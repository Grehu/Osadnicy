#pragma once
#include <SFML/Graphics.hpp>
#include "Stale_i_Operatory.hpp"

using namespace sf;

class RysunekComponent {
protected: 
	Shape * ksztalt;
	Vector2f * pozycja;
public:
	void ustawPozycje(Vector2f * pozycja);
	void ustawKsztalt(Shape  & ksztalt);
	virtual void rysuj(RenderWindow & okno, Vector2f * przewijanie);
};