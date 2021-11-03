#pragma once
#include "Czolg.h"

class game
{
private:
	sf::RenderWindow* window;
	sf::Event gevent;
	

	//mapa
	sf::Sprite map_bg;
	sf::Texture map_txt;


	Czolg* gracz1;
	Czolg* gracz2;


	void inicjalizacja_mapy();
	void inicjalizacja_zmiennych();
	void inicjalizacja_gracza1();
	void rysuj_mapke();


public:
	//konstruktor / dekonstruktor
	game();
	virtual ~game();

	//inne
	const bool running() const;

	//metody
	void updateEvents();
	void update(); 
	void updateMapy();
	void kolizje();
	void rysowanie_mapki();
	void rysuj();
	
	void inicjalizacja_okna();
};

