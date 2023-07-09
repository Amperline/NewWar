#include "Object.h"

Object::Object(sf::RenderWindow* window, std::string fileName, std::string name, ObjectStatus obSt, sf::Vector2f scaleNorm,
	sf::Vector2f scalePresent)
	: ObStat(obSt), m_scaleNorm(scaleNorm), m_scalePresent(scalePresent), m_window(window), Name(name)
{
	m_img.loadFromFile(fileName + ".png");
	m_txtr.loadFromImage(m_img);
	m_sprt.setTexture(m_txtr);
	m_sprtPresent = m_sprt;
	m_sprt.setScale(m_scaleNorm);
	m_sprtPresent.setScale(m_scalePresent);
}

void Object::death()
{
	LifeStat = DEAD;
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
	if (LifeStat == ALIFE)
	{
		if(hp <= 0)
		{
			LifeStat = DEAD;
		}
	}
	else if (LifeStat == DEAD)
	{
		END = 1;
	}
}

void Object::draw()
{
	if(ObStat == ObjectStatus::INPLAYER 
		|| ObStat == ObjectStatus::USED
		||ObStat == ObjectStatus::GROUND)
	{
		m_window->draw(m_sprt);
	}
	else if (ObStat == ObjectStatus::INVENT)
	{
		m_window->draw(m_sprtPresent);
	}
}
