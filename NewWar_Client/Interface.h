#pragma once
#pragma warning( disable : 4430 )
#include <list>
#include "Object.h"
#include "Character.h"
#include "Chest.h"
#include <NewWar/GameString.h>
#include "FlagsStruct.h"

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
	int* currObInChest = nullptr;
	Character* player = nullptr;
	KeyFlags* m_KEYflags;
	Chest* m_CurrChest = nullptr;
	InterfaceStatus InterfStat = DEFAULT;
	sf::Clock PressTimer;
	sf::Clock OwnTimer;

	bool TABBED = 0;
	bool PRESSED = 0;
	bool PERMISSION = 0;

	bool ButtonMpressed = 0;
	bool ButtonMpressed2 = 0;
	bool ButtonMpressed3 = 1;
	bool InventIsSwap = 0;

	sf::RenderWindow* m_window;

	sf::Image Bin_img;
	sf::Texture Bin_txtr;
	sf::Sprite Bin_sprt;

	sf::Image Icon_img;
	sf::Texture Icon_txtr;
	sf::Sprite Icon_sprt;

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

	sf::Image ChestIntf_img;
	sf::Texture ChestIntf_txtr;
	sf::Sprite ChestIntf_sprt;

public:
	Interface(sf::RenderWindow* window, Character* pl);
	InterfaceStatus& getStatus() { return InterfStat; }
	void setKeyflags(KeyFlags* KeyFlags) { m_KEYflags = KeyFlags; }
	void checkKeys();
	void checkAll(std::list<Chest*>& CHESTS);
	void draw(std::list<Object*>& OBJECTS);
};

