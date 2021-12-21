	#pragma once
		

		#include <SFML/Audio/SoundBuffer.hpp>
		#include <SFML/Audio/Sound.hpp>
		#include <SFML/Audio/Music.hpp>
		#include <SFML/Audio/Listener.hpp>
		#include <SFML/System/Clock.hpp>
		#include <SFML/Window/Event.hpp>
		#include <SFML/Window/Window.hpp>
		#include <SFML/Graphics/RenderWindow.hpp>
		#include <SFML/Graphics.hpp>
		#include "mainMenu.h"


	using namespace std;
	using namespace sf;
	#define Max_Opcje 4
		class Opcje
		{
		private:
			sf::RenderWindow* window;
			sf::Event op;
			sf::Font font;

			MainMenu* menu;

			Text opcje[Max_Opcje];
			void inicjalizacja_zmiennych();
		public:
			Opcje();
			virtual	~Opcje();

			const bool working() const;

			void updateEvents();
			void updateO();
			void rysujO();
			void inicjalizacja_oknaO();
			void zmianaNicku();
			

		};

