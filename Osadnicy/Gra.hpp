#pragma once
#include <SFML\Graphics.hpp>
#include "PlanszaBuilder.hpp"
#include "Plansza.hpp"
#include "Gracz.hpp"

class Gra {
private:
	Plansza * plansza;
	
public:
	Plansza * stworzPlansze(PlanszaBuilder & budowniczy);
};