#include "PoleWartosciLeaf.hpp"

void PoleWartosciLeaf::nadajZlodziejowiGrafike(Sprite & sprite)
{
	zlodziejGrafika = &sprite;
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

void PoleWartosciLeaf::rysuj(RenderWindow okno)
{
	RysunekComponent::rysuj(okno);
	text.setPosition(*pozycja);
	if (zlodziej) {
		okno.draw(*zlodziejGrafika);
	}
}
