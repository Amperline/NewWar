#pragma once
#include "Chest.h"
#include "Interface.h"
#include <list>

void CheckChest(std::list<Chest*>& chests, float time);
void drawChest(std::list<Chest*>& chests, sf::RenderWindow* window, Interface interface);
