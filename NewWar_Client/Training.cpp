#include "Training.h"
#include "Grass.h"

void Training(sf::RenderWindow* window)
{
    sf::Clock clock;
    Grass grass(window);
    Character pl(window, sf::Vector2f(100, 100));
    sf::View vTr = window->getView();

    Weapon CarbineAlpha(window, "resource/images/Weapon/CarbineAlpha", "CarbineAlpha", Object::ObjectStatus::INPLAYER, Weapon::WeaponType::Carbine,
        sf::Vector2f(6, 6), sf::Vector2f(1, 1), sf::Vector2f(1, 1));

    pl.CurrOb = &CarbineAlpha;
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
        CarbineAlpha.checkAll(NormalTime, sf::Mouse::getPosition());
        CarbineAlpha.setOwner(&pl);
        
        float x = pl.getSprt().getPosition().x;
        float y = pl.getSprt().getPosition().y;
        
        //if (x < 320) x = 320;
        //else if (x > 640) x = 640;
        //else if (y < 240) y = 240;
        //else if (y > 720) y = 720;
        vTr.setCenter(x + 60, y + 108);

        window->setView(vTr);
        window->clear();
        grass.draw();
        pl.draw();
        window->display();
    }
}
