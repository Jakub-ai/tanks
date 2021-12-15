#include "przeszkody.h"
#include <time.h>

using namespace std;

void przeszkody::inicjalizacja_tekstur()
{
	if (!this->teksturkaPrzeszkoda.loadFromFile("Texture/block.png"))
	{
		std::cout << "Blad tekstury vloku! czolg.h" << std::endl;
	}
}

void przeszkody::inicjalizacja_sprite()
{
	this->x = rand() % 16 + 1;
	this->x *= 50;
	this->y = rand() % 13 + 1;
	this->y *= 50;
	this->spritePrzeszkoda.setTexture(this->teksturkaPrzeszkoda);
	this->spritePrzeszkoda.setPosition(this->x, this->y);
	std::cout << "zespawnowana przeszkoda x: " << this->x << "y: " << this->y << std::endl;
	//this->spritePrzeszkoda.setScale(0.5f, 0.5f);
}

przeszkody::przeszkody()
{
	this->inicjalizacja_tekstur();
	this->inicjalizacja_sprite();
}

przeszkody::~przeszkody()
{
}

void przeszkody::update()
{
}

void przeszkody::rysuj(sf::RenderTarget& target)
{
	for (int i = 0; i < 10; i++)
	{
		target.draw(this->spritePrzeszkoda);
		this->x = rand() % 16 + 1;
		this->x *= 50;
		this->y = rand() % 13 + 1;
		this->y *= 50;
		//std::cout << "zespawnowana przeszkoda x: " << this->x << "y: " << this->y << std::endl;
		
	}
	
}
