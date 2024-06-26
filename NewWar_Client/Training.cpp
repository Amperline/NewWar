#include "Training.h"
#include "Grass.h"
#include "Ammo.h"
#include "Resources.h"
#include "Tree.h"
#include "Stone.h"
#include "FlagsStruct.h"

void Training(sf::RenderWindow* window, KeyFlags* flagsKey)
{
    sf::Clock clock;
    Grass grass(window);

    std::list<Weapon*> WPNS;
    std::list<Ammo*> AMMOS;
    std::list<Resources*> RES;
    std::list<Tree*> TREES;
    std::list<Stone*> STONES;
    std::list<Chest*> CHESTS;
    
    sf::View vTr = window->getView();

    Character pl(window, sf::Vector2f(100, 100));
    Interface m_interface(window, &pl);
    
    pl.setKeyflags(flagsKey);
    m_interface.setKeyflags(flagsKey);

    WPNS.push_back(new Weapon(window, &AMMOS, "CarbineAlpha", Object::ObjectStatus::GROUND, Weapon::WeaponType::Carbine,
        Weapon::LEVEL::Initial, sf::Vector2f(6, 6), sf::Vector2f(100, 100)));
    WPNS.push_back(new Weapon(window, &AMMOS, "CarbineAlpha", Object::ObjectStatus::GROUND, Weapon::WeaponType::Carbine,
        Weapon::LEVEL::Electi, sf::Vector2f(6, 6), sf::Vector2f(300, 100)));
    WPNS.push_back(new Weapon(window, &AMMOS, "CarbineAlpha", Object::ObjectStatus::GROUND, Weapon::WeaponType::Carbine,
        Weapon::LEVEL::Provecta, sf::Vector2f(6, 6), sf::Vector2f(500, 100)));

    CHESTS.push_back(new Chest(window, Object::ObjectStatus::USED, sf::Vector2f(200, 200)));

    

    for (int i = 0; i < 20; i++)
    {
        TREES.push_back(new Tree(window, &RES, Tree::SMALL, sf::Vector2f(1000 + (300 * i), 1000), Object::ObjectStatus::USED));
    }
    for (int i = 0; i < 20; i++)
    {
        TREES.push_back(new Tree(window, &RES, Tree::MID, sf::Vector2f(1000 + (300 * i) + 50, 1500), Object::ObjectStatus::USED));
    }
    for (int i = 0; i < 20; i++)
    {
        TREES.push_back(new Tree(window, &RES, Tree::BIG, sf::Vector2f(1000 + (300 * i) + 100, 2000), Object::ObjectStatus::USED));
    }
    for (int i = 0; i < 20; i++)
    {
        STONES.push_back(new Stone(window, &RES, Stone::SMALL, sf::Vector2f(1000 + (300 * i) + 150, 2500), Object::ObjectStatus::USED));
    }
    for (int i = 0; i < 20; i++)
    {
        STONES.push_back(new Stone(window, &RES, Stone::MID, sf::Vector2f(1000 + (300 * i) + 200, 3000), Object::ObjectStatus::USED));
    }
    for (int i = 0; i < 20; i++)
    {
        STONES.push_back(new Stone(window, &RES, Stone::BIG, sf::Vector2f(1000 + (300 * i) + 200, 3500), Object::ObjectStatus::USED));
    }

    pl.setCurrOb(1);
    while (window->isOpen())
    {
        float time = clock.getElapsedTime().asMicroseconds();
        clock.restart();
        auto NormalTime{ time / 850 };
        auto FastTime{ time / 400 };
        time = NormalTime;

        sf::Event event;
        while (window->pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window->close();
        }
        m_interface.checkKeys();
        pl.checkAll(NormalTime);

        CheckWeapon(WPNS, NormalTime);
        checkAmmoWithOb(AMMOS, TREES);
        checkAmmoWithOb(AMMOS, STONES);
        CheckAmmo(AMMOS, NormalTime);

        CheckTree(TREES, NormalTime);
        CheckStone(STONES, NormalTime);

        CheckRes(RES, NormalTime);
        checkResWithRes(RES, NormalTime);

        checkPlayerWithOb(pl, TREES, NormalTime);
        checkPlayerWithOb(pl, STONES, NormalTime);
        
        m_interface.checkAll(CHESTS);

        float x = pl.getSprite().getPosition().x;
        float y = pl.getSprite().getPosition().y;
        vTr.setCenter(x + 34, y + 108);

        window->setView(vTr);
        window->clear();

        grass.draw();
        drawAmmo(AMMOS);
        drawRes(RES);
        drawWeapon(WPNS);
        drawChest(CHESTS, window, m_interface);

        Object* ValCrrOb = *pl.CurrOb;
        if(checkPlANDside(pl, TREES) || checkPlANDside(pl, STONES))
        {
            drawTree(TREES);
            drawStone(STONES);
            if (ValCrrOb != nullptr)
            {
                if (pl.lastSide == 2 || pl.lastSide == 3 || pl.lastSide == 4)
                {
                    pl.draw();
                    ValCrrOb->draw();
                }
                else if (pl.lastSide == 1)
                {
                    ValCrrOb->draw();
                    pl.draw();
                }
            }
            else
            {
                pl.draw();
            }
        }
        else 
        {
            if (ValCrrOb != nullptr)
            {
                if (pl.lastSide == 2 || pl.lastSide == 3 || pl.lastSide == 4)
                {
                    pl.draw();
                    ValCrrOb->draw();
                }
                else if (pl.lastSide == 1)
                {
                    ValCrrOb->draw();
                    pl.draw();
                }
            }
            else
            {
                pl.draw();
            }
            drawTree(TREES);
            drawStone(STONES);
        }
        
        std::list<Object*> Objects;
        for(auto i = RES.begin(); i != RES.end(); i++)
        {
            Objects.push_back(*i);
        }
        for (auto i = WPNS.begin(); i != WPNS.end(); i++)
        {
            Objects.push_back(*i);
        }

        m_interface.draw(Objects);
        window->display();
    }
    window->setView(window->getDefaultView());
}
