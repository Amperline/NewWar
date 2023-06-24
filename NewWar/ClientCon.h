#pragma once
#include <SFML/Network.hpp>
#include <SFML/Graphics.hpp>

class ClientCon
{

private:
	std::string m_nickname;
	std::string m_id;
	sf::TcpSocket* clientHandle;
public:
	ClientCon(sf::TcpSocket* sockClient, std::string name, std::string id);
};
