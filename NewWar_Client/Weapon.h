#pragma once
#include <string>
#include "Character.h"
#include "Object.h"
#include <list>
#include "Ammo.h"

class Weapon : public Object
{
public:
	enum LEVEL
	{
		Initial,
		Provecta,
		Electi
	};
	enum WeaponType
	{
		Carbine,
		Pistol,
		MachineGun
	};
private:
	sf::Clock FireTimer;
	sf::Clock ReloadTimer;
	sf::IntRect RightSide;
	sf::IntRect LeftSide;
	LEVEL lvl;
	WeaponType Type;
	std::list<Ammo*>* m_ammos;
	int AmmoVal = 0;
	int AmmoValMax1 = 0;
	const int& AmmoValMax = AmmoValMax1;
	bool Reload = 0;
	float timeR = 0;
public:
	Weapon(sf::RenderWindow* window, std::list<Ammo*>* ammos, std::string name, ObjectStatus obStat, WeaponType type, LEVEL level, sf::Vector2f normalScale, sf::Vector2f startPos);
	void checkAll (float time);
	std::string identify() override{ if (Type == Carbine || Type == MachineGun) { return "Main"; } else if (Type == Pistol) { return "Pistol"; } }
	std::string getMiniInfoDefault() override;
};

