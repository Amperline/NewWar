#pragma once
#include "Object.h"
#include"Resources.h"
#include <list>

class Tree : public Object
{
public:
	enum TreeType
	{
		SMALL, 
		MID,
		BIG
	};
private:
	std::list<Resources*>* resPtrArr;
	int valOfDrop = 0;
	TreeType treeType;
public:
	Tree(sf::RenderWindow* window, std::list<Resources*>* resArr, TreeType treetype, sf::Vector2f StartPos, ObjectStatus obSt);
	void checkAll(float time);
	void checkDeath() override;
};

