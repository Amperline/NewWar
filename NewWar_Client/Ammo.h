#pragma once
#include <NewWar/NewWarLib.h>

class Ammo
{
public:
	enum AMMOVAR
	{
		SMALL,
		MIDD,
		BIG
	};
private:
	AMMOVAR AmmoVar;
	sf::RenderWindow* m_window;
	sf::Image m_img;
	sf::Texture m_txtr;
	sf::Sprite m_sprt;

	float angle;
	sf::Vector2f vector;
public:
	Ammo(sf::RenderWindow* window, AMMOVAR ammoVar, sf::Vector2f Start, sf::Vector2f Finish, float angle);
	void check(float time);
	void draw();
};

