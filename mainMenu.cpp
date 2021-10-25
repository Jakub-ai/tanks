#include "mainMenu.h"
MainMenu::MainMenu(float width, float heigh)
{
	if (!font.loadFromFile("Fonts/AlexandriaFLF.ttf")) {
		cout << "No Font HERE !!!";
	}


	//Graj
	mainMenu[0].setFont(font);
	mainMenu[0].setFillColor(Color::White);
	mainMenu[0].setString("Graj");
	mainMenu[0].setCharacterSize(70);
	mainMenu[0].setPosition(400, 200);

	//opcje
	mainMenu[1].setFont(font);
	mainMenu[1].setFillColor(Color::Yellow);
	mainMenu[1].setString("Opcje");
	mainMenu[1].setCharacterSize(70);
	mainMenu[1].setPosition(400, 300);
	// Twórcy
	mainMenu[2].setFont(font);
	mainMenu[2].setFillColor(Color::Red);
	mainMenu[2].setString("Twórcy");
	mainMenu[2].setCharacterSize(70);
	mainMenu[2].setPosition(400, 400);
	//Wyjœcie
	mainMenu[3].setFont(font);
	mainMenu[3].setFillColor(Color::Blue);
	mainMenu[3].setString("Wyjœcie");
	mainMenu[3].setCharacterSize(70);
	mainMenu[3].setPosition(400, 500);

	MainMenuSelected = -1;

};
MainMenu::~MainMenu()
{

}
//rysowanie Menu
void MainMenu::draw(RenderWindow& window)
{
	for (int i = 0; i < Max_main_menu; ++i)
	{
		window.draw(mainMenu[i]);
	}
}
//Move up
void MainMenu::MoveUp()
{
	if (MainMenuSelected - 1 >= 0) {
		mainMenu[MainMenuSelected].setFillColor(Color::White);

		MainMenuSelected--;
		if (MainMenuSelected == - 1) {
			MainMenuSelected = 2;
		}
		mainMenu[MainMenuSelected].setFillColor(Color::Red);
	}
}
//Move Down
void MainMenu::MoveDown()
{
	if (MainMenuSelected + 1 <= Max_main_menu)
	{
		mainMenu[MainMenuSelected].setFillColor(Color::White);
		MainMenuSelected++;
		if (MainMenuSelected == 4)
		{
			MainMenuSelected = 0;
		}
		mainMenu[MainMenuSelected].setFillColor(Color::Red);

	}
}
