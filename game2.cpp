#include "game2.h"
#include "mainMenu.h"
#include "przeszkody.h"



void game2::inicjalizacja_mapy()
{
	if (!this->map_txt.loadFromFile("Texture/mapka.png"))
	{
		std::cout << "Blad mapki" << std::endl;
	}
	this->map_bg.setTexture(this->map_txt);
}


void game2::inicjalizacja_zmiennych()
{
	this->window = nullptr;
}

void game2::inicjalizacja_gracza1()
{
	this->gracz1 = new Czolg();
	this->oponent = new Oponent();
}
void game2::inicjalizacja_przeszkod()
{
	this->przeszkoda1 = new przeszkody();
}

void game2::inicjalizacja_tekstur()
{
	this->tekstury["BULLET"] = new sf::Texture();
	this->tekstury["BULLET"]->loadFromFile("Texture/bullet.png");
}

void game2::inicjalizacja_okna()
{
	this->window = new sf::RenderWindow(sf::VideoMode(1440, 900), "Gra Tanki", sf::Style::Titlebar | sf::Style::Close);
	this->window->setFramerateLimit(60);
	this->window->setVerticalSyncEnabled(false);
}

void game2::zegarek()
{
	this->czas = this->clock.restart();
	//this->czas = this->clock.getElapsedTime();
	this->zegar.setFont(font);
	this->zegar.setFillColor(sf::Color::Black);
	this->zegar.setString(to_string(this->czas.asSeconds()));
	this->zegar.setPosition(1150, 300);

}

void game2::updateEvents()
{
	this->is_paused = 0;
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
				this->gracz1->rotacja1(1.f);
			if (this->gevent.key.code == sf::Keyboard::A)
				this->gracz1->rotacja1(-1.f);
			if (this->gevent.key.code == sf::Keyboard::P)
			{
				this->is_paused = 1;
				if (this->gevent.key.code == sf::Keyboard::P)
					this->is_paused = 0;
			}
				
			break;
		}
	}

	//ruch czolgu1

	//do przodu
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) && this->gracz1->jaki_kat1() == 0)
	{
		this->gracz1->movement1(0.f, -1.f);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) && this->gracz1->jaki_kat1() == 90)
	{
		this->gracz1->movement1(1.f, 0.f);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) && this->gracz1->jaki_kat1() == 180)
	{
		this->gracz1->movement1(0.f, 1.f);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) && this->gracz1->jaki_kat1() == 270)
	{
		this->gracz1->movement1(-1.f, 0.f);
	}


	//do tylu
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) && this->gracz1->jaki_kat1() == 0)
	{
		this->gracz1->movement1(0.f, 1.f);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) && this->gracz1->jaki_kat1() == 90)
	{
		this->gracz1->movement1(-1.f, 0.f);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) && this->gracz1->jaki_kat1() == 180)
	{
		this->gracz1->movement1(0.f, -1.f);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) && this->gracz1->jaki_kat1() == 270)
	{
		this->gracz1->movement1(1.f, 0.f);
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
	{
		if (this->gracz1->jaki_kat1() == 90 && this->gracz1->canAttack())
		{
			this->bullets.push_back(new bullet(this->tekstury["BULLET"], this->gracz1->pos1().x + 15, this->gracz1->pos1().y - 5, 1.f, 0.f, 5.f));
		}
		if (this->gracz1->jaki_kat1() == 180 && this->gracz1->canAttack())
		{
			this->bullets.push_back(new bullet(this->tekstury["BULLET"], this->gracz1->pos1().x - 5, this->gracz1->pos1().y + 15, 0.f, 1.f, 5.f));
		}
		if (this->gracz1->jaki_kat1() == 270 && this->gracz1->canAttack())
		{
			this->bullets.push_back(new bullet(this->tekstury["BULLET"], this->gracz1->pos1().x - 25, this->gracz1->pos1().y - 5, -1.f, 0.f, 5.f));
		}
		if (this->gracz1->jaki_kat1() == 0 && this->gracz1->canAttack())
		{
			this->bullets.push_back(new bullet(this->tekstury["BULLET"], this->gracz1->pos1().x - 5, this->gracz1->pos1().y - 25, 0.f, -1.f, 5.f));
		}
	}
	

	// ruch oponenta

	/*if (this->oponent->jaki_kat() == 0)
	{
		this->oponent->movement(0, -1.f);
		this->oponent->movement_rs(0, -1.f);
	}
	if (this->oponent->jaki_kat() == 180)
	{
		this->oponent->movement(0, 1.f);
		this->oponent->movement_rs(0, 1.f);
	}*/

	if (this->oponent->pozycja().top < 60.f)
	{
		this->oponent->rotacja(2.f);

	}
	if (this->oponent->pozycja().top > 810.f)
	{
		this->oponent->rotacja(2.f);
	}

	//strzelanie

	for (int i = 0; i < 125; i++)
	{
		if (this->oponent->x_axis.getGlobalBounds().intersects(this->przeszkoda1->spriteP[i].getGlobalBounds()))
		{
			this->oponent->rozmiar_x(this->oponent->pozycja().left - this->przeszkoda1->spriteP[i].getGlobalBounds().left);
			break;
		}
		else if (!this->oponent->x_axis.getGlobalBounds().intersects(this->przeszkoda1->spriteP[i].getGlobalBounds()))
		{
			this->oponent->rozmiar_x(2000);
		}
	}



	if (this->gracz1->pozycja1().intersects(this->oponent->y_axis.getGlobalBounds()) && this->oponent->canAttack() && this->oponent->jaki_kat() == 0)
	{
		this->bullets.push_back(new bullet(this->tekstury["BULLET"], this->oponent->pos().x - 5, this->oponent->pos().y - 25, 0.f, -1.f, 5.f));
	}
	if (this->gracz1->pozycja1().intersects(this->oponent->y_axis.getGlobalBounds()) && this->oponent->canAttack() && this->oponent->jaki_kat() == 180)
	{
		this->bullets.push_back(new bullet(this->tekstury["BULLET"], this->oponent->pos().x - 5, this->oponent->pos().y + 15, 0.f, 1.f, 5.f));
	}
	if (!this->gracz1->pozycja1().intersects(this->oponent->x_axis.getGlobalBounds()))
	{
		if (this->oponent->jaki_kat() == 0)
		{
			this->oponent->movement(0, -1.f);
			this->oponent->movement_rs(0, -1.f);
		}
		if (this->oponent->jaki_kat() == 180)
		{
			this->oponent->movement(0, 1.f);
			this->oponent->movement_rs(0, 1.f);
		}
		if (this->oponent->jaki_kat() == 270)
		{
			if (this->oponent->last_angle == 0)
			{
				this->oponent->rotacja(1.f);
			}
			else
			{
				this->oponent->rotacja(-1.f);
			}
		}

	}
	else 	
	{
			if (this->oponent->jaki_kat() == 270)
			{
				if (this->oponent->canAttack())
				{
					this->bullets.push_back(new bullet(this->tekstury["BULLET"], this->oponent->pos().x - 25, this->oponent->pos().y - 5, -1.f, 0.f, 5.f));
				}
				
			}
			else if (this->oponent->jaki_kat() !=270)
			{
				this->oponent->last_angle = this->oponent->jaki_kat();

				if (this->oponent->last_angle == 0)
				{
					this->oponent->rotacja(-1.f);
					if (this->oponent->canAttack())
					{
						this->bullets.push_back(new bullet(this->tekstury["BULLET"], this->oponent->pos().x - 25, this->oponent->pos().y - 5, -1.f, 0.f, 5.f));
					}
				}
				else if (this->oponent->last_angle == 180)
				{
					this->oponent->rotacja(1.f);
					if (this->oponent->canAttack())
					{
						this->bullets.push_back(new bullet(this->tekstury["BULLET"], this->oponent->pos().x - 25, this->oponent->pos().y - 5, -1.f, 0.f, 5.f));
					}
				}
				
				
			}
			
	}

}

void game2::updateBullets()
{
	for (auto* bullet : this->bullets)
	{
		if (bullet->pos().intersects(this->gracz1->pozycja1()))
			this->window->close();
	}

	unsigned licznik = 0;
	for (auto* bullet : this->bullets)
	{
		bullet->update();
		for (int i = 0; i < 125; i++)
		{
			//std::cout << "X: " << this->gracz2->pos2().x << " Y: " << this->gracz2->pos2().y << std::endl;
			if (bullet->pos().top + bullet->pos().height <= 50.f || bullet->pos().top - bullet->pos().height >= 850.f || bullet->pos().left + bullet->pos().width <= 50.f || bullet->pos().left - bullet->pos().width >= 1050.f || bullet->pos().intersects(this->przeszkoda1->spriteP[i].getGlobalBounds()) || bullet->pos().intersects(this->gracz1->pozycja1()))
			{
				delete this->bullets.at(licznik);
				this->bullets.erase(this->bullets.begin() + licznik);
				--licznik;
				break;
			}
		}
		++licznik;

		std::cout << this->bullets.size() << std::endl;
	}

}


void game2::update()
{
		this->zegarek();
		this->updateEvents();
		this->kolizjeP();
		//this->kolizjeB();
		this->kolizje();
		this->updateBullets();
		this->gracz1->update();
		this->oponent->update();
}

void game2::updateMapy()
{
}

void game2::kolizje()
{
	//lewa strona
	if (this->gracz1->pozycja1().left < 50.f)
	{
		this->gracz1->zmien_pozycje1(63.f, this->gracz1->pozycja1().top + 13);
		std::cout << "granica " << std::endl;

	}
	//prawa strona
	if (this->gracz1->pozycja1().left > 1020.f)
	{
		this->gracz1->zmien_pozycje1(1033.f, this->gracz1->pozycja1().top + 13);
		std::cout << "granica " << std::endl;

	}

	//gora
	if (this->gracz1->pozycja1().top < 50.f)
	{
		this->gracz1->zmien_pozycje1(this->gracz1->pozycja1().left + 13, 63.f);
		std::cout << "granica " << std::endl;

	}

	//dol
	if (this->gracz1->pozycja1().top > 820.f)
	{
		this->gracz1->zmien_pozycje1(this->gracz1->pozycja1().left + 13, 833.f);
		std::cout << "granica " << std::endl;

	}


}
//kolizja z przeszkodami
void game2::kolizjeP()
{
	for (int i = 0; i < 125; i++)
	{
		//od lewej
		if (this->gracz1->pozycja1().intersects(this->przeszkoda1->spriteP[i].getGlobalBounds()) && this->gracz1->jaki_kat1() == 90)
		{
			this->gracz1->zmien_pozycje1(this->gracz1->pozycja1().left + 11, this->gracz1->pozycja1().top + 13);
			std::cout << "kolizja" << std::endl;
		}
		
		//od gory
		if (this->gracz1->pozycja1().intersects(this->przeszkoda1->spriteP[i].getGlobalBounds()) && this->gracz1->jaki_kat1() == 180)
		{
			this->gracz1->zmien_pozycje1(this->gracz1->pozycja1().left + 13, this->gracz1->pozycja1().top + 11);
			std::cout << "kolizja" << std::endl;
		}
		
		//od prawej
		if (this->gracz1->pozycja1().intersects(this->przeszkoda1->spriteP[i].getGlobalBounds()) && this->gracz1->jaki_kat1() == 270)
		{
			this->gracz1->zmien_pozycje1(this->gracz1->pozycja1().left + 15, this->gracz1->pozycja1().top + 13);
			std::cout << "kolizja" << std::endl;
		}
		
		//od dolu
		if (this->gracz1->pozycja1().intersects(this->przeszkoda1->spriteP[i].getGlobalBounds()) && this->gracz1->jaki_kat1() == 0)
		{
			this->gracz1->zmien_pozycje1(this->gracz1->pozycja1().left + 13, this->gracz1->pozycja1().top + 15);
			std::cout << "kolizja" << std::endl;
		}
	
	}

}

void game2::rysowanie_mapki()
{
	this->window->draw(this->map_bg);
}

void game2::rysuj()
{
	this->window->clear(sf::Color::Green);
	this->rysowanie_mapki();
	this->gracz1->rysuj1(*this->window);
	this->oponent->rysuj(*this->window);
	this->przeszkoda1->rysuj(*this->window);
	this->window->draw(this->zegar);
	for (auto* bullet : this->bullets)
	{
		bullet->rysuj(*this->window);
	}
	//std::cout << "Y pos: " << this->gracz1->pozycja().top << std::endl;


	this->window->display();
}


game2::game2()
{
	if (!font.loadFromFile("Fonts/AlexandriaFLF.ttf")) {
		cout << "No Font HERE !!!";
	}

	this->inicjalizacja_mapy();
	this->inicjalizacja_zmiennych();
	this->inicjalizacja_przeszkod();
	this->inicjalizacja_gracza1();
	this->inicjalizacja_tekstur();
	//this->inicjalizacja_okna();
}

game2::~game2()
{
	delete this->window;
	delete this->gracz1;
	delete this->oponent;

	delete this->przeszkoda1;

	for (auto& i : this->tekstury)
	{
		delete i.second;
	}

	for (auto* i : this->bullets)
	{
		delete i;
	}
}

const bool game2::running() const
{
	return this->window->isOpen();
}

