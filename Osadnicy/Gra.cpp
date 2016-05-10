#include "Gra.hpp"

Plansza * Gra::stworzPlansze(PlanszaBuilder & budowniczy)
{
	budowniczy.budujPlansze();
	budowniczy.budujLokacje();
	budowniczy.budujPola();
	budowniczy.budujPorty();
	return nullptr;
}
