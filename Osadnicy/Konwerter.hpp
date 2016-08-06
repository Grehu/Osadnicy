#pragma once
#include "PlanszaBuilder.hpp"

class Konwerter {
private:
	Plansza * plansza;
	PlanszaBuilder * budowniczy;
	string schemat = "MMMMMMMM-MMZGWMM-MMKDKZMM-MDZGZDM-MMGWWGMM-MMDPWMM-MMMMMMMM";
public:
	void przypiszBudowniczego(PlanszaBuilder & budowniczy);
	void przypiszBudowniczego(PlanszaBuilder * budowniczy);
	void wczytajSchemat(string & schemat);
	void wczytajSchemat(string * schemat);
	void przetworzSchemat();
	Plansza * zwrocPlansze();
};