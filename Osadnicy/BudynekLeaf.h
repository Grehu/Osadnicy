#pragma once
#include <SFML\Graphics.hpp>
#include "RysunekComponent.hpp"

class BudynekLeaf : public RysunekComponent {
private:
	bool zbudowane = false;
public:
	void zbuduj();
	virtual void rysuj(RenderWindow & okno);
};