#include "PoleLeaf.hpp"

void PoleLeaf::rysuj(RenderWindow & okno)
{
	if (sprawdzPunkt(okno)) {
		sprite.setColor(Color(255, 255, 200, 255));
	}
	else {
		sprite.setColor(Color(255, 255, 255, 255));
	}
	RysunekComponent::rysuj(okno);
}

bool PoleLeaf::sprawdzPunkt(RenderWindow & okno)
{
	if (sprite.getGlobalBounds().contains(Vector2f(Mouse::getPosition(okno)))) {
		return true;
	}
	else {
		return false;
	}
}
