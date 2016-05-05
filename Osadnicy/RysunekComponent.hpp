#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;
using namespace std;

class RysunekComponent {
private: 
	Sprite sprite;
	Vector2f lokalizacja;
public:
	void ustawSprite(Sprite & sprite);
	void rysuj(RenderWindow & okno);
};