#include "RamkaLeaf.hpp"


void RamkaLeaf::rysuj(RenderWindow & okno)
{
	ksztalt->setPosition(*pozycja);
	okno.draw(*ksztalt);
}

void RamkaLeaf::kolorujRamke(Color kolor)
{
	ksztalt->setFillColor(kolor);
}
