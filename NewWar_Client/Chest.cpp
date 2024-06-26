#include "Chest.h"

Chest::Chest(sf::RenderWindow* window, ObjectStatus obSt, sf::Vector2f startPos)
	:Block(window, "resource/images/Blocks/Chest", "Chest", obSt)
{
	setDeathAble(0);
	hp = 1;
	m_sprt.setPosition(startPos);
	for(auto i : m_objets)
	{
		i = nullptr;
	}
}

bool Chest::ownObject(Object* ob, int ind)
{
	return false;
}

void Chest::swapOB(int ind1, int ind2)
{
	if (ind1 != ind2)
	{
		Object& ptr = *m_objets[ind2];
		m_objets[ind2] = m_objets[ind1];
		m_objets[ind1] = &ptr;
	}
}

void Chest::throwObject(short index)
{
	if (m_objets[index] != nullptr)
	{
		m_objets[index]->setKeyflags(nullptr);
		m_objets[index]->setObStat(Object::GROUND);
		m_objets[index]->getGroundPos().x = m_sprt.getPosition().x;
		m_objets[index]->getGroundPos().y = m_sprt.getPosition().y;
		m_objets[index] = nullptr;
	}
}
