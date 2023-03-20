#include "../include/Game.h"
#include <ctime>


void Game::initVariables()
{
	this->window = nullptr;

	 //game logic
	this->points = 0;
	this->enemySpawnTimer ;
	this->enemySpawnTimerMax = 100.f;
	this->enemySpawnTimer = this->enemySpawnTimerMax;
	this->maxEnemies = 5;
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

void Game::updateMousePositions()
{
	this->mousePosWindow = sf::Mouse::getPosition(*this->window);
}


void Game::spawnEnemy()
{
	//spawn enemya dn set color and positon

	this->enemy.setPosition(
		static_cast<float> (rand() % static_cast<int>(this->window->getSize().x - this->enemy.getSize().x)),
		0.f
	);

	this->enemy.setFillColor(sf::Color::Green);

	//spawn the enemy
	this->enemies.push_back(this->enemy);
}




void Game::updateEnemies() 
{
	if (this->enemies.size() < this->maxEnemies)
	{
		if (this->enemySpawnTimer >= this->enemySpawnTimerMax)
		{
			//spawn the enemy and reset the timer
			this->spawnEnemy();
			this->enemySpawnTimer = 0.f;
		}
		else
		{
			this->enemySpawnTimer += 1.f;
		}
	}

	//Move the enemies
	for (auto& e : this->enemies)
	{
		e.move(0.f, 5.f);
	}
}

void Game::update()
{
	this->pollEvents();
	this->updateMousePositions();
	this->updateEnemies();
}





void Game::renderEnemies()
{
	for (auto& e : this->enemies)
	{
		this->window->draw(e);
	}
}





void Game::render()
{
	//render old frame and render objects and sidplay window.


	this->window->clear();


	this->renderEnemies();
	this->window->display();
}
