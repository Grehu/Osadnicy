#pragma once
#include <SFML/Graphics.hpp>
#include "RysunekComponent.hpp"

using namespace sf;

class RamkaLeaf : public RysunekComponent {
public: 
	void rysuj(RenderWindow & okno, Vector2f * przewijanie);
	void kolorujRamke(Color kolor);
};