#pragma once
#include "RysunekComponent.hpp"

using namespace sf;

class DrogaLeaf : public RysunekComponent {
protected:
	Color kolorWlasciciela;
public:
	void ustawKolor(Color kolor);
	void rysuj(RenderWindow & okno); //TO REBUILD
};