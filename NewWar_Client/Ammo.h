#pragma once
#include <NewWar/NewWarLib.h>
#include <array>
#define PI 3.14159265358979323846

class Ammo
{
public:
	enum AMMOVAR
	{
		SMALL,
		MIDD,
		BIG
	};
	enum LIFE_STATUS
	{
		ALIFE,
		DEAD
	};
private:
	LIFE_STATUS LifeStat;
	AMMOVAR AmmoVar;
	sf::RenderWindow* m_window;
	sf::Image m_img;
	sf::Texture m_txtr;
	sf::Sprite m_sprt;
	std::array<sf::IntRect, 3> m_txtrRects;

	float m_angle;
	sf::Vector2f vector;
	sf::Clock TimerAnim;
	sf::Clock TimertoDeath;
	bool Dead;
	bool END;
public:
	Ammo(sf::RenderWindow* window, AMMOVAR ammoVar, sf::Vector2f Start, float angle);
	void death();
	void check(float time);
	LIFE_STATUS& getLifeStat() { return LifeStat; }
	bool getEnd() { return END; }
	void draw();
	~Ammo();
};

