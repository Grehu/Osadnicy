#include "RysunekComponent.hpp"


void RysunekComponent::ustawPozycje(Vector2f & pozycja)
{
	this->pozycja = &pozycja;
}

void RysunekComponent::ustawKsztalt(Shape  & ksztalt)
{
	this->ksztalt = &ksztalt;
}

void RysunekComponent::rysuj(RenderWindow & okno)
{

	ksztalt->setPosition(*pozycja);
	okno.draw(*ksztalt);
}
