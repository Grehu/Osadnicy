#pragma once
#include <SFML\Graphics.hpp>
#include "PlanszaBuilder.hpp"
#include "Plansza.hpp"

using namespace std;
//using namespace sf;

struct Koordynaty {
	int x;
	int y;
};

class Gra {
private:
	Plansza * plansza;
	
public:
	Plansza * stworzPlansze(PlanszaBuilder & budowniczy);
};