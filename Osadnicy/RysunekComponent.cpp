#include "RysunekComponent.hpp"


void RysunekComponent::ustawPozycje(Vector2f * pozycja)
{
	this->pozycja = pozycja;
}

void RysunekComponent::ustawKsztalt(Shape  & ksztalt)
{
	this->ksztalt = &ksztalt;
}

void RysunekComponent::rysuj(RenderWindow & okno, Vector2f * przewijanie)
{

	ksztalt->setPosition(*pozycja+*przewijanie);
	okno.draw(*ksztalt);
}
