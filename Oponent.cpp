#include "Oponent.h"

void Oponent::inicjalizacja_tekstur_oponenta()
{
	if (!this->teksturka.loadFromFile("Texture/czolg1.png"))
	{
		std::cout << "Blad tekstury oponenta! oponent.h" << std::endl;
	}
}

void Oponent::inicjalizacja_sprite_oponenta()
{
	this->sprite.setTexture(this->teksturka);
	this->sprite.setPosition(1020.f, 700.f);
	this->sprite.setOrigin(13.f, 13.f);

}

Oponent::Oponent()
{
	this->inicjalizacja_oponenta();
	this->inicjalizacja_tekstur_oponenta();
	this->inicjalizacja_sprite_oponenta();
	this->inicjalizacja_rs();
}

Oponent::~Oponent()
{
	
}

const sf::FloatRect Oponent::pozycja() const
{
	return this->sprite.getGlobalBounds();
}

const sf::Vector2f& Oponent::pos() const
{
	return this->sprite.getPosition();
}

void Oponent::inicjalizacja_oponenta()
{
	this->MoveSpeed = 2.f;
	this->kat_obrotu = 90.f;
	this->AttackCD_Max = 50.f;
	this->AttackCD = this->AttackCD_Max;
	this->last_angle = 0;
}

void Oponent::inicjalizacja_rs()
{
	this->x_axis.setSize(sf::Vector2f(1600,2));
	this->x_axis.setPosition(this->sprite.getPosition().x, this->sprite.getPosition().y);
	this->x_axis.setFillColor(sf::Color(0,0,255,100));
	this->x_axis.setOrigin(sf::Vector2f(800,1));

	this->y_axis.setSize(sf::Vector2f(2,800));
	this->y_axis.setPosition(this->sprite.getPosition().x, this->sprite.getPosition().y);
	this->y_axis.setFillColor(sf::Color(0,0,255,100));
	this->y_axis.setOrigin(sf::Vector2f(1, 400));
}

void Oponent::zmien_pozycje(const sf::Vector2f position)
{
	this->sprite.setPosition(position);
}

void Oponent::zmien_pozycje(const float x, const float y)
{
	this->sprite.setPosition(x, y);
}

void Oponent::movement(const float kierX, const float kierY)
{
	this->sprite.move(this->MoveSpeed * kierX, this->MoveSpeed * kierY);
}

void Oponent::movement_rs(const float kierX, const float kierY)
{
	this->x_axis.move(this->MoveSpeed * kierX, this->MoveSpeed * kierY);
	this->y_axis.move(this->MoveSpeed * kierX, this->MoveSpeed * kierY);
}


void Oponent::rotacja(const float kierunek)
{
	this->sprite.rotate(this->kat_obrotu * kierunek);
}

int Oponent::jaki_kat()
{
	return this->sprite.getRotation();
}

const bool Oponent::canAttack()
{
	if (this->AttackCD >= this->AttackCD_Max)
	{
		this->AttackCD = 0.f;
		return true;
	}

	return false;
}

void Oponent::update()
{
	this->updateAttack();
}

void Oponent::updateAttack()
{
	if (this->AttackCD < this->AttackCD_Max)
		this->AttackCD += 0.25f;
}

void Oponent::rysuj(sf::RenderTarget& target)
{
	target.draw(this->sprite);
	target.draw(this->x_axis);
	target.draw(this->y_axis);
}
