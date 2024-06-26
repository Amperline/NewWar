#pragma once
#include "Weapon.h"
#include <list>

void CheckWeapon(std::list<Weapon*>& wpns, float time);
void drawWeapon(std::list<Weapon*>& wpns);