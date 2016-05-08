#include "RamkaLeaf.hpp"

void RamkaLeaf::rysuj(RenderWindow & okno)
{
	sprite.setPosition(*pozycja);
	okno.draw(sprite);
}
