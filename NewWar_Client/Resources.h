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

	int valueOfStack;
	int MAXVal = 100;
	const int& MAXVAL = MAXVal;
public:
	Resources(sf::RenderWindow* window, std::string name, ObjectStatus obSt, ResourceType typeRes);
	int& getValofStack() { return valueOfStack; }
	std::string getMiniInfoDefault() override { return std::string(std::to_string(valueOfStack)); }
	std::string identify() override;
};

