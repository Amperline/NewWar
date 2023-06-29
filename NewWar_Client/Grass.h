#pragma once
#include <NewWar/NewWarLib.h>

class Grass
{
private:
	sf::Image m_img;
	sf::Texture m_txtr;
	sf::Sprite m_sprt;
	sf::RenderWindow* m_window;
public:
	Grass(sf::RenderWindow* window);
	void draw();
};

