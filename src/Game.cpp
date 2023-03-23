#include "../include/Game.h"
#include <ctime>


void Game::initVariables()
{
	this->window = nullptr;

	 //game logic
	this->points = 0;
	this->health = 10;
	this->endGame = false;
	this->enemySpawnTimer ;
	this->enemySpawnTimerMax = 10.f;
	this->enemySpawnTimer = this->enemySpawnTimerMax;
	this->maxEnemies = 5;
	this->mouseHeld = false;
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
	this->mousePosView = this->window->mapPixelToCoords(this->mousePosWindow);
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
	for (int i = 0; i < this->enemies.size(); i++)
	{
		this->enemies[i].move(0.f, 5.f);
		bool deleted = false;

		if (enemies[i].getPosition().y > this->window->getSize().y)
		{
			this->enemies.erase(this->enemies.begin() + i);
			this->health -= 1;
			std::cout << " health " << this->health << "\n";
		}
	}


	//check if clicked
	if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
	{
		if (this->mouseHeld == false)
		{
			this->mouseHeld = true;
			bool deleted = false;
			for (size_t i = 0; i < this->enemies.size() && deleted == false; i++)
			{
				if (enemies[i].getGlobalBounds().contains(this->mousePosView))
				{
					deleted = true;
					this->enemies.erase(this->enemies.begin() + i);
					this->points += 10;
					std::cout << " points " << this->health << "\n";
				}
			}
		}
	}
	else
	{
		this->mouseHeld = false;
	}

}

void Game::update()
{
	this->pollEvents();

	if (this -> endGame == false)
	{
		this->updateMousePositions();
		this->updateEnemies();
	}

	if (this->health <= 0)
	{
		this->endGame = true;
	}
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
