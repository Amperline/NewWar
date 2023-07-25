#include "CheckRes.h"

void CheckRes(std::list<Resources*>& Res, float time)
{
    for (auto it = Res.begin(); it != Res.end();)
    {
        Resources* res = *it;
        if (res != nullptr)
        {
            res->checkAll(time);
            if (res->getEnd())
            {
                delete res;
                it = Res.erase(it);
                break;
            }
        }
        else { Res.erase(it); }
        ++it;
    }
    Res.remove(nullptr);
}

void drawRes(std::list<Resources*>& Res)
{
	for (Resources* res : Res)
	{
        if(res != nullptr)
        {
            if(res->getObStat() != Object::ObjectStatus::INVENT)
            {
                res->draw();
            }
        }
	}
}

void checkPlWithRes(std::list<Resources*>& Res, Character& pl)
{
    for (auto it = Res.begin(); it != Res.end();)
    {
        Resources* res = *it;
        if (res != nullptr)
        {
            if (pl.getSprite().getGlobalBounds().intersects(res->getSprite().getGlobalBounds()))
            {
                pl.ownObject(res);
            }
        }
        ++it;
    }
}
