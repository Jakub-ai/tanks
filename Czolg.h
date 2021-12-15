#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <iostream>

class Czolg
{
private:
	sf::Sprite sprite1;
	sf::Texture teksturka1;
	sf::Sprite sprite2;
	sf::Texture teksturka2;
	

	float MoveSpeed;
	float kat_obrotu;
	std::string Nick;

	void inicjalizacja_tekstur();
	void inicjalizacja_sprite();

public:
	//konstruktor i destruktor
	Czolg();
	virtual ~Czolg();

	const sf::FloatRect pozycja1() const;
	const sf::FloatRect pozycja2() const;
	const sf::FloatRect czyDotyka() const;

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
	void kolizja();
	void update();
	void rysuj1(sf::RenderTarget& target);
	void rysuj2(sf::RenderTarget& target);
};

