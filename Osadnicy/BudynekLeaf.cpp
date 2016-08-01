#include "BudynekLeaf.hpp"

void BudynekLeaf::rysuj(RenderWindow & okno, Vector2f * przewijanie)
{
	if (sprawdzPunkt(okno)) {
		if (rozjasnienie < 127) { rozjasnienie += 0.2f; }
	}
	else {
		if (rozjasnienie > 0) { rozjasnienie -= 0.2f; }
	}
	ksztalt->setFillColor(Color(128 + rozjasnienie, 128 + rozjasnienie, 128 + rozjasnienie, 255));
	ksztalt->setOutlineColor(kolorWlasciciela);
	ksztalt->setOutlineThickness(2.0f);
	ksztalt->setPosition(pozycja + *przewijanie);
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
