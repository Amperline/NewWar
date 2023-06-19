#include "Menu.h"

Menu::Menu(sf::RenderWindow* window, UseVariation usevariation, std::string fileName,
	int time_switcher, int valueOfImgs_Frames)
	:Animation(window, usevariation, fileName, time_switcher, valueOfImgs_Frames)
{
	m_sprt.setScale(6, 6);
}

void Menu::checkAll()
{
	Animation::checkAnim();
}

void Menu::draw()
{
	Animation::draw();
}
