#include "mainMenu.h"
#include <SFML/Graphics.hpp>
using namespace sf;
using namespace std;
void main()
{
	//Tworzenie g³ownego okna 
	RenderWindow Menu(VideoMode(960, 720), "Main Menu", Style::Default);
	MainMenu mainMenu(Menu.getSize().x, Menu.getSize().y);


	// kiedy okno menu jest wyswietlane
	while (Menu.isOpen())
	{
		Event event;
		while
			(Menu.pollEvent(event))
		{
			if (event.type == Event::Closed)
			{
				Menu.close();
			}
			if (event.type == Event::KeyReleased)
			{
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
				//tutaj mamy nasze opcje. po ich wyborze przechodzimy do ich zawartosci. Graj wiadomo, opcje no tu damy glosnosc aplikacji moze jeszcze nick wybor czolgu czy cos...
				//w tworcach sie da imie i nazwisko plus kto co robil taki credits z filmu tylko bez xd

				int x = mainMenu.MainMenuPressed();
				if (x == 0)
				{
					RenderWindow Graj(VideoMode(960, 720), "Gra_Tanki");
					while (Graj.isOpen())// tu jest napisane co dokladnie sie dzieje przy wyborze opcji graj
					{
						Event aevent;
						while (Graj.pollEvent(aevent))
						{
							if (aevent.type == Event::Closed)
							{
								Graj.close();
							}
							if (aevent.type == Event::KeyPressed)
							{
								if (aevent.key.code == Keyboard::Escape)
								{
									Graj.close();
								}
							}
						}
						Graj.clear();
						Graj.display();
					}

				}
				if (x == 1)
				{
					RenderWindow Opcje(VideoMode(960, 720), "Opcje");
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
						Opcje.display();

					}
				}
				if (x == 2)
				{
					RenderWindow Twórcy(VideoMode(960, 720), "Twórcy");
					while (Twórcy.isOpen())// tu jest napisane co dokladnie sie dzieje przy wyborze opcji Twórcy
					{
						Event aevent;
						while (Twórcy.pollEvent(aevent)) {
							if (aevent.type == Event::Closed)
							{
								Twórcy.close();
							}
							if (aevent.type == Event::KeyPressed)
							{
								if (aevent.key.code == Keyboard::Escape)
								{
									Twórcy.close();
								}
							}
						}
						Twórcy.clear();//czysci
						Twórcy.display();//otwiera
					}
				}
				if (x == 3)			//zamykamy menu
					Menu.close();
				break;
			}
		}
	}
	Menu.clear();
	mainMenu.draw(Menu);
	Menu.display();
}