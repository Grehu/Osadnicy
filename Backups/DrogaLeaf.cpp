#include "DrogaLeaf.hpp"

void DrogaLeaf::ustawOrientacje(int orientacja)
{
	this->orientacja = orientacja;
}

void DrogaLeaf::rysuj(RenderWindow & okno)
{
	ksztalt->setRotation(orientacja);
	RysunekComponent::rysuj(okno);
}
