#pragma once
#include "Object.h"

class Resources : public Object
{
public:
	enum ResourceType
	{
		WOOD,
		STONE
	};
private:
	ResourceType TypeRes;

	int m_valueOfStack;
	int MAXVal = 100;
	const int& MAXVAL = MAXVal;
public:
	Resources(sf::RenderWindow* window, sf::Vector2f StartPos, int valueofStack, std::string name, ObjectStatus obSt, ResourceType typeRes);
	int& getValofStack() { return m_valueOfStack; }
	std::string getMiniInfoDefault() override { return std::string(std::to_string(m_valueOfStack)); }
	std::string identify() override;
};

