#pragma once
#include <SFML/Graphics.hpp>
#include <cstring>
#include "RysunekComponent.hpp"

using namespace sf;

class PoleWartosciLeaf : public RysunekComponent {
protected:
	bool zlodziej = false;
	Shape  * zlodziejGrafika;
	Text text;
public:
	void nadajZlodziejowiGrafike(Shape  & ksztalt);
	void przypiszText(Text & text);
	void ustawZlodzieja();
	void zdejmijZlodzieja();
	void rysuj(RenderWindow & okno);
};