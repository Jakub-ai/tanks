#include "Opcje.h"
#include "Czolg.h"
#include "mainMenu.h"
#include <SFML/Graphics.hpp>

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
	/*this->inicjalizacja_zmiennych();
	if (!font.loadFromFile("Fonts/AlexandriaFLF.ttf")) {
		cout << "No Font HERE !!!";
	}
	opcje[0].setFont(font);
	opcje[0].setFillColor(Color::White);
	opcje[0].setString("Sound");
	opcje[0].setCharacterSize(70);
	opcje[0].setPosition(400, 200);*/
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

