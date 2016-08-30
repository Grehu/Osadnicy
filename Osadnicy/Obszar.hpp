#pragma once
#include "RysunekComponent.hpp"
#include "Pole.hpp"
#include "Osada.hpp"
#include "Port.hpp"
#include "Droga.hpp"


enum class Odmiana {
	nieprawidlowa,
	poleSurowcow,
	pustynia,
	morze,
	miejsceDostepne,
	miejsceNiedostepne, 
	wybrzeze
};
template <class typ>
struct Obszar{
	RysunekComponent * grafika;
	Odmiana odmiana = Odmiana::nieprawidlowa;
	typ obiekt;
};

