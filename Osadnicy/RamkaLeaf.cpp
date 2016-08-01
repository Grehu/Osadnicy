#include "RamkaLeaf.hpp"


void RamkaLeaf::rysuj(RenderWindow & okno, Vector2f * przewijanie)
{
	ksztalt->setPosition(pozycja + *przewijanie);
	okno.draw(*ksztalt);
}
