#include "PortLeaf.hpp"

void PortLeaf::ustawSurowiec(Shape & surowiec)
{
	this->surowiec = &surowiec;
}

void PortLeaf::ustawKolory(Color * kolor1, Color * kolor2)
{
	this->kolor1 = kolor1;
	this->kolor2 = kolor2;
}

void PortLeaf::rysuj(RenderWindow & okno, Vector2f * przewijanie)
{
	if (pierwszyKolor < 0.1f) { przekolorowanie = true; }
	if (drugiKolor < 0.1f) { przekolorowanie = false; }
	if (przekolorowanie) { pierwszyKolor += 0.0005f; drugiKolor -= 0.0005f; }
	else { pierwszyKolor -= 0.0005f; drugiKolor += 0.0005f; }
	float r = (kolor1->r * pierwszyKolor) + (kolor2->r * drugiKolor);
	float g = (kolor1->g * pierwszyKolor) + (kolor2->g * drugiKolor);
	float b = (kolor1->b * pierwszyKolor) + (kolor2->b * drugiKolor);
	Color kolorWynikowy = Color(r ,g ,b);
	if (sprawdzPunkt(okno)) {
		if (faza > 254.0f) { przyrost = false; }
		if (faza < 1.0f) { przyrost = true; }
		if (przyrost) { faza += 0.001f; }
		else { faza -= 0.001f; }

		surowiec->setOutlineColor(kolorWynikowy);
		surowiec->setOutlineThickness(2.0f);
		surowiec->setPosition(*pozycja + *przewijanie);
		surowiec->setFillColor(Color(255, 255, 255, przyrost));

		ksztalt->setOutlineColor(kolorWynikowy);
		ksztalt->setOutlineThickness(2.0f);
		ksztalt->setPosition(*pozycja + *przewijanie);
		ksztalt->setFillColor(Color(255, 255, 255, 255 - przyrost));

		okno.draw(*surowiec);
		okno.draw(*ksztalt);
	}
	else {
		ksztalt->setOutlineColor(kolorWynikowy);
		ksztalt->setOutlineThickness(1.0f);
		ksztalt->setPosition(*pozycja + *przewijanie);
		ksztalt->setFillColor(Color(128, 128, 128, 255));
		okno.draw(*ksztalt);
	}
	
}
