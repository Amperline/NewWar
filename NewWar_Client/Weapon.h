#pragma once
#include "Character.h"
#include "Object.h"
#include <list>

class Weapon : public Object
{
public:
	enum WeaponType
	{
		Carbine,
		MachineGun
	};
private:
	sf::IntRect RightSide;
	sf::IntRect LeftSide;
	Character* m_owner = NULL;
	WeaponType Type;
public:
	Weapon(sf::RenderWindow* window, std::string FileName, std::string name, ObjectStatus obStat, WeaponType type,
		sf::Vector2f normalScale, sf::Vector2f presentScale, sf::Vector2f startPos);
	void setOwner(Character* owner) { m_owner = owner; }
	void checkAll (float time, sf::Vector2i forAngle);
};

