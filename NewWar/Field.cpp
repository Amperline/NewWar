#include "Field.h"


Field::Field(sf::RenderWindow* window, std::string fileName, int x, int y)
	:Animation(window, UseVariation::Imgs, fileName, 100, 2)
{
	m_sprt.setTexture(m_txtrs[0]);

	m_sprt.setScale(6, 6);
	m_sprt.setPosition(x, y);
}
void Field::checkInteraction()
{
	if (((sf::Mouse::getPosition().x > (m_sprt.getPosition().x + (7 * 6)))
		&& sf::Mouse::getPosition().x < (m_sprt.getPosition().x + (67 * 6)))
		&& (sf::Mouse::getPosition().y > m_sprt.getPosition().y)
		&& sf::Mouse::getPosition().y < (m_sprt.getPosition().y + (15 * 6)))
	{
		if (selected != 1)
		{
			selected = 1;
		}
	}
	else { selected = 0; }
}

void Field::checkAnim()
{
	if (selected == 1 || CurrentField == 1)
	{
		m_sprt.setTexture(m_txtrs[1]);
	}
	else if (selected == 0)
	{
		m_sprt.setTexture(m_txtrs[0]);
	}
}

void Field::checkAll()
{
	checkInteraction();
	checkAnim();
	if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && selected == 0)
	{
		Pressed = 0;
		UnPressedReady = 0;
		CurrentField = 0;
	}
	if(getLogicClick())
	{
		CurrentField = 1;
	}
}

bool Field::getLogicClick()
{
	if (selected == 1)
	{
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			Pressed = 1;
		}
		if (!sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			if (Pressed == 1)
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

void Field::draw()
{
	Animation::draw();
}
