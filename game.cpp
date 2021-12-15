#include "game.h"
#include "mainMenu.h"



void game::inicjalizacja_mapy()
{
	if (!this->map_txt.loadFromFile("Texture/mapka.png"))
	{
		std::cout << "Blad mapki"<<std::endl;
	}
	this->map_bg.setTexture(this->map_txt);
}

void game::inicjalizacja_zmiennych()
{
	this->window = nullptr;
}

void game::inicjalizacja_gracza1()
{
	this->gracz1 = new Czolg();
	this->gracz2 = new Czolg();
}
void game::inicjalizacja_przeszkod()
{
	this->przeszkoda1 = new przeszkody();
}
/*
void game::rysuj_mapke()
{
	if (!this->mapka.loadFromFile("Texture/mapka.png"))
	{
		std::cout << "Blad tekstury mapy! game.h" << std::endl;
	}

	this->mapka.loadFromFile("Texture/mapka.png");
	this->mapka_bg.setSize(sf::Vector2f(1440, 900));
	this->mapka_bg.setTexture(this->mapka);


}
*/
void game::inicjalizacja_okna()
{
	this->window = new sf::RenderWindow(sf::VideoMode(1440, 900), "Gra Tanki", sf::Style::Titlebar | sf::Style::Close);
	this->window->setFramerateLimit(60);
	this->window->setVerticalSyncEnabled(false);
}

void game::updateEvents()
{
	
		while (this->window->pollEvent(this->gevent))
		{
			switch (this->gevent.type)
			{
			case sf::Event::Closed:
				this->window->close();
				break;
			case sf::Event::KeyPressed:
				if (this->gevent.key.code == sf::Keyboard::Escape)
					this->window->close();
				break;
			case sf::Event::KeyReleased:
				if (this->gevent.key.code == sf::Keyboard::D)
					this->gracz1->rotacja(1.f);
				if (this->gevent.key.code == sf::Keyboard::A)
					this->gracz1->rotacja(-1.f);
				if (this->gevent.key.code == sf::Keyboard::Right)
					this->gracz2->rotacja(1.f);
				if (this->gevent.key.code == sf::Keyboard::Left)
					this->gracz2->rotacja(-1.f);
				break;
			}
		}

		//ruch czolgu1

		//do przodu
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) && this->gracz1->jaki_kat() == 0)
		{
			this->gracz1->movement(0.f, -1.f);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) && this->gracz1->jaki_kat() == 90)
		{
			this->gracz1->movement(1.f, 0.f);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) && this->gracz1->jaki_kat() == 180)
		{
			this->gracz1->movement(0.f, 1.f);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) && this->gracz1->jaki_kat() == 270)
		{
			this->gracz1->movement(-1.f, 0.f);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) && this->gracz1->jaki_kat() == 45)
		{
			this->gracz1->movement(0.75f, -0.75f);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) && this->gracz1->jaki_kat() == 135)
		{
			this->gracz1->movement(0.75f, 0.75f);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) && this->gracz1->jaki_kat() == 225)
		{
			this->gracz1->movement(-0.75f, 0.75f);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) && this->gracz1->jaki_kat() == 315)
		{
			this->gracz1->movement(-0.75f, -0.75f);
		}

		//do tylu
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) && this->gracz1->jaki_kat() == 0)
		{
			this->gracz1->movement(0.f, 1.f);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) && this->gracz1->jaki_kat() == 90)
		{
			this->gracz1->movement(-1.f, 0.f);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) && this->gracz1->jaki_kat() == 180)
		{
			this->gracz1->movement(0.f, -1.f);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) && this->gracz1->jaki_kat() == 270)
		{
			this->gracz1->movement(1.f, 0.f);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) && this->gracz1->jaki_kat() == 45)
		{
			this->gracz1->movement(-0.75f, 0.75f);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) && this->gracz1->jaki_kat() == 135)
		{
			this->gracz1->movement(-0.75f, -0.75f);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) && this->gracz1->jaki_kat() == 225)
		{
			this->gracz1->movement(0.75f, -0.75f);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) && this->gracz1->jaki_kat() == 315)
		{
			this->gracz1->movement(0.75f, 0.75f);
		}

		//ruch czolgu2

		//do przodu
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && this->gracz2->jaki_kat() == 0)
		{
			this->gracz2->movement(0.f, -1.f);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && this->gracz2->jaki_kat() == 90)
		{
			this->gracz2->movement(1.f, 0.f);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && this->gracz2->jaki_kat() == 180)
		{
			this->gracz2->movement(0.f, 1.f);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && this->gracz2->jaki_kat() == 270)
		{
			this->gracz2->movement(-1.f, 0.f);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && this->gracz2->jaki_kat() == 45)
		{
			this->gracz2->movement(0.75f, -0.75f);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && this->gracz2->jaki_kat() == 135)
		{
			this->gracz2->movement(0.75f, 0.75f);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && this->gracz2->jaki_kat() == 225)
		{
			this->gracz2->movement(-0.75f, 0.75f);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && this->gracz2->jaki_kat() == 315)
		{
			this->gracz2->movement(-0.75f, -0.75f);
		}

		//do tylu
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && this->gracz2->jaki_kat() == 0)
		{
			this->gracz2->movement(0.f, 1.f);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && this->gracz2->jaki_kat() == 90)
		{
			this->gracz2->movement(-1.f, 0.f);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && this->gracz2->jaki_kat() == 180)
		{
			this->gracz2->movement(0.f, -1.f);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && this->gracz2->jaki_kat() == 270)
		{
			this->gracz2->movement(1.f, 0.f);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && this->gracz2->jaki_kat() == 45)
		{
			this->gracz2->movement(-0.75f, 0.75f);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && this->gracz2->jaki_kat() == 135)
		{
			this->gracz2->movement(-0.75f, -0.75f);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && this->gracz2->jaki_kat() == 225)
		{
			this->gracz2->movement(0.75f, -0.75f);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && this->gracz2->jaki_kat() == 315)
		{
			this->gracz2->movement(0.75f, 0.75f);
		}
}

void game::update()
{
	this->updateEvents();

	this->kolizje();
}

void game::updateMapy()
{
}

void game::kolizje()
{
	//lewa strona
	if (this->gracz1->pozycja().left < 0.f)
	{
		this->gracz1->zmien_pozycje(38.f, this->gracz1->pozycja().top+38);
		std::cout <<"Y pos: " << this->gracz1->pozycja().top<<std::endl;

	}
	if (this->gracz2->pozycja().left < 0.f)
	{
		this->gracz2->zmien_pozycje(38.f, this->gracz2->pozycja().top + 38);
		std::cout << "Y pos: " << this->gracz2->pozycja().top << std::endl;

	}
	//prawa strona
	if (this->gracz1->pozycja().left-38 > 1160.f)
	{
		this->gracz1->zmien_pozycje(1236.f, this->gracz1->pozycja().top + 37);
		std::cout << "Y pos: " << this->gracz1->pozycja().top << std::endl;

	}
	if (this->gracz2->pozycja().left - 38 > 1160.f)
	{
		this->gracz2->zmien_pozycje(1236.f, this->gracz2->pozycja().top + 37);
		std::cout << "Y pos: " << this->gracz2->pozycja().top << std::endl;

	}
	
	//gora
	if (this->gracz1->pozycja().top - 80 < 0.f)
	{
		this->gracz1->zmien_pozycje(this->gracz1->pozycja().left + 37, 118.f);
		std::cout << "Y pos: " << this->gracz1->pozycja().left << std::endl;

	}
	if (this->gracz2->pozycja().top - 80  < 0.f)
	{
		this->gracz2->zmien_pozycje(this->gracz2->pozycja().left+37, 118.f);
		std::cout << "Y pos: " << this->gracz2->pozycja().left << std::endl;

	}

	//dol
	if (this->gracz1->pozycja().top + 38 > 830.f)
	{
		this->gracz1->zmien_pozycje(this->gracz1->pozycja().left + 38, 830.f);
		std::cout << "Y pos: " << this->gracz1->pozycja().left << std::endl;

	}
	if (this->gracz2->pozycja().top + 38 > 830.f)
	{
		this->gracz2->zmien_pozycje(this->gracz2->pozycja().left + 38, 830.f);
		std::cout << "Y pos: " << this->gracz2->pozycja().left << std::endl;

	}
	//przeszkody
	/*
	if (this->gracz1->pozycja().intersects == true)
	{
		this->gracz1->zmien_pozycje(this->gracz1->pozycja().top, this->gracz1->pozycja().left);
	}
	*/

}

void game::rysowanie_mapki()
{
	this->window->draw(this->map_bg);
}

void game::rysuj()
{
	this->window->clear(sf::Color::Green);
	this->rysowanie_mapki();
	this->gracz1->rysuj(*this->window);
	this->gracz2->rysuj(*this->window);
	//for (int i = 0; i < 10; i++)
	
		this->przeszkoda1->rysuj(*this->window);
	
	
	//std::cout << "Y pos: " << this->gracz1->pozycja().top << std::endl;


	this->window->display();
}


game::game()
{
	this->inicjalizacja_mapy();
	this->inicjalizacja_zmiennych();
	this->inicjalizacja_przeszkod();
	this->inicjalizacja_gracza1();
	//this->inicjalizacja_okna();
}

game::~game()
{
	delete this->window;
	delete this->gracz1;
	delete this->gracz2;
	delete this->przeszkoda1;
}

const bool game::running() const
{
	return this->window->isOpen();
}
