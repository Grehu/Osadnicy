#include "RysunekComponent.hpp"


void RysunekComponent::aktywujMenagerEfektow()
{
	if (me != nullptr) { delete me; }
	me = new MenagerEfektow(Color(55,55,55,255), Color(55, 55, 55, 255));
}

void RysunekComponent::ustawPozycje(Vector2f pozycja)
{
	this->pozycja = pozycja;
}

void RysunekComponent::ustawKsztalt(Shape  * ksztalt)
{
	this->ksztalt = ksztalt;
}

void RysunekComponent::rysuj(RenderWindow & okno, Vector2f * przewijanie)
{

	ksztalt->setPosition(pozycja+*przewijanie);
	okno.draw(*ksztalt);
}

void RysunekComponent::czyscWskazniki()
{
	delete ksztalt;
}
