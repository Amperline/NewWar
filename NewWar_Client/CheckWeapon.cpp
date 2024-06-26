#include "CheckWeapon.h"

void CheckWeapon(std::list<Weapon*>& wpns, float time)
{
    for (auto it = wpns.begin(); it != wpns.end();)
    {
        Weapon* wp = *it;
        if (wp != nullptr)
        {
            wp->checkAll(time);
            if (wp->getEnd() == 1)
            {
                delete wp;
                it = wpns.erase(it);
                break;
            }
        }
        ++it;
    }
}

void drawWeapon(std::list<Weapon*>& wpns)
{
    for (Weapon* wp : wpns)
    {
        if (wp->getObStat() == Object::ObjectStatus::GROUND)
        {
            wp->draw();
        }
    }
}