#include <iostream>
#include <thread>

#include <NewWar/NewWarLib.h>
#include <SFML/Graphics.hpp>
#include "Registration.h"
#include "ButtonController.h"

GameStatus GAMESTATUS{GameStatus::IN_MENU};

int main()
{
    sf::RenderWindow window(sf::VideoMode(1920, 1080), "NewWar", sf::Style::Fullscreen);

    Menu MainMenu(&window, UseVariation::Imgs, "resource/images/MainMenu/MainMenu", 300, 12);
    Button Button1(&window, "resource/images/Buttons/Button", 128 * 6, 40 * 6);
    Button Button2(&window, "resource/images/Buttons/Button", 128 * 6, 66 * 6);
    Button Button3(&window, "resource/images/Buttons/Button", 128 * 6, 92 * 6);
    Button Button4(&window, "resource/images/Buttons/Button", 128 * 6, 118 * 6);
    Button1.setupFont("Play", 32, 0);
    Button2.setupFont("Training", 8, 6);
    Button3.setupFont("Settings", 8, 4);
    Button2.getText().setCharacterSize(32);
    Button3.getText().setCharacterSize(32);
    Button4.setupFont("Exit", 38, 0);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        if(GetButtonlogicPress(Button1))
        {
            GAMESTATUS = GameStatus::PLAYING;
        }
        else if(GetButtonlogicPress(Button2))
        {
            GAMESTATUS = GameStatus::TRAINING;
        }
        else if(GetButtonlogicPress(Button3))
        {
            GAMESTATUS = GameStatus::SETTINGS;
        }
        else if(GetButtonlogicPress(Button4))
        {
            exit(1);
        }


        if(GAMESTATUS == GameStatus::IN_MENU)
        {
            MainMenu.checkAll();
            Button1.checkAll();
            Button2.checkAll();
            Button3.checkAll();
            Button4.checkAll();
        }
        else if(GAMESTATUS == GameStatus::PLAYING)
        {
            if(Registration(&window))
            {

            }
            GAMESTATUS = GameStatus::IN_MENU;
        }
        else if (GAMESTATUS == GameStatus::TRAINING)
        {

        }
        else if (GAMESTATUS == GameStatus::SETTINGS)
        {

        }


         





        window.clear();



        if (GAMESTATUS == GameStatus::IN_MENU)
        {
            MainMenu.draw();
            Button1.draw();
            Button2.draw();
            Button3.draw();
            Button4.draw();
        }
        else if (GAMESTATUS == GameStatus::PLAYING)
        {

        }
        else if (GAMESTATUS == GameStatus::TRAINING)
        {

        }
        else if (GAMESTATUS == GameStatus::SETTINGS)
        {
        }
        window.display();
    }
	return 0;
}