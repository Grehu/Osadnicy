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
	this->sprite.setPosition(*pozycja);
	this->sprite.move(Vector2f(128.0f, 128.0f));
	okno.draw(sprite);
	text.setPosition(*pozycja);
	//text.move(Vector2f(128.0f, 128.0f));
	if (zlodziej) {
		zlodziejGrafika->setPosition(*pozycja);
		zlodziejGrafika->move(Vector2f(128.0f, 128.0f));
		okno.draw(*zlodziejGrafika);
	}
}
