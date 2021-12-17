#include "game.h"
#include "mainMenu.h"
#include "przeszkody.h"



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

void game::inicjalizacja_tekstur()
{
	this->tekstury["BULLET"] = new sf::Texture();
	this->tekstury["BULLET"]->loadFromFile("Texture/bullet.png");
}

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
				this->gracz1->rotacja1(1.f);
			if (this->gevent.key.code == sf::Keyboard::A)
				this->gracz1->rotacja1(-1.f);
			if (this->gevent.key.code == sf::Keyboard::Right)
				this->gracz2->rotacja2(1.f);
			if (this->gevent.key.code == sf::Keyboard::Left)
				this->gracz2->rotacja2(-1.f);
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


	//ruch czolgu2

	//do przodu
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && this->gracz2->jaki_kat2() == 0)
	{
		this->gracz2->movement2(0.f, -1.f);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && this->gracz2->jaki_kat2() == 90)
	{
		this->gracz2->movement2(1.f, 0.f);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && this->gracz2->jaki_kat2() == 180)
	{
		this->gracz2->movement2(0.f, 1.f);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && this->gracz2->jaki_kat2() == 270)
	{
		this->gracz2->movement2(-1.f, 0.f);
	}

	//do tylu
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && this->gracz2->jaki_kat2() == 0)
	{
		this->gracz2->movement2(0.f, 1.f);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && this->gracz2->jaki_kat2() == 90)
	{
		this->gracz2->movement2(-1.f, 0.f);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && this->gracz2->jaki_kat2() == 180)
	{
		this->gracz2->movement2(0.f, -1.f);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && this->gracz2->jaki_kat2() == 270)
	{
		this->gracz2->movement2(1.f, 0.f);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
	{
		if (this->gracz1->jaki_kat1() == 90 && this->gracz1->canAttack())
		{
			this->bullets.push_back(new bullet(this->tekstury["BULLET"], this->gracz1->pos1().x + 10, this->gracz1->pos1().y - 5, 1.f, 0.f, 5.f));
		}
		if (this->gracz1->jaki_kat1() == 180 && this->gracz1->canAttack())
		{
			this->bullets.push_back(new bullet(this->tekstury["BULLET"], this->gracz1->pos1().x - 5, this->gracz1->pos1().y + 10, 0.f, 1.f, 5.f));
		}
		if (this->gracz1->jaki_kat1() == 270 && this->gracz1->canAttack())
		{
			this->bullets.push_back(new bullet(this->tekstury["BULLET"], this->gracz1->pos1().x-10, this->gracz1->pos1().y - 5, -1.f, 0.f, 5.f));
		}
		if (this->gracz1->jaki_kat1() == 0 && this->gracz1->canAttack())
		{
			this->bullets.push_back(new bullet(this->tekstury["BULLET"], this->gracz1->pos1().x - 5, this->gracz1->pos1().y-10, 0.f, -1.f, 5.f));
		}
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::K))
	{
		if (this->gracz2->jaki_kat2() == 90 && this->gracz2->canAttack())
		{
			this->bullets.push_back(new bullet(this->tekstury["BULLET"], this->gracz2->pos2().x + 10, this->gracz2->pos2().y - 5, 1.f, 0.f, 5.f));
		}
		if (this->gracz2->jaki_kat2() == 180 && this->gracz2->canAttack())
		{
			this->bullets.push_back(new bullet(this->tekstury["BULLET"], this->gracz2->pos2().x - 5, this->gracz2->pos2().y + 10, 0.f, 1.f, 5.f));
		}
		if (this->gracz2->jaki_kat2() == 270 && this->gracz2->canAttack())
		{
			this->bullets.push_back(new bullet(this->tekstury["BULLET"], this->gracz2->pos2().x - 10, this->gracz2->pos2().y - 5, -1.f, 0.f, 5.f));
		}
		if (this->gracz2->jaki_kat2() == 0 && this->gracz2->canAttack())
		{
			this->bullets.push_back(new bullet(this->tekstury["BULLET"], this->gracz2->pos2().x - 5, this->gracz2->pos2().y - 10, 0.f, -1.f, 5.f));
		}
	}
}

void game::updateBullets()
{
	
	unsigned licznik = 0;
	for (auto* bullet : this->bullets)
	{
		bullet->update();
		for (int i = 0; i < 125; i++)
		{
			if (bullet->pos().top + bullet->pos().height <= 50.f || bullet->pos().top - bullet->pos().height >= 850.f || bullet->pos().left + bullet->pos().width <= 50.f || bullet->pos().left - bullet->pos().width >= 1050.f || bullet->pos().intersects(this->przeszkoda1->spriteP[i].getGlobalBounds()) || bullet->pos().intersects(this->gracz1->pozycja1()) || bullet->pos().intersects(this->gracz2->pozycja2()))
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
	/*
	for (auto* bullet : this->bullets)
	{
		if (bullet->pos().intersects(this->gracz2->pozycja2()))
			this->~game();
	}
	*/
	
	
	
	
	
	
	
	/*
	unsigned licznik = 0;
	for (auto* bullet : this->bullets)
	{
		bullet->update();
		
			if (bullet->pos().top + bullet->pos().height <= 50.f || bullet->pos().top - bullet->pos().height >= 850.f || bullet->pos().left + bullet->pos().width <= 50.f || bullet->pos().left - bullet->pos().width >= 1050.f || bullet->pos().intersects(this->gracz2->pozycja2()) || bullet->pos().intersects(this->gracz1->pozycja1()))
			{
				delete this->bullets.at(licznik);
				this->bullets.erase(this->bullets.begin() + licznik);
				--licznik;
			}
			++licznik;
		
		std::cout << this->bullets.size() << std::endl;
	}*/
}


void game::update()
{
	this->updateEvents();
	this->kolizjeP();
	//this->kolizjeB();
	this->kolizje();
	this->updateBullets();
	this->gracz1->update();
	this->gracz2->update();
}

void game::updateMapy()
{
}

void game::kolizje()
{
	//lewa strona
	if (this->gracz1->pozycja1().left < 50.f)
	{
		this->gracz1->zmien_pozycje1(63.f, this->gracz1->pozycja1().top+13);
		std::cout << "granica " << std::endl;

	}
	if (this->gracz2->pozycja1().left < 50.f)
	{
		this->gracz2->zmien_pozycje2(63.f, this->gracz2->pozycja2().top+13);
		std::cout << "granica " << std::endl;

	}
	//prawa strona
	if (this->gracz1->pozycja1().left > 1020.f)
	{
		this->gracz1->zmien_pozycje1(1033.f, this->gracz1->pozycja1().top+13);
		std::cout << "granica " << std::endl;

	}
	if (this->gracz2->pozycja2().left > 1020.f)
	{
		this->gracz2->zmien_pozycje2(1033.f, this->gracz2->pozycja2().top + 13);
		std::cout << "granica "<< std::endl;

	}
	
	//gora
	if (this->gracz1->pozycja1().top < 50.f)
	{
		this->gracz1->zmien_pozycje1(this->gracz1->pozycja1().left + 13, 63.f);
		std::cout << "granica " << std::endl;

	}
	if (this->gracz2->pozycja2().top  < 50.f)
	{
		this->gracz2->zmien_pozycje2(this->gracz2->pozycja2().left+13, 63.f);
		std::cout << "granica " << std::endl;

	}

	//dol
	if (this->gracz1->pozycja1().top > 820.f)
	{
		this->gracz1->zmien_pozycje1(this->gracz1->pozycja1().left + 13, 833.f);
		std::cout << "granica " << std::endl;

	}
	if (this->gracz2->pozycja2().top > 820.f)
	{
		this->gracz2->zmien_pozycje2(this->gracz2->pozycja2().left + 13, 833.f);
		std::cout << "granica " << std::endl;

	}


}
//kolizja z przeszkodami
void game::kolizjeP()
{
	for (int i = 0; i < 125; i++)
	{
		//od lewej
		if (this->gracz1->pozycja1().intersects(this->przeszkoda1->spriteP[i].getGlobalBounds()) && this->gracz1->jaki_kat1() == 90)
		{
			this->gracz1->zmien_pozycje1(this->gracz1->pozycja1().left + 11, this->gracz1->pozycja1().top + 13);
			std::cout << "kolizja" << std::endl;
		}
		if (this->gracz2->pozycja2().intersects(this->przeszkoda1->spriteP[i].getGlobalBounds()) && this->gracz2->jaki_kat2() == 90)
		{
			this->gracz2->zmien_pozycje2(this->gracz2->pozycja2().left + 11, this->gracz2->pozycja2().top + 13);
			std::cout << "kolizja" << std::endl;
		}
		//od gory
		if (this->gracz1->pozycja1().intersects(this->przeszkoda1->spriteP[i].getGlobalBounds()) && this->gracz1->jaki_kat1() == 180)
		{
			this->gracz1->zmien_pozycje1(this->gracz1->pozycja1().left + 13, this->gracz1->pozycja1().top + 11);
			std::cout << "kolizja" << std::endl;
		}
		if (this->gracz2->pozycja2().intersects(this->przeszkoda1->spriteP[i].getGlobalBounds()) && this->gracz2->jaki_kat2() == 180)
		{
			this->gracz2->zmien_pozycje2(this->gracz2->pozycja2().left + 13, this->gracz2->pozycja2().top + 11);
			std::cout << "kolizja" << std::endl;
		}
		//od prawej
		if (this->gracz1->pozycja1().intersects(this->przeszkoda1->spriteP[i].getGlobalBounds()) && this->gracz1->jaki_kat1() == 270)
		{
			this->gracz1->zmien_pozycje1(this->gracz1->pozycja1().left + 15, this->gracz1->pozycja1().top + 13);
			std::cout << "kolizja" << std::endl;
		}
		if (this->gracz2->pozycja2().intersects(this->przeszkoda1->spriteP[i].getGlobalBounds()) && this->gracz2->jaki_kat2() == 270)
		{
			this->gracz2->zmien_pozycje2(this->gracz2->pozycja2().left + 15, this->gracz2->pozycja2().top + 13);
			std::cout << "kolizja" << std::endl;
		}
		//od dolu
		if (this->gracz1->pozycja1().intersects(this->przeszkoda1->spriteP[i].getGlobalBounds()) && this->gracz1->jaki_kat1() == 0)
		{
			this->gracz1->zmien_pozycje1(this->gracz1->pozycja1().left + 13, this->gracz1->pozycja1().top + 15);
			std::cout << "kolizja" << std::endl;
		}
		if (this->gracz2->pozycja2().intersects(this->przeszkoda1->spriteP[i].getGlobalBounds()) && this->gracz2->jaki_kat2() == 0)
		{
			this->gracz2->zmien_pozycje2(this->gracz2->pozycja2().left + 13, this->gracz2->pozycja2().top + 15);
			std::cout << "kolizja" << std::endl;
		}
	}
	
}
/*
void game::kolizjeB()
{
	for (int i = 0; i < 125; i++)
	{
		if (this->pocisk->pos().intersects(this->przeszkoda1->spriteP[i].getGlobalBounds()))
		{
			this->bullets.pop_back();
		}
	}
	
}
*/
void game::rysowanie_mapki()
{
	this->window->draw(this->map_bg);
}

void game::rysuj()
{
	this->window->clear(sf::Color::Green);
	this->rysowanie_mapki();
	this->gracz1->rysuj1(*this->window);
	this->gracz2->rysuj2(*this->window);
	this->przeszkoda1->rysuj(*this->window);

	for (auto *bullet : this->bullets)
	{
		bullet->rysuj(*this->window); 
	}
	//std::cout << "Y pos: " << this->gracz1->pozycja().top << std::endl;


	this->window->display();
}


game::game()
{
	this->inicjalizacja_mapy();
	this->inicjalizacja_zmiennych();
	this->inicjalizacja_przeszkod();
	this->inicjalizacja_gracza1();
	this->inicjalizacja_tekstur();
	//this->inicjalizacja_okna();
}

game::~game()
{
	delete this->window;
	delete this->gracz1;
	delete this->gracz2;
	delete this->przeszkoda1;

	for (auto& i : this->tekstury)
	{
		delete i.second;
	}

	for (auto *i : this->bullets)
	{
		delete i;
	}
}

const bool game::running() const
{
	return this->window->isOpen();
}
