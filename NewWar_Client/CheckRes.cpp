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
        ++it;
    }
}

void drawRes(std::list<Resources*>& Res)
{
	for (Resources* res : Res)
	{
		res->draw();
	}
}
