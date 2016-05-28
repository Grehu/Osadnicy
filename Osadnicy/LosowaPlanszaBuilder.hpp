#pragma once
#include "PlanszaBuilder.hpp"
#include "Stale.hpp"
#include <random>
#include <ctime>
class LosowaPlanszaBuilder : public PlanszaBuilder {
protected:
	//Tworzenie ksztaltow
	virtual Shape * tworzSzescian(Etykieta etykieta);
	virtual Shape * tworzProstokat(Etykieta etykieta, int orientacja);
	virtual Shape * tworzKolo(Etykieta etykieta);

	//Tworzenie tekstow
	virtual Text * tworzTekst(String tresc);

	//Tworzenie modelow
	virtual Pole tworzObiektPola(Surowiec surowiec);
	virtual Port tworzObiektPortu(Surowiec surowiec);
	virtual Droga tworzObiektDrogi();
	virtual Osada tworzObiektOsady();

	//Ustalanie wektorow
	virtual Vector2f ustawPozycjePola();
	virtual Vector2f ustawPozycjeOsady();
	virtual Vector2f ustawPozycjeDrogi();
	virtual Vector2f ustawPozycjePortu();
	//Losowanie surowcow
	virtual Surowiec losujSurowiec();

public:
	virtual void budujPlansze();
	//Budowa komponentow planszy
	virtual void budujMorze();
	virtual void budujPustynie();
	virtual void budujObszarMieszkalny();
	virtual void budujPole();
	virtual void budujPole(Surowiec surowiec);
	virtual void budujPortZwykly();
	virtual void budujPortSpecjalistyczny();
	virtual void budujPortSpecjalistyczny(Surowiec surowiec);

	virtual Plansza * zwrocPlansze() { return plansza; };
};