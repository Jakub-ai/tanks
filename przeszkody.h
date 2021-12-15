#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <iostream>

class przeszkody
{
private:
	sf::Sprite spriteP[125];
	//sf::Sprite spritePrzeszkoda;
	sf::Texture teksturkaPrzeszkoda;

	//sf::VertexArray przeszkody(sf::Quads,5)

	int x, y, n;

	void inicjalizacja_tekstur();
	void inicjalizacja_sprite();

public:
	przeszkody();
	virtual ~przeszkody();

	void update();
	void rysuj(sf::RenderTarget& target);

};

