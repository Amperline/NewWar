#include "Object.h"

Object::Object(sf::RenderWindow* window, std::string fileName, std::string name, ObjectStatus obSt, sf::Vector2f scaleNorm,
	sf::Vector2f scalePresent)
	: ObStat(obSt), m_scaleNorm(scaleNorm), m_scalePresent(scalePresent), m_window(window), Name(name)
{
	m_img.loadFromFile(fileName + ".png");
	m_txtr.loadFromImage(m_img);
	m_sprt.setTexture(m_txtr);
	m_sprtPresent = m_sprt;
	if (ObStat == ObjectStatus::INPLAYER) { m_sprt.setScale(scaleNorm); }
	if(ObStat == ObjectStatus::INVENT || ObStat == ObjectStatus::INPLAYER)
	{
		Owned = 1;
	}
}

void Object::checkAll(float time)
{
	
	if(ObStat == ObjectStatus::GROUND)
	{
		m_sprt.setRotation(90);
		counterAnim += 0.005 * time;
		if (counterAnim >= 4) AnimGround = 1;
		if (counterAnim >= 8) counterAnim = 0; AnimGround = 0;
		if(AnimGround == 0)
		{
			m_sprt.move(0, -0.05 * time);
		}
		else if(AnimGround == 1)
		{
			m_sprt.move(0, 0.05 * time);
		}
	}
	if(ObStat == ObjectStatus::INPLAYER)
	{
		m_sprt.setPosition(sf::Vector2f(m_posSet));
	}
}

void Object::draw()
{
	m_window->draw(m_sprtPresent);
}
