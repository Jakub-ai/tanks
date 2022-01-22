#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <iostream>
#include "przeszkody.h"
class Oponent
{
private:
	sf::Sprite sprite;
	sf::Texture teksturka;


	przeszkody* przeszkoda;

	float AttackCD;
	float AttackCD_Max;
	float MoveSpeed;
	float kat_obrotu;


	void inicjalizacja_tekstur_oponenta();
	void inicjalizacja_sprite_oponenta();

public:
	Oponent();
	virtual ~Oponent();

	const sf::FloatRect pozycja() const;
	const sf::Vector2f& pos() const;

	sf::RectangleShape x_axis;
	sf::RectangleShape y_axis;
	float last_angle;

	void inicjalizacja_oponenta();
	void inicjalizacja_rs();
	void rozmiar_x(const float x_width);
	void zmien_pozycje(const sf::Vector2f position);
	void zmien_pozycje(const float x, const float y);


	//metody
	void movement(const float kierX, const float kierY);
	void movement_rs(const float kierX, const float kierY);
	void rotacja(const float kat_obrotu);
	int jaki_kat();

	const bool canAttack();

	void update();
	void updateAttack();
	void rysuj(sf::RenderTarget& target);
};

