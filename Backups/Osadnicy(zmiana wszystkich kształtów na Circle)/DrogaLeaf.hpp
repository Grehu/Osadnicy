#pragma once
#include "RysunekComponent.hpp"

using namespace sf;

class DrogaLeaf : public RysunekComponent {
protected:
	Color kolorWlasciciela;
	int orientacja;
public:
	void ustawKolor(Color kolor);
	void ustawOrientacje(int orientacja);
	void rysuj(RenderWindow & okno);
};