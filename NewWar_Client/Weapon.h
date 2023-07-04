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
		Pistol,
		MachineGun
	};
private:
	sf::IntRect RightSide;
	sf::IntRect LeftSide;
	WeaponType Type;
public:
	Weapon(sf::RenderWindow* window, std::string FileName, std::string name, ObjectStatus obStat, WeaponType type,
		sf::Vector2f normalScale, sf::Vector2f presentScale, sf::Vector2f startPos);
	void checkAll (float time);
	std::string identify() override{ if (Type == Carbine || Type == MachineGun) { return "Main"; } else if (Type == Pistol) { return "Pistol"; } }
};

