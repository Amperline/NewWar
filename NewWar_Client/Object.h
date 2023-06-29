#pragma once
#include <NewWar/NewWarLib.h>

class Object
{
public:
	enum ObjectStatus
	{
		INPLAYER,
		INVENT,
		GROUND,
		USED
	};
protected:
	std::string Name;

	sf::Image m_img;
	sf::Texture m_txtr;
	sf::Sprite m_sprt;
	sf::Sprite m_sprtPresent;

	sf::Vector2f m_scaleNorm;
	sf::Vector2f m_scalePresent;
	ObjectStatus ObStat;
	sf::RenderWindow* m_window;
	sf::Vector2i m_posSet;

	bool Owned;
	bool AnimGround;
	int counterAnim = 0;
public:
	Object(sf::RenderWindow* window, std::string fileName, std::string name, ObjectStatus obSt, sf::Vector2f scaleNorm = sf::Vector2f(1, 1),
		sf::Vector2f scalePresent = sf::Vector2f(1, 1));
	sf::Vector2i& getPosSet() { return m_posSet; }
	void setObStat(ObjectStatus obstat) { ObStat = obstat; }
	virtual void checkAll(float time);
	virtual void draw();
};

