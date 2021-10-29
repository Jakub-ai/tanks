#include "game.h"
#include "mainMenu.h"


void game::inicjalizacja_zmiennych()
{
	this->window = nullptr;
}

void game::inicjalizacja_gracza1()
{
	this->gracz1 = new Czolg();
	this->gracz2 = new Czolg();
}

void game::inicjalizacja_okna()
{
	this->window = new sf::RenderWindow(sf::VideoMode(1440, 900), "Gra Tanki", sf::Style::Titlebar | sf::Style::Close);
	this->window->setFramerateLimit(60);
	this->window->setVerticalSyncEnabled(false);
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
			case sf::Event::KeyReleased:
				if (this->gevent.key.code == sf::Keyboard::D)
					this->gracz1->rotacja(1.f);
				if (this->gevent.key.code == sf::Keyboard::A)
					this->gracz1->rotacja(-1.f);
				if (this->gevent.key.code == sf::Keyboard::Right)
					this->gracz2->rotacja(1.f);
				if (this->gevent.key.code == sf::Keyboard::Left)
					this->gracz2->rotacja(-1.f);
				break;
			}
		}

		//ruch czolgu1

		//do przodu
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) && this->gracz1->jaki_kat() == 0)
		{
			this->gracz1->movement(0.f, -1.f);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) && this->gracz1->jaki_kat() == 90)
		{
			this->gracz1->movement(1.f, 0.f);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) && this->gracz1->jaki_kat() == 180)
		{
			this->gracz1->movement(0.f, 1.f);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) && this->gracz1->jaki_kat() == 270)
		{
			this->gracz1->movement(-1.f, 0.f);
		}

		//do tylu
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) && this->gracz1->jaki_kat() == 0)
		{
			this->gracz1->movement(0.f, 1.f);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) && this->gracz1->jaki_kat() == 90)
		{
			this->gracz1->movement(-1.f, 0.f);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) && this->gracz1->jaki_kat() == 180)
		{
			this->gracz1->movement(0.f, -1.f);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) && this->gracz1->jaki_kat() == 270)
		{
			this->gracz1->movement(1.f, 0.f);
		}

		//ruch czolgu2

		//do przodu
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && this->gracz2->jaki_kat() == 0)
		{
			this->gracz2->movement(0.f, -1.f);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && this->gracz2->jaki_kat() == 90)
		{
			this->gracz2->movement(1.f, 0.f);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && this->gracz2->jaki_kat() == 180)
		{
			this->gracz2->movement(0.f, 1.f);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && this->gracz2->jaki_kat() == 270)
		{
			this->gracz2->movement(-1.f, 0.f);
		}

		//do tylu
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && this->gracz2->jaki_kat() == 0)
		{
			this->gracz2->movement(0.f, 1.f);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && this->gracz2->jaki_kat() == 90)
		{
			this->gracz2->movement(-1.f, 0.f);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && this->gracz2->jaki_kat() == 180)
		{
			this->gracz2->movement(0.f, -1.f);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && this->gracz2->jaki_kat() == 270)
		{
			this->gracz2->movement(1.f, 0.f);
		}
}

void game::update()
{
	this->updateEvents();
}

void game::rysuj()
{
	this->window->clear();
	this->gracz1->rysuj(*this->window);
	this->gracz2->rysuj(*this->window);


	this->window->display();
}





game::game()
{
	this->inicjalizacja_zmiennych();
	this->inicjalizacja_gracza1();
	//this->inicjalizacja_okna();
}

game::~game()
{
	delete this->window;
	delete this->gracz1;
}

const bool game::running() const
{
	return this->window->isOpen();
}
