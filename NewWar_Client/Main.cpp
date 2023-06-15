#include <iostream>

#include <NewWar/NewWarLib.h>
#include <SFML/Graphics.hpp>


int main()
{
    sf::RenderWindow window(sf::VideoMode(1920, 1080), "NewWar", sf::Style::Fullscreen);

    Animation MainMenu(&window, UseVariation::Imgs, "resource/images/MainMenu/MainMenu", 300, 12);
    MainMenu.getSprite().setScale(6, 6);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        MainMenu.checkAnim();

        window.clear();

        MainMenu.draw();
        window.display();
    }
	return 0;
}