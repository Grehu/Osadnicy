#include "DrogaLeaf.hpp"

void DrogaLeaf::ustawKolor(Color kolor)
{
	kolorWlasciciela = kolor;
}

void DrogaLeaf::rysuj(RenderWindow & okno, Vector2f * przewijanie)
{
	ksztalt->setFillColor(kolorWlasciciela);
	ksztalt->setPosition(pozycja+*przewijanie);
	okno.draw(*ksztalt);
}
