#pragma once
#include <list>
#include "Character.h"
#include "Ammo.h"
#include "Tree.h"
#include "Resources.h"

void checkAmmoWithOb(std::list<Ammo*>& Ammos, std::list<Tree*>& TrArr);


void checkResWithRes(std::list<Resources*>& ResArr, float time);

void checkPlayerWithOb(Character& player, std::list<Tree*>& ObArr, float time);
