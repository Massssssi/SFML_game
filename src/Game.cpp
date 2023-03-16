#include "../include/Game.h"


void Game::initVariables()
{
	this->window = nullptr;
}

void Game::initWindow()
{
	this->videoMode.height = 600;
	this->videoMode.width = 800;
	this ->window =  new sf::RenderWindow(this->videoMode, "Game 1", sf::Style::Titlebar | sf::Style::Close);
} 

//Constructors / Destructors

Game::Game()
{
	this->initVariables();
	this->initWindow();
}

Game::~Game()
{

}

const bool Game::running() const
{
	return true;
}

const bool Game::getEndGame() const
{
	return false;
}

void Game::pollEvents()
{

	//event polling
	while (this->window->pollEvent(this->ev))
	{
		switch (this->ev.type)
		{
		case sf::Event::Closed:
			break;
		case sf::Event::KeyPressed:

			if (ev.key.code == sf::Keyboard::Escape)
			{
				window->close();
				break;
			}
		}
	}

}

void Game::update()
{
	this->pollEvents();
}

void Game::render()
{
	//render old frame and render objects and sidplay window.


	this->window->clear(sf::Color(255, 0, 0));
	this->window->display();
}
