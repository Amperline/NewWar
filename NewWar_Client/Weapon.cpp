#include "Weapon.h"
#include <cmath>
#define PI 3.14159265358979323846

Weapon::Weapon(sf::RenderWindow* window, std::string FileName, std::list<Ammo*>* ammos, std::string name, ObjectStatus obStat, WeaponType type, sf::Vector2f normalScale, sf::Vector2f startPos)
	:Object(window, FileName, name, obStat, normalScale, m_scalePresent), Type(type), m_ammos(ammos)
{
	if (Type == Pistol)
	{
	}
	else if (Type == Carbine)
	{
		AmmoValMax1 = 30;
		AmmoVal = 30;
		m_sprt.setOrigin(3, 11);
		RightSide = sf::IntRect(0, 0, 6, 18);
		LeftSide = sf::IntRect(6, 0, -6, 18);
	}
	else if (Type == MachineGun)
	{
	}
	m_sprtPresent.setScale(4.4, 4.4);
	m_sprtPresent.setOrigin(0, 18);
	m_sprtPresent.setRotation(90);
}

void Weapon::checkAll(float time)
{
	Object::checkAll(time);

	sf::Vector2i mousePosition = sf::Mouse::getPosition(*m_window);
	sf::Vector2f worldPosition = m_window->mapPixelToCoords(mousePosition);
	sf::Vector2f direction = worldPosition - m_sprt.getPosition();
	float angleRadians = std::atan2(direction.y, direction.x);
	float angleDegrees = angleRadians * 180 / PI;
	sf::Vector2f plPos(m_sprt.getGlobalBounds().left, m_sprt.getGlobalBounds().top);
	m_sprt.setRotation(angleDegrees + 90);

	float temprAngle = m_sprt.getRotation();
	if (temprAngle >= 0 && temprAngle < 180)
	{
		m_sprt.setTextureRect(RightSide);
	}
	else
		m_sprt.setTextureRect(LeftSide);
	if(ObStat == INPLAYER)
	{
		if(sf::Keyboard::isKeyPressed(sf::Keyboard::R))
		{
			Reload = 1;
		}
		if (AmmoVal < AmmoValMax && Reload == 1)
		{
			if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
			{
				ReloadTimer.restart();
			}
			if (ReloadTimer.getElapsedTime().asMilliseconds() > 500)
			{
				++AmmoVal;
				ReloadTimer.restart();
			}
		}
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && FireTimer.getElapsedTime().asMilliseconds() > 100)
		{
			if (AmmoVal <= AmmoValMax && AmmoVal != 0)
			{
				m_sprt.setOrigin(0, 3);
				if (Type == Pistol)
				{
					m_ammos->push_back(new Ammo(m_window, Ammo::AMMOVAR::SMALL, m_sprt.getPosition(), m_sprt.getRotation() - 90));
				}
				else if (Type == Carbine)
				{
					m_ammos->push_back(new Ammo(m_window, Ammo::AMMOVAR::MIDD, m_sprt.getPosition(), m_sprt.getRotation() - 90));
				}
				else if (Type == MachineGun)
				{
					m_ammos->push_back(new Ammo(m_window, Ammo::AMMOVAR::BIG, m_sprt.getPosition(), m_sprt.getRotation() - 90));
				}
				m_sprt.setOrigin(3, 11);
				--AmmoVal;
				Reload = 0;
				FireTimer.restart();
			}
		} 
	}
	else
	{
		Reload = 0;
	}
}

std::string Weapon::getMiniInfoDefault()
{
	return std::string(std::to_string(AmmoValMax) + "\\" + std::to_string(AmmoVal));
}
