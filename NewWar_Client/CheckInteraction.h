#pragma once
#include <list>
#include "Character.h"
#include "Ammo.h"
#include "Tree.h"
#include "Stone.h"
#include "Resources.h"

void checkAmmoWithOb(std::list<Ammo*>& Ammos, std::list<Tree*>& TrArr);
void checkAmmoWithOb(std::list<Ammo*>& Ammos, std::list<Stone*>& StArr);


void checkResWithRes(std::list<Resources*>& ResArr, float time);

void checkPlayerWithOb(Character& player, std::list<Tree*>& ObArr, float time);
void checkPlayerWithOb(Character& player, std::list<Stone*>& ObArr, float time);

bool checkPlANDside(Character& player, std::list<Tree*>& ObArr);
bool checkPlANDside(Character& player, std::list<Stone*>& ObArr);