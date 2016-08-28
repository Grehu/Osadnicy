#include "Testy.hpp"



void Test::porownaj(Koordynaty port, Koordynaty poprawne1, Koordynaty poprawne2)
{
	std::cout << "Dane portu: " << port.x << " " << port.y << std::endl;

	if (Parowanie::osadaDlaDrogi_1(port) == poprawne1 || Parowanie::osadaDlaDrogi_1(port) == poprawne2) { std::cout << "Poprawne przyporzadkowanie osady do portu" << std::endl; }
	else { std::cout << "Niepoprawne przyporzadkowanie osady do portu. Jest: "<< Parowanie::osadaDlaDrogi_1(port).x<<" "<< Parowanie::osadaDlaDrogi_1(port).y<<" a powinno byc "<<poprawne1.x<<" "<<poprawne1.y<<" albo"<< poprawne2.x << " " << poprawne2.y << std::endl; }
	if (Parowanie::osadaDlaDrogi_2(port) == poprawne2 || Parowanie::osadaDlaDrogi_2(port) == poprawne1) { std::cout << "Poprawne przyporzadkowanie osady do portu" << std::endl; }
	else { std::cout << "Niepoprawne przyporzadkowanie osady do portu. Jest: " << Parowanie::osadaDlaDrogi_2(port).x << " " << Parowanie::osadaDlaDrogi_2(port).y << " a powinno byc " << poprawne1.x << " " << poprawne1.y << " albo" << poprawne2.x << " " << poprawne2.y << std::endl; }
	if (Parowanie::osadaDlaDrogi_2(port) == Parowanie::osadaDlaDrogi_1(port)) { std::cout << L"Dwukrotne przyporz¹dkowanie tej samej osady" << std::endl; }
}

void Test::porownaj(Koordynaty osada, Koordynaty poprawne1, Koordynaty poprawne2, Koordynaty poprawne3)
{
	std::cout << "Dane osady: " << osada.x << " " << osada.y << std::endl;

	if (Parowanie::poleDlaOsady_1(osada) == poprawne1 || Parowanie::poleDlaOsady_1(osada) == poprawne2 || Parowanie::poleDlaOsady_1(osada) == poprawne3) { std::cout << "Poprawne przyporzadkowanie pola do osady" << "Jest: " << Parowanie::poleDlaOsady_1(osada).x << " " << Parowanie::poleDlaOsady_1(osada).y << std::endl; }
	else { std::cout << "Niepoprawne przyporzadkowanie pola do osady. Jest: " << Parowanie::poleDlaOsady_1(osada).x << " " << Parowanie::poleDlaOsady_1(osada).y << " a powinno byc " << poprawne1.x << " " << poprawne1.y << " albo " << poprawne2.x << " " << poprawne2.y << " albo" << poprawne3.x << " " << poprawne3.y << std::endl; }
	if (Parowanie::poleDlaOsady_2(osada) == poprawne2 || Parowanie::poleDlaOsady_2(osada) == poprawne1 || Parowanie::poleDlaOsady_2(osada) == poprawne3) { std::cout << "Poprawne przyporzadkowanie pola do osady" << "Jest: " << Parowanie::poleDlaOsady_2(osada).x << " " << Parowanie::poleDlaOsady_2(osada).y << std::endl; }
	else { std::cout << "Niepoprawne przyporzadkowanie pola do osady. Jest: " << Parowanie::poleDlaOsady_2(osada).x << " " << Parowanie::poleDlaOsady_2(osada).y << " a powinno byc " << poprawne1.x << " " << poprawne1.y << " albo " << poprawne2.x << " " << poprawne2.y << " albo" << poprawne3.x << " " << poprawne3.y << std::endl; }
	if (Parowanie::poleDlaOsady_3(osada) == poprawne2 || Parowanie::poleDlaOsady_3(osada) == poprawne1 || Parowanie::poleDlaOsady_3(osada) == poprawne3) { std::cout << "Poprawne przyporzadkowanie pola do osady" << "Jest: " << Parowanie::poleDlaOsady_3(osada).x << " " << Parowanie::poleDlaOsady_3(osada).y << std::endl; }
	else { std::cout << "Niepoprawne przyporzadkowanie pola do osady. Jest: " << Parowanie::poleDlaOsady_3(osada).x << " " << Parowanie::poleDlaOsady_3(osada).y << " a powinno byc " << poprawne1.x << " " << poprawne1.y << " albo " << poprawne2.x << " " << poprawne2.y << " albo" << poprawne3.x << " " << poprawne3.y << std::endl; }

	if (Parowanie::poleDlaOsady_2(osada) == Parowanie::poleDlaOsady_1(osada) || Parowanie::poleDlaOsady_2(osada) == Parowanie::poleDlaOsady_3(osada) || Parowanie::poleDlaOsady_3(osada) == Parowanie::poleDlaOsady_1(osada)) { std::cout << "Wielokrotne przyporz¹dkowanie tego samego pola" << std::endl; }

}

void Test::testPrzyporzadkowaniaPortu()
{
	Koordynaty port1 = { 1,1 };
	Koordynaty osada1_1 = { 1,1 };
	Koordynaty osada1_2 = { 1,2 };

	Koordynaty port2 = { 1,2 };
	Koordynaty osada2_1 = { 1,2 };
	Koordynaty osada2_2 = { 1,3 };

	Koordynaty port3 = { 1,3 };
	Koordynaty osada3_1 = { 1,3 };
	Koordynaty osada3_2 = { 1,4 };

	Koordynaty port4 = { 2,1 };
	Koordynaty osada4_1 = { 1,1 };
	Koordynaty osada4_2 = { 2,1 };

	Koordynaty port5 = { 3,1 };
	Koordynaty osada5_1 = { 2,1 };
	Koordynaty osada5_2 = { 2,2 };

	Koordynaty port6 = { 4,1 };
	Koordynaty osada6_1 = { 2,2 };
	Koordynaty osada6_2 = { 3,2 };

	Koordynaty port7 = { 2,2 };
	Koordynaty osada7_1 = { 1,3 };
	Koordynaty osada7_2 = { 2,3 };

	Koordynaty port8 = { 3,4 };
	Koordynaty osada8_1 = { 2,4 };
	Koordynaty osada8_2 = { 2,5 };

	Koordynaty port9 = { 3,6 };
	Koordynaty osada9_1 = { 2,6 };
	Koordynaty osada9_2 = { 2,7 };

	Koordynaty port10 = { 5,3 };
	Koordynaty osada10_1 = { 3,3 };
	Koordynaty osada10_2 = { 3,4 };

	Koordynaty port11 = { 4,3 };
	Koordynaty osada11_1 = { 2,6 };
	Koordynaty osada11_2 = { 3,6 };

	std::cout << "Port 1:" << std::endl;
	porownaj(port1, osada1_1, osada1_2);
	std::cout << "Port 2:" << std::endl;
	porownaj(port2, osada2_1, osada2_2);
	std::cout << "Port 3:" << std::endl;
	porownaj(port3, osada3_1, osada3_2);
	std::cout << "Port 4:" << std::endl;
	porownaj(port4, osada4_1, osada4_2);
	std::cout << "Port 5:" << std::endl;
	porownaj(port5, osada5_1, osada5_2);
	std::cout << "Port 6:" << std::endl;
	porownaj(port6, osada6_1, osada6_2);
	std::cout << "Port 7:" << std::endl;
	porownaj(port7, osada7_1, osada7_2);
	std::cout << "Port 8:" << std::endl;
	porownaj(port8, osada8_1, osada8_2);
	std::cout << "Port 9:" << std::endl;
	porownaj(port9, osada9_1, osada9_2);
	std::cout << "Port 10:" << std::endl;
	porownaj(port10, osada10_1, osada10_2);
	std::cout << "Port 11:" << std::endl;
	porownaj(port11, osada11_1, osada11_2);
}

void Test::testPrzyporzadkowaniaOsady()
{
	Koordynaty osada1 = { 2,3 };
	Koordynaty pole1_1 = { 1,1 };
	Koordynaty pole1_2 = { 1,2 };
	Koordynaty pole1_3 = { 2,1 };

	Koordynaty osada2 = { 3,5 };
	Koordynaty pole2_1 = { 2,2 };
	Koordynaty pole2_2 = { 3,2 };
	Koordynaty pole2_3 = { 3,3 };

	Koordynaty osada3 = { 3,3 };
	Koordynaty pole3_1 = { 2,1 };
	Koordynaty pole3_2 = { 3,1 };
	Koordynaty pole3_3 = { 3,2 };

	Koordynaty osada4 = { 2,8 };
	Koordynaty pole4_1 = { 1,4 };
	Koordynaty pole4_2 = { 2,3 };
	Koordynaty pole4_3 = { 2,4 };

	Koordynaty osada5 = { 3,8 };
	Koordynaty pole5_1 = { 2,3 };
	Koordynaty pole5_2 = { 2,4 };
	Koordynaty pole5_3 = { 3,4 };

	Koordynaty osada6 = { 3,6 };
	Koordynaty pole6_1 = { 2,2 };
	Koordynaty pole6_2 = { 2,3 };
	Koordynaty pole6_3 = { 3,3 };

	Koordynaty osada7 = { 3,4 };
	Koordynaty pole7_1 = { 2,1 };
	Koordynaty pole7_2 = { 2,2 };
	Koordynaty pole7_3 = { 3,2 };

	Koordynaty osada8 = { 3,7 };
	Koordynaty pole8_1 = { 2,3 };
	Koordynaty pole8_2 = { 3,3 };
	Koordynaty pole8_3 = { 3,4 };

	Koordynaty osada9 = { 2,6 };
	Koordynaty pole9_1 = { 1,3 };
	Koordynaty pole9_2 = { 2,2 };
	Koordynaty pole9_3 = { 2,3 };


	std::cout << "osada 1:" << std::endl;
	porownaj(osada1, pole1_1, pole1_2, pole1_3);
	std::cout << "osada 2:" << std::endl;
	porownaj(osada2, pole2_1, pole2_2, pole2_3);
	std::cout << "osada 3:" << std::endl;
	porownaj(osada3, pole3_1, pole3_2, pole3_3);
	std::cout << "osada 4:" << std::endl;
	porownaj(osada4, pole4_1, pole4_2, pole4_3);
	std::cout << "osada 5:" << std::endl;
	porownaj(osada5, pole5_1, pole5_2, pole5_3);
	std::cout << "osada 6:" << std::endl;
	porownaj(osada6, pole6_1, pole6_2, pole6_3);
	std::cout << "osada 7:" << std::endl;
	porownaj(osada7, pole7_1, pole7_2, pole7_3);
	std::cout << "osada 8:" << std::endl;
	porownaj(osada8, pole8_1, pole8_2, pole8_3);
	std::cout << "osada 9:" << std::endl;
	porownaj(osada9, pole9_1, pole9_2, pole9_3);
	std::cout << "osada 10:" << std::endl;
	}

void Test::przypiszOknoWyswietlania(RenderWindow * okno)
{
	this->okno = okno;
}

void Test::inicjujTesteraBudowniczych()
{
	czcionki = new DystrybutorCzcionek();
	tekstury = new DystrybutorTekstur();
	wartosci = new DystrybutorWartosci();
	PlanszaBuilder * builder = new LosowaPlanszaBuilder();
	builder->przypiszDystrybutory(tekstury, czcionki, wartosci);
	this->builder = builder;
}

void Test::testBudowaniaPola()
{
	builder->budujPlansze();
	builder->budujPole(Surowiec::drewno);
	builder->nastepnaKolumna();
	builder->budujPole(Surowiec::glina);
	builder->nastepnaKolumna();
	builder->budujPole(Surowiec::kamien);
	builder->nastepnyWiersz();
	builder->budujPole(Surowiec::welna);
	builder->nastepnaKolumna();
	builder->budujPole(Surowiec::zboze);
	plansza = builder->zwrocPlansze();
	cout << "Zakonczono tworzenie pola." << endl;
}
void Test::testBudowaniaMorza()
{
	builder->budujPlansze();
	builder->budujMorze();
	plansza = builder->zwrocPlansze();
	cout << "Zakonczono tworzenie morza." << endl;
}
void Test::inicjalizacjaInterfejsu()
{
	hud = new HUD();
}
void Test::testOdtwarzaniaSchematu()
{
	Konwerter konwerter;
	konwerter.przypiszBudowniczego(builder);
	konwerter.przetworzSchemat();
	plansza = konwerter.zwrocPlansze();
}
void Test::testBudowaniaPustyni()
{
	builder->budujPlansze();
	builder->budujPustynie();
	plansza = builder->zwrocPlansze();
	cout << "Zakonczono tworzenie pustyni." << endl;
}

void Test::testWyswietlania()
{
	plansza->wyswietlPlansze(*okno, Ustawienia::przewijanie);
	hud->wyswietlPanele(*okno);
}

Text Test::testDystrybutoraCzcionek()
{

	Text tekst;
	string tresc = "test";
	tekst.setFont(*czcionki->pobierzLosowaCzcionke(menu));
	tekst.setCharacterSize(56);
	tekst.setColor(Color(255,255,255));
	tekst.setString(tresc);
	return tekst;
}

void Test::inicjujTestLokalizacjiOsad()
{
	CircleShape * kulka;

	for (int i = 0; i < 15; i++) {
		for (int j = 0;j < 15;j++) {
			kulka = new CircleShape;
			kulka->setPosition(OSADA_BAZA_X + (PRZESUNIECIE_X * i / 2), OSADA_BAZA_Y + (PRZESUNIECIE_Y * j) + ((i+j)%2? 0.0f : OSADA_PRZESUNIECIE_DODATKOWE_Y));
			kulka->setRadius(32.0f);
			kulka->setFillColor(Color(255, 255, 255, 224));
			dzialki.push_back(kulka);
		}
	}
}

void Test::wyswietlOsady()
{
	for (int i = 0; i < dzialki.size(); i++) {
		okno->draw(*dzialki[i]);
	}
}

void Test::inicjujTestLokalizacjiDrog()
{
	RectangleShape * prostokat;

	for (int i = 0; i < 15; i++) {
		for (int j = 0;j < 15;j++) {
			prostokat = new RectangleShape;
			prostokat->setPosition(i%2? DROGA_BAZA_PION + (((i+1) % 4) ? 0.0f : MODYFIKATOR_RZEDU_NIEPARZYSTEGO) +(PRZESUNIECIE_X*j): DROGA_BAZA_X + (PRZESUNIECIE_X*j / 2) , i*PRZESUNIECIE_Y/2 + DROGA_BAZA_Y);
			prostokat->setOrigin(Vector2f(64.0f, 8.0f));
			prostokat->setRotation(i % 2 ? 90 : (i % 4 ? (j % 2 ? 150 : 30) : (j % 2 ? 30 : 150)));
			prostokat->setSize(Vector2f(128.0f, 16.0f));
			prostokat->setFillColor(Color(255, 255, 255, 224));
			drozki.push_back(prostokat);
		}
	}
}

void Test::wyswietlDrogi()
{
	for (int i = 0; i < drozki.size(); i++) {
		okno->draw(*drozki[i]);
	}
}

void Test::inicjujTestLokalizacjiPortow()
{
	CircleShape * kolo;

	for (int i = 0; i < 15; i++) {
		for (int j = 0;j < 15;j++) {
			kolo = new CircleShape;
			kolo->setPosition(i % 2 ? DROGA_BAZA_PION + (((i + 1) % 4) ? 0.0f : MODYFIKATOR_RZEDU_NIEPARZYSTEGO) + (PRZESUNIECIE_X*j) : DROGA_BAZA_X + (PRZESUNIECIE_X*j / 2), i*PRZESUNIECIE_Y / 2 + DROGA_BAZA_Y);
			kolo->setOrigin(Vector2f(32.0f, 32.0f));
			kolo->setRadius(32.0f);

			kolo->setFillColor(Color(0, 255, 255, 224));
			dzialki.push_back(kolo);
		}
	}
}


