#include "Czolg.h"


//metody private

void Czolg::inicjalizacja_tekstur()
{
	if (!this->teksturka1.loadFromFile("Texture/czolg1.png"))
	{
		std::cout << "Blad tekstury czolgu! czolg.h" << std::endl;
	}
	if (!this->teksturka2.loadFromFile("Texture/czolg1.png"))
	{
		std::cout << "Blad tekstury czolgu! czolg.h" << std::endl;
	}
	
	
}
void Czolg::inicjalizacja_sprite()
{
	this->sprite1.setTexture(this->teksturka1);
	this->sprite1.setPosition(70.f, 150.f);
	this->sprite1.setOrigin(37.f, 38.f);

	this->sprite2.setTexture(this->teksturka2);
	this->sprite2.setPosition(1030.f, 750.f);
	this->sprite2.setOrigin(37.f, 38.f);
}

//konstrukor i destruktor
Czolg::Czolg()
{
	this->MoveSpeed = 2.f;
	this->kat_obrotu = 90.f;

	this->inicjalizacja_tekstur();
	this->inicjalizacja_sprite();
}

Czolg::~Czolg()
{

}
const sf::FloatRect Czolg::pozycja1() const
{
	return this->sprite1.getGlobalBounds();
}
const sf::FloatRect Czolg::pozycja2() const
{
	return this->sprite2.getGlobalBounds();
}
/*
const sf::FloatRect Czolg::czyDotyka() const
{
	if (this->sprite.getGlobalBounds().intersects(this->spritePrzeszkoda) == true)
		return true;
}
*/
void Czolg::zmien_pozycje1(const sf::Vector2f position)
{
	this->sprite1.setPosition(position);
}
void Czolg::zmien_pozycje2(const sf::Vector2f position)
{
	this->sprite2.setPosition(position);
}

void Czolg::zmien_pozycje1(const float x, const float y)
{
	this->sprite1.setPosition(x, y);
}
void Czolg::zmien_pozycje2(const float x, const float y)
{
	this->sprite2.setPosition(x, y);
}

//metody public 
void Czolg::movement1(const float kierX, const float kierY)
{
	this->sprite1.move(this->MoveSpeed * kierX, this->MoveSpeed * kierY);
}
void Czolg::movement2(const float kierX, const float kierY)
{
	this->sprite2.move(this->MoveSpeed * kierX, this->MoveSpeed * kierY);
}

void Czolg::rotacja1(const float kierunek)
{
	this->sprite1.rotate(this->kat_obrotu*kierunek);
	//std::cout << this->sprite.getRotation() << std::endl;
}
void Czolg::rotacja2(const float kierunek)
{
	this->sprite2.rotate(this->kat_obrotu * kierunek);
	//std::cout << this->sprite.getRotation() << std::endl;
}

int Czolg::jaki_kat1()
{
	return this->sprite1.getRotation();
}
int Czolg::jaki_kat2()
{
	return this->sprite2.getRotation();
}

void Czolg::update()
{
}

void Czolg::rysuj1(sf::RenderTarget& target)
{
	target.draw(this->sprite1);
}
void Czolg::rysuj2(sf::RenderTarget& target)
{
	target.draw(this->sprite2);
}
