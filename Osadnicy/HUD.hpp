#pragma once
#include "PanelPrzewijania.hpp"
#include <vector>

class HUD {
private:
	std::vector<PanelPrzewijania> panelePrzewijania;
public:
	HUD();
	void wyswietlPanele(RenderWindow & okno);

};