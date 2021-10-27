#include "game.h"
#include "mainMenu.h"


void game::inicjalizacja_zmiennych()
{
	this->window = nullptr;
}

void game::inicjalizacja_okna()
{
	this->window = new sf::RenderWindow(sf::VideoMode(1440, 900), "Gra Tanki", sf::Style::Titlebar | sf::Style::Close);
}

void game::updateEvents()
{
	
		while (this->window->pollEvent(this->gevent))
		{
			switch (this->gevent.type)
			{
			case sf::Event::Closed:
				this->window->close();
				break;
			case sf::Event::KeyPressed:
				if (this->gevent.key.code == sf::Keyboard::Escape)
					this->window->close();
				break;
			}
		}
}

void game::update()
{
	this->updateEvents();
}

void game::rysuj()
{
	this->window->clear(sf::Color(255, 0, 0, 255));
	this->window->display();
}





game::game()
{
	this->inicjalizacja_zmiennych();
	//this->inicjalizacja_okna();
}

game::~game()
{
	delete this->window;
}

const bool game::running() const
{
	return this->window->isOpen();
}
