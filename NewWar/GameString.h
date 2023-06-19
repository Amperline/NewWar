#pragma once
#include <SFML/Graphics.hpp>
#include <string>

class GameString
{
private:
	sf::RenderWindow* m_window;
	bool m_change = 0;
	sf::Font m_font;
	sf::Text m_text;
	std::string m_str;
	int m_sizeLimit;
	bool ShowAble = 1;
	sf::Clock typeTimer;
public:
	GameString(std::string fileName, sf::RenderWindow *window, int limit);
	sf::Text& getText() { return m_text; }
	std::string& getStr() { return m_str; }
	void checkText();
	void setShowa(bool show) { ShowAble = show; }
	bool getShowAble() { return ShowAble; }
	void setCangeAble(bool change) { m_change = change; }
	void draw();
};

