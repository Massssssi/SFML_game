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

	this->window->setFramerateLimit(60);
}


void Game::initEnemies()
{
	this->enemy.setPosition(30.f, 30.f);
	this->enemy.setSize(sf::Vector2f(60.f, 60.f));
	this->enemy.setFillColor(sf::Color::Cyan);
	this->enemy.setOutlineColor(sf::Color::Cyan);
	this->enemy.setOutlineThickness(5.f);

}


//Constructors / Destructors

Game::Game()
{
	this->initVariables();
	this->initWindow();
	this->initEnemies();
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

	std::cout << "Mouse pos x: " << sf::Mouse::getPosition(*this->window).x << "   Mouse pos y: " <<  sf::Mouse::getPosition(*this->window).y<< "\n";
}

void Game::render()
{
	//render old frame and render objects and sidplay window.


	this->window->clear();

	this->window->draw(this->enemy);
	this->window->display();
}
