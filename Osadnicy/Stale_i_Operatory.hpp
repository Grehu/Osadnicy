#pragma once
#include <SFML\Graphics.hpp>
using namespace sf;
const Vector2f PRZESUNIECIE_POLE_WARTOSCI = Vector2f(94.0f, 94.0f);
const Vector2f PRZESUNIECIE_TEKSTU_WARTOSCI = Vector2f(105.0f, 90.0f);

const Vector2f PRZESUNIECIE_X = Vector2f(224.0f, 0.0f);
const Vector2f PRZESUNIECIE_Y = Vector2f(0.0f, 192.0f);

const Vector2f MODYFIKATOR_RZEDU_NIEPARZYSTEGO = Vector2f(112.0f, 0.0f);

/*Vector2f operator * (const Vector2f & wektor, float czynnik) {
	return Vector2f(wektor.x*czynnik, wektor.y*czynnik);
}*/