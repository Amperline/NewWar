#include "CheckChest.h"

void CheckChest(std::list<Chest*>& chests, float time)
{
    for (auto it = chests.begin(); it != chests.end();)
    {
        Chest* ch = *it;
        if (ch != nullptr)
        {
            ch->checkAll(time);
        }
        ++it;
    }
}

void drawChest(std::list<Chest*>& chests, sf::RenderWindow* window, Interface interface)
{
    sf::Vector2i mousePosition = sf::Mouse::getPosition(*window);
    sf::Vector2f worldPosition = window->mapPixelToCoords(mousePosition);
    for (Chest* ch : chests)
    {
        if(ch != nullptr)
        {
            ch->getSprite().setTextureRect(sf::IntRect(0, 0, 20, 20));

            if(ch->getSprite().getGlobalBounds().contains(worldPosition))
            {
                ch->getSprite().setTextureRect(sf::IntRect(20, 0, 20, 20));
            }
            ch->draw();
        }
    }
}

