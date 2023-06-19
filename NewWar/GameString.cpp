#include "GameString.h"
#include <iostream>

GameString::GameString(std::string fileName, sf::RenderWindow* window, int limit)
	:m_window(window), m_sizeLimit(limit)
{
	m_font.loadFromFile(fileName + ".ttf");
	m_text.setFont(m_font);
}

void GameString::checkText()
{
	if(m_str.empty())
	{
		ShowAble = 0;
	}
	else
	{
		ShowAble = 1;
	}
	 if(m_change == 1)
	 {
		 bool changeIn = 1;
		 if (typeTimer.getElapsedTime().asMilliseconds() > 200) {
			 if (m_str.size() < m_sizeLimit) {
				 if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q)) {
					 m_str.push_back('q');
				 }
				 else if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
					 m_str.push_back('w');
				 }
				 else if (sf::Keyboard::isKeyPressed(sf::Keyboard::E)) {
					 m_str.push_back('e');
				 }
				 else if (sf::Keyboard::isKeyPressed(sf::Keyboard::R)) {
					 m_str.push_back('r');
				 }
				 else if (sf::Keyboard::isKeyPressed(sf::Keyboard::T)) {
					 m_str.push_back('t');
				 }
				 else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Y)) {
					 m_str.push_back('y');
				 }
				 else if (sf::Keyboard::isKeyPressed(sf::Keyboard::U)) {
					 m_str.push_back('u');
				 }
				 else if (sf::Keyboard::isKeyPressed(sf::Keyboard::I)) {
					 m_str.push_back('i');
				 }
				 else if (sf::Keyboard::isKeyPressed(sf::Keyboard::O)) {
					 m_str.push_back('o');
				 }
				 else if (sf::Keyboard::isKeyPressed(sf::Keyboard::P)) {
					 m_str.push_back('p');
				 }
				 else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
					 m_str.push_back('a');
				 }
				 else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
					 m_str.push_back('s');
				 }
				 else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
					 m_str.push_back('d');
				 }
				 else if (sf::Keyboard::isKeyPressed(sf::Keyboard::F)) {
					 m_str.push_back('f');
				 }
				 else if (sf::Keyboard::isKeyPressed(sf::Keyboard::G)) {
					 m_str.push_back('g');
				 }
				 else if (sf::Keyboard::isKeyPressed(sf::Keyboard::H)) {
					 m_str.push_back('h');
				 }
				 else if (sf::Keyboard::isKeyPressed(sf::Keyboard::J)) {
					 m_str.push_back('j');
				 }
				 else if (sf::Keyboard::isKeyPressed(sf::Keyboard::K)) {
					 m_str.push_back('k');
				 }
				 else if (sf::Keyboard::isKeyPressed(sf::Keyboard::L)) {
					 m_str.push_back('l');
				 }
				 else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z)) {
					 m_str.push_back('z');
				 }
				 else if (sf::Keyboard::isKeyPressed(sf::Keyboard::X)) {
					 m_str.push_back('x');
				 }
				 else if (sf::Keyboard::isKeyPressed(sf::Keyboard::C)) {
					 m_str.push_back('c');
				 }
				 else if (sf::Keyboard::isKeyPressed(sf::Keyboard::V)) {
					 m_str.push_back('v');
				 }
				 else if (sf::Keyboard::isKeyPressed(sf::Keyboard::B)) {
					 m_str.push_back('b');
				 }
				 else if (sf::Keyboard::isKeyPressed(sf::Keyboard::N)) {
					 m_str.push_back('n');
				 }
				 else if (sf::Keyboard::isKeyPressed(sf::Keyboard::M)) {
					 m_str.push_back('m');
				 }
				 else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num0)) {
					 m_str.push_back('0');
				 }
				 else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num1)) {
					 m_str.push_back('1');
				 }
				 else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num2)) {
					 m_str.push_back('2');
				 }
				 else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num3)) {
					 m_str.push_back('3');
				 }
				 else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num4)) {
					 m_str.push_back('4');
				 }
				 else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num5)) {
					 m_str.push_back('5');
				 }
				 else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num6)) {
					 m_str.push_back('6');
				 }
				 else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num7)) {
					 m_str.push_back('7');
				 }
				 else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num8)) {
					 m_str.push_back('8');
				 }
				 else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num9)) {
					 m_str.push_back('9');
				 }
				 else
				 {
					 changeIn = 0;
				 }
			 }

			 if ((sf::Keyboard::isKeyPressed(sf::Keyboard::LShift)
				 || sf::Keyboard::isKeyPressed(sf::Keyboard::RShift))
				 && changeIn == 1)
			 {
				m_str[m_str.size() - 1] = std::toupper(m_str[m_str.size() - 1]);
			 }
			 if(changeIn){ typeTimer.restart(); }
		 }
		 if (sf::Keyboard::isKeyPressed(sf::Keyboard::BackSpace) && !m_str.empty()
			 && typeTimer.getElapsedTime().asMilliseconds() > 100) {
			 m_str.pop_back();
			 typeTimer.restart();
		 }
		 m_text.setString(m_str);
	 }
}

void GameString::draw()
{
	if(ShowAble)
		m_window->draw(m_text);
}
