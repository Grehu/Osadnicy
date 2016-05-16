#include "BudynekLeaf.hpp"

void BudynekLeaf::rysuj(RenderWindow & okno, Vector2f * przewijanie)
{
	if (sprawdzPunkt(okno)) {
		ksztalt->setFillColor(Color(255, 255, 255, 255));
	}
	else {
		ksztalt->setFillColor(Color(128, 128, 128, 255));
	}
	ksztalt->setOutlineColor(kolorWlasciciela);
	ksztalt->setOutlineThickness(2.0f);
	ksztalt->setPosition(*pozycja + *przewijanie);
	okno.draw(*ksztalt);
}

void BudynekLeaf::ustawKolorRamki(Color kolor)
{
	kolorWlasciciela = kolor;
}

bool BudynekLeaf::sprawdzPunkt(RenderWindow & okno)
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
