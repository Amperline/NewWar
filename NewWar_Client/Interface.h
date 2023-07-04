#pragma once
#include "Character.h"

class Interface
{
public:
	enum InterfaceStatus
	{
		DEFAULT,
		INVENTORY,
		SETTINGS
	};
private:
	InterfaceStatus InterfStat = DEFAULT;

	sf::RenderWindow* m_window;
	sf::Image Line_img;
	sf::Texture Line_txtr;
	sf::Sprite Line_sprt;

	sf::Image Invnt_img;
	sf::Texture Invnt_txtr;
	sf::Sprite Invnt_sprt;

	sf::Image Curr_img;
	sf::Texture Curr_txtr;
	sf::Sprite Curr_sprt;

	Character* player;
public:
	Interface(sf::RenderWindow* window, Character* pl);
	void checkAll();
	void draw();
};

