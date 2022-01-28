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

	//obiekty do klas

	Czolg* gracz1;
	Czolg* gracz2;

	przeszkody* przeszkoda1;

	std::map<std::string, sf::Texture*> tekstury;
	std::vector<bullet*> bullets;
	bullet* pocisk;

	


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

	sf::Text zegar;
	sf::Clock clock;
	sf::Time czas;
	sf::Font font;
	sf::Text tekst0;

	sf::Text tekst1;

	sf::Text tekst2;

	sf::RectangleShape go_window;


	//metody
	void GameOver1();
	void GameOver2();
	void zegarek();
	void updateEvents();
	void update(); 
	void updateBullets();
	void updateMapy();
	void kolizje();
	void kolizjeP();
	void kolizjeB();
	void rysowanie_mapki();
	void rysuj();
	
	void inicjalizacja_okna();
};

