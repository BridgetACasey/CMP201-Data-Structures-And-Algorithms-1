//@BridgetACasey

#include <SFML/Graphics.hpp>

#include "Grid.h"

#include "Lee.h"

int main()
{
	srand((unsigned)time(0));

	Grid grid;

	Lee lee;

	lee.setGrid(&grid);

	grid.populate();

	lee.flood();
	grid.render();
	lee.trace();

	lee.setPathOnGrid();
	lee.printPathCoords();

	grid.render();

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