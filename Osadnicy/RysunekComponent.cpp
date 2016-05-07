#include "RysunekComponent.hpp"

void RysunekComponent::ustawPozycje(Vector2f & pozycja)
{
	this->pozycja = &pozycja;
}

void RysunekComponent::ustawSprite(Sprite & sprite)
{
	this->sprite = sprite;
}

void RysunekComponent::rysuj(RenderWindow & okno)
{
	sprite.setPosition(*pozycja);
	okno.draw(sprite);
}
