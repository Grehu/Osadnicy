#pragma once
#include "RysunekComponent.hpp"
#include "Plansza.hpp"

class PlanszaBuilder {
	Plansza * plansza;
public:
	virtual void budujPlansze() {};
	virtual void budujLokacje() {};
	virtual void budujPola() {};
	virtual void budujPorty() {};
	virtual Plansza * zwrocPlansze() { return 0; };
protected:
	PlanszaBuilder();


};