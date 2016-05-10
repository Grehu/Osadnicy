#pragma once
#include <SFML\Graphics.hpp>
#include "RysunekComponent.hpp"

using namespace sf;

class PoleLeaf : public RysunekComponent {
protected:
	bool podswietlone;
public:
	void rysuj(RenderWindow & okno);
	bool sprawdzPunkt(RenderWindow & okno);
};