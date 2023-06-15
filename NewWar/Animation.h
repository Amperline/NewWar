#pragma once
#include <SFML/Graphics.hpp>
#include "UseVariation.h"
#include <vector>

class Animation
{
protected:
	sf::RenderWindow* m_window;
	UseVariation useVariant;
	std::vector<sf::IntRect> m_frames;
	std::vector<sf::Image> m_imgs;
	std::vector<sf::Texture> m_txtrs;
	sf::Sprite m_sprt;
	sf::Clock m_frameTimer;
	int timeSwitcher;
public:
	Animation(sf::RenderWindow* window,UseVariation usevariation, std::string fileName, int time_switcher, int valueOfImgs_Frames = 0);
	void checkAnim();
	virtual void draw();
	sf::IntRect& getFramesRect(int index) { return m_frames[index]; }
	sf::Sprite& getSprite() { return m_sprt; }
};

