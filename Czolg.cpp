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
	this->sprite1.setOrigin(13.f, 13.f);
	this->sprite1.setRotation(180.f);

	this->sprite2.setTexture(this->teksturka2);
	this->sprite2.setPosition(1020.f, 700.f);
	this->sprite2.setOrigin(13.f, 13.f);
}

//konstrukor i destruktor
Czolg::Czolg()
{
	this->inicjalizacja_gracza();
	this->inicjalizacja_tekstur();
	this->inicjalizacja_sprite();
}

Czolg::~Czolg()
{

}
//zwraca pozycje boku/gory/dolu no granicy czolgu
const sf::FloatRect Czolg::pozycja1() const
{
	return this->sprite1.getGlobalBounds();
}
const sf::FloatRect Czolg::pozycja2() const
{
	return this->sprite2.getGlobalBounds();
}
//zwraca pozycje x/y czolgu
const sf::Vector2f& Czolg::pos1() const
{
	return this->sprite1.getPosition();
}

const sf::Vector2f& Czolg::pos2() const
{
	return this->sprite2.getPosition();
}

void Czolg::inicjalizacja_gracza()
{
	this->MoveSpeed = 2.f;
	this->kat_obrotu = 90.f;
	this->AttackCD_Max = 50.f;
	this->AttackCD = this->AttackCD_Max;
}

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
//cooldown sprzelania
const bool Czolg::canAttack()
{
	if (this->AttackCD >= this->AttackCD_Max)
	{
		this->AttackCD = 0.f;
		return true;
	}
		
	return false;
}


void Czolg::update()
{
	this->updateAttack();
}
//rowniez cooldown strzelania
void Czolg::updateAttack()
{
	if(this->AttackCD<this->AttackCD_Max)
		this->AttackCD += 0.25f;

}

void Czolg::rysuj1(sf::RenderTarget& target)
{
	target.draw(this->sprite1);
}
void Czolg::rysuj2(sf::RenderTarget& target)
{
	target.draw(this->sprite2);
}
