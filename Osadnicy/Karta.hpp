#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;

class Karta {
private:
	Sprite rewers;
	Sprite awers;
	Sprite podswietlone();
public:
	void ustawAwers(Sprite & sprite);
	void ustawRewers(Sprite & sprite);
	void rysujAwers(RenderWindow & okno);
	void rysujRewers(RenderWindow & okno);
};