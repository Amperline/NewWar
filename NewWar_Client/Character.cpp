#include "Character.h"

Character::Character(sf::RenderWindow* window, sf::Vector2f startPos)
	:m_window(window)
{
	m_img.loadFromFile("resource/images/Character/DefaultSoldeir.png");
	m_txtr.loadFromImage(m_img);
	m_sprt.setTexture(m_txtr);
	m_sprt.setTextureRect(sf::IntRect(0, 0, 20, 34));
	m_sprt.setOrigin(4, 0);
	m_sprt.setScale(6, 6);

	NormalDown[0] = sf::IntRect(0, 0, 20, 34);
	NormalDown[1] = sf::IntRect(20, 0, 20, 34);
	NormalDown[2] = sf::IntRect(40, 0, 20, 34);
	NormalDown[3] = sf::IntRect(20, 0, 20, 34);

	NormalUp[0] = sf::IntRect(0, 34, 20, 34);
	NormalUp[1] = sf::IntRect(20, 34, 20, 34);
	NormalUp[2] = sf::IntRect(40, 34, 20, 34);
	NormalUp[3] = sf::IntRect(20, 34, 20, 34);

	NormalLeft[0] = sf::IntRect(0, 68, 20, 34);
	NormalLeft[1] = sf::IntRect(20, 68, 20, 34);
	NormalLeft[2] = sf::IntRect(40, 68, 20, 34);
	NormalLeft[3] = sf::IntRect(20, 68, 20, 34);

	NormalRight[0] = sf::IntRect(0, 102, 20, 34);
	NormalRight[1] = sf::IntRect(20, 102, 20, 34);
	NormalRight[2] = sf::IntRect(40, 102, 20, 34);
	NormalRight[3] = sf::IntRect(20, 102, 20, 34);

	CarryingDown[0] = sf::IntRect(0 + 60, 0, 20, 34);
	CarryingDown[1] = sf::IntRect(20 + 60, 0, 20, 34);
	CarryingDown[2] = sf::IntRect(40 + 60, 0, 20, 34);
	CarryingDown[3] = sf::IntRect(20 + 60, 0, 20, 34);

	CarryingUp[0] = sf::IntRect(0 + 60, 34, 20, 34);
	CarryingUp[1] = sf::IntRect(20 + 60, 34, 20, 34);
	CarryingUp[2] = sf::IntRect(40 + 60, 34, 20, 34);
	CarryingUp[3] = sf::IntRect(20 + 60, 34, 20, 34);

	CarryingLeft[0] = sf::IntRect(0 + 60, 68, 20, 34);
	CarryingLeft[1] = sf::IntRect(20 + 60, 68, 20, 34);
	CarryingLeft[2] = sf::IntRect(40 + 60, 68, 20, 34);
	CarryingLeft[3] = sf::IntRect(20 + 60, 68, 20, 34);

	CarryingRight[0] = sf::IntRect(0 + 60, 102, 20, 34);
	CarryingRight[1] = sf::IntRect(20 + 60, 102, 20, 34);
	CarryingRight[2] = sf::IntRect(40 + 60, 102, 20, 34);
	CarryingRight[3] = sf::IntRect(20 + 60, 102, 20, 34);

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


	m_sprt.setTextureRect(NormalDown[0]);
	CurrOb = &ObjectsLine[1];
}

void Character::checkAnim(float time)
{
	currFrame += 0.005 * time;
	if (currFrame >= 4) { currFrame = 0; }
	if(playerStat == NORMAL)
	{	
		if(Left == 1)
		{
			m_sprt.move(-0.2 * time, 0);
			m_sprt.setTextureRect(NormalLeft[int(currFrame)]);
		}
		else if(Right == 1 && Left == 0)
		{
			m_sprt.move(0.2 * time, 0);
			m_sprt.setTextureRect(NormalRight[int(currFrame)]);
		}
		if(Up == 1)
		{
			m_sprt.move(0, -0.2 * time);
			m_sprt.setTextureRect(NormalUp[int(currFrame)]);
		}
		else if(Down == 1 && Up == 0)
		{
			m_sprt.move(0, 0.2 * time);
			m_sprt.setTextureRect(NormalDown[int(currFrame)]);
		}
	}
	else if (playerStat == CARRYING)
	{
		if (Left == 1)
		{
			m_sprt.move(-0.2 * time, 0);
			m_sprt.setTextureRect(CarryingLeft[int(currFrame)]);
		}
		else if (Right == 1 && Left == 0)
		{
			m_sprt.move(0.2 * time, 0);
			m_sprt.setTextureRect(CarryingRight[int(currFrame)]);
		}
		if (Up == 1)
		{
			m_sprt.move(0, -0.2 * time);
			m_sprt.setTextureRect(CarryingUp[int(currFrame)]);
		}
		else if (Down == 1 && Up == 0)
		{
			m_sprt.move(0, 0.2 * time);
			m_sprt.setTextureRect(CarryingDown[int(currFrame)]);
		}
	}
}

void Character::checkAll(float time)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) { Left = 1; Right = 0; lastSide = 3; }
	else { Left = 0; }
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) { Right = 1; Left = 0; lastSide = 4; }
	else { Right = 0; }
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) { Up = 1; Down = 0; lastSide = 1; }
	else { Up = 0; }
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) { Down = 1; Up = 0; lastSide = 2; }
	else { Down = 0; }
	checkAnim(time);
	if(CurrOb != nullptr)
	{
		Object* ValCrrOb = *CurrOb;
		ValCrrOb->setObStat(Object::INPLAYER);
		if(Right == 1)
		{
			ValCrrOb->getPosSet() = sf::Vector2i(sf::Vector2f(m_sprt.getPosition().x + 72, m_sprt.getPosition().y + 84));
		}
		else if (Left == 1)
		{
			ValCrrOb->getPosSet() = sf::Vector2i(sf::Vector2f(m_sprt.getPosition().x, m_sprt.getPosition().y + 84));
		}
		if (Down == 1 || Up == 1)
		{
			ValCrrOb->getPosSet() = sf::Vector2i(sf::Vector2f(m_sprt.getPosition().x + 36, m_sprt.getPosition().y + 84));
		}
	}
	if(CurrOb != &ObjectsLine[0] && CurrOb != nullptr)
	{
		playerStat = PlayerStatus::CARRYING;
	}
	else
	{
		playerStat = PlayerStatus::NORMAL;
	}
}

void Character::draw()
{
	if(CurrOb != nullptr)
	{
		Object* ValCrrOb = *CurrOb;
		if (lastSide == 2 || lastSide == 3 || lastSide == 4)
		{
			m_window->draw(m_sprt);
			ValCrrOb->draw();
		}
		else if(lastSide == 1)
		{
			ValCrrOb->draw();
			m_window->draw(m_sprt);
		}
	}
	else
	{
		m_window->draw(m_sprt);
	}
}

bool Character::ownObject(Object* ob)
{
	for(int i = 1; i < 36; i++)
	{
		if(ObjectsLine[i] == nullptr)
		{
			if(i == 1)
			{
				if (ob->identify() == "Main")
				{
					ObjectsLine[1] = ob;
					ob->setObStat(Object::INVENT);
					return 1;
				}
			}
			else if(i == 2)
			{
				if (ob->identify() == "Pistol")
				{
					ObjectsLine[2] = ob;
					ob->setObStat(Object::INVENT);
					return 1;
				}
			}
			else
			{
				ObjectsLine[i] = ob;
				ob->setObStat(Object::INVENT);
				return 1;
			}
		}
	}
	return false;
}

void Character::throwObject(short index)
{
	ObjectsLine[index]->setObStat(Object::GROUND);
	ObjectsLine[index] = nullptr;
}