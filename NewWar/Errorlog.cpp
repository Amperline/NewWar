#include "Errorlog.h"

void makeError(sf::RenderWindow* window, std::string str)
{
    Menu menu(window, UseVariation::Imgs, "resource/images/MainMenu/MainMenu", 300, 12);
    Button b(window, "resource/images/Buttons/Button", 128 * 6, 86 * 6);
    b.setupFont("OK", 46, 0);
    

    sf::Texture txtr;
    txtr.loadFromFile("resource/images/Error/ErrorLog.png");
    sf::Sprite sprt;
    sprt.setTexture(txtr);
    sprt.setPosition(102 * 6, 53 * 6);
    sprt.setScale(6, 6);

    sf::Font f;
    f.loadFromFile("resource/fonts/NewWar.ttf");
    sf::Text t(str, f);
    t.setPosition(112 * 6, 63 * 6);
    t.setCharacterSize(46);
    while (window->isOpen())
    {
        menu.checkAll();
        b.checkAll();

        if(b.getLogicClick())
        {
            return;
        }
        window->clear();
        menu.draw();
        window->draw(sprt);
        b.draw();
        window->draw(t);
        window->display();
    }
}
