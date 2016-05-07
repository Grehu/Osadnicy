#pragma once
#include <SFML\Graphics.hpp>
#include "RysunekComponent.hpp"
#include "BudynekLeaf.h"

class DrogaLeaf : public BudynekLeaf {
private:
	int orientacja;
	bool zbudowane = false;
public:
	void ustawOrientacje(int orientacja);
	void rysuj(RenderWindow & okno);
};