#include "Ammo.h"

Ammo::Ammo(sf::RenderWindow* window, AMMOVAR ammoVar, sf::Vector2f Start, float angle)
	: m_window(window), AmmoVar(ammoVar), m_angle(angle)
{
	LifeStat = ALIFE;
	m_img.loadFromFile("resource/images/Weapon/Ammo.png");
	m_txtr.loadFromImage(m_img);
	m_sprt.setTexture(m_txtr);
	m_sprt.setPosition(Start);
	m_sprt.setScale(6, 6);
	m_sprt.setRotation(angle + 90);

	if(AmmoVar == SMALL)
	{
		m_txtrRects[0] = {0, 0, 3, 6 };
		m_txtrRects[1] = {0, 7, 3, 6 };
		m_txtrRects[2] = {0, 14, 3, 6 };
	}
	else if(AmmoVar == MIDD)
	{
		m_txtrRects[0] = { 4, 0, 3, 6 };
		m_txtrRects[1] = { 4, 7, 3, 6 };
		m_txtrRects[2] = { 4, 14, 3, 6 };
	}
	else if(AmmoVar == BIG)
	{
		m_txtrRects[0] = { 8, 0, 3, 6 };
		m_txtrRects[1] = { 8, 7, 3, 6 };
		m_txtrRects[2] = { 8, 14, 3, 6 };
	}
	m_sprt.setTextureRect(m_txtrRects[0]);
	float temprAngle = m_sprt.getRotation();
	if(temprAngle >= 0 && temprAngle < 180)
	{
		m_sprt.setOrigin(2, 5);
	}
	else
	{
		m_sprt.setOrigin(1, 5);
	}

	float radians = m_angle * PI / 180;
	float speed = 50;

	float x = m_sprt.getPosition().x + (std::cos(radians) * speed);
	float y = m_sprt.getPosition().y + (std::sin(radians) * speed);
	m_sprt.setPosition(x, y);

	TimertoDeath.restart();
}

void Ammo::death()
{
	LifeStat = DEAD;
}

void Ammo::check(float time)
{
	if (LifeStat == ALIFE)
	{
		float radians = m_angle * PI / 180;
		float speed = 2;

		float x = m_sprt.getPosition().x + std::cos(radians) * speed * time;
		float y = m_sprt.getPosition().y + std::sin(radians) * speed * time;
		m_sprt.setPosition(x, y);

		if (TimertoDeath.getElapsedTime().asMilliseconds() > 2000)
		{
			LifeStat = DEAD;
		}
	}
	else if (LifeStat == DEAD)
	{
		if (Dead != 1)
		{
			TimerAnim.restart();
			Dead = 1;
		}
	}
}

void Ammo::draw()
{
	if(LifeStat == ALIFE)
	{
		m_window->draw(m_sprt);
	}
	else if(LifeStat == DEAD && END != 1)
	{
		int frame = 0;
		frame = TimerAnim.getElapsedTime().asMilliseconds() / 500;
		if (frame > 2)
		{
			frame = 2;
		}
		m_sprt.setTextureRect(m_txtrRects[frame]);
		if(frame >= 2)
		{
			END = 1;
		}
		m_window->draw(m_sprt);
	}
}

Ammo::~Ammo()
{
	m_window = nullptr;
}
