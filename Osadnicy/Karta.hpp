#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;

class Karta {
private:
	CircleShape  rewers;
	CircleShape  awers;
	CircleShape  podswietlone();
public:
	void ustawAwers(CircleShape  & ksztalt);
	void ustawRewers(CircleShape  & ksztalt);
	void rysujAwers(RenderWindow & okno);
	void rysujRewers(RenderWindow & okno);
};