#include "Tree.h"

Tree::Tree(sf::RenderWindow* window, std::list<Resources*>* resArr,TreeType treetype, sf::Vector2f StartPos, ObjectStatus obSt)
	:Object(window, "resource/images/Trees/Trees", std::string("Tree"), ObjectStatus::USED,
	sf::Vector2f(6, 6), sf::Vector2f(6, 6)), treeType(treetype), resPtrArr(resArr)
{
	if(treeType == SMALL)
	{
		m_sprt.setTextureRect(sf::IntRect(0, 0, 20, 42));
		m_sprt.setOrigin(0, 42);
	}
	else if (treeType == MID)
	{
		m_sprt.setTextureRect(sf::IntRect(21, 0, 19, 68));
		m_sprt.setOrigin(0, 68);
	}
	else if (treeType == BIG)
	{
		m_sprt.setTextureRect(sf::IntRect(40, 0, 20, 102));
		m_sprt.setOrigin(0, 102);
	}
	m_sprt.setPosition(StartPos);
	getScaleUsed() = sf::Vector2f(6, 6);
	DeathAble = 1;
	hp = 100;
}

std::string Tree::identify()
{
	if(treeType == TreeType::SMALL) return std::string("small");
	else if (treeType == TreeType::MID) return std::string("mid");
	else if (treeType == TreeType::BIG) return std::string("big");
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
				resPtrArr->push_back(new Resources(m_window, m_sprt.getPosition(), 100, std::string("Wood"), ObjectStatus::GROUND, Resources::ResourceType::WOOD));
			}
			else if (treeType == MID)
			{
				resPtrArr->push_back(new Resources(m_window, m_sprt.getPosition(), 100, std::string("Wood"), ObjectStatus::GROUND, Resources::ResourceType::WOOD));
				resPtrArr->push_back(new Resources(m_window, m_sprt.getPosition(), 50, std::string("Wood"), ObjectStatus::GROUND, Resources::ResourceType::WOOD));
			}
			else if (treeType == BIG)
			{
				resPtrArr->push_back(new Resources(m_window, m_sprt.getPosition(), 100, std::string("Wood"), ObjectStatus::GROUND, Resources::ResourceType::WOOD));
				resPtrArr->push_back(new Resources(m_window, m_sprt.getPosition(), 100, std::string("Wood"), ObjectStatus::GROUND, Resources::ResourceType::WOOD));
				resPtrArr->push_back(new Resources(m_window, m_sprt.getPosition(), 100, std::string("Wood"), ObjectStatus::GROUND, Resources::ResourceType::WOOD));
			}
			LifeStat = DEAD;
		}
	}
	else if (LifeStat == DEAD)
	{
		END = 1;
	}
}
