#include "Resources.h"

Resources::Resources(sf::RenderWindow* window, sf::Vector2f StartPos, int valueofStack, std::string name, ObjectStatus obSt, ResourceType typeRes)
	:Object(window, std::string("resource/images/GameRes/Resources"), name, obSt, sf::Vector2f(6, 6), sf::Vector2f(6, 6)),
	TypeRes(typeRes), m_valueOfStack(valueofStack)
{
	m_sprt.setPosition(StartPos);
	setDeathAble(0);
	if (TypeRes == WOOD) { m_sprt.setTextureRect(sf::IntRect(0, 0, 10, 10)); }
	else if (TypeRes == STONE) { m_sprt.setTextureRect(sf::IntRect(11, 0, 10, 10)); }
	
	groundPos = StartPos;
}

std::string Resources::identify()
{
	if (TypeRes == WOOD) { return std::string("wood"); }
	else if (TypeRes == STONE) { return std::string("stone"); }
}

