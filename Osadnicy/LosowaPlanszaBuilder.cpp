#include "LosowaPlanszaBuilder.hpp"

Vector2f LosowaPlanszaBuilder::ustawPozycjeDrogi()
{
	return Vector2f(wskaznik.y % 2 ? DROGA_BAZA_PION + (((wskaznik.y + 1) % 4) ? 0.0f : MODYFIKATOR_RZEDU_NIEPARZYSTEGO) + (PRZESUNIECIE_X*wskaznik.x) : DROGA_BAZA_X + (PRZESUNIECIE_X*wskaznik.x / 2), wskaznik.y*PRZESUNIECIE_Y / 2 + DROGA_BAZA_Y);
}

Vector2f LosowaPlanszaBuilder::ustawPozycjePortu()
{
	return Vector2f(wskaznik.y % 2 ? DROGA_BAZA_PION + (((wskaznik.y + 1) % 4) ? 0.0f : MODYFIKATOR_RZEDU_NIEPARZYSTEGO) + (PRZESUNIECIE_X*wskaznik.x) : DROGA_BAZA_X + (PRZESUNIECIE_X*wskaznik.x / 2), wskaznik.y*PRZESUNIECIE_Y / 2 + DROGA_BAZA_Y);
}

int LosowaPlanszaBuilder::ustawOrientacjeDrogi()
{
	return (wskaznik.y % 2 ? 90 : (wskaznik.y % 4 ? (wskaznik.x % 2 ? 150 : 30) : (wskaznik.x % 2 ? 30 : 150)));
}

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
	zmianaTrybu(TrybEdycji::budowaPol);
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
	nowe.obiekt = tworzObiektPola(Surowiec::nic);

	plansza->wstawPole(nowe);
}

void LosowaPlanszaBuilder::budujPustynie()
{
	zmianaTrybu(TrybEdycji::budowaPol);
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
	nowe.obiekt = tworzObiektPola(Surowiec::nic);

	plansza->wstawPole(nowe);
}

void LosowaPlanszaBuilder::budujObszarMieszkalny(bool blokada)
{
	zmianaTrybu(TrybEdycji::budowaOsad);
	Obszar<Osada> nowe;
	Shape * grafika0 = tworzKolo(Etykieta::ciemnosc);
	Shape * grafika1 = tworzKolo(Etykieta::wioska);
	Shape * grafika2 = tworzKolo(Etykieta::miasto);

	BudynekLeaf * kompozyt = new BudynekLeaf;
	kompozyt->ustawGrafiki(grafika0, grafika1, grafika2);
	kompozyt->ustawKolorRamki(Color(55, 55, 55));
	kompozyt->ustawPozycje(ustawPozycjeOsady());
	
	nowe.grafika = kompozyt;
	nowe.obiekt = tworzObiektOsady();
	nowe.odmiana = blokada? Odmiana::miejsceNiedostepne : Odmiana::miejsceDostepne;

	plansza->wstawOsade(nowe);
}

void LosowaPlanszaBuilder::budujDroge(bool blokada)
{
	zmianaTrybu(TrybEdycji::budowaDrog);
	Obszar<Droga> nowe;

	Shape * ksztalt = tworzProstokat(Etykieta::droga);

	ksztalt->setRotation(ustawOrientacjeDrogi());
	
	DrogaLeaf * komponent = new DrogaLeaf;
	komponent->ustawKolor(Color(55, 55, 55, 55));
	komponent->ustawKsztalt(ksztalt);
	komponent->ustawPozycje(ustawPozycjeDrogi());

	nowe.grafika = komponent;
	nowe.obiekt = tworzObiektDrogi();
	nowe.odmiana = blokada ? Odmiana::miejsceNiedostepne : Odmiana::miejsceDostepne;

	plansza->wstawDroge(nowe);
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
	zmianaTrybu(TrybEdycji::budowaPol);
	Obszar<Pole> nowe;
	Vector2f pozycja(ustawPozycjePola());
	Etykieta etykieta = konwertujSurowiec(surowiec);

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

	nowe.obiekt = tworzObiektPola(surowiec);
	nowe.obiekt.ustawSurowiec(surowiec);
	nowe.obiekt.ustawWartosc(3);
	

	plansza->wstawPole(nowe);

	//TO CHECK
}

void LosowaPlanszaBuilder::budujPortZwykly()
{
	zmianaTrybu(TrybEdycji::budowaPortow);
	Obszar<Port> nowe;

	Shape * ksztalt = tworzKolo(Etykieta::port);
	ksztalt->setOrigin(32.0f, 32.0f);
	Vector2f pozycja = ustawPozycjePortu();

	PortLeaf * komponent = new PortLeaf;
	komponent->ustawKolory(Color(55, 55, 55), Color(55, 55, 55));
	komponent->ustawKsztalt(ksztalt);
	komponent->ustawSurowiec(ksztalt);
	komponent->ustawPozycje(pozycja);

	nowe.grafika = komponent;
	nowe.obiekt = tworzObiektPortu(Surowiec::nic);
	nowe.odmiana = Odmiana::wybrzeze;

	plansza->wstawPort(nowe);
}

void LosowaPlanszaBuilder::budujPortSpecjalistyczny(Surowiec surowiec)
{
	zmianaTrybu(TrybEdycji::budowaPortow);
	Obszar<Port> nowe;
	
	Shape * ksztalt = tworzKolo(Etykieta::port);
	Shape * ksztalt2 = tworzKolo(przetworzEtykieteSurowca(konwertujSurowiec(surowiec)));
	ksztalt->setOrigin(32.0f, 32.0f);
	ksztalt2->setOrigin(32.0f, 32.0f);
	Vector2f pozycja = ustawPozycjePortu();

	PortLeaf * komponent = new PortLeaf;
	komponent->ustawKolory(Color(55, 55, 55), Color(55, 55, 55));
	komponent->ustawKsztalt(ksztalt);
	komponent->ustawSurowiec(ksztalt2);
	komponent->ustawPozycje(pozycja);

	nowe.grafika = komponent;
	nowe.obiekt = tworzObiektPortu(surowiec);
	nowe.odmiana = Odmiana::wybrzeze;

	plansza->wstawPort(nowe);
}


void LosowaPlanszaBuilder::wykonczPlansze()
{
	Koordynaty koordynaty;
	Koordynaty koordynatySprawdzane;
	Pole * p_sasiad1;
	Pole * p_sasiad2;
	Pole * p_sasiad3;
	Osada * o_sasiad1;
	Osada * o_sasiad2;
	for (int i = 0; i < plansza->osady.size(); i++) {
		for (int j = 0; j < plansza->osady[i].size(); j++) {
			if (plansza->osady[i][j].odmiana == Odmiana::miejsceDostepne) {
				koordynaty.x = i;
				koordynaty.y = j;

				koordynatySprawdzane = Parowanie::poleDlaOsady_1(koordynaty);
				p_sasiad1 = &plansza->pobierzPole(koordynatySprawdzane)->obiekt;
				koordynatySprawdzane = Parowanie::poleDlaOsady_2(koordynaty);
				p_sasiad2 = &plansza->pobierzPole(koordynatySprawdzane)->obiekt;
				koordynatySprawdzane = Parowanie::poleDlaOsady_3(koordynaty);
				p_sasiad3 = &plansza->pobierzPole(koordynatySprawdzane)->obiekt;

				plansza->osady[i][j].obiekt.ustawSasiadow(p_sasiad1, p_sasiad2, p_sasiad3);
			}
		}
	}
	for (int i = 0; i < plansza->drogi.size(); i++) {
		for (int j = 0; j < plansza->drogi[i].size(); j++) {
			if (plansza->drogi[i][j].odmiana == Odmiana::miejsceDostepne) {
				koordynaty.x = i;
				koordynaty.y = j;

				koordynatySprawdzane = Parowanie::osadaDlaDrogi_1(koordynaty);
				o_sasiad1 = &plansza->pobierzOsade(koordynatySprawdzane)->obiekt;
				koordynatySprawdzane = Parowanie::osadaDlaDrogi_2(koordynaty);
				o_sasiad2 = &plansza->pobierzOsade(koordynatySprawdzane)->obiekt;

				plansza->drogi[i][j].obiekt.ustawWezly(o_sasiad1, o_sasiad2);
			}
		}
	}
	for (int i = 0; i < plansza->porty.size(); i++) {
		for (int j = 0; j < plansza->porty[i].size(); j++) {
			if (plansza->porty[i][j].odmiana == Odmiana::wybrzeze) {
				koordynaty.x = i;
				koordynaty.y = j;

				koordynatySprawdzane = Parowanie::osadaDlaDrogi_1(koordynaty);
				o_sasiad1 = &plansza->pobierzOsade(koordynatySprawdzane)->obiekt;
				koordynatySprawdzane = Parowanie::osadaDlaDrogi_2(koordynaty);
				o_sasiad2 = &plansza->pobierzOsade(koordynatySprawdzane)->obiekt;

				plansza->porty[i][j].obiekt.dodajKlientow(o_sasiad1, o_sasiad2);
			}
		}
	}
}

Shape * LosowaPlanszaBuilder::tworzSzescian(Etykieta etykieta)
{
	Shape * ksztalt = new CircleShape(128, 6);
	ksztalt->setTexture(tekstury->pobierzLosowaTeksture(etykieta));
	return ksztalt;
}

Shape * LosowaPlanszaBuilder::tworzProstokat(Etykieta etykieta)
{
	Shape * ksztalt = new RectangleShape(Vector2f(128.0f, 16.0f));
	ksztalt->setTexture(tekstury->pobierzLosowaTeksture(etykieta));
	ksztalt->setOrigin(Vector2f(64.0f, 8.0f));
	ksztalt->setFillColor(Color(55, 55, 55, 128));
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
	port.dodajKlientow(&plansza->pobierzOsade(osada1)->obiekt, &plansza->pobierzOsade(osada2)->obiekt);
	port.ustawSurowiec(surowiec);
	return port;
}

Droga LosowaPlanszaBuilder::tworzObiektDrogi()
{
	Droga droga;
	//Koordynaty osada1 = Parowanie::osadaDlaDrogi_1(wskaznik);
	//Koordynaty osada2 = Parowanie::osadaDlaDrogi_2(wskaznik);
	//droga.ustawWezly(&plansza->pobierzOsade(osada1)->obiekt, &plansza->pobierzOsade(osada2)->obiekt);
	return droga;
}

Osada LosowaPlanszaBuilder::tworzObiektOsady()
{
	Osada osada;
	//Koordynaty pole1 = Parowanie::poleDlaOsady_1(wskaznik);
	//Koordynaty pole2 = Parowanie::poleDlaOsady_2(wskaznik);
	//Koordynaty pole3 = Parowanie::poleDlaOsady_3(wskaznik);
	//osada.ustawSasiadow(&plansza->pobierzPole(pole1)->obiekt, &plansza->pobierzPole(pole2)->obiekt, &plansza->pobierzPole(pole3)->obiekt);
	return osada;
}

Vector2f LosowaPlanszaBuilder::ustawPozycjePola()
{
	return Vector2f(wskaznik.x*PRZESUNIECIE_X + ((wskaznik.y % 2) ? MODYFIKATOR_RZEDU_NIEPARZYSTEGO : 0.0f), wskaznik.y*PRZESUNIECIE_Y);
}

Vector2f LosowaPlanszaBuilder::ustawPozycjeOsady()
{
	return Vector2f(OSADA_BAZA_X + (PRZESUNIECIE_X * wskaznik.x / 2), OSADA_BAZA_Y + (PRZESUNIECIE_Y * wskaznik.y) + ((wskaznik.x + wskaznik.y) % 2 ? 0.0f : OSADA_PRZESUNIECIE_DODATKOWE_Y));
}
