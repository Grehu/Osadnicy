#include "PanelPrzewijania.hpp"

PanelPrzewijania::PanelPrzewijania(Kierunek kierunek)
{
	this->kierunek = kierunek;
	switch (kierunek) {
	case Kierunek::dol: ksztalt = new RectangleShape(Vector2f((float)Ustawienia::szerokosc, 10.0f)); ksztalt->setPosition(Vector2f(0.0f, Ustawienia::wysokosc-10.0f)); break;
	case Kierunek::gora: ksztalt = new RectangleShape(Vector2f((float)Ustawienia::szerokosc, 10.0f)); ksztalt->setPosition(Vector2f(0.0f, 0.0f)); break;
	case Kierunek::lewo: ksztalt = new RectangleShape(Vector2f(10.0f, (float)Ustawienia::wysokosc)); ksztalt->setPosition(Vector2f(0.0f, 0.0f)); break;
	case Kierunek::prawo: ksztalt = new RectangleShape(Vector2f(10.0f, (float)Ustawienia::wysokosc)); ksztalt->setPosition(Vector2f(Ustawienia::szerokosc-10.0f, 0.0f)); break;
	}
	///TO CHANGE
	ksztalt->setFillColor(Color::Black);
}

void PanelPrzewijania::przewin(RenderWindow & okno)
{
	if (ksztalt->getGlobalBounds().contains(Vector2f(Mouse::getPosition(okno)))) {
		switch (kierunek) {
		case Kierunek::dol: Ustawienia::przewijanie -= Vector2f(0.0f, 1.5f); break;
		case Kierunek::gora: Ustawienia::przewijanie += Vector2f(0.0f, 1.5f); break;
		case Kierunek::lewo: Ustawienia::przewijanie += Vector2f(1.5f, 0.0f); break;
		case Kierunek::prawo: Ustawienia::przewijanie -= Vector2f(1.5f, 0.0f); break;
		}
	}
}

void PanelPrzewijania::wyswietl(RenderWindow & okno)
{
	okno.draw(*ksztalt);
}
