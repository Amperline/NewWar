#pragma once
#include "Ammo.h"
#include <list>

void CheckAmmo(std::list<Ammo*>& ammos, float time);
void drawAmmo(std::list<Ammo*>& ammos);
