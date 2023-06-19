#pragma once
#include "Button.h"
#include "GameString.h"

class Field: public Animation
{
protected:
	bool CurrentField = 0;
	bool Pressed = 0;
	bool UnPressedReady = 0;
	bool selected{ 0 };
	void checkInteraction();
public:
	Field(sf::RenderWindow* window, std::string fileName, int x, int y);
	void checkAnim() override;
	void checkAll();
	bool getLogicClick();
	bool isCuttrntField() { return CurrentField; }
	void draw() override;
};

