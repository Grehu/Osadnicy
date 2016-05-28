#include "DrogaLeaf.hpp"

void DrogaLeaf::ustawKolor(Color kolor)
{
	kolorWlasciciela = kolor;
}

void DrogaLeaf::rysuj(RenderWindow & okno)
{
	ksztalt->setFillColor(kolorWlasciciela);
	ksztalt->setPosition(*pozycja);
	okno.draw(*ksztalt);
}
