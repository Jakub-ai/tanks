#include "Opcje.h"
#include "Czolg.h"


void Opcje::inicjalizacja_zmiennych()
{
	this->window = nullptr;
}

const bool Opcje::working() const
{
	return this->window->isOpen();
}

Opcje::Opcje()
{
	this->inicjalizacja_zmiennych();

}

Opcje::~Opcje()
{
	delete this->window;


}

void Opcje::updateEvents()
{
	while (this->window->pollEvent(this->op))
	{
		switch (this->op.type)
		{
		case sf::Event::Closed:
			this->window->close();
			break;
		case sf::Event::KeyPressed:
			if (this->op.key.code == sf::Keyboard::Escape)
				this->window->close();
			break;
		}
	}
}


	void Opcje::updateO()
	{
		this->updateEvents();
	}

void Opcje::rysujO()
{
	this->window->clear();
	this->window->display();
	
}

void Opcje::inicjalizacja_oknaO()
{
	this->window = new sf::RenderWindow(sf::VideoMode(1440, 900), "Opcje", sf::Style::Titlebar | sf::Style::Close);
	this->window->setFramerateLimit(60);
	this->window->setVerticalSyncEnabled(false);
}

void Opcje::zmianaNicku()
{

}
