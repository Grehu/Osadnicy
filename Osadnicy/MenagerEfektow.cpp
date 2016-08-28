#include "MenagerEfektow.hpp"




void MenagerEfektow::ustawPrzyrosty()
{
	przyrostR = (kolory[nastepnyKolor()].r - kolory[numerKoloru].r) / (float)krokiDoCelu;
	przyrostG = (kolory[nastepnyKolor()].g - kolory[numerKoloru].g) / (float)krokiDoCelu;
	przyrostB = (kolory[nastepnyKolor()].b - kolory[numerKoloru].b) / (float)krokiDoCelu;
	przyrostA = (kolory[nastepnyKolor()].a - kolory[numerKoloru].a) / (float)krokiDoCelu;
}

MenagerEfektow::MenagerEfektow(Color & poczatkowy, Color & docelowy)
{
	dodajKolor(poczatkowy);
	dodajKolor(docelowy);
	aktualnyKolor = kolory[0];
	ustawPrzyrosty();
}

void MenagerEfektow::dodajKolor(Color & kolor)
{
	kolory.push_back(kolor);
}

void MenagerEfektow::mieszaj()
{
	if (++licznikKrokow < krokiDoCelu) {
		magazynR += przyrostR;
		magazynG += przyrostG;
		magazynB += przyrostB;
		magazynA += przyrostA;
		aktualnyKolor = Color((int)(kolory[numerKoloru].r + magazynR), (int)(kolory[numerKoloru].g + magazynG), (int)(kolory[numerKoloru].b + magazynB), (int)(kolory[numerKoloru].a + magazynA));
	}
	else {

			magazynR, magazynB, magazynG, magazynA = 0.0f;
			licznikKrokow = 0;
			numerKoloru = nastepnyKolor();
			aktualnyKolor = kolory[numerKoloru];
			ustawPrzyrosty();
		}
	if (aktualnyKolor == Color(0, 0, 0, 0) || aktualnyKolor == Color(0, 0, 0, 255)) {
	
	}
	
}

Color MenagerEfektow::pobierzKolor()
{
	return aktualnyKolor;
}
