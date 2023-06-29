#include "Ammo.h"


Ammo::Ammo(sf::RenderWindow* window, AMMOVAR ammoVar, sf::Vector2f Start, sf::Vector2f Finish, float angle)
	: m_window(window), AmmoVar(ammoVar)
{
	m_img.loadFromFile("resource/images/Weapon/Ammo.png");
	m_sprt.setPosition(Start);
	m_sprt.setScale(6, 6);
	m_sprt.setRotation(angle);
}

void Ammo::check(float time)
{
}

void Ammo::draw()
{
}
