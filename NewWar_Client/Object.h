#pragma once
#include <NewWar/NewWarLib.h>
#include "FlagsStruct.h"

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
	enum LIFE_STATUS
	{
		ALIFE,
		DEAD
	};
protected:
	KeyFlags* m_KEYflags = nullptr;

	LIFE_STATUS LifeStat;
	std::string Name;
	sf::Clock LifeTimer;

	sf::Image m_img;
	sf::Texture m_txtr;
	sf::Sprite m_sprt;
	sf::Sprite m_sprtPresent;

	sf::Vector2f m_scaleNorm;
	sf::Vector2f m_scalePresent;
	sf::Vector2f m_scaleUsed;
	ObjectStatus ObStat;
	sf::RenderWindow* m_window;
	sf::Vector2i m_posSet;

	sf::Vector2f groundPos;
	bool AnimGround;
	bool groundPause = 0;

	bool ClockLife = 0;
	bool DeathAble = 1;
	bool END;
	int hp;
public:
	Object(sf::RenderWindow* window, std::string fileName, std::string name, ObjectStatus obSt, sf::Vector2f scaleNorm = sf::Vector2f(1, 1),
		sf::Vector2f scalePresent = sf::Vector2f(1, 1));
	sf::Vector2i& getPosSet() { return m_posSet; }
	void setObStat(ObjectStatus obstat) { ObStat = obstat; }
	sf::Sprite& getSprite() { return m_sprt; }
	sf::Sprite& getPresentSprite() { return m_sprtPresent; }
	ObjectStatus getObStat() { return ObStat; }
	sf::Vector2f& getScaleUsed() { return m_scaleUsed; }

	LIFE_STATUS getlifeStat() { return LifeStat; }
	void setDeathAble(bool val) { DeathAble = val; }
	int& getHP() { return hp; }
	void death();
	bool getEnd() { return END; }
	void setClockLife(bool val) { ClockLife = val; }
	virtual void checkDeath();
	void setGrPause(bool val) { groundPause = val; }
	void setKeyflags(KeyFlags* KeyFlags) { m_KEYflags = KeyFlags; }
	
	sf::Vector2f& getGroundPos() { return groundPos; }

	virtual std::string getMiniInfoDefault() { return std::string(""); }
	virtual std::string identify() { return "default"; }
	virtual void checkAll(float time);
	virtual void draw();
};

