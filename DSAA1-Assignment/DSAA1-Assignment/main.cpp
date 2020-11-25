//@BridgetACasey

#include <SFML/Graphics.hpp>

int main()
{
	sf::RenderWindow window(sf::VideoMode(1600, 900), "Data Structures and Algorithms 1", sf::Style::Titlebar | sf::Style::Close);

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
	}

	return 0;
}