#include "Weapon.h"

Weapon::Weapon(sf::RenderWindow* window, std::string FileName, std::string name, ObjectStatus obStat, WeaponType type, sf::Vector2f normalScale, sf::Vector2f presentScale, sf::Vector2f startPos)
	:Object(window, FileName, name, obStat, normalScale, presentScale), Type(type)
{
	if(Type == WeaponType::Carbine)
	{
		RightSide = sf::IntRect(0, 0, 6, 18);
		LeftSide = sf::IntRect(0, 6, 0, 18);
	}
}

void Weapon::checkAll(float time, sf::Vector2i MousePos)
{
	if (m_owner != NULL)
	{
		if (MousePos.x > (m_owner->getSprt().getPosition().x + 60))
			m_sprt.setTextureRect(RightSide);
		else if (MousePos.x < (m_owner->getSprt().getPosition().x + 60))
			m_sprt.setTextureRect(LeftSide);
	}
	Object::checkAll(time);
	sf::Vector2f distance = sf::Vector2f(MousePos) - m_sprt.getPosition();
	float angle = std::atan2(distance.y, distance.x) * 180 / 3.14;
	m_sprt.setRotation(angle);
}