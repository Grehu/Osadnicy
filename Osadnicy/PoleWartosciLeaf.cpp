#include "PoleWartosciLeaf.hpp"



void PoleWartosciLeaf::nadajZlodziejowiGrafike(Shape  & ksztalt)
{
	zlodziejGrafika = &ksztalt;
}

void PoleWartosciLeaf::przypiszText(Text & text)
{
	this->text = text;
}

void PoleWartosciLeaf::ustawZlodzieja()
{
	zlodziej = true;
}

void PoleWartosciLeaf::zdejmijZlodzieja()
{
	zlodziej = false;
}

void PoleWartosciLeaf::rysuj(RenderWindow & okno)
{

	this->ksztalt->setPosition(*pozycja);
	this->ksztalt->move(Vector2f(94.0f, 94.0f));
	okno.draw(*ksztalt);
	
	if (zlodziej) {
		zlodziejGrafika->setPosition(*pozycja);
		zlodziejGrafika->move(Vector2f(94.0f, 94.0f));
		okno.draw(*zlodziejGrafika);
	}
	else {
		text.setPosition(*pozycja);
		text.move(Vector2f(105.0f, 90.0f));
		okno.draw(text);
	}
	
}
