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
	srand(time(NULL));

	for (int i = 0; i < 125; i++)
	{
		this->x = rand() % 18 + 2;
		this->x *= 50;
		this->y = rand() % 16 + 1;
		this->y *= 50;
		this->spriteP[i].setTexture(this->teksturkaPrzeszkoda);
		this->spriteP[i].setPosition(this->x, this->y);
		std::cout << "X: " << this->spriteP[i].getPosition().x << " Y: " << this->spriteP[i].getPosition().y << std::endl;
		std::cout << "OX: " << this->spriteP[i].getOrigin().x << " OY: " << this->spriteP[i].getOrigin().y << std::endl;

		
	}
}

przeszkody::przeszkody()
{
	this->inicjalizacja_tekstur();
	this->inicjalizacja_sprite();
}

przeszkody::~przeszkody()
{
}

void przeszkody::pos()
{
	
}

void przeszkody::update()
{
}

void przeszkody::rysuj(sf::RenderTarget& target)
{
	for (int i = 0; i < 125; i++)
	{
		target.draw(this->spriteP[i]);
	}
}
