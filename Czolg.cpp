#include "Czolg.h"


//metody private

void Czolg::inicjalizacja_tekstur()
{
	if (!this->teksturka.loadFromFile("Texture/czolg1.png"))
	{
		std::cout << "Blad tekstury czolgu! czolg1.h" << std::endl;
	}
	
}
void Czolg::inicjalizacja_sprite()
{
	this->sprite.setTexture(this->teksturka);
	this->sprite.setScale(0.25f, 0.25f);
	this->sprite.setPosition(100.f, 100.f);
	this->sprite.setOrigin(100.f, 100.f);
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

//metody public 
void Czolg::movement(const float kierX, const float kierY)
{
	this->sprite.move(this->MoveSpeed * kierX, this->MoveSpeed * kierY);
}

void Czolg::rotacja(const float kierunek)
{
	this->sprite.rotate(this->kat_obrotu*kierunek);
	std::cout << this->sprite.getRotation() << std::endl;
}

int Czolg::jaki_kat()
{
	return this->sprite.getRotation();
}

void Czolg::update()
{
}

void Czolg::rysuj(sf::RenderTarget& target)
{
	target.draw(this->sprite);
}
