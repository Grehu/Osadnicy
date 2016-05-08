#pragma once
#include "RysunekComponent.hpp"
#include "PoleLeaf.hpp"
#include "PoleWartosciLeaf.hpp"
#include "RamkaLeaf.hpp"

using namespace sf;

class RysunekComposite : public RysunekComponent {
private:
	RysunekComponent * pole;
	RysunekComponent * poleWartosci;
	RysunekComponent * ramka;
public:
	void ustawPole(PoleLeaf & pole);
	void ustawWartosc(PoleWartosciLeaf & poleWartosci);
	void ustawRamke(RamkaLeaf & ramka);
	void rysuj(RenderWindow & okno);
};