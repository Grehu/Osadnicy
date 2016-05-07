#include "DrogaLeaf.hpp"

void DrogaLeaf::ustawOrientacje(int orientacja)
{
	this->orientacja = orientacja;
}

void DrogaLeaf::rysuj(RenderWindow & okno)
{
	sprite.setRotation(orientacja);
	BudynekLeaf::rysuj(okno);
}
