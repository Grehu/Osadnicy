#include "PoleLeaf.hpp"


void PoleLeaf::rysuj(RenderWindow & okno)
{

	if (sprawdzPunkt(okno)) {
		ksztalt->setFillColor(Color(255, 255, 255, 255));
	}
	else {
		ksztalt->setFillColor(Color(128, 128, 128, 255));
	}
	RysunekComponent::rysuj(okno);
}

bool PoleLeaf::sprawdzPunkt(RenderWindow & okno)
{
	if (ksztalt->getGlobalBounds().contains(Vector2f(Mouse::getPosition(okno)))) {
		return true;
	}
	else {
		return false;
	}
}
