#pragma once
#include <unordered_map>
#include "RysunekComponent.hpp"
#include "Gracz.hpp"

using namespace sf;
using namespace std;

class Sytuacja {
	struct pole {
		Vector2f lokalizacja;
		RysunekComponent grafika;
	};
	unordered_map<int[2], pole> plansza;

};