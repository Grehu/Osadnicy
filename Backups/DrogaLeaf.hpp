#pragma once
#include <SFML\Graphics.hpp>
#include "RysunekComponent.hpp"
#include "BudynekLeaf.hpp"

class DrogaLeaf : public RysunekComponent {
private:
	int orientacja;
	
	bool zbudowane = false;
public:
	void ustawOrientacje(int orientacja);
	void rysuj(RenderWindow & okno);
};