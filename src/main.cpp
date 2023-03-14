#include <iostream>

#include<SFML/Graphics.hpp>
#include<SFML/System.hpp>
#include<SFML/Window.hpp>
#include<SFML/Audio.hpp>
#include<SFML/Network.hpp>



int main()
{

	sf::RenderWindow window(sf::VideoMode(640, 480), "game 1", sf::Style::Titlebar | sf::Style::Close);
	sf::Event ev{};

	//main game loop
	while (window.isOpen())
	{
		// Event polling
		while (window.pollEvent(ev))
		{
			switch (ev.type)
			{
				case sf::Event::Closed:
					window.close();
					break;
				case sf::Event::KeyPressed:
					if (ev.key.code == sf::Keyboard::Escape)
						window.close();
					break;
			}
		}
		//update


		//Render
		window.clear(sf::Color::White); // clear old frame

		//drawing the game
		window.display(); // window is done drawing

	}

}