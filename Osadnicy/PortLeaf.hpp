#pragma once
#include <SFML/Graphics.hpp>
#include "RysunekComponent.hpp"
#include "BudynekLeaf.hpp"

class PortLeaf : public BudynekLeaf {
protected:
	Shape * surowiec;
public:
	void ustawSurowiec(Shape & surowiec);
	void rysuj(RenderWindow & okno, Vector2f * przewijanie);
};

