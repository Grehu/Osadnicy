#include "LosowaPlanszaBuilder.hpp"

/*LosowaPlanszaBuilder::LosowaPlanszaBuilder()
{
	srand(time(NULL));
}*/

string LosowaPlanszaBuilder::losujSurowiec()
{
	srand(time(NULL));
	string zasoby[5] = { "drewno", "glina", "welna", "kamien", "zboze" };
	int los = rand() % 5;
	return zasoby[los];
}

void LosowaPlanszaBuilder::budujPlansze(int szerokosc, int wysokosc)
{
	plansza = new Plansza(szerokosc, wysokosc);
	wskaznik.x = 0;
	wskaznik.y = 0;
}

void LosowaPlanszaBuilder::budujPole()
{
	budujPole(losujSurowiec());
}

void LosowaPlanszaBuilder::budujPort()
{
	budujPort(losujSurowiec());
}

void LosowaPlanszaBuilder::budujPole(string surowiec)
{
	CircleShape * poleGrafika = new CircleShape(128, 6);
	poleGrafika->setTexture(tekstury->pobierzLosowaTeksture(surowiec));
	CircleShape * ramkaGrafika = new CircleShape(128, 6);
	ramkaGrafika->setTexture(tekstury->pobierzLosowaTeksture("ramka"));
	CircleShape * poleWartosciGrafika = new CircleShape(32);
	poleWartosciGrafika->setTexture(tekstury->pobierzLosowaTeksture("poleWartosci"));
	CircleShape * zlodziejGrafika = new CircleShape(32);
	zlodziejGrafika->setTexture(tekstury->pobierzLosowaTeksture("zlodziej"));

	PoleLeaf * pole = new PoleLeaf;
	RamkaLeaf * ramka = new RamkaLeaf;
	PoleWartosciLeaf * poleWartosci = new PoleWartosciLeaf;
	RysunekComposite * kompozyt = new RysunekComposite;

	pole->ustawKsztalt(*poleGrafika);
	pole->ustawPozycje(plansza->pobierzPozycjePola(wskaznik));
	ramka->ustawKsztalt(*ramkaGrafika);
	ramka->ustawPozycje(plansza->pobierzPozycjePola(wskaznik));
	
}

void LosowaPlanszaBuilder::budujPort(string surowiec)
{
	
}
