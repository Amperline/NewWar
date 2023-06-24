#include <iostream>

#include <NewWar/NewWarLib.h>
#include "ConnectorGuard.h"

#include <mysql_driver.h>
#include <mysql_connection.h>
#include <cppconn/prepared_statement.h>
#include <cppconn/resultset.h>
#include <list>
#include <thread>

#include <SFML/Graphics.hpp>
#include <SFML/Network.hpp>

std::list<ClientCon> connections;

int main()
{
	/*std::thread guardCon(ConnectorGuard, std::ref(connections), std::ref(std::cout));
	guardCon.detach();*/
	ConnectorGuard(connections, std::cout);

	while (1)
	{

	}
	return 0;
}