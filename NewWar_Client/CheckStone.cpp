#include "CheckStone.h"

void CheckStone(std::list<Stone*>& Stones, float time)
{
    for (auto it = Stones.begin(); it != Stones.end();)
    {
        Stone* st = *it;
        if (st != nullptr)
        {
            st->checkAll(time);
            if (st->getEnd() == 1)
            {
                delete st;
                it = Stones.erase(it);
                break;
            }
        }
        ++it;
    }
}

void drawStone(std::list<Stone*>& Stones)
{
    for (Stone* tr : Stones)
    {
        tr->draw();
    }
}
