#include "BudynekLeaf.h"

void BudynekLeaf::zbuduj()
{
	zbudowane = true;
}

void BudynekLeaf::ustawKolor(Color kolor)
{
	this->kolor = kolor;
}

void BudynekLeaf::rysuj(RenderWindow & okno)
{
	if (zbudowane) {
		sprite.setColor(Color(255, 255, 255, 128));
	}
	else {
		sprite.setColor(Color(255, 255, 255, 255));
	}
	sprite.setPosition(*pozycja);
	okno.draw(sprite);
}
