#pragma once
#include <SFML/Graphics.hpp>
#include "UseVariation.h"
#include "Animation.h"

class Button : public Animation
{
protected:
	bool Pressed = 0;
	bool UnPressedReady = 0;
	sf::Font m_font;
	sf::Text m_text;
	bool selected{0};
	void checkInteraction();
public:
	Button(sf::RenderWindow* window, std::string fileName, int x, int y);
	void checkAnim() override;
	void checkAll();
	void setupFont(std::string str, int plusX, int plusY);
	bool getLogicClick();
	sf::Text& getText() { return m_text; }
	void draw() override;
};

