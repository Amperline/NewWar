#include "CheckTree.h"

void CheckTree(std::list<Tree*>& Trees, float time)
{
    for (auto it = Trees.begin(); it != Trees.end();)
    {
        Tree* tr = *it;
        if (tr != nullptr)
        {
            tr->checkAll(time);
            if (tr->getEnd() == 1)
            {
                delete tr;
                it = Trees.erase(it);
                break;
            }
        }
        ++it;
    }
}

void drawTree(std::list<Tree*>& Trees)
{
    for (Tree* tr : Trees)
    {
        tr->draw();
    }
}
