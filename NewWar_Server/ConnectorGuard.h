#pragma once
#include <NewWar/NewWarLib.h>
#include <SFML/Network.hpp>
#include <list>
#include <iostream>
#include <mysql_driver.h>
#include <mysql_connection.h>
#include <cppconn/prepared_statement.h>
#include <cppconn/resultset.h>

void ConnectorGuard(std::list<ClientCon>& connections, std::ostream& cout);