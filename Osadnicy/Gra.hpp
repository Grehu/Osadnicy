#pragma once
#include <SFML\Graphics.hpp>

using namespace std;
//using namespace sf;

struct Koordynaty {
	int x;
	int y;
};

class Gra {
private:
	map::unordered_map<Koordynaty, PoleComposite> plansza;
};