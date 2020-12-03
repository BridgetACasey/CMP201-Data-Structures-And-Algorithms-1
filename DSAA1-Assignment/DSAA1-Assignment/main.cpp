//@BridgetACasey

#include <SFML/Graphics.hpp>

#include "Lee.h"

int main()
{
	srand((unsigned)time(0));

	Lee lee;

	lee.initGrid();

	lee.floodGrid();
	lee.displayGrid();

	lee.tracePath();
	lee.printPathCoords();

	lee.setPathOnGrid();
	lee.displayGrid();

	/*sf::RenderWindow window(sf::VideoMode(1600, 900), "Data Structures and Algorithms 1", sf::Style::Titlebar | sf::Style::Close);

	sf::Event event;

	while (window.isOpen())
	{
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				window.close();
			}
		}
	}*/

	return 0;
}