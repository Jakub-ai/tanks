#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <iostream>

class przeszkody
{
private:
	sf::Sprite spritePrzeszkoda;
	sf::Texture teksturkaPrzeszkoda;

	int x, y;

	void inicjalizacja_tekstur();
	void inicjalizacja_sprite();

public:
	przeszkody();
	virtual ~przeszkody();

	void update();
	void rysuj(sf::RenderTarget& target);

};

