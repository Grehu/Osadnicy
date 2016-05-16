#pragma once

#include "Plansza.hpp"
#include "DystrybutorTekstur.hpp"
#include <SFML\Graphics.hpp>



class PlanszaBuilder {
protected:
	//PlanszaBuilder();
	Plansza * plansza;
	DystrybutorTekstur * tekstury;
public:
	void przypiszDystrybutora(DystrybutorTekstur & tekstury);
	virtual void budujPlansze(int szerokosc, int wysokosc) {};
	virtual void budujPole() {};
	virtual void budujPort() {};
	virtual void budujPole(string surowiec) {};
	virtual void budujPort(string surowiec) {};
	virtual Plansza * zwrocPlansze() { return 0; };



};