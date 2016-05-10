#include "DrogaLeaf.hpp"

void DrogaLeaf::ustawKolor(Color kolor)
{
	kolorWlasciciela = kolor;
}

void DrogaLeaf::ustawOrientacje(int orientacja)
{
	this->orientacja = orientacja;
}

void DrogaLeaf::rysuj(RenderWindow & okno)
{
	ksztalt->setFillColor(kolorWlasciciela);
	ksztalt->setPosition(*pozycja);
	ksztalt->setRotation(orientacja);
	okno.draw(*ksztalt);
}
