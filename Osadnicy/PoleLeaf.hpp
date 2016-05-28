#pragma once
#include <SFML\Graphics.hpp>
#include "RysunekComponent.hpp"

using namespace sf;

class PoleLeaf : public RysunekComponent {
protected:
	bool podswietlone;
	double rozjasnienie = 0.0f;
public:
	void rysuj(RenderWindow & okno, Vector2f * lokalizacja);
	bool sprawdzPunkt(RenderWindow & okno);
};