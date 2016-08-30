#include "PlanszaBuilder.hpp"

Texture * PlanszaBuilder::pobierzTekstureSurowca(Surowiec surowiec)
{
	return pobierzTekstureEtykiety(konwertujSurowiec(surowiec));
}

Texture * PlanszaBuilder::pobierzTekstureEtykiety(Etykieta etykieta)
{
	return tekstury->pobierzLosowaTeksture(etykieta);
}

Surowiec PlanszaBuilder::konwertujEtykiete(Etykieta etykieta)
{
	Surowiec konwersjaEtykiety;
	switch (etykieta) {
	case Etykieta::drewno: konwersjaEtykiety = Surowiec::drewno; break;
	case Etykieta::glina: konwersjaEtykiety = Surowiec::glina; break;
	case Etykieta::kamien: konwersjaEtykiety = Surowiec::kamien; break;
	case Etykieta::welna: konwersjaEtykiety = Surowiec::welna; break;
	case Etykieta::zboze: konwersjaEtykiety = Surowiec::zboze; break;
	default: konwersjaEtykiety = Surowiec::nic; break;
	}
	return konwersjaEtykiety;
}

Etykieta PlanszaBuilder::konwertujSurowiec(Surowiec surowiec)
{
	Etykieta konwersjaSurowca;
	switch (surowiec) {
	case Surowiec::drewno: konwersjaSurowca = Etykieta::drewno; break;
	case Surowiec::glina: konwersjaSurowca = Etykieta::glina; break;
	case Surowiec::kamien: konwersjaSurowca = Etykieta::kamien; break;
	case Surowiec::welna: konwersjaSurowca = Etykieta::welna; break;
	case Surowiec::zboze: konwersjaSurowca = Etykieta::zboze; break;
	case Surowiec::nic: konwersjaSurowca = Etykieta::blad; break;
	}
	return konwersjaSurowca;
}

Etykieta PlanszaBuilder::przetworzEtykieteSurowca(Etykieta etykieta)
{
	Etykieta konwersjaEtykiety;
	switch (etykieta) {
	case Etykieta::drewno: konwersjaEtykiety = Etykieta::drewnoKarta; break;
	case Etykieta::glina: konwersjaEtykiety = Etykieta::glinaKarta; break;
	case Etykieta::kamien: konwersjaEtykiety = Etykieta::kamienKarta; break;
	case Etykieta::welna: konwersjaEtykiety = Etykieta::welnaKarta; break;
	case Etykieta::zboze: konwersjaEtykiety = Etykieta::zbozeKarta; break;
	case Etykieta::drewnoKarta: konwersjaEtykiety = Etykieta::drewno; break;
	case Etykieta::glinaKarta: konwersjaEtykiety = Etykieta::glina; break;
	case Etykieta::kamienKarta: konwersjaEtykiety = Etykieta::kamien; break;
	case Etykieta::welnaKarta: konwersjaEtykiety = Etykieta::welna; break;
	case Etykieta::zbozeKarta: konwersjaEtykiety = Etykieta::zboze; break;
	default: konwersjaEtykiety = etykieta; break;
	}
	return konwersjaEtykiety;
}



void PlanszaBuilder::przypiszDystrybutory(DystrybutorTekstur * tekstury, DystrybutorCzcionek * czcionki, DystrybutorWartosci * wartosci)
{
	this->tekstury = tekstury;
	this->czcionki = czcionki;
	this->wartosci = wartosci;
}

void PlanszaBuilder::dodajKostke(int iloscScian)
{
	plansza->dodajKostke(iloscScian);
}

void PlanszaBuilder::zmianaTrybu(TrybEdycji nowyTryb)
{
	trybEdycji = nowyTryb;
}

void PlanszaBuilder::budujFejkPole()
{
	Obszar<Pole> fejk;
	fejk.grafika = nullptr;
	fejk.odmiana = Odmiana::miejsceNiedostepne;

	plansza->wstawPole(fejk);
}

void PlanszaBuilder::budujFejkDroge()
{
	Obszar<Droga> fejk;
	fejk.grafika = nullptr;
	fejk.odmiana = Odmiana::miejsceNiedostepne;

	plansza->wstawDroge(fejk);
}

void PlanszaBuilder::budujFejkOsade()
{
	Obszar<Osada> fejk;
	fejk.grafika = nullptr;
	fejk.odmiana = Odmiana::miejsceNiedostepne;

	plansza->wstawOsade(fejk);
}

void PlanszaBuilder::budujFejkPort()
{
	Obszar<Port> fejk;
	fejk.grafika = nullptr;
	fejk.odmiana = Odmiana::miejsceNiedostepne;

	plansza->wstawPort(fejk);
}
