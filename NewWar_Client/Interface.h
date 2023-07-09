#pragma once
#pragma warning( disable : 4430 )
#include "Character.h"
#include <NewWar/GameString.h>

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
	sf::Clock PressTimer;

	bool TABBED;
	bool PRESSED;
	bool PERMISSION;
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

	sf::Image CURR_img;
	sf::Texture CURR_txtr;
	sf::Sprite CURR_sprt;
	Character* player;
public:
	Interface(sf::RenderWindow* window, Character* pl);
	InterfaceStatus& getStatus() { return InterfStat; }
	void checkKeys();
	void checkAll();
	void draw();
};

