#include "Czolg.h"


//metody private

void Czolg::inicjalizacja_tekstur()
{
	if (!this->teksturka.loadFromFile("Texture/czolg1.png"))
	{
		std::cout << "Blad tekstury czolgu! czolg.h" << std::endl;
	}
	
	
}
void Czolg::inicjalizacja_sprite()
{
	this->sprite.setTexture(this->teksturka);
	//this->sprite.setScale(0.25f, 0.25f);
	this->sprite.setPosition(300.f, 300.f);
	this->sprite.setOrigin(37.f, 38.f);
}

//konstrukor i destruktor
Czolg::Czolg()
{
	this->MoveSpeed = 2.f;
	this->kat_obrotu = 45.f;

	this->inicjalizacja_tekstur();
	this->inicjalizacja_sprite();
}

Czolg::~Czolg()
{

}
const sf::FloatRect Czolg::pozycja() const
{
	return this->sprite.getGlobalBounds();
}
/*
const sf::FloatRect Czolg::czyDotyka() const
{
	if (this->sprite.getGlobalBounds().intersects(this->spritePrzeszkoda) == true)
		return true;
}
*/
void Czolg::zmien_pozycje(const sf::Vector2f position)
{
	this->sprite.setPosition(position);
}

void Czolg::zmien_pozycje(const float x, const float y)
{
	this->sprite.setPosition(x, y);
}

//metody public 
void Czolg::movement(const float kierX, const float kierY)
{
	this->sprite.move(this->MoveSpeed * kierX, this->MoveSpeed * kierY);
}

void Czolg::rotacja(const float kierunek)
{
	this->sprite.rotate(this->kat_obrotu*kierunek);
	//std::cout << this->sprite.getRotation() << std::endl;
}

int Czolg::jaki_kat()
{
	return this->sprite.getRotation();
}
/*
void Czolg::kolizja()
{ 
	sf::FloatRect pozycja = this->sprite.getGlobalBounds();
	//lewa strona
	if (pozycja.left <= 0.f)
		this->sprite.setPosition(0.f, pozycja.top);
	//prawa strona
	if (pozycja.left + pozycja.width >= 1440.f)
		this->sprite.setPosition(1440.f - pozycja.width, pozycja.top);

	//gora
	if (pozycja.top <= 0.f)
		this->sprite.setPosition(pozycja.left, 0.f);
	//dol
	if (pozycja.left + pozycja.width >= 900.f)
		this->sprite.setPosition(pozycja.left, 900.f - pozycja.height);
}
*/
void Czolg::update()
{
	//this->kolizja();
}

void Czolg::rysuj(sf::RenderTarget& target)
{
	target.draw(this->sprite);
}
