#include "Interface.h"

Interface::Interface(sf::RenderWindow* window, Character* pl)
	:m_window(window), player(pl)
{
	Line_img.loadFromFile("resource/images/Interface/ObjectLine.png");
	Line_txtr.loadFromImage(Line_img);
	Line_sprt.setTexture(Line_txtr);

	Invnt_img.loadFromFile("resource/images/Interface/Inventory.png");
	Invnt_txtr.loadFromImage(Invnt_img);
	Invnt_sprt.setTexture(Invnt_txtr);

	Curr_img.loadFromFile("resource/images/Interface/CurrentOb.png");
	Curr_txtr.loadFromImage(Curr_img);
	Curr_sprt.setTexture(Curr_txtr);

	CURR_img.loadFromFile("resource/images/Interface/CURRObVAL.png");
	CURR_txtr.loadFromImage(CURR_img);
	CURR_sprt.setTexture(CURR_txtr);

	Line_sprt.setScale(6, 6);
	Invnt_sprt.setScale(6, 6);
	Curr_sprt.setScale(6, 6);
	CURR_sprt.setScale(6, 6);
}

void Interface::checkKeys()
{
	/*int valOfCurrEl{};
	for(int i = 0; i < player->ObjectsLine.size();)
	{
		Object* Val = *player->CurrOb;
		if (Val != nullptr)
		{
			if(Val == player->ObjectsLine[i])
			{
				valOfCurrEl = i;
				break;
			}
		}
		++i;
	}*/
	if(InterfStat == DEFAULT || InterfStat == INVENTORY)
	{
		PRESSED = 1;

		if(sf::Keyboard::isKeyPressed(sf::Keyboard::Num1))
		{
			player->setCurrOb(0);
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num2))
		{
			player->setCurrOb(1);
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num3))
		{
			player->setCurrOb(2);
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num4))
		{
			player->setCurrOb(3);
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num5))
		{
			player->setCurrOb(4);
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num6))
		{
			player->setCurrOb(5);
		}
		else
		{
			PRESSED = 0;
		}

		if (PRESSED == 1) { PressTimer.restart(); }
		if(PressTimer.getElapsedTime().asMilliseconds() < 600)
		{
			if(PERMISSION == 1)
				PRESSED = 1;
		}
		
		if(PressTimer.getElapsedTime().asMilliseconds() > 500)
		{
			PERMISSION = 1;
		}
	}
}

void Interface::checkAll()
{
	if(TABBED == 0)
	{
		if(sf::Keyboard::isKeyPressed(sf::Keyboard::Tab))
		{
			if(InterfStat == DEFAULT)
			{
				InterfStat = INVENTORY;
			}
			else if(InterfStat == INVENTORY)
			{
				InterfStat = DEFAULT;
			}
			TABBED = 1;
		}
	}
	else
		if(!sf::Keyboard::isKeyPressed(sf::Keyboard::Tab))
		{
			TABBED = 0;
		}
	checkKeys();
}

void Interface::draw()
{
	if (InterfStat == DEFAULT)
	{
		sf::Font f;
		f.loadFromFile("resource/fonts/NewWar.ttf");
		sf::Text miniInfo;
		miniInfo.setFont(f);
		miniInfo.setPosition(m_window->getView().getCenter().x - 960 + (21 * 6) + 4,
			m_window->getView().getCenter().y - 540 + (170 * 6) + 10);

		CURR_sprt.setPosition(m_window->getView().getCenter().x - 960,
			m_window->getView().getCenter().y - 540);
		m_window->draw(CURR_sprt);

		Object* SprtPTR = *player->CurrOb;
		if (SprtPTR != nullptr)
		{
			miniInfo.setString(SprtPTR->getMiniInfoDefault());
			miniInfo.setCharacterSize(22);

			sf::Sprite CURRSP = SprtPTR->getPresentSprite();
			CURRSP.setPosition((m_window->getView().getCenter().x - 960 + (3 * 6) + 4),
				(m_window->getView().getCenter().y - 540 + (162 * 6)) + 5 * 6);
			m_window->draw(CURRSP);
			m_window->draw(miniInfo);
		}
	}
	if (InterfStat == DEFAULT || InterfStat == INVENTORY)
	{
		Line_sprt.setPosition(m_window->getView().getCenter().x - 960, m_window->getView().getCenter().y - 540);
		Invnt_sprt.setPosition(m_window->getView().getCenter().x - 960, m_window->getView().getCenter().y - 540);
		if (InterfStat == INVENTORY)
		{
			PressTimer.restart();
			m_window->draw(Invnt_sprt);
		}
		if (PRESSED == 1 || InterfStat == INVENTORY)
		{
			m_window->draw(Line_sprt);
			for (int i = 0; i < 6; i++)
			{
				if (player->ObjectsLine[i] != nullptr)
				{
					player->ObjectsLine[i]->getPresentSprite().setPosition((m_window->getView().getCenter().x - 960 + (103 * 6 + (120 * i)) + 4),
						(m_window->getView().getCenter().y - 540 + (160 * 6)) + 5 * 6);
					if (player->ObjectsLine[i]->getObStat() == Object::INPLAYER)
					{
						m_window->draw(player->ObjectsLine[i]->getPresentSprite());
					}
					else player->ObjectsLine[i]->draw();
				}
			}
			for (int i = 0; i < 36; i++)
			{
				Object* Curr = *player->CurrOb;
				if (player->CurrOb == &player->ObjectsLine[i])
				{
					if (i < 6)
					{
						Curr_sprt.setPosition((m_window->getView().getCenter().x - 960 + (98 * 6) + (120 * i)),
							(m_window->getView().getCenter().y - 540 + (155 * 6)));
					}
					else
					{
					}
					m_window->draw(Curr_sprt);
				}
			}
		}
	}
	else if (InterfStat == SETTINGS)
	{

	}
}
