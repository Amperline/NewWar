#include "Resources.h"

Resources::Resources(sf::RenderWindow* window, sf::Vector2f StartPos, int valueofStack, std::string name, ObjectStatus obSt, ResourceType typeRes)
	:Object(window, std::string("resource/images/GameRes/Resources"), name, obSt, sf::Vector2f(6, 6), sf::Vector2f(6, 6)),
	TypeRes(typeRes), m_valueOfStack(valueofStack)
{
	m_sprt.setPosition(StartPos);
	setDeathAble(1);
	if (TypeRes == WOOD) {
		m_sprt.setTextureRect(sf::IntRect(0, 0, 10, 10));
		m_sprtPresent.setTextureRect(sf::IntRect(0, 0, 10, 10));
	}
	else if (TypeRes == STONE) {
		m_sprt.setTextureRect(sf::IntRect(14, 0, 10, 10));
		m_sprtPresent.setTextureRect(sf::IntRect(14, 0, 10, 10));
	}
	
	groundPos = StartPos;
	LifeTimer.restart();
	hp = 1;
	m_sprtPresent.setScale(6.4, 6.4);
	m_sprtPresent.setOrigin(-2, -2);
}

void Resources::checkDeath()
{
	if (ObStat == INPLAYER || ObStat == INVENT) LifeTimer.restart();
	if (LifeStat == ALIFE && ObStat == GROUND)
	{
		if(LifeTimer.getElapsedTime().asMilliseconds() > 14000)
		{
			LifeStat = DEAD;
		}
	}
	Object::checkDeath();
}

std::string Resources::identify()
{
	if (TypeRes == WOOD) { return std::string("wood"); }
	else if (TypeRes == STONE) { return std::string("stone"); }
}

