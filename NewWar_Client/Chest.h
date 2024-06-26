#pragma once
#include "Object.h"
#include "Resources.h"
#include "Block.h"
#include <array>

class Chest : public Block
{
private:
	std::array<Object*, 20> m_objets;
public:
	Chest(sf::RenderWindow* window, ObjectStatus obSt, sf::Vector2f startPoss);
	std::array<Object*, 20>& getObArray() { return m_objets; }
	bool ownObject(Object* ob, int ind);
	void swapOB(int ind1, int ind2);
	void throwObject(short index);
	std::array<Object*, 20>& getArray() { return m_objets; }
	Object* operator[](int i) { return m_objets[i]; }
};
