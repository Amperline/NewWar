#pragma once
#pragma once
#include "Object.h"
#include"Resources.h"
#include <list>

class Stone : public Object
{
public:
	enum StoneType
	{
		SMALL,
		MID,
		BIG
	};
private:
	std::list<Resources*>* resPtrArr;
	int valOfDrop = 0;
	StoneType stoneType;
public:
	Stone(sf::RenderWindow* window, std::list<Resources*>* resArr, StoneType treetype, sf::Vector2f StartPos, ObjectStatus obSt);
	std::string identify() override;
	void checkAll(float time);
	void checkDeath() override;
};
