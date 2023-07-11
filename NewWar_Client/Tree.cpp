#include "Tree.h"

Tree::Tree(sf::RenderWindow* window, std::list<Resources*>* resArr,TreeType treetype, sf::Vector2f StartPos, ObjectStatus obSt)
	:Object(window, "resource/images/Trees/Tree", std::string("Tree"), ObjectStatus::USED,
	sf::Vector2f(6, 6), sf::Vector2f(6, 6)), treeType(treetype), resPtrArr(resArr)
{
	if(treeType == SMALL)
	{
		m_sprt.setTextureRect(sf::IntRect(0, 0, 21, 42));
	}
	else if (treeType == MID)
	{
	}
	else if (treeType == BIG)
	{
	}
	m_sprt.setPosition(StartPos);
	getScaleUsed() = sf::Vector2f(6, 6);
	DeathAble = 1;
	hp = 100;
}

void Tree::checkAll(float time)
{
	Object::checkAll(time);
}

void Tree::checkDeath()
{
	if (LifeStat == ALIFE)
	{
		if (hp <= 0)
		{
			if (treeType == SMALL)
			{
				resPtrArr->push_back(new Resources(m_window, m_sprt.getPosition(), valOfDrop, std::string("Wood"), ObjectStatus::GROUND, Resources::ResourceType::WOOD));
			}
			else if (treeType == MID)
			{
				resPtrArr->push_back(new Resources(m_window, m_sprt.getPosition(), valOfDrop, std::string("Wood"), ObjectStatus::GROUND, Resources::ResourceType::WOOD));
			}
			else if (treeType == BIG)
			{
				resPtrArr->push_back(new Resources(m_window, m_sprt.getPosition(), valOfDrop, std::string("Wood"), ObjectStatus::GROUND, Resources::ResourceType::WOOD));
			}
			
			LifeStat = DEAD;
		}
	}
	else if (LifeStat == DEAD)
	{
		END = 1;
	}
}
