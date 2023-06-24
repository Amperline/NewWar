#pragma once
#include <string>
#include <SFML/Graphics.hpp>

struct ConnectorPacket
{
	bool LorC;
	std::string Name;
	std::string Password;
};