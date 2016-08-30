#include "BudynekLeaf.hpp"

void BudynekLeaf::rysuj(RenderWindow & okno, Vector2f * przewijanie)
{
	wybierzObraz();
	if (sprawdzPunkt(okno)) {
		if (rozjasnienie < 127) { rozjasnienie += 0.5f; }
	}
	else {
		if (rozjasnienie > 0) { rozjasnienie -= 0.5f; }
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

void BudynekLeaf::wybierzObraz()
{
	switch (stopienRozwoju) {
	case 0: ksztalt = zerowyStopien; break;
	case 1: ksztalt = pierwszyStopien; break;
	case 2: ksztalt = drugiStopien; break;
	default: break;
	}
}

void BudynekLeaf::rozbuduj()
{
	if (stopienRozwoju < 2) { stopienRozwoju++; } 
}

void BudynekLeaf::ustawGrafiki(Shape * grafika1, Shape * grafika2, Shape * grafika3)
{
	zerowyStopien = grafika1;
	pierwszyStopien = grafika2;
	drugiStopien = grafika3;
}

BudynekLeaf::~BudynekLeaf()
{
	delete zerowyStopien;
	delete pierwszyStopien;
	delete drugiStopien;
}
