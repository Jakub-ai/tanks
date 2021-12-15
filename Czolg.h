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
	std::string Nick;

	void inicjalizacja_tekstur();
	void inicjalizacja_sprite();

public:
	//konstruktor i destruktor
	Czolg();
	virtual ~Czolg();

	const sf::FloatRect pozycja() const;
	const sf::FloatRect czyDotyka() const;

	void zmien_pozycje(const sf::Vector2f position);
	void zmien_pozycje(const float x, const float y);

	//metody
	void movement(const float kierX, const float kierY);
	void rotacja(const float kat_obrotu);
	int jaki_kat();
	void kolizja();
	void update();
	void rysuj(sf::RenderTarget& target);
};

