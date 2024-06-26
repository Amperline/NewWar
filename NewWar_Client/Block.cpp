#include "Block.h"

Block::Block(sf::RenderWindow* window, std::string fileName, std::string name, ObjectStatus obSt)
	: Object(window, fileName, name, obSt, sf::Vector2f(6, 6), sf::Vector2f(4.4, 4.4))
{
	m_sprt.setTextureRect(sf::IntRect(0, 0, 20, 20));
	m_sprt.setScale(6, 6);
}

void Block::draw()
{
	m_window->draw(m_sprt);
}

void Block::checkAll(float time)
{
	Object::checkAll(time);
}
