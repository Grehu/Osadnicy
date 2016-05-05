#pragma once
#include <SFML\Graphics.hpp>
#include "RysunekComponent.hpp"

using namespace sf;

class PoleLeaf : public RysunekComponent {
private: 
	void obroc(int stopnie);
public:
	void rysuj(RenderWindow & okno);
	void podswietl(RenderWindow & okno);
	bool sprawdzPunkt(Vector2f punkt);
};