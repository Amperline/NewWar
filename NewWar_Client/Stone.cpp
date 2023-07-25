#include "Stone.h"
Stone::Stone(sf::RenderWindow* window, std::list<Resources*>* resArr, StoneType treetype, sf::Vector2f StartPos, ObjectStatus obSt)
	:Object(window, "resource/images/Stones/Stones", std::string("Tree"), ObjectStatus::USED,
		sf::Vector2f(6, 6), sf::Vector2f(6, 6)), stoneType(treetype), resPtrArr(resArr)
{
	if (stoneType == SMALL)
	{
		m_sprt.setTextureRect(sf::IntRect(0, 0, 10, 7));
		m_sprt.setOrigin(0, 7);
	}
	else if (stoneType == MID)
	{
		m_sprt.setTextureRect(sf::IntRect(20, 0, 13, 7));
		m_sprt.setOrigin(0, 7);
	}
	else if (stoneType == BIG)
	{
		m_sprt.setTextureRect(sf::IntRect(40, 0, 15, 12));
		m_sprt.setOrigin(0, 12);
	}
	m_sprt.setPosition(StartPos);
	getScaleUsed() = sf::Vector2f(6, 6);
	DeathAble = 1;
	hp = 100;
}

std::string Stone::identify()
{
	if (stoneType == StoneType::SMALL) return std::string("small");
	else if (stoneType == StoneType::MID) return std::string("mid");
	else if (stoneType == StoneType::BIG) return std::string("big");
}

void Stone::checkAll(float time)
{
	Object::checkAll(time);
}

void Stone::checkDeath()
{
	if (LifeStat == ALIFE)
	{
		if (hp <= 0)
		{
			if (stoneType == SMALL)
			{
				resPtrArr->push_back(new Resources(m_window, m_sprt.getPosition(), 100, std::string("Stone"), ObjectStatus::GROUND, Resources::ResourceType::STONE));
			}
			else if (stoneType == MID)
			{
				resPtrArr->push_back(new Resources(m_window, m_sprt.getPosition(), 100, std::string("Stone"), ObjectStatus::GROUND, Resources::ResourceType::STONE));
				resPtrArr->push_back(new Resources(m_window, m_sprt.getPosition(), 50, std::string("Stone"), ObjectStatus::GROUND, Resources::ResourceType::STONE));
			}
			else if (stoneType == BIG)
			{
				resPtrArr->push_back(new Resources(m_window, m_sprt.getPosition(), 100, std::string("Stone"), ObjectStatus::GROUND, Resources::ResourceType::STONE));
				resPtrArr->push_back(new Resources(m_window, m_sprt.getPosition(), 100, std::string("Stone"), ObjectStatus::GROUND, Resources::ResourceType::STONE));
				resPtrArr->push_back(new Resources(m_window, m_sprt.getPosition(), 100, std::string("Stone"), ObjectStatus::GROUND, Resources::ResourceType::STONE));
			}

			LifeStat = DEAD;
		}
	}
	else if (LifeStat == DEAD)
	{
		END = 1;
	}
}