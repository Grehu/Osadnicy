#include "PortLeaf.hpp"

void PortLeaf::ustawSurowiec(Shape & surowiec)
{
	this->surowiec = &surowiec;
}

void PortLeaf::rysuj(RenderWindow & okno)
{
	ksztalt->setOutlineColor(kolorWlasciciela);
	ksztalt->setOutlineThickness(5.0f);
	ksztalt->setPosition(*pozycja);
	if (sprawdzPunkt(okno)) {
		//ksztalt->setFillColor(Color(255, 255, 255, 255));
		okno.draw(*surowiec);
	}
	else {
		ksztalt->setFillColor(Color(128, 128, 128, 255));
		okno.draw(*ksztalt);
	}
	
}
