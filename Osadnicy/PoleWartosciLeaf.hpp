#pragma once
#include <SFML/Graphics.hpp>
#include <cstring>
#include "RysunekComponent.hpp"

using namespace sf;

class PoleWartosciLeaf : public RysunekComponent {
protected:
	bool zlodziej = false;
	static Shape  * zlodziejGrafika;
	Text * text;
public:
	static void nadajZlodziejowiGrafike(Shape  & ksztalt);
	void przypiszText(Font & font, std::string wartosc);
	void ustawZlodzieja();
	void zdejmijZlodzieja();
	void rysuj(RenderWindow & okno, Vector2f * przewijanie);
};

