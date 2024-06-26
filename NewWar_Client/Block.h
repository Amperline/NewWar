#pragma once
#include "Object.h"
#include "SFML/Graphics.hpp"

class Block : public Object
{
protected:
public:
	Block(sf::RenderWindow* window, std::string fileName, std::string name, ObjectStatus obSt);
	void draw() override;
	void checkAll(float time) override;
};