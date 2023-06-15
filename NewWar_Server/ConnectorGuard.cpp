#include "ConnectorGuard.h"

void ConnectorGuard(std::list<sf::UdpSocket> connections)
{
	sf::TcpListener listner;
	listner.setBlocking(true);
	
	try
	{
		if (listner.listen(4097) != sf::Socket::Done)
		{
			throw std::exception("Error in socket binding!");
		}
	}
	catch (const std::exception& e)
	{
		std::cout << "Error: " << e.what();
		std::cout << std::endl;
	}
}
