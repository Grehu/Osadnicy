#include "PoleWartosciLeaf.hpp"



void PoleWartosciLeaf::nadajZlodziejowiGrafike(Shape  & ksztalt)
{
	zlodziejGrafika = &ksztalt;
}

void PoleWartosciLeaf::przypiszText(Text & text)
{
	this->text = &text;
}

void PoleWartosciLeaf::ustawZlodzieja()
{
	zlodziej = true;
}

void PoleWartosciLeaf::zdejmijZlodzieja()
{
	zlodziej = false;
}

void PoleWartosciLeaf::rysuj(RenderWindow & okno, Vector2f * przewijanie)
{

	this->ksztalt->setPosition(*pozycja + PRZESUNIECIE_POLE_WARTOSCI + *przewijanie);
	//this->ksztalt->move(PRZESUNIECIE_POLE_WARTOSCI);
	okno.draw(*ksztalt);
	
	if (zlodziej) {
		zlodziejGrafika->setPosition(*pozycja + PRZESUNIECIE_POLE_WARTOSCI + *przewijanie);
		//zlodziejGrafika->move(PRZESUNIECIE_POLE_WARTOSCI);
		okno.draw(*zlodziejGrafika);
	}
	else {
		text->setPosition(*pozycja + PRZESUNIECIE_TEKSTU_WARTOSCI + *przewijanie);
		//text.move(PRZESUNIECIE_TEKSTU_WARTOSCI);
		okno.draw(*text);
	}
	
}
