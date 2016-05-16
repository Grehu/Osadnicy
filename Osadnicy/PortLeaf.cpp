#include "PortLeaf.hpp"

void PortLeaf::ustawSurowiec(Shape & surowiec)
{
	this->surowiec = &surowiec;
}

void PortLeaf::rysuj(RenderWindow & okno, Vector2f * przewijanie)
{
	if (sprawdzPunkt(okno)) {
		surowiec->setOutlineColor(kolorWlasciciela);
		surowiec->setOutlineThickness(5.0f);
		surowiec->setPosition(*pozycja + *przewijanie);
		ksztalt->setFillColor(Color(255, 255, 255, 255));
		okno.draw(*surowiec);
	}
	else {
		ksztalt->setOutlineColor(kolorWlasciciela);
		ksztalt->setOutlineThickness(5.0f);
		ksztalt->setPosition(*pozycja + *przewijanie);
		ksztalt->setFillColor(Color(128, 128, 128, 255));
		okno.draw(*ksztalt);
	}
	
}
