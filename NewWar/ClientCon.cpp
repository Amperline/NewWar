#include "ClientCon.h"
#include "SFML/Network/SocketHandle.hpp"

ClientCon::ClientCon(sf::TcpSocket* sockClient, std::string name, std::string id)
{
	clientHandle = sockClient;
	m_nickname = name;
	m_id = id;
}
