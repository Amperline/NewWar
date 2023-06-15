#include "Animation.h"

Animation::Animation(sf::RenderWindow* window ,UseVariation usevariation, std::string fileName, int time_switcher, int valueOfImgs_Frames)
	:m_window(window), useVariant(usevariation), timeSwitcher(time_switcher)
{
	 if(usevariation == UseVariation::Imgs)
	 {
		 for(int i = 0; i < valueOfImgs_Frames; i++)
		 {
			 m_imgs.push_back(sf::Image());
			 m_txtrs.push_back(sf::Texture());
			 m_imgs.at(i).loadFromFile(fileName + std::to_string(i) + ".png");
			 m_txtrs.at(i).loadFromImage(m_imgs.at(i));
		 }
	 }
	 else if(UseVariation::OneImg == UseVariation::OneImg)
	 {
		 m_imgs.push_back(sf::Image());
		 m_txtrs.push_back(sf::Texture());
		 m_imgs.at(0).loadFromFile(fileName + ".png");
		 m_txtrs.at(0).loadFromImage(m_imgs.at(0));

		 for(int i = 0; i < valueOfImgs_Frames; i++)
		 {
			 m_frames.push_back(sf::IntRect());
		 }
	 }
	 
	 m_frameTimer.restart();
}

void Animation::checkAnim()
{
	if (useVariant == UseVariation::Imgs)
	{
		if (m_frameTimer.getElapsedTime().asMilliseconds() >= (m_imgs.size() * timeSwitcher))
		{
			m_frameTimer.restart();
		}
		m_sprt.setTexture(m_txtrs.at(m_frameTimer.getElapsedTime().asMilliseconds() / timeSwitcher));
	}
	else if (useVariant == UseVariation::OneImg)
	{
		if (useVariant == UseVariation::Imgs)
		{
			if (m_frameTimer.getElapsedTime().asMilliseconds() >= (m_frames.size() * timeSwitcher))
			{
				m_frameTimer.restart();
			}
			m_sprt.setTextureRect(m_frames.at(m_frameTimer.getElapsedTime().asMilliseconds() / timeSwitcher));
		}
	}
	
}

void Animation::draw()
{
	m_window->draw(m_sprt);
}

