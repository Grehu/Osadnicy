#include "PoleLeaf.hpp"


void PoleLeaf::rysuj(RenderWindow & okno, Vector2f * lokalizacja)
{

	if (sprawdzPunkt(okno)) {
		ksztalt->setFillColor(Color(255, 255, 255, 255));
	}
	else {
		ksztalt->setFillColor(Color(128, 128, 128, 255));
	}
	RysunekComponent::rysuj(okno, lokalizacja);
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
