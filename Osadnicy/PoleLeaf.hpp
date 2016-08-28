#pragma once
#include <SFML\Graphics.hpp>
#include "RysunekComponent.hpp"

using namespace sf;

enum class Rog {
	prawyGorny,
	prawy,
	prawyDolny,
	lewyDolny,
	lewy,
	lewyGorny
};

class PoleLeaf : public RysunekComponent {
protected:
	bool podswietlone;
	double rozjasnienie = 0.0f;
public:
	void rysuj(RenderWindow & okno, Vector2f * lokalizacja);
	Vector2f wspolrzedneRogu(int rog);
	bool sprawdzPunkt(RenderWindow & okno);
};