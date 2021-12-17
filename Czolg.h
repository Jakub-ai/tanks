#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <iostream>
#include "przeszkody.h"

class Czolg
{
private:
	sf::Sprite sprite1;
	sf::Texture teksturka1;
	sf::Sprite sprite2;
	sf::Texture teksturka2;

	przeszkody* przeszkoda;

	float MoveSpeed;
	float kat_obrotu;
	float AttackCD;
	float AttackCD_Max;
	std::string Nick;

	void inicjalizacja_tekstur();
	void inicjalizacja_sprite();

public:
	//konstruktor i destruktor
	Czolg();
	virtual ~Czolg();
	
	const sf::FloatRect pozycja1() const;
	const sf::FloatRect pozycja2() const;

	const sf::Vector2f& pos1() const;
	const sf::Vector2f& pos2() const;

	void inicjalizacja_gracza();
	void zmien_pozycje1(const sf::Vector2f position);
	void zmien_pozycje1(const float x, const float y);
	void zmien_pozycje2(const sf::Vector2f position);
	void zmien_pozycje2(const float x, const float y);

	//metody
	void movement1(const float kierX, const float kierY);
	void movement2(const float kierX, const float kierY);
	void rotacja1(const float kat_obrotu);
	void rotacja2(const float kat_obrotu);
	int jaki_kat1();
	int jaki_kat2();

	const bool canAttack();

	void update();
	void updateAttack();
	void rysuj1(sf::RenderTarget& target);
	void rysuj2(sf::RenderTarget& target);
};

