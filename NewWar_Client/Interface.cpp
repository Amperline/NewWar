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

	ChestIntf_img.loadFromFile("resource/images/Interface/ChestInterf.png");
	ChestIntf_txtr.loadFromImage(ChestIntf_img);
	ChestIntf_sprt.setTexture(ChestIntf_txtr);

	Line_sprt.setScale(6, 6);
	Invnt_sprt.setScale(6, 6);
	Curr_sprt.setScale(6, 6);
	CURR_sprt.setScale(6, 6);
	Icon_sprt.setScale(6, 6);
	Bin_sprt.setScale(6, 6);
	ChestIntf_sprt.setScale(6, 6);

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
			//drawing and checking object, that is controled by mouse in inventory 
			int v = 0;
			int b = 0;
			sf::Sprite sp;
			sp.setTextureRect(sf::IntRect(0, 0, 25, 25));
			sp.setScale(6, 6);	
			
			for (int i = 0; i < 33; i++)
			{
				if (i < 6)
				{
					sp.setPosition((m_window->getView().getCenter().x - 960 + (98 * 6) + (120 * i)),
						(m_window->getView().getCenter().y - 540 + (155 * 6)));
				}
				else if (i < 31)
				{
					sp.setPosition((m_window->getView().getCenter().x - 960 + (118 * 6 + (120 * v))),
						(m_window->getView().getCenter().y - 540 + (40 * 6 + (120 * b))));
					v++;
					if (v == 5) { v = 0; b++; }
				}
				else if (i < 33)
				{
					if (i == 31) {
						sp.setPosition((m_window->getView().getCenter().x - 960 + (53 * 6)),
							(m_window->getView().getCenter().y - 540 + (120 * 6)));
					}
					else if (i == 32) {
						sp.setPosition((m_window->getView().getCenter().x - 960 + (73 * 6)),
							(m_window->getView().getCenter().y - 540 + (120 * 6)));
					}
				}
				sf::Vector2i mousePosition = sf::Mouse::getPosition(*m_window);
				sf::Vector2f worldPosition = m_window->mapPixelToCoords(mousePosition);
				if (sp.getGlobalBounds().contains(worldPosition)
					&& sf::Mouse::isButtonPressed(sf::Mouse::Left)
					&& ButtonMpressed2 == 0)
				{
					if(player->ObjectsLine[i] != nullptr)
						InventIsSwap = 1;
					player->setCurrOb(i);
					ButtonMpressed2 = 1;
					delete currObInChest;
					currObInChest = nullptr;
					break;
				}
				if (InventIsSwap && player->ObjectsLine[i] != nullptr
					&& player->CurrOb == &player->ObjectsLine[i]
					&& i != 0 && currObInChest == nullptr)
				{
					sf::Sprite spC(player->ObjectsLine[i]->getPresentSprite());
					spC.setOrigin(0, 0);
					float x = worldPosition.x - (spC.getGlobalBounds().width / 2);
					float y = worldPosition.y - (spC.getGlobalBounds().height / 2);
					player->ObjectsLine[i]->getPresentSprite().setPosition(x, y);
				}
			}
			
			if (m_CurrChest != nullptr)
			{
				int v1 = 0;
				int b1 = 0;
				for (int i = 0; i < 20; i++)
				{
					sp.setPosition((m_window->getView().getCenter().x - 960 + (235 * 6 + (120 * v1))),
						(m_window->getView().getCenter().y - 540 + (40 * 6 + (120 * b1))));

					sf::Vector2i mousePosition = sf::Mouse::getPosition(*m_window);
					sf::Vector2f worldPosition = m_window->mapPixelToCoords(mousePosition);

					if(sp.getGlobalBounds().contains(worldPosition)
						&& sf::Mouse::isButtonPressed(sf::Mouse::Left)
						&& ButtonMpressed2 == 0)
					{
						if(currObInChest != nullptr)
							InventIsSwap = 1;
						currObInChest = new int(i);
						ButtonMpressed2 = 1;
						break;
					}
					v1++;
					if (v1 == 4) { v1 = 0; b1++; }
					if (InventIsSwap && currObInChest != nullptr 
						&& m_CurrChest->getArray()[i] != nullptr && *currObInChest == i)
					{
						sf::Sprite spC(m_CurrChest->getArray()[i]->getPresentSprite());
						spC.setOrigin(0, 0);
						float x = worldPosition.x - (spC.getGlobalBounds().width / 2);
						float y = worldPosition.y - (spC.getGlobalBounds().height / 2);
						m_CurrChest->getArray()[i]->getPresentSprite().setPosition(x, y);
					}
				}
			}

			Bin_sprt.setTextureRect(sf::IntRect(0, 0, 15, 15));
			//check swap
			if (InventIsSwap)
			{
				if(currObInChest != nullptr)
				{

					int v2 = 0;
					int b2 = 0;
					for (int j = 0; j < 33; j++)
					{
						sf::Sprite sp2;
						sp2.setTextureRect(sf::IntRect(0, 0, 25, 25));
						sp2.setScale(6, 6);
						if (j < 6)
						{
							sp2.setPosition((m_window->getView().getCenter().x - 960 + (98 * 6) + (120 * j)),
								(m_window->getView().getCenter().y - 540 + (155 * 6)));
						}
						else if (j < 31)
						{
							sp2.setPosition((m_window->getView().getCenter().x - 960 + (118 * 6 + (120 * v2))),
								(m_window->getView().getCenter().y - 540 + (40 * 6 + (120 * b2))));
							v2++;
							if (v2 == 5) { v2 = 0; b2++; }
						}
						else if (j < 33)
						{
							if (j == 31) {
								sp2.setPosition((m_window->getView().getCenter().x - 960 + (53 * 6)),
									(m_window->getView().getCenter().y - 540 + (120 * 6)));
							}
							else if (j == 32) {
								sp2.setPosition((m_window->getView().getCenter().x - 960 + (73 * 6)),
									(m_window->getView().getCenter().y - 540 + (120 * 6)));
							}
						}
						sf::Vector2i mousePosition = sf::Mouse::getPosition(*m_window);
						sf::Vector2f worldPosition = m_window->mapPixelToCoords(mousePosition);

						if (sp2.getGlobalBounds().contains(worldPosition)
							&& !sf::Mouse::isButtonPressed(sf::Mouse::Left))
						{
							player->swapWithChest(m_CurrChest, j, *currObInChest);
							player->setCurrOb(j);
							delete currObInChest;
							currObInChest = nullptr;
							break;
						}
					}
				}

				for (int i = 0; i < 33; i++)
				{
					if (player->ObjectsLine[i] != nullptr
						&& player->CurrOb == &player->ObjectsLine[i]
						&& i != 0)
					{
						int v2 = 0;
						int b2 = 0;
						for (int j = 0; j < 33; j++)
						{
							sf::Sprite sp2;
							sp2.setTextureRect(sf::IntRect(0, 0, 25, 25));
							sp2.setScale(6, 6);
							if (j < 6)
							{
								sp2.setPosition((m_window->getView().getCenter().x - 960 + (98 * 6) + (120 * j)),
									(m_window->getView().getCenter().y - 540 + (155 * 6)));
							}
							else if (j < 31)
							{
								sp2.setPosition((m_window->getView().getCenter().x - 960 + (118 * 6 + (120 * v2))),
									(m_window->getView().getCenter().y - 540 + (40 * 6 + (120 * b2))));
								v2++;
								if (v2 == 5) { v2 = 0; b2++; }
							}
							else if (j < 33)
							{
								if (j == 31) {
									sp2.setPosition((m_window->getView().getCenter().x - 960 + (53 * 6)),
										(m_window->getView().getCenter().y - 540 + (120 * 6)));
								}
								else if (j == 32) {
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
								if (!sf::Mouse::isButtonPressed(sf::Mouse::Left))
								{
									player->throwObject(i);
									break;
								}
							}
						}
					}
				}

				int indexChar = 0;
				int v1 = 0;
				int b1 = 0;
				for (int i = 0; i < 33; i++) { if (player->ObjectsLine[i] == *player->CurrOb) indexChar = i; }
				for (int i = 0; i < 20; i++)
				{
					sf::Sprite sp2;
					sp2.setTextureRect(sf::IntRect(0, 0, 25, 25));
					sp2.setScale(6, 6);
						
					sp2.setPosition((m_window->getView().getCenter().x - 960 + (235 * 6 + (120 * v1))),
						(m_window->getView().getCenter().y - 540 + (40 * 6 + (120 * b1))));


					sf::Vector2i mousePosition = sf::Mouse::getPosition(*m_window);
					sf::Vector2f worldPosition = m_window->mapPixelToCoords(mousePosition);

					sf::Sprite sp3(sp2);
					sp3.setPosition((m_window->getView().getCenter().x - 960 + (33 * 6)),
						(m_window->getView().getCenter().y - 540 + (120 * 6)));

					if (sp2.getGlobalBounds().contains(worldPosition)
						&& !sf::Mouse::isButtonPressed(sf::Mouse::Left))
					{
						if(currObInChest == nullptr)
						{
							player->swapWithChest(m_CurrChest, indexChar, i);
							delete currObInChest;
							currObInChest = new int(i);
							player->setCurrOb(0);
							break;
						}
						if (*currObInChest != i)
						{
							m_CurrChest->swapOB(*currObInChest, i);
							delete currObInChest;
							currObInChest = new int(i);
							break;
						}
					}
					else if (sp3.getGlobalBounds().contains(worldPosition) && currObInChest != nullptr)
					{
						Bin_sprt.setTextureRect(sf::IntRect(20, 0, 15, 15));
						if (!sf::Mouse::isButtonPressed(sf::Mouse::Left))
						{
							m_CurrChest->throwObject(*currObInChest);
							break;
						}
					}
					v1++;
					if (v1 == 4) { v1 = 0; b1++; }
				}
				
			}
			if (!sf::Mouse::isButtonPressed(sf::Mouse::Left)) { InventIsSwap = 0; }
		}
	}
	
	m_KEYflags->MouseL = 0;
	m_KEYflags->KeyR = 0;
	m_KEYflags->x = sf::Mouse::getPosition().x;
	m_KEYflags->y = sf::Mouse::getPosition().y;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::R)) { m_KEYflags->KeyR = 1; }
	if (InterfStat == DEFAULT)
	{
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) { m_KEYflags->MouseL = 1; }
	}
}

void Interface::checkAll(std::list<Chest*>& CHESTS)
{
	
	if (!sf::Mouse::isButtonPressed(sf::Mouse::Left)) { ButtonMpressed = 0; ButtonMpressed2 = 0; ButtonMpressed3 = 0; }
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
				m_CurrChest = nullptr;
				if (currObInChest != nullptr)  delete currObInChest;
				currObInChest = nullptr;
			}
			TABBED = 1;
		}
	}
	else
		if(!sf::Keyboard::isKeyPressed(sf::Keyboard::Tab))
		{
			TABBED = 0;
		}

	sf::Vector2i mousePosition = sf::Mouse::getPosition(*m_window);
	sf::Vector2f worldPosition = m_window->mapPixelToCoords(mousePosition);

	for (auto it = CHESTS.begin(); it != CHESTS.end(); it++)
	{
		Chest* ch = *it;
		sf::Sprite tmpSp = ch->getSprite();
		tmpSp.setScale(6, 6);
		tmpSp.setTextureRect(sf::IntRect(0, 0, 100, 100));
		tmpSp.setOrigin(40, 40);

		sf::Sprite sp = player->getSprite();
		sp.setPosition(player->getSprite().getPosition().x, player->getSprite().getPosition().y + (16 * 6));
		sp.setOrigin(4, 16);

		if(InterfStat == DEFAULT
			&& sp.getGlobalBounds().intersects(tmpSp.getGlobalBounds())
			&& ButtonMpressed3 == 0 && sf::Mouse::isButtonPressed(sf::Mouse::Left)
			&& ch->getSprite().getGlobalBounds().contains(worldPosition))
		{
			m_CurrChest = *it;
			ButtonMpressed3 = 1;
			InterfStat = InterfaceStatus::INVENTORY;
		}
		if(InterfStat == INVENTORY 
			&& m_CurrChest != nullptr && m_CurrChest == *it
			&& !sp.getGlobalBounds().intersects(tmpSp.getGlobalBounds()))
		{
			InterfStat = DEFAULT;
			InventIsSwap = 0;
			m_CurrChest = nullptr;
			if (currObInChest != nullptr)  delete currObInChest;
			currObInChest = nullptr;
		}
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
			CURRSP.setPosition((m_window->getView().getCenter().x - 960 + (3 * 6)),
				(m_window->getView().getCenter().y - 540 + (162 * 6)));
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

		//Getting objects from the ground
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
			m_window->draw(Line_sprt);
			if (InterfStat == INVENTORY)
			{
				if(m_CurrChest != nullptr)
				{
					ChestIntf_sprt.setPosition(m_window->getView().getCenter().x - 960, m_window->getView().getCenter().y - 540);
					m_window->draw(ChestIntf_sprt);
					if (currObInChest != nullptr)
					{
						int v1 = 0;
						int b1 = 0;
						for (int i = 0; i < 20; i++)
						{
							Curr_sprt.setPosition((m_window->getView().getCenter().x - 960 + (235 * 6 + (120 * v1))),
								(m_window->getView().getCenter().y - 540 + (40 * 6 + (120 * b1))));
							if (*currObInChest == i) { m_window->draw(Curr_sprt); }
							if (m_CurrChest->getArray()[i] != nullptr)
							{
								bool IsSwap = 0;
								if (InventIsSwap && *currObInChest == i) { IsSwap = 1; }
								if (!IsSwap)
								{
									m_CurrChest[i].getPresentSprite().setPosition((m_window->getView().getCenter().x - 960 + (240 * 6) + (120 * v1)),
										(m_window->getView().getCenter().y - 540 + (45 * 6) + (120 * b1)));
								}
								m_window->draw(m_CurrChest[i].getPresentSprite());
							}
							v1++;
							if (v1 == 4) { v1 = 0; b1++; }
						}
					}
				}
				Bin_sprt.setPosition((m_window->getView().getCenter().x - 960 + (38 * 6)),
					(m_window->getView().getCenter().y - 540 + (125 * 6)));
				m_window->draw(Bin_sprt);
				//Red object icon
				if(currObInChest == nullptr){
					int b = 0;
					int v = 0;
					for (int i = 6; i < 33; i++)
					{
						if (player->CurrOb == &player->ObjectsLine[i])
						{
							if (i < 31)
							{
								Curr_sprt.setPosition((m_window->getView().getCenter().x - 960 + (118 * 6 + (120 * v))),
									(m_window->getView().getCenter().y - 540 + (40 * 6 + (120 * b))));
							}
							else if (i < 33)
							{
								if (i == 31) {
									Curr_sprt.setPosition((m_window->getView().getCenter().x - 960 + (53 * 6)),
										(m_window->getView().getCenter().y - 540 + (120 * 6)));
								}
								else if (i == 32) {
									Curr_sprt.setPosition((m_window->getView().getCenter().x - 960 + (73 * 6)),
										(m_window->getView().getCenter().y - 540 + (120 * 6)));
								}

							}
							m_window->draw(Curr_sprt);
							break;
						}
						if (i >= 6 && i < 31)
						{
							v++;
							if (v == 5) { v = 0; b++; }
						}
					}
				}
				int b = 0;
				int v = 0;
				for (int i = 6; i < 31; i++)
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

			//Object line
			for (int i = 0; i < 6; i++)
			{
				if (player->CurrOb == &player->ObjectsLine[i] && currObInChest == nullptr)
				{
					Curr_sprt.setPosition((m_window->getView().getCenter().x - 960 + (98 * 6) + (120 * i)),
						(m_window->getView().getCenter().y - 540 + (155 * 6)));
					m_window->draw(Curr_sprt);
					break;
				}
			}
			for (int i = 0; i < 6; i++)
			{
				if (player->ObjectsLine[i] != nullptr)
				{
					bool IsSwap = 0;
					if (InventIsSwap && player->CurrOb == &player->ObjectsLine[i] && currObInChest == nullptr) { IsSwap = 1; }
					if (!IsSwap)
					{
						player->ObjectsLine[i]->getPresentSprite().setPosition((m_window->getView().getCenter().x - 960 + (103 * 6 + (120 * i))),
							(m_window->getView().getCenter().y - 540 + (160 * 6)));
					}
					if (player->ObjectsLine[i]->getObStat() == Object::INPLAYER)
					{
						m_window->draw(player->ObjectsLine[i]->getPresentSprite());
					}
					else player->ObjectsLine[i]->draw();
				}
			}
		}
	}
	else if (InterfStat == SETTINGS)
	{

	}
}
