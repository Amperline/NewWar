#include "Button.h"


Button::Button(sf::RenderWindow* window, std::string fileName, int x, int y)
	:Animation(window, UseVariation::OneImg, fileName, 100, 2)
{
	m_frames[0] = sf::IntRect(0, 0, 64, 20);
	m_frames[1] = sf::IntRect(0, 22, 64, 20);
	m_sprt.setTextureRect(m_frames[0]);

	m_sprt.setScale(6, 6);
	m_sprt.setPosition(x, y);

	m_font.loadFromFile("resource/fonts/NewWar.ttf");
	m_text.setFont(m_font);
	m_text.setCharacterSize(42);
	m_text.setPosition(m_sprt.getPosition().x + (6 * 18) - 3,
		m_sprt.getPosition().y + (6 * 3));
}

void Button::checkInteraction()
{
	if (((sf::Mouse::getPosition().x > (m_sprt.getPosition().x + (8 * 6)))
		&& sf::Mouse::getPosition().x < (m_sprt.getPosition().x + (56 * 6)))
		&& (sf::Mouse::getPosition().y > m_sprt.getPosition().y)
		&& sf::Mouse::getPosition().y < (m_sprt.getPosition().y + (15 * 6)))
	{
		if(selected != 1)
		{
			selected = 1;
		}
	}
	else{ selected = 0; }
}

void Button::checkAnim()
{
	if(selected == 1 && (m_sprt.getTextureRect() != m_frames[1]))
	{
		m_sprt.setTextureRect(m_frames[1]);
		m_text.setFillColor(sf::Color(152, 32, 32));
	}
	else if(selected == 0)
	{
		m_text.setFillColor(sf::Color::White);
		m_sprt.setTextureRect(m_frames[0]); 
	}
}

void Button::checkAll()
{
	checkInteraction();
	checkAnim();
}

void Button::setupFont(std::string str, int plusX, int plusY)
{
	m_text.setString(str);
	m_text.setPosition(m_text.getPosition().x + plusX,
		m_text.getPosition().y + plusY);
}

bool Button::getLogicClick()
{
	if(selected == 1)
	{
		if(sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{	
			Pressed = 1;
		}
		if(!sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			if(Pressed == 1)
				UnPressedReady = 1;
		}
		if (UnPressedReady == 1)
		{
			selected = 0;
			Pressed = 0;
			UnPressedReady = 0;
			return true;
		}
	}
	else
	{
		Pressed = 0;
		UnPressedReady = 0;
	}
	return false;
}

void Button::draw()
{
	Animation::draw();
	if(m_text.getString().getSize() != 0)
	{
		m_window->draw(m_text);
	}
}
