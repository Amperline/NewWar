#include "ConnectorGuard.h"

void ConnectorGuard(std::list<ClientCon>& connections, std::ostream& cout)
{
	sf::TcpListener listner;
    
    sql::mysql::MySQL_Driver* driver;
    sql::Connection* con{};
    sql::PreparedStatement* stmt{};
    sql::ResultSet* res{};
    driver = sql::mysql::get_mysql_driver_instance();
    con = driver->connect("127.0.0.1:3306", "root", "");
	
	if (listner.listen(4097) != sf::Socket::Done)
	{
		std::cerr << "Error in socket binding!";
	}

    while (listner.getLocalPort() != 0)
    {
        sf::TcpSocket* client = new sf::TcpSocket;
        if (listner.accept(*client) != sf::Socket::Done)
        {
            std::cerr << "Error in accept client!";
        }
        else
        {
            std::cout << "Client connected!\n";
        }
        client->setBlocking(1);
        sf::Packet packet;
        try
        {
            client->receive(packet);

            try {
                ConnectorPacket packetData;
                packet >> packetData.LorC >> packetData.Name >> packetData.Password;
                if (!con->isValid())
                {
                    throw sql::SQLException("Fail to connect (SQL)!");
                }
                if (packetData.LorC == 1)
                {
                    stmt = con->prepareStatement("SELECT nickname FROM newwar.users WHERE nickname = ?");
                    stmt->setString(1, packetData.Name);
                    res = stmt->executeQuery();
                    if (res->next())
                    {
                        if (!res->getString("nickname").asStdString().empty())
                        {
                            stmt = con->prepareStatement("SELECT * FROM newwar.users WHERE nickname = ?");
                            stmt->setString(1, packetData.Name);
                            res = stmt->executeQuery();
                            if (res->next()) {
                                if (res->getString("mpassword").asStdString() == packetData.Password)
                                {
                                    sf::Packet p;
                                    bool succ = 1;
                                    std::string str("");
                                    p << succ << str;
                                    client->send(p);
                                    connections.push_back(ClientCon(client, packetData.Name, res->getString("id")));
                                }
                            }
                            else
                            {
                                sf::Packet p;
                                bool succ = 0;
                                std::string str("Error passward!");
                                p << succ << str;
                                client->send(p);
                                client->disconnect();
                            }
                        }
                    }
                    else
                    {
                        sf::Packet p;
                        bool succ = 0;
                        std::string str("Not found!");
                        p << succ << str;
                        client->send(p);
                        client->disconnect();
                    }
                }
                else if (packetData.LorC == 0)
                {
                    stmt = con->prepareStatement("SELECT nickname FROM newwar.users WHERE nickname = ?");
                    stmt->setString(1, packetData.Name);
                    res = stmt->executeQuery();
                    if (res->next())
                    {
                        if (!res->getString("nickname").asStdString().empty())
                        {
                            sf::Packet p;
                            bool succ = 0;
                            std::string str = "Occupied name!";
                            p << succ << str;
                            client->send(p);
                        }
                    }
                    else
                    {
                        stmt = con->prepareStatement("INSERT INTO newwar.users (nickname, mpassword, ip) VALUES (?, ?, ?)");
                        stmt->setString(1, packetData.Name);
                        stmt->setString(2, packetData.Password);
                        stmt->setString(3, client->getRemoteAddress().toString());
                        res = stmt->executeQuery();
                        if (res)
                        {
                            sf::Packet p;
                            bool succ = 1;
                            std::string str("");
                            p << succ << str;
                            client->send(p);
                            client->disconnect();
                        }
                    }


                }
            }
            catch (sql::SQLException& e) {
                cout << "SQLException: " << e.what() << std::endl;
            }


        }
        catch (const std::exception& e)
        {
            cout << "Error: " << e.what();
            cout << std::endl;
        }
    }
}

