#include "CheckInteraction.h"

void checkAmmoWithOb(std::list<Ammo*>& Ammos, std::list<Tree*>& TrArr)
{
    for (auto itAm = Ammos.begin(); itAm != Ammos.end(); itAm++)
    {
        Ammo* am = *itAm;
        if (am != nullptr && am->getLifeStat() == Ammo::ALIFE)
        {
            for (auto it = TrArr.begin(); it != TrArr.end(); it++)
            {
                Object* ob = *it;
                if (ob != nullptr && ob->getlifeStat() == Object::ALIFE)
                {
                    if(am->getSprt().getGlobalBounds().intersects(ob->getSprite().getGlobalBounds()))
                    {
                        am->death();
                        ob->getHP() -= 20;
                    }
                }
            }
        }
    }
}

void checkResWithRes(std::list<Resources*>& ResArr, float time)
{
    for (auto it = ResArr.begin(); it != ResArr.end(); it++)
    {
        Resources* res = *it;
        if (res != nullptr && res->getObStat() == Object::GROUND)
        {
            for (auto it2 = ResArr.begin(); it2 != ResArr.end(); it2++)
            {
                Resources* res2 = *it2;
                if (res2 != nullptr && *it != *it2 && res2->getObStat() == Object::GROUND)
                {
                    sf::Sprite sprt1 = res->getSprite();
                    sf::Sprite sprt2 = res2->getSprite();
                    sprt1.setTextureRect(sf::IntRect(-1, -1, 12, 12));
                    sprt2.setTextureRect(sf::IntRect(-1, -1, 12, 12));

                    
                    if (sprt1.getGlobalBounds().intersects(sprt2.getGlobalBounds()))
                    {
                        if(res->getSprite().getPosition().x <= res2->getSprite().getPosition().x)
                        {
                            if (res->getSprite().getPosition().y <= res2->getSprite().getPosition().y)
                            {
                                res->getSprite().move(-0.1 * time, -0.1 * time);
                                res2->getSprite().move(0.1 * time, 0.1 * time);
                            }
                            else if (res->getSprite().getPosition().y > res2->getSprite().getPosition().y)
                            {
                                res->getSprite().move(-0.1 * time, 0.1 * time);
                                res2->getSprite().move(0.1 * time, -0.1 * time);
                            }
                        }
                        else if(res->getSprite().getPosition().x > res2->getSprite().getPosition().x)
                        {
                            if (res->getSprite().getPosition().y <= res2->getSprite().getPosition().y)
                            {
                                res->getSprite().move(0.1 * time, -0.1 * time);
                                res2->getSprite().move(-0.1 * time, 0.1 * time);
                            }
                            else if (res->getSprite().getPosition().y > res2->getSprite().getPosition().y)
                            {
                                res->getSprite().move(0.1 * time, 0.1 * time);
                                res2->getSprite().move(-0.1 * time, -0.1 * time);
                            }
                        }
                        res->setGrPause(1);
                        res2->setGrPause(1);
                    }
                    else
                    {
                        res->setGrPause(0);
                        res2->setGrPause(0);
                    }
                }
            }
        }
    }
}

void checkPlayerWithOb(Character& player, std::list<Tree*>& ObArr, float time)
{
    for (auto it = ObArr.begin(); it != ObArr.end(); it++)
    {
        Object* ob = *it;
        if (ob != nullptr && ob->getlifeStat() == Object::ALIFE
            &&(ob->getObStat() == Object::GROUND || ob->getObStat() == Object::USED))
        {
            sf::FloatRect rectTop(ob->getSprite().getGlobalBounds().left, ob->getSprite().getGlobalBounds().top,
                ob->getSprite().getGlobalBounds().width, 1);
            sf::FloatRect rectDown(ob->getSprite().getGlobalBounds().left, ob->getSprite().getGlobalBounds().top + ob->getSprite().getGlobalBounds().height - 1,
                ob->getSprite().getGlobalBounds().width, ob->getSprite().getGlobalBounds().height);
            sf::FloatRect rectLeft(ob->getSprite().getGlobalBounds().left, ob->getSprite().getGlobalBounds().top, 
                ob->getSprite().getGlobalBounds().left + 1, ob->getSprite().getGlobalBounds().height);
            sf::FloatRect rectRight(ob->getSprite().getGlobalBounds().left + ob->getSprite().getGlobalBounds().width - 1, ob->getSprite().getGlobalBounds().top,
                ob->getSprite().getGlobalBounds().width, ob->getSprite().getGlobalBounds().height);
            if (player.getSprite().getGlobalBounds().intersects(sf::FloatRect(rectTop))) { player.getSprite().move(0, -1 * time); }
            if (player.getSprite().getGlobalBounds().intersects(sf::FloatRect(rectDown))) { player.getSprite().move(0, 1 * time); }
            if (player.getSprite().getGlobalBounds().intersects(sf::FloatRect(rectLeft))) { player.getSprite().move(-1 * time, 0); }
            if (player.getSprite().getGlobalBounds().intersects(sf::FloatRect(rectRight))) { player.getSprite().move(1 * time, 0); }
        }
    }
}
