#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;

class Karta {
private:
	ConvexShape  rewers;
	ConvexShape  awers;
	ConvexShape  podswietlone();
public:
	void ustawAwers(ConvexShape  & ksztalt);
	void ustawRewers(ConvexShape  & ksztalt);
	void rysujAwers(RenderWindow & okno);
	void rysujRewers(RenderWindow & okno);
};