#include "Gra.hpp"

Plansza * Gra::stworzPlansze(PlanszaBuilder & budowniczy)
{
	budowniczy.budujPlansze(7,7);
	//budowniczy.budujPola();
	//budowniczy.budujPorty();
	return nullptr;
}
