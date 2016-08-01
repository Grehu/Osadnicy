#include "PoleWartosciLeaf.hpp"

Shape * PoleWartosciLeaf::zlodziejGrafika = nullptr;

void PoleWartosciLeaf::nadajZlodziejowiGrafike(Shape  & ksztalt)
{
	zlodziejGrafika = &ksztalt;
}

void PoleWartosciLeaf::przypiszText(Font & font, std::string wartosc)
{

	text = new Text();
	text->setFont(font);
	text->setCharacterSize(56);
	text->setColor(Color(0, 0, 0));
	text->setString(wartosc);
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

	this->ksztalt->setPosition(pozycja + PRZESUNIECIE_POLE_WARTOSCI + *przewijanie);
	//this->ksztalt->move(PRZESUNIECIE_POLE_WARTOSCI);
	okno.draw(*ksztalt);
	
	if (zlodziej) {
		zlodziejGrafika->setPosition(pozycja + PRZESUNIECIE_POLE_WARTOSCI + *przewijanie);
		//zlodziejGrafika->move(PRZESUNIECIE_POLE_WARTOSCI);
		okno.draw(*zlodziejGrafika);
	}
	else {
		text->setPosition(pozycja + PRZESUNIECIE_TEKSTU_WARTOSCI + *przewijanie);
		//text.move(PRZESUNIECIE_TEKSTU_WARTOSCI);
		okno.draw(*text); //ERROR
	}
	
}
