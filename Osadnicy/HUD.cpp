#include "HUD.hpp"

HUD::HUD()
{
	panelePrzewijania.push_back(PanelPrzewijania(Kierunek::dol));
	panelePrzewijania.push_back(PanelPrzewijania(Kierunek::gora));
	panelePrzewijania.push_back(PanelPrzewijania(Kierunek::prawo));
	panelePrzewijania.push_back(PanelPrzewijania(Kierunek::lewo));
}

void HUD::wyswietlPanele(RenderWindow & okno)
{
	for (int i = 0; i < panelePrzewijania.size(); i++) {
		panelePrzewijania[i].wyswietl(okno);
		panelePrzewijania[i].przewin(okno);
	}
}
