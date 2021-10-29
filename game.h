#pragma once
#include "Czolg.h"

class game
{
private:
	sf::RenderWindow* window;
	sf::Event gevent;

	Czolg* gracz1;

	void inicjalizacja_zmiennych();
	void inicjalizacja_gracza1();


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

