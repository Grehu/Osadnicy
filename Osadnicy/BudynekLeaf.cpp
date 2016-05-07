#include "BudynekLeaf.h"

void BudynekLeaf::zbuduj()
{
	zbudowane = true;
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
