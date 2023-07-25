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

	Icon_img.loadFromFile("resource/images/Interface/IconForOB.png");
	Icon_txtr.loadFromImage(Icon_img);
	Icon_sprt.setTexture(Icon_txtr);

	Bin_img.loadFromFile("resource/images/Interface/Bin.png");
	Bin_txtr.loadFromImage(Bin_img);
	Bin_sprt.setTexture(Bin_txtr);

	Line_sprt.setScale(6, 6);
	Invnt_sprt.setScale(6, 6);
	Curr_sprt.setScale(6, 6);
	CURR_sprt.setScale(6, 6);
	Icon_sprt.setScale(6, 6);
	Bin_sprt.setScale(6, 6);

	Icon_sprt.setTextureRect(sf::IntRect(0, 0, 25, 25));
	Bin_sprt.setTextureRect(sf::IntRect(0, 0, 15, 15));
	ButtonMpressed = 1;
}

void Interface::checkKeys()
{
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
		
		if(InterfStat == INVENTORY)
		{
			int v = 0;
			int b = 0;
			sf::Sprite sp;
			sp.setTextureRect(sf::IntRect(0, 0, 25, 25));
			sp.setScale(6, 6);	
			for (int i = 0; i < 43; i++)
			{
				if (i < 6)
				{
					sp.setPosition((m_window->getView().getCenter().x - 960 + (98 * 6) + (120 * i)),
						(m_window->getView().getCenter().y - 540 + (155 * 6)));
				}
				else if (i < 41)
				{
					sp.setPosition((m_window->getView().getCenter().x - 960 + (118 * 6 + (120 * v))),
						(m_window->getView().getCenter().y - 540 + (40 * 6 + (120 * b))));
					v++;
					if (v == 5) { v = 0; b++; }
				}
				else if (i < 44)
				{
					if (i == 41) {
						sp.setPosition((m_window->getView().getCenter().x - 960 + (33 * 6)),
							(m_window->getView().getCenter().y - 540 + (120 * 6)));
					}
					else if (i == 42) {
						sp.setPosition((m_window->getView().getCenter().x - 960 + (53 * 6)),
							(m_window->getView().getCenter().y - 540 + (120 * 6)));
					}
					else if (i == 43) {
						sp.setPosition((m_window->getView().getCenter().x - 960 + (73 * 6)),
							(m_window->getView().getCenter().y - 540 + (120 * 6)));
					}
				}
				sf::Vector2i mousePosition = sf::Mouse::getPosition(*m_window);
				sf::Vector2f worldPosition = m_window->mapPixelToCoords(mousePosition);
				if(sp.getGlobalBounds().contains(worldPosition)
					&& sf::Mouse::isButtonPressed(sf::Mouse::Left)
					&& ButtonMpressed2 == 0)
				{
					InventIsSwap = 1;
					player->setCurrOb(i);
					ButtonMpressed2 = 1;
					break;
				}
				if(InventIsSwap && player->ObjectsLine[i] != nullptr 
					&& player->CurrOb == &player->ObjectsLine[i]
					&& i != 0 && i != 3)
				{
					sf::Sprite spC(player->ObjectsLine[i]->getPresentSprite());
					spC.setOrigin(0, 0);
					float x = worldPosition.x - (spC.getGlobalBounds().width / 2);
					float y = worldPosition.y - (spC.getGlobalBounds().height / 2);
					player->ObjectsLine[i]->getPresentSprite().setPosition(x, y);
				}
			}
			Bin_sprt.setTextureRect(sf::IntRect(0, 0, 15, 15));
			if (InventIsSwap)
			{
				for (int i = 0; i < 43; i++)
				{
					if (player->ObjectsLine[i] != nullptr
						&& player->CurrOb == &player->ObjectsLine[i]
						&& i != 0 && i != 3)
					{
						int v2 = 0;
						int b2 = 0;
						for (int j = 0; j < 43; j++)
						{
							sf::Sprite sp2;
							sp2.setTextureRect(sf::IntRect(0, 0, 25, 25));
							sp2.setScale(6, 6);
							if (j < 6)
							{
								sp2.setPosition((m_window->getView().getCenter().x - 960 + (98 * 6) + (120 * j)),
									(m_window->getView().getCenter().y - 540 + (155 * 6)));
							}
							else if (j < 41)
							{
								sp2.setPosition((m_window->getView().getCenter().x - 960 + (118 * 6 + (120 * v2))),
									(m_window->getView().getCenter().y - 540 + (40 * 6 + (120 * b2))));
								v2++;
								if (v2 == 5) { v2 = 0; b2++; }
							}
							else if (j < 43)
							{
								if (j == 41) {
									sp2.setPosition((m_window->getView().getCenter().x - 960 + (53 * 6)),
										(m_window->getView().getCenter().y - 540 + (120 * 6)));
								}
								else if (j == 42) {
									sp2.setPosition((m_window->getView().getCenter().x - 960 + (73 * 6)),
										(m_window->getView().getCenter().y - 540 + (120 * 6)));
								}
							}

							sf::Sprite sp3(sp2);
							sp3.setPosition((m_window->getView().getCenter().x - 960 + (33 * 6)),
								(m_window->getView().getCenter().y - 540 + (120 * 6)));

							sf::Vector2i mousePosition = sf::Mouse::getPosition(*m_window);
							sf::Vector2f worldPosition = m_window->mapPixelToCoords(mousePosition);

							if (sp2.getGlobalBounds().contains(worldPosition)
								&& !sf::Mouse::isButtonPressed(sf::Mouse::Left))
							{
								player->swapOB(i, j);
								player->setCurrOb(j);
								break;
							}
							else if (sp3.getGlobalBounds().contains(worldPosition))
							{
								Bin_sprt.setTextureRect(sf::IntRect(20, 0, 15, 15));
								if(!sf::Mouse::isButtonPressed(sf::Mouse::Left))
								{
									player->throwObject(i);
									break;
								}
							}
						}
					}
				}
			}
			if (!sf::Mouse::isButtonPressed(sf::Mouse::Left)) { InventIsSwap = 0; }
		}
	}
}

void Interface::checkAll()
{
	
	if (!sf::Mouse::isButtonPressed(sf::Mouse::Left)) { ButtonMpressed = 0; ButtonMpressed2 = 0; }
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
				player->setCurrOb(0);
				InventIsSwap = 0;
			}
			TABBED = 1;
		}
	}
	else
		if(!sf::Keyboard::isKeyPressed(sf::Keyboard::Tab))
		{
			TABBED = 0;
		}
}

void Interface::draw(std::list<Object*>& OBJECTS)
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

		sf::Sprite sp = player->getSprite();
		sp.setTextureRect(sf::IntRect(0, 0, 40, 54));
		sp.setOrigin(20, 16);

		int Founded = 0;
		for (auto it = OBJECTS.begin(); it != OBJECTS.end(); it++)
		{
			Object* ob = *it;
			if (ob != nullptr && ob->getObStat() == Object::ObjectStatus::GROUND)
			{
				if (sp.getGlobalBounds().intersects(ob->getSprite().getGlobalBounds()))
				{
					Icon_sprt.setPosition((m_window->getView().getCenter().x + 960 - (25 * 6) - (6 * 20 * Founded)),
						(m_window->getView().getCenter().y - 540));

					ob->getPresentSprite().setPosition((m_window->getView().getCenter().x - 960 + 1800 - (6 * 20 * Founded)) ,
						(m_window->getView().getCenter().y - 540 + 30));
					m_window->draw(Icon_sprt);
					m_window->draw(ob->getPresentSprite());
					Founded++;
					if (Founded > 0) { Icon_sprt.setTextureRect(sf::IntRect(0, 0, 20, 25)); }


					sf::Vector2i mousePosition = sf::Mouse::getPosition(*m_window);
					sf::Vector2f worldPosition = m_window->mapPixelToCoords(mousePosition);
					if(Icon_sprt.getGlobalBounds().contains(worldPosition)
						&& sf::Mouse::isButtonPressed(sf::Mouse::Left)
						&& ButtonMpressed == 0)
					{
						player->ownObject(ob);
						ButtonMpressed = 1;
					}
				}
			}
		}
		Icon_sprt.setTextureRect(sf::IntRect(0, 0, 25, 25));


		if (PRESSED == 1 || InterfStat == INVENTORY)
		{

			if (InterfStat == INVENTORY)
			{
				Bin_sprt.setPosition((m_window->getView().getCenter().x - 960 + (38 * 6)),
					(m_window->getView().getCenter().y - 540 + (125 * 6)));
				m_window->draw(Bin_sprt);
			{
				int b = 0;
				int v = 0;
				for (int i = 0; i < 43; i++)
				{
					if (player->CurrOb == &player->ObjectsLine[i])
					{
						if (i < 6)
						{
							Curr_sprt.setPosition((m_window->getView().getCenter().x - 960 + (98 * 6) + (120 * i)),
								(m_window->getView().getCenter().y - 540 + (155 * 6)));
						}
						else if (i < 41)
						{
							Curr_sprt.setPosition((m_window->getView().getCenter().x - 960 + (118 * 6 + (120 * v))),
								(m_window->getView().getCenter().y - 540 + (40 * 6 + (120 * b))));
						}
						else if (i < 43)
						{
							if (i == 41) { Curr_sprt.setPosition((m_window->getView().getCenter().x - 960 + (53 * 6)),
									(m_window->getView().getCenter().y - 540 + (120 * 6)));
							}
							else if (i == 42) { Curr_sprt.setPosition((m_window->getView().getCenter().x - 960 + (73 * 6)),
									(m_window->getView().getCenter().y - 540 + (120 * 6))); 
							}

						}
						m_window->draw(Curr_sprt);
						break;
					}
					if(i >= 6 && i < 41)
					{
						v++;
						if (v == 5) { v = 0; b++; }
					}
				}
			}

			m_window->draw(Line_sprt);
			for (int i = 0; i < 6; i++)
			{
				if (player->ObjectsLine[i] != nullptr)
				{
					bool IsSwap = 0;
					if (InventIsSwap && player->CurrOb == &player->ObjectsLine[i]) { IsSwap = 1; }
					if (!IsSwap)
					{
						player->ObjectsLine[i]->getPresentSprite().setPosition((m_window->getView().getCenter().x - 960 + (103 * 6 + (120 * i)) + 4),
							(m_window->getView().getCenter().y - 540 + (160 * 6)) + 5 * 6);
					}
					if (player->ObjectsLine[i]->getObStat() == Object::INPLAYER)
					{
						m_window->draw(player->ObjectsLine[i]->getPresentSprite());
					}
					else player->ObjectsLine[i]->draw();
				}
			}

				int b = 0;
				int v = 0;
				for (int i = 6; i < 41; i++)
				{
					if (player->ObjectsLine[i] != nullptr)
					{
						bool IsSwap = 0;
						if (InventIsSwap && player->CurrOb == &player->ObjectsLine[i]) { IsSwap = 1; }
						if (!IsSwap)
						{
							player->ObjectsLine[i]->getPresentSprite().setPosition((m_window->getView().getCenter().x - 960 + (123 * 6) + (120 * v)),
								(m_window->getView().getCenter().y - 540 + (45 * 6) + (b * 20 * 6)));
						}
						m_window->draw(player->ObjectsLine[i]->getPresentSprite());
					}
					v++;
					if (v == 5) { v = 0; b++; }
				}
			}
		}
	}
	else if (InterfStat == SETTINGS)
	{

	}
}
