#pragma once
#include "PlanszaBuilder.hpp"

class Konwerter {
private:
	Plansza * plansza;
	PlanszaBuilder * budowniczy;
	string schematS = "MMMMMMMM-MMZGWMM-MMKDKZMM-MDZGZDM-MMGWWGMM-MMDPWMM-MMMMMMMM";
public:
	void przypiszBudowniczego(PlanszaBuilder & budowniczy);
	void przypiszBudowniczego(PlanszaBuilder * budowniczy);
	void wczytajSchematS(string & schemat);
	void wczytajSchematS(string * schemat);
	void przetworzSchemat();
	Plansza * zwrocPlansze();
};