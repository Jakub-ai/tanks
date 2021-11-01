#pragma once
#include <SFML/Window/Event.hpp>
#include <SFML/Window/Window.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
	class Opcje
	{
	private:
		sf::RenderWindow* window;
		sf::Event op;
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

