#pragma once
#include "Czolg.h"
#include "przeszkody.h"
#include "bullet.h"
#include <map>

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

	przeszkody* przeszkoda1;

	std::map<std::string, sf::Texture*> tekstury;
	std::vector<bullet*> bullets;


	void inicjalizacja_mapy();
	void inicjalizacja_zmiennych();
	void inicjalizacja_gracza1();
	void inicjalizacja_przeszkod();
	void inicjalizacja_tekstur();
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
	void updateBullets();
	void updateMapy();
	void kolizje();
	void kolizjeP();
	void rysowanie_mapki();
	void rysuj();
	
	void inicjalizacja_okna();
};

