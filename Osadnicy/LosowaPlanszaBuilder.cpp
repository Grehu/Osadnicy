#include "LosowaPlanszaBuilder.hpp"

Surowiec LosowaPlanszaBuilder::losujSurowiec()
{
	srand(time(NULL));
	Surowiec zasoby[5] = {	Surowiec::drewno, 
							Surowiec::glina, 
							Surowiec::welna, 
							Surowiec::kamien, 
							Surowiec::zboze };
	int los = rand() % 5;
	return zasoby[los];
}

void LosowaPlanszaBuilder::budujPlansze()
{
	if (plansza == nullptr) plansza = new Plansza();
}

void LosowaPlanszaBuilder::budujMorze()
{
	Obszar<Pole> nowe;
	Vector2f pozycja(ustawPozycjePola());
	
	RamkaLeaf * ramka = new RamkaLeaf();
	PoleLeaf * pole = new PoleLeaf();

	pole->ustawKsztalt(tworzSzescian(Etykieta::morze));
	pole->ustawPozycje(pozycja);
	ramka->ustawKsztalt(tworzSzescian(Etykieta::ramka));
	ramka->ustawPozycje(pozycja);

	RysunekComposite * kompozyt = new RysunekComposite();

	kompozyt->ustawPole(pole);
	kompozyt->ustawPozycje(pozycja);
	kompozyt->ustawRamke(ramka);
	kompozyt->ustawKsztalt(tworzSzescian(Etykieta::morze));
	kompozyt->ustawWartosc(nullptr);


	nowe.grafika = kompozyt;
	nowe.odmiana = Odmiana::morze;

	plansza->wstawPole(nowe);
}

void LosowaPlanszaBuilder::budujPustynie()
{
	Obszar<Pole> nowe;
	Vector2f pozycja(ustawPozycjePola());
	
	PoleWartosciLeaf * wartosc = new PoleWartosciLeaf();
	RamkaLeaf * ramka = new RamkaLeaf();
	PoleLeaf * pole = new PoleLeaf();

	pole->ustawKsztalt(tworzSzescian(Etykieta::pustynia));
	pole->ustawPozycje(pozycja);
	ramka->ustawKsztalt(tworzSzescian(Etykieta::ramka));
	ramka->ustawPozycje(pozycja);
	wartosc->ustawKsztalt(tworzKolo(Etykieta::wartosc));
	wartosc->ustawPozycje(pozycja);
	wartosc->przypiszText(*czcionki->pobierzLosowaCzcionke(PrzeznaczenieFontu::wartosc), "0");

	RysunekComposite * kompozyt = new RysunekComposite();

	kompozyt->ustawPole(pole);
	kompozyt->ustawPozycje(pozycja);
	kompozyt->ustawRamke(ramka);
	kompozyt->ustawWartosc(wartosc);
	kompozyt->ustawKsztalt(tworzSzescian(Etykieta::pustynia));


	nowe.grafika = kompozyt;
	nowe.odmiana = Odmiana::pustynia;

	plansza->wstawPole(nowe);
}

void LosowaPlanszaBuilder::budujPole()
{
	budujPole(losujSurowiec());
}

void LosowaPlanszaBuilder::budujPortSpecjalistyczny()
{
	budujPortSpecjalistyczny(losujSurowiec());
}

void LosowaPlanszaBuilder::budujPole(Surowiec surowiec)
{
	Obszar<Pole> nowe;
	Vector2f pozycja(ustawPozycjePola());
	Etykieta etykieta;
	switch (surowiec) {
	case Surowiec::drewno: etykieta = Etykieta::drewno; break;
	case Surowiec::glina: etykieta = Etykieta::glina; break;
	case Surowiec::welna: etykieta = Etykieta::welna; break;
	case Surowiec::zboze: etykieta = Etykieta::zboze; break;
	case Surowiec::kamien: etykieta = Etykieta::kamien; break;
	}

	PoleWartosciLeaf * wartosc = new PoleWartosciLeaf();
	RamkaLeaf * ramka = new RamkaLeaf();
	PoleLeaf * pole = new PoleLeaf();

	pole->ustawKsztalt(tworzSzescian(etykieta));
	pole->ustawPozycje(pozycja);
	ramka->ustawKsztalt(tworzSzescian(Etykieta::ramka));
	ramka->ustawPozycje(pozycja);
	wartosc->ustawKsztalt(tworzKolo(Etykieta::wartosc));
	wartosc->ustawPozycje(pozycja);
	wartosc->przypiszText(*czcionki->pobierzLosowaCzcionke(PrzeznaczenieFontu::wartosc), "3");

	RysunekComposite * kompozyt = new RysunekComposite();

	kompozyt->ustawPole(pole);
	kompozyt->ustawPozycje(pozycja);
	kompozyt->ustawRamke(ramka);
	kompozyt->ustawWartosc(wartosc);
	kompozyt->ustawKsztalt(tworzSzescian(etykieta));


	nowe.grafika = kompozyt;
	nowe.odmiana = Odmiana::poleSurowcow;

	plansza->wstawPole(nowe);
	/*Text * text = new Text;
	text->setFont(*czcionki->pobierzKonkretnaCzcionke("wartosc", 0));
	text->setCharacterSize(56);
	text->setColor(Color(0, 0, 0));
	text->setString("0");

	CircleShape * poleGrafika = new CircleShape(128, 6);
	poleGrafika->setTexture(tekstury->pobierzLosowaTeksture(surowiec));
	CircleShape * ramkaGrafika = new CircleShape(128, 6);
	ramkaGrafika->setTexture(tekstury->pobierzLosowaTeksture("ramka"));
	CircleShape * poleWartosciGrafika = new CircleShape(32);
	poleWartosciGrafika->setTexture(tekstury->pobierzLosowaTeksture("poleWartosci"));
	CircleShape * zlodziejGrafika = new CircleShape(32);
	zlodziejGrafika->setTexture(tekstury->pobierzLosowaTeksture("zlodziej"));

	PoleLeaf * poleRC = new PoleLeaf;
	RamkaLeaf * ramkaRC = new RamkaLeaf;
	PoleWartosciLeaf * poleWartosciRC = new PoleWartosciLeaf;
	RysunekComposite * kompozytRC = new RysunekComposite;

	poleRC->ustawKsztalt(*poleGrafika);
	poleRC->ustawPozycje(plansza->pobierzPozycjePola(wskaznik));
	ramkaRC->ustawKsztalt(*ramkaGrafika);
	ramkaRC->ustawPozycje(plansza->pobierzPozycjePola(wskaznik));
	poleWartosciRC->ustawKsztalt(*poleWartosciGrafika);
	poleWartosciRC->nadajZlodziejowiGrafike(*zlodziejGrafika);
	poleWartosciRC->przypiszText(*text);
	poleWartosciRC->ustawPozycje(plansza->pobierzPozycjePola(wskaznik));
	kompozytRC->ustawPole(*poleRC);
	kompozytRC->ustawRamke(*ramkaRC);
	kompozytRC->ustawWartosc(*poleWartosciRC);
	std::cout << "Wskaznik: " << wskaznik.x << " " << wskaznik.y << endl;
	std:cout << "Pozycja kompozytu ustawiana jest na" << plansza->pobierzPozycjePola(wskaznik)->x << " " << plansza->pobierzPozycjePola(wskaznik)->y << endl;
	kompozytRC->ustawPozycje(plansza->pobierzPozycjePola(wskaznik));

	plansza->ustawGrafikePola(wskaznik, *kompozytRC);
	delete kompozytRC;

	Pole * pole = new Pole;
	pole->ustawSurowiec(surowiec);
	pole->ustawWartosc(0);
	
	plansza->ustawPole(wskaznik, *pole);
	delete pole;

	wskaznik.x++;*/
	//TODO
}

void LosowaPlanszaBuilder::budujPortSpecjalistyczny(Surowiec surowiec)
{
	
}

Shape * LosowaPlanszaBuilder::tworzSzescian(Etykieta etykieta)
{
	Shape * ksztalt = new CircleShape(128, 6);
	ksztalt->setTexture(tekstury->pobierzLosowaTeksture(etykieta));
	return ksztalt;
}

Shape * LosowaPlanszaBuilder::tworzProstokat(Etykieta etykieta, int orientacja)
{
	Shape * ksztalt = new RectangleShape(Vector2f(128, 16));
	ksztalt->setTexture(tekstury->pobierzLosowaTeksture(etykieta));
	ksztalt->setRotation(orientacja);
	return ksztalt;
}

Shape * LosowaPlanszaBuilder::tworzKolo(Etykieta etykieta)
{
	Shape * ksztalt = new CircleShape(32);
	ksztalt->setTexture(tekstury->pobierzLosowaTeksture(etykieta));
	return ksztalt;
}

Text * LosowaPlanszaBuilder::tworzTekst(String tresc)
{
	Text * tekst = new Text;
	tekst->setFont(*czcionki->pobierzLosowaCzcionke(wartosc));
	tekst->setCharacterSize(56);
	tekst->setColor(Color(0, 0, 0));
	tekst->setString(tresc);
	return tekst;
}

Pole LosowaPlanszaBuilder::tworzObiektPola(Surowiec surowiec)
{
	Pole nowe;
	nowe.ustawSurowiec(surowiec);
	nowe.ustawWartosc(0);
	return nowe;
}

Port LosowaPlanszaBuilder::tworzObiektPortu(Surowiec surowiec)
{
	Port port;
	Koordynaty osada1 = Parowanie::osadaDlaDrogi_1(wskaznik);
	Koordynaty osada2 = Parowanie::osadaDlaDrogi_2(wskaznik);
	port.dodajKlientow(plansza->pobierzOsade(osada1)->obiekt, plansza->pobierzOsade(osada2)->obiekt);
	port.ustawSurowiec(surowiec);
	return port;
}

Droga LosowaPlanszaBuilder::tworzObiektDrogi()
{
	Droga droga;
	Koordynaty osada1 = Parowanie::osadaDlaDrogi_1(wskaznik);
	Koordynaty osada2 = Parowanie::osadaDlaDrogi_2(wskaznik);
	droga.ustawWezly(&plansza->pobierzOsade(osada1)->obiekt, &plansza->pobierzOsade(osada2)->obiekt);
	return droga;
}

Osada LosowaPlanszaBuilder::tworzObiektOsady()
{
	Osada osada;
	Koordynaty pole1 = Parowanie::poleDlaOsady_1(wskaznik);
	Koordynaty pole2 = Parowanie::poleDlaOsady_2(wskaznik);
	Koordynaty pole3 = Parowanie::poleDlaOsady_3(wskaznik);
	osada.ustawSasiadow(&plansza->pobierzPole(pole1)->obiekt, &plansza->pobierzPole(pole2)->obiekt, &plansza->pobierzPole(pole3)->obiekt);
	return osada;
}

Vector2f LosowaPlanszaBuilder::ustawPozycjePola()
{
	return Vector2f(wskaznik.x*PRZESUNIECIE_X + ((wskaznik.y % 2) ? MODYFIKATOR_RZEDU_NIEPARZYSTEGO : 0.0f), wskaznik.y*PRZESUNIECIE_Y);
}
