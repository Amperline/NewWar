#pragma once
#include <NewWar/NewWarLib.h>
#include "FlagsStruct.h"
#include "Resources.h"
#include "Object.h"
#include "Chest.h"
#include <vector>
#include <array>

class Character
{
	enum PlayerStatus
	{
		NORMAL,
		CARRYING
	};
private:
	KeyFlags* m_KEYflags;

	float currFrame = 0;
	sf::RenderWindow* m_window;
	PlayerStatus playerStat = NORMAL;

	sf::Image m_img;
	sf::Texture m_txtr;
	sf::Sprite m_sprt;

	std::array<sf::IntRect, 4> NormalDown;
	std::array<sf::IntRect, 4> NormalUp;
	std::array<sf::IntRect, 4> NormalLeft;
	std::array<sf::IntRect, 4> NormalRight;
	
	std::array<sf::IntRect, 4> CarryingDown;
	std::array<sf::IntRect, 4> CarryingUp;
	std::array<sf::IntRect, 4> CarryingLeft;
	std::array<sf::IntRect, 4> CarryingRight;

	bool Down;
	bool Up;
	bool Left;
	bool Right;

	void checkAnim(float time);
public:
	short lastSide = 2;
	std::array<Object*, 33> ObjectsLine;
	Object** CurrOb;
	Character(sf::RenderWindow* window, sf::Vector2f startPos);
	sf::Sprite& ownSprt() { return m_sprt; }
	void checkAll(float time);
	sf::Sprite& getSprite() { return m_sprt; }
	void draw();
	sf::FloatRect getFloatRect();
	bool getSIDE(int side);
	void setKeyflags(KeyFlags* KeyFlags) { m_KEYflags = KeyFlags; }
	void setCurrOb(short index);
	bool ownObject(Object* ob);
	void swapOB(int ind1, int ind2);
	void throwObject(short index);
	void swapWithChest(Chest* chest, int indChar, int indChest);
	friend class Chest;
};