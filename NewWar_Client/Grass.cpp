#include "Grass.h"

Grass::Grass(sf::RenderWindow* window)
	:m_window(window)
{
	m_img.loadFromFile("resource/images/Grass/Grass.png");
	m_txtr.loadFromImage(m_img);
	m_sprt.setTexture(m_txtr);
	m_sprt.setScale(6, 6);
}

void Grass::draw()
{
	m_window->draw(m_sprt);
}
