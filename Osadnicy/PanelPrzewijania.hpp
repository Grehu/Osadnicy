#pragma once
#include <SFML/Graphics.hpp>
#include "Kierunek.hpp"
#include "Ustawienia.hpp"
using namespace sf;



class PanelPrzewijania {
private:
	Shape * ksztalt;
	Kierunek kierunek;
public:
	PanelPrzewijania(Kierunek kierunek);
	void przewin(RenderWindow & okno);
	void wyswietl(RenderWindow & okno);

};