#include "Weapon.h"
#include <cmath>
#define PI 3.14159265358979323846

Weapon::Weapon(sf::RenderWindow* window, std::string FileName, std::string name, ObjectStatus obStat, WeaponType type, sf::Vector2f normalScale, sf::Vector2f presentScale, sf::Vector2f startPos)
	:Object(window, FileName, name, obStat, normalScale, presentScale), Type(type)
{
	if(Type == WeaponType::Carbine)
	{
		m_sprt.setOrigin(3, 11);
		RightSide = sf::IntRect(0, 0, 6, 18);
		LeftSide = sf::IntRect(6, 0, -6, 18);
	}
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
	if (mousePosition.x > plPos.x)
		m_sprt.setTextureRect(RightSide);
	else if(mousePosition.x < plPos.x)
		m_sprt.setTextureRect(LeftSide);
}