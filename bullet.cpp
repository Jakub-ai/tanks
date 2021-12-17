#include "bullet.h"
#include <iostream>



bullet::bullet()
{
}

bullet::bullet(sf::Texture *textureB, float pos_x, float pos_y, float dir_x, float dir_y, float move_speed)
{
	this->spriteB.setTexture(*textureB);
	this->spriteB.setPosition(pos_x, pos_y);
	this->direction.x = dir_x;
	this->direction.y = dir_y;
	this->MoveSpeed = move_speed;
}

bullet::~bullet()
{
}

const sf::FloatRect bullet::pos() const
{
	return this->spriteB.getGlobalBounds();
}

void bullet::update()
{
	this->spriteB.move(this->MoveSpeed * this->direction);
}

void bullet::rysuj(sf::RenderTarget& target)
{
	target.draw(this->spriteB);
}
