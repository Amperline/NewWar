#include <iostream>
#include <mysql_driver.h>
#include <mysql_connection.h>
#include <cppconn/prepared_statement.h>
#include <cppconn/resultset.h>
#include <SFML/Graphics.hpp>

#include <NewWar/TestF.h>


int main()
{
    
	
	int a = summy(5, 3);
	std::cout << a;

	std::cin.get();
	system("pause");
	return 0;
}