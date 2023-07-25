#pragma once
#include "Character.h"
#include "Resources.h"
#include <list>

void CheckRes(std::list<Resources*>& Res, float time);
void drawRes(std::list<Resources*>& Res);

void checkPlWithRes(std::list<Resources*>& Res, Character& pl);