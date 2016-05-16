#pragma once
#include "PlanszaBuilder.hpp"
#include <random>
#include <ctime>
class LosowaPlanszaBuilder : public PlanszaBuilder {
protected:
	//LosowaPlanszaBuilder();
	Koordynaty wskaznik;
	virtual string losujSurowiec();
public:
	virtual void budujPlansze(int szerokosc, int wysokosc);
	void budujPole();
	void budujPort();
	virtual void budujPole(string surowiec);
	virtual void budujPort(string surowiec);
	virtual Plansza * zwrocPlansze() { return plansza; };
};