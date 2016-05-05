#pragma once
#include <SFML/Graphics.hpp>
#include "RysunekComponent.hpp"

class PoleWartosciLeaf : public RysunekComponent {
private: 
	int wartosc;
	bool zlodziej;
	static Sprite * zlodziejGrafika;
public:
	void rysuj(RenderWindow okno);
};