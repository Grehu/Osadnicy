#pragma once
#include <SFML\Graphics.hpp>
#include <map>

using namespace std;
//using namespace sf;

struct Koordynaty {
	int x;
	int y;
};

class Gra {
private:
	unordered_map<Koordynaty, PoleComposite> plansza;
};