#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <iostream>

class przeszkody
{
private:
	

	int x, y, n;

	void inicjalizacja_tekstur();
	void inicjalizacja_sprite();

public:
	przeszkody();
	virtual ~przeszkody();

	sf::Sprite spriteP[125];
	sf::Texture teksturkaPrzeszkoda;

	void pos();
	void update();
	void rysuj(sf::RenderTarget& target);

};

