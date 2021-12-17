#pragma once
#include "SFML/Graphics.hpp"

class bullet
{
private:
	

	sf::Vector2f direction;
	float MoveSpeed;

public:
	bullet();
	bullet(sf::Texture *textureB, float pos_x, float pos_y, float dir_x, float dir_y, float move_speed);
	virtual ~bullet();

	sf::Sprite spriteB;

	const sf::FloatRect pos() const;
	void update(); 
	void rysuj(sf::RenderTarget& target);
};

