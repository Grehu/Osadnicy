#pragma once
#include <SFML/Graphics.hpp>
#include <cstring>
#include "RysunekComponent.hpp"

using namespace sf;

class PoleWartosciLeaf : public RysunekComponent {
private: 
	bool zlodziej = false;
	Sprite * zlodziejGrafika;
	Text text;
public:
	void nadajZlodziejowiGrafike(Sprite & sprite);
	void przypiszText(Text & text);
	void ustawZlodzieja();
	void zdejmijZlodzieja();
	void rysuj(RenderWindow & okno);
};