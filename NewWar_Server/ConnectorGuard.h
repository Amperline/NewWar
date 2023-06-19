#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Network.hpp>
#include <list>
#include <iostream>

void ConnectorGuard(std::list<sf::UdpSocket> connections);