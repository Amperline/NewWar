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
	LifeTimer.restart();
}

void Object::death()
{
	LifeStat = DEAD;
}

void Object::checkDeath()
{
	if (LifeStat == ALIFE)
	{
		if (ObStat == INPLAYER || ObStat == INVENT) LifeTimer.restart();
		if (ObStat == GROUND && ClockLife == 1)
		{
			if (LifeTimer.getElapsedTime().asSeconds() > 60)
			{
				LifeStat = DEAD;
			}
		}
		if (hp <= 0)
		{
			LifeStat = DEAD;
		}
	}
	else if (LifeStat == DEAD)
	{
		END = 1;
	}
}

void Object::checkAll(float time)
{
	if(ObStat == ObjectStatus::INPLAYER)
	{
		m_sprt.setPosition(sf::Vector2f(m_posSet));
	}
	else if(ObStat == ObjectStatus::GROUND)
	{
		if (!groundPause)
		{
			if (AnimGround == 0 && (m_sprt.getPosition().y >= (groundPos.y - 50)))
			{
				m_sprt.move(0, -0.06 * time);
			}
			else { AnimGround = 1; }
			if (AnimGround == 1 && (m_sprt.getPosition().y < groundPos.y))
			{
				m_sprt.move(0, 0.05 * time);
			}
			else { AnimGround = 0; }
		}
		else { groundPos = m_sprt.getPosition(); }
	}
	else if (ObStat == ObjectStatus::USED)
	{
		m_sprt.setScale(m_scaleUsed);
	}
	if (DeathAble)
	{
		checkDeath();
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
