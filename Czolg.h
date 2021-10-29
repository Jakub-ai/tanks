#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <iostream>

class Czolg
{
private:
	sf::Sprite sprite;
	sf::Texture teksturka;

	float MoveSpeed;
	float kat_obrotu;

	void inicjalizacja_tekstur();
	void inicjalizacja_sprite();
public:
	//konstruktor i destruktor
	Czolg();
	virtual ~Czolg();

	//metody
	void movement(const float kierX, const float kierY);
	void rotacja(const float kat_obrotu);
	int jaki_kat();
	void update();
	void rysuj(sf::RenderTarget& target);
};

