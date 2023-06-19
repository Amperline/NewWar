#pragma once
#include "Animation.h"
#include "Button.h"
#include "UseVariation.h"
#include <vector>


class Menu: public Animation
{
public:
	Menu(sf::RenderWindow* window, UseVariation usevariation, std::string fileName,
		int time_switcher, int valueOfImgs_Frames = 0);
	virtual void checkAll();
	void draw() override;
};

