#pragma once
#include <SFML/Graphics.hpp>
#include "RysunekComponent.hpp"
#include "BudynekLeaf.hpp"

class PortLeaf : public BudynekLeaf{
protected:
	Shape * surowiec;
	float faza = 0.0f;
	float pierwszyKolor = 0.0f;
	float drugiKolor = 1.0f;
	bool przyrost = true;
	bool przekolorowanie = true;
	Color * kolor1;
	Color * kolor2;
public:
	void ustawSurowiec(Shape & surowiec);
	void ustawKolory(Color * kolor1, Color * kolor2);
	void rysuj(RenderWindow & okno, Vector2f * przewijanie);
};

