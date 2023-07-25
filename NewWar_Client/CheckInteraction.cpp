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

void checkAmmoWithOb(std::list<Ammo*>& Ammos, std::list<Stone*>& StArr)
{
    for (auto itAm = Ammos.begin(); itAm != Ammos.end(); itAm++)
    {
        Ammo* am = *itAm;
        if (am != nullptr && am->getLifeStat() == Ammo::ALIFE)
        {
            for (auto it = StArr.begin(); it != StArr.end(); it++)
            {
                Object* ob = *it;
                if (ob != nullptr && ob->getlifeStat() == Object::ALIFE)
                {
                    if(ob->identify() == "big")
                    {
                        sf::CircleShape circle;
                        circle.setRadius(6 * 6);
                        circle.setOrigin(0, 12 * 6);
                        circle.setPosition(ob->getSprite().getPosition());
                        if(am->getSprt().getGlobalBounds().intersects(circle.getGlobalBounds()))
                        {
                            am->death();
                            ob->getHP() -= 20;
                        }
                    }
                    else if (am->getSprt().getGlobalBounds().intersects(ob->getSprite().getGlobalBounds()))
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
           sf::Sprite sp;
           sp.setPosition(ob->getSprite().getPosition());
           sp.setScale(6, 6);
           if (ob->identify() == "small") { sp.setTextureRect(sf::IntRect(0, 0, 16, 4)); sp.move(2 * 6, - 4 * 6); }
           else if(ob->identify() == "mid"){ sp.setTextureRect(sf::IntRect(0, 0, 16, 5)); sp.move(2 * 6, -5 * 6); }
           else if(ob->identify() == "big"){ sp.setTextureRect(sf::IntRect(0, 0, 16, 4)); sp.move(2 * 6, -4 * 6); }

           if(player.getFloatRect().intersects(sp.getGlobalBounds()))
           {
                if (player.lastSide == 1)
                {
                    if (player.getFloatRect().left - 24 < ob->getSprite().getPosition().x)
                        player.getSprite().move(-0.5 * time, 0.5 * time);
                    else player.getSprite().move(0.5 * time, 0.5 * time);
                }
                else if (player.lastSide == 2)
                {
                    if (player.getFloatRect().left - 24 < ob->getSprite().getPosition().x)
                        player.getSprite().move(-0.5 * time, -0.5 * time);
                    else player.getSprite().move(0.5 * time, -0.5 * time);
                }
                else if (player.lastSide == 3)
                {
                    if (player.getFloatRect().top + player.getFloatRect().height < (sp.getPosition().y + (sp.getTextureRect().height / 2 * 6) + 6))
                        player.getSprite().move(0.5 * time, -0.5 * time);
                    else player.getSprite().move(0.5 * time, 0.5 * time);
                }
                else if (player.lastSide == 4)
                {
                    if (player.getFloatRect().top + player.getFloatRect().height < (sp.getPosition().y + (sp.getTextureRect().height / 2 * 6) + 6))
                        player.getSprite().move(-0.5 * time, -0.5 * time);
                    else player.getSprite().move(-0.5 * time, 0.5 * time);
                }
           }
        }
    }
}

void checkPlayerWithOb(Character& player, std::list<Stone*>& ObArr, float time)
{
    for (auto it = ObArr.begin(); it != ObArr.end(); it++)
    {
        Object* ob = *it;
        if (ob != nullptr && ob->getlifeStat() == Object::ALIFE
            && (ob->getObStat() == Object::GROUND || ob->getObStat() == Object::USED))
        {
            sf::Sprite sp;
            sp.setPosition(ob->getSprite().getPosition());
            sp.setScale(6, 6);
            if (ob->identify() == "small") { sp.setTextureRect(sf::IntRect(0, 0, 10, 7)); sp.move(0, -7 * 6); }
            else if (ob->identify() == "mid") { sp.setTextureRect(sf::IntRect(0, 0, 13, 7)); sp.move(0, -7 * 6); }
            else if (ob->identify() == "big") { sp.setTextureRect(sf::IntRect(0, 0, 15, 12)); sp.move(0, -12 * 6); }
            if (player.getFloatRect().intersects(sp.getGlobalBounds()))
            {
                if (player.lastSide == 1)
                {
                    if(player.getFloatRect().left < ob->getSprite().getPosition().x)
                        player.getSprite().move(-0.5 * time, 0.5 * time);
                    else player.getSprite().move(0.5 * time, 0.5 * time);
                }
                else if (player.lastSide == 2)
                {
                    if (player.getFloatRect().left < ob->getSprite().getPosition().x)
                        player.getSprite().move(-0.5 * time, -0.5 * time);
                    else player.getSprite().move(0.5 * time, -0.5 * time);
                }
                else if (player.lastSide == 3)
                {
                    if (player.getFloatRect().top + player.getFloatRect().height < (ob->getSprite().getPosition().y - (ob->getSprite().getTextureRect().height / 2 * 6) + 6)) 
                        player.getSprite().move(0.5 * time, -0.5 * time);
                    else player.getSprite().move(0.5 * time, 0.5 * time);
                }
                else if (player.lastSide == 4)
                {
                    if (player.getFloatRect().top + player.getFloatRect().height < (ob->getSprite().getPosition().y - (ob->getSprite().getTextureRect().height / 2 * 6) + 6))
                        player.getSprite().move(-0.5 * time, -0.5 * time);
                    else player.getSprite().move(-0.5 * time, 0.5 * time);
                }
            }
        }
    }
}

bool checkPlANDside(Character& player, std::list<Tree*>& ObArr)
{
    for (auto it = ObArr.begin(); it != ObArr.end(); it++)
    {
        Object* ob = *it;
        if (ob != nullptr && ob->getlifeStat() == Object::ALIFE
            && (ob->getObStat() == Object::GROUND || ob->getObStat() == Object::USED))
        {
            sf::Sprite sp;
            sp.setPosition(ob->getSprite().getPosition());
            sp.setScale(6, 6);
            if (ob->identify() == "small") { sp.setTextureRect(sf::IntRect(0, 0, 16, 4)); sp.move(2 * 6, -4 * 6); }
            else if (ob->identify() == "mid") { sp.setTextureRect(sf::IntRect(0, 0, 16, 5)); sp.move(2 * 6, -5 * 6); }
            else if (ob->identify() == "big") { sp.setTextureRect(sf::IntRect(0, 0, 16, 4)); sp.move(2 * 6, -4 * 6); }

            if (player.getSprite().getGlobalBounds().intersects(sp.getGlobalBounds()))
            {
                if((player.getSprite().getPosition().y + 34 * 6) > ob->getSprite().getPosition().y)
                {
                    return true;
                }
            }
        }
    }
    return false;
}

bool checkPlANDside(Character& player, std::list<Stone*>& ObArr)
{
    for (auto it = ObArr.begin(); it != ObArr.end(); it++)
    {
        Object* ob = *it;
        if (ob != nullptr && ob->getlifeStat() == Object::ALIFE
            && (ob->getObStat() == Object::GROUND || ob->getObStat() == Object::USED))
        {
            sf::Sprite sp;
            sp.setPosition(ob->getSprite().getPosition());
            sp.setScale(6, 6);
            if (ob->identify() == "small") { sp.setTextureRect(sf::IntRect(0, 0, 10, 7)); sp.move(0, -7 * 6); }
            else if (ob->identify() == "mid") { sp.setTextureRect(sf::IntRect(0, 0, 13, 7)); sp.move(0, -7 * 6); }
            else if (ob->identify() == "big") { sp.setTextureRect(sf::IntRect(0, 0, 15, 12)); sp.move(0, -12 * 6); }

            if (player.getSprite().getGlobalBounds().intersects(sp.getGlobalBounds()))
            {
                if ((player.getSprite().getPosition().y + 34 * 6) > ob->getSprite().getPosition().y)
                {
                    return true;
                }
            }
        }
    }
    return false;
}
