#include "PoleLeaf.hpp"


void PoleLeaf::rysuj(RenderWindow & okno, Vector2f * lokalizacja)
{

	if (sprawdzPunkt(okno)) {
		if (rozjasnienie < 127) { rozjasnienie += 0.2f; }
	}
	else {
		if (rozjasnienie > 0) { rozjasnienie -= 0.2f; }
	}
	ksztalt->setFillColor(Color(128 + rozjasnienie, 128 + rozjasnienie, 128 + rozjasnienie, 255));
	RysunekComponent::rysuj(okno, lokalizacja);
}

Vector2f PoleLeaf::wspolrzedneRogu(int rog)
{
	CircleShape * ksztalt = (CircleShape*) this->ksztalt;
	return ksztalt->getPoint(rog);
}

bool PoleLeaf::sprawdzPunkt(RenderWindow & okno)
{
	if (ksztalt->getGlobalBounds().contains(Vector2f(Mouse::getPosition(okno)))) {
		return true;
	}
	else {
		return false;
	}
}
