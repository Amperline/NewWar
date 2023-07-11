#include "Training.h"
#include "Grass.h"
#include "Ammo.h"
#include "Resources.h"
#include "Tree.h"

void Training(sf::RenderWindow* window)
{
    sf::Clock clock;
    Grass grass(window);

    std::list<Ammo*> AMMOS;
    std::list<Resources*> RES;
    std::list<Tree*> TREES;

    Character pl(window, sf::Vector2f(1000, 1000));
    sf::View vTr = window->getView();
    Interface m_interface(window, &pl);
    Weapon CarbineAlpha(window, "resource/images/Weapon/CarbineAlpha", &AMMOS, "CarbineAlpha",Object::ObjectStatus::INPLAYER, Weapon::WeaponType::Carbine,
        sf::Vector2f(6, 6), sf::Vector2f(100, 100));
    for (int i = 0; i < 20; i++)
    {
        TREES.push_back(new Tree(window, &RES, Tree::SMALL, sf::Vector2f(1000 + (200 * i), 1000), Object::ObjectStatus::USED));
    }
    for (int i = 0; i < 20; i++)
    {
        TREES.push_back(new Tree(window, &RES, Tree::SMALL, sf::Vector2f(1000 + (200 * i) + 50, 1000), Object::ObjectStatus::USED));
    }
    for (int i = 0; i < 20; i++)
    {
        TREES.push_back(new Tree(window, &RES, Tree::SMALL, sf::Vector2f(1000 + (200 * i) + 100, 1000), Object::ObjectStatus::USED));
    }
    for (int i = 0; i < 20; i++)
    {
        TREES.push_back(new Tree(window, &RES, Tree::SMALL, sf::Vector2f(1000 + (200 * i) + 150, 1000), Object::ObjectStatus::USED));
    }
    for (int i = 0; i < 20; i++)
    {
        TREES.push_back(new Tree(window, &RES, Tree::SMALL, sf::Vector2f(1000 + (200 * i) + 200, 1000), Object::ObjectStatus::USED));
    }
    
    pl.ownObject(&CarbineAlpha);
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
        pl.checkAll(NormalTime);

        checkAmmoWithOb(AMMOS, TREES);
        CheckAmmo(AMMOS, NormalTime);
        CheckTree(TREES, NormalTime);
        CheckRes(RES, NormalTime);
        checkResWithRes(RES, NormalTime);
        checkPlayerWithOb(pl, TREES, time);
        

        CarbineAlpha.checkAll(NormalTime);
        m_interface.checkAll();

        float x = pl.getSprite().getPosition().x;
        float y = pl.getSprite().getPosition().y;
        vTr.setCenter(x + 34, y + 108);

        window->setView(vTr);
        window->clear();

        grass.draw();
        drawAmmo(AMMOS);
        drawRes(RES);

        Object* ValCrrOb = *pl.CurrOb;
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
        m_interface.draw();
        window->display();
    }
    window->setView(window->getDefaultView());
}
