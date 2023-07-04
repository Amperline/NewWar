#pragma once
#include <NewWar/NewWarLib.h>
#include "Object.h"
#include <vector>
#include <array>
#include "Interface.h"

class Character
{
	enum PlayerStatus
	{
		NORMAL,
		CARRYING
	};
private:
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

	short lastSide = 1;
	void checkAnim(float time);
	std::array<Object*, 36> ObjectsLine;
	Object** CurrOb;
public:
	Character(sf::RenderWindow* window, sf::Vector2f startPos);
	sf::Sprite& ownSprt() { return m_sprt; }
	void checkAll(float time);
	sf::Sprite& getSprite() { return m_sprt; }
	void draw();
	bool ownObject(Object* ob);
	void throwObject(short index);
	
	friend Object;
	friend Interface;
};