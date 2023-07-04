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

	Line_sprt.setScale(6, 6);
	Invnt_sprt.setScale(6, 6);
	Curr_sprt.setScale(6, 6);
}

void Interface::checkAll()
{
	Line_sprt.setPosition(m_window->getView().getCenter().x - 960, m_window->getView().getCenter().y - 540);
}

void Interface::draw()
{
	if (InterfStat == DEFAULT || InterfStat == INVENTORY)
	{
		m_window->draw(Line_sprt);
		if (InterfStat == INVENTORY)
		{
			m_window->draw(Invnt_sprt);
		}
		for (int i = 0; i < 6; i++)
		{
			if (player->ObjectsLine[i] != nullptr)
			{
				player->ObjectsLine[i]->getPresentSprite().setPosition((m_window->getView().getCenter().x - 960 + (98 * 6)),
					(m_window->getView().getCenter().y - 540 + (155 * 6)));
				if (player->ObjectsLine[i]->getObStat() == Object::INPLAYER)
				{
					m_window->draw(player->ObjectsLine[i]->getPresentSprite());
				}
				else player->ObjectsLine[i]->draw();
			}
		}
	}
	else if (InterfStat == SETTINGS)
	{

	}
}
