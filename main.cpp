#include "mainMenu.h"
#include "game.h"
#include "game2.h"
#include "Opcje.h"
#include <SFML/Graphics.hpp>

using namespace sf;
using namespace std;
int main()
{
	//Tworzenie g?ownego okna 
	RenderWindow Menu(VideoMode(1440, 900), "Main Menu");
	MainMenu mainMenu(Menu.getSize().x, Menu.getSize().y);
	//Ustawienie t?a do MainMenu
	RectangleShape background;
	background.setSize(Vector2f(1440, 900));
	Texture Maintexture;
	Maintexture.loadFromFile("Texture/background.png");
	background.setTexture(&Maintexture);

	//zdjecie do gry
	RectangleShape Pbackground;
	Pbackground.setSize(Vector2f(1440, 900));
	Texture back_texture;
	back_texture.loadFromFile("Texture/background.png");
	Pbackground.setTexture(&back_texture);

	//zdjecie do opcji
	RectangleShape Obackground;
	Obackground.setSize(Vector2f(1440, 900));
	Texture Optiontexture;
	Optiontexture.loadFromFile("Texture/background.png");
	Obackground.setTexture(&Optiontexture);
	//Tworcy
	RectangleShape ABbackground;
	ABbackground.setSize(Vector2f(1440, 900));
	Texture Abouttexture;
	Abouttexture.loadFromFile("Texture/background.png");
	ABbackground.setTexture(&Abouttexture);


	//gra
	game gra;
	game2 gra2;
	//opcje
	Opcje opcje;



	// kiedy okno menu jest wyswietlane
	mainMenu.Sound();
	while (Menu.isOpen())
	{
		
		Event event;
		while
			(Menu.pollEvent(event))
		{
			if (event.type == Event::Closed)
			{
				Menu.close();
				mainMenu.EndMusic();
			}
			if (event.type == Event::KeyReleased)
			{
				if (event.key.code == sf::Keyboard::W)
				{
					mainMenu.VolUp();
					break;
				}
				if (event.key.code == sf::Keyboard::S)
				{
					mainMenu.VolDown();
					break;
				}
				if (event.key.code == Keyboard::Up)
				{
					mainMenu.MoveUp();
					break;
				}
				if (event.key.code == Keyboard::Down)
					mainMenu.MoveDown();
					break;
			}
			if (event.key.code == Keyboard::Return) {

				int x = mainMenu.MainMenuPressed();
				if (x == 0)
				{
					Menu.close();
					mainMenu.EndMusic();
					gra.inicjalizacja_okna();
					while (gra.running())
					{
						gra.update();
						gra.rysuj();
					}

		
					

				}
				if (x == 1)
				{

					Menu.close();
					mainMenu.EndMusic();
					gra2.inicjalizacja_okna();
					while (gra2.running())
					{
						gra2.update();
						gra2.rysuj();
						
						
					}
					/*RenderWindow Opcje(VideoMode(1440, 900), "Opcje");
					while (Opcje.isOpen())// tu jest napisane co dokladnie sie dzieje przy wyborze opcji opcje
					{
						Event aevent;
						while (Opcje.pollEvent(aevent)) {
							if (aevent.type == Event::Closed)
							{
								Opcje.close();
							}
							if (aevent.type == Event::KeyPressed)
							{
								if (aevent.key.code == Keyboard::Escape)
								{
									Opcje.close();
								}
							}
						}
						Opcje.clear();
						Opcje.draw(Obackground);
						Opcje.display();
						
					}
					*/
				}
				if (x == 2)
				{
					RenderWindow Tw?rcy(VideoMode(1440, 900), "Tw?rcy");
					while (Tw?rcy.isOpen())// tu jest napisane co dokladnie sie dzieje przy wyborze opcji Tw?rcy
					{
						Event aevent;
						while (Tw?rcy.pollEvent(aevent)) {
							if (aevent.type == Event::Closed)
							{
								Tw?rcy.close();
							}
							if (aevent.type == Event::KeyPressed)
							{
								if (aevent.key.code == Keyboard::Escape)
								{
									Tw?rcy.close();
								}
							}
						}
						Tw?rcy.clear();//czysci
						Tw?rcy.draw(ABbackground);
						Tw?rcy.display();//otwiera
					}
				}
				if (x == 3)			//zamykamy menu
					Menu.close();
				mainMenu.EndMusic();
				break;
			}
		}
		Menu.clear();
		Menu.draw(background);
		mainMenu.draw(Menu);
		Menu.display();
	}
	
}