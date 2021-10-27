#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
class game
{
private:
	sf::RenderWindow* window;
	sf::Event gevent;

	void inicjalizacja_zmiennych();
	


public:
	//konstruktor / dekonstruktor
	game();
	virtual ~game();

	//inne
	const bool running() const;

	//metody
	void updateEvents();
	void update();
	void rysuj();
	void inicjalizacja_okna();
};

