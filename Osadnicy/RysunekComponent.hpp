#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;

class RysunekComponent {
protected: 
	Sprite sprite;
	Vector2f * pozycja;
public:
	void ustawPozycje(Vector2f & pozycja);
	void ustawSprite(Sprite & sprite);
	virtual void rysuj(RenderWindow & okno);
};