#include "CheckAmmo.h"

void CheckAmmo(std::list<Ammo*>& ammos, float time)
{
    for (auto it = ammos.begin(); it != ammos.end();)
    {
        Ammo* am = *it;
        if (am != nullptr)
        {
            am->check(time);
            if (am->getEnd() == 1)
            {
                delete am;
                it = ammos.erase(it);
                break;
            }
        }
        ++it;
    }
}

void drawAmmo(std::list<Ammo*>& ammos)
{
	for(Ammo* am : ammos)
	{
		am->draw();
	}
}
