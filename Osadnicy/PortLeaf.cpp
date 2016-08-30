#include "PortLeaf.hpp"

void PortLeaf::ustawSurowiec(Shape * surowiec)
{
	this->surowiec = surowiec;
}


void PortLeaf::ustawKolory(Color kolor1, Color kolor2)
{
	this->kolor1 = kolor1;
	this->kolor2 = kolor2;
	aktywujMenagerEfektow();
	me->resetujKolory();
	me->dodajKolor(kolor1);
	me->dodajKolor(kolor2);
}

bool PortLeaf::sprawdzPunkt(RenderWindow & okno)
{
	if (ksztalt->getGlobalBounds().contains(Vector2f(Mouse::getPosition(okno)))) {
		podswietlone = true;
		return true;
	}
	else {
		podswietlone = false;
		return false;
	}
}

void PortLeaf::rysuj(RenderWindow & okno, Vector2f * przewijanie)
{
	if (me == nullptr) { me == new MenagerEfektow(Color(55, 55, 55), Color(55, 55, 55)); }
	me->resetujKolory();
	me->dodajKolor(kolor1);
	me->dodajKolor(kolor2);
	me->mieszaj();
	kolorWlasciciela = me->pobierzKolor();
	ksztalt->setOutlineColor(kolorWlasciciela);
	surowiec->setOutlineColor(kolorWlasciciela);
	ksztalt->setOutlineThickness(2.0f);
	surowiec->setOutlineThickness(2.0f);
	ksztalt->setPosition(pozycja + *przewijanie);
	surowiec->setPosition(pozycja + *przewijanie);
	
	if (sprawdzPunkt(okno)) {
		okno.draw(*surowiec);
	}
	else {
		okno.draw(*ksztalt);
	}
	
}

PortLeaf::~PortLeaf()
{
	delete surowiec;
}
