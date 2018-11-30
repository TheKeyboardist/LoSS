#include <iostream>
#include <string>
#include "PLayer.h"
#include "Engine.h"
#include "BGTile.h"
#include "Action.h"
using namespace std;

void Options(Player& player, Engine& engine);
void MainMenu(Player& player, Engine& engine);
void RealTimeMenu(Player& player, Engine& engine);
int main()
{
	bool finish = false;
	Player player;
	Engine engine;
	Action action;
	engine.takeTiles("config.txt");
	while (action.gameOver == false)
	{
		MainMenu(player, engine);
		return 0;
	}

	
}

void MainMenu(Player& player, Engine& engine)
{
	system("cls");
	cout << "LIFE OUTSIDE SELF-SIMULATION" << endl;
	cout << "s - Start a new game" << endl;
	cout << "o - Options" << endl;
	cout << "e - Leave the game" << endl;
	char input;
	cin >> input;
	switch (input)
	{
	case 's':
		system("cls");
		char in;
		engine.NewStart(player);
		engine.makeMovement(player);
		break;
	case 'e':
		system("cls");
		cout << "See you later" << endl;
		system("pause");
		break;
	case 'o' :
		Options(player, engine);
		break;
	}
}

void Options(Player& player, Engine& engine)
{
	system("cls");
	cout << "- player model customization -" << endl;
	cout << "you can choose a skin for your player" << endl;
	cout << " your current skin  - " << engine.playerModel << endl;
	cout << "1) 'P' - default skin" << endl;
	cout << "2) 'E' - Eee guy" << endl;
	cout << "3) '@' - good boy" << endl;
	cout << "4) 'S' - Ss-snake" << endl;
	cout << endl;
	cout << "5) exit to main menu" << endl;
	char input;

	cin >> input;
	switch (input)
	{
	case '1':
		engine.playerModel = 'P';
		cout << "You have chosen a default skin" << endl;
		Options(player, engine);
		break;
	case '2':
		engine.playerModel = 'E';
		Options(player, engine);
		break;
	case '3':
		engine.playerModel = '@';
		Options(player, engine);
		break;
	case '4':
		engine.playerModel = 'S';
		Options(player, engine);
		break;
	case '5':
		MainMenu(player, engine);
		break;
	}
}

void RealTimeMenu(Player& player, Engine& engine)
{
	char in;
	cout << "1) Main menu" << endl;
	cout << "2) Exit" << endl;
	cin >> in;
	switch (in)
	{
	case '1':
		MainMenu(player, engine);
		break;
	case '2':
		break;
	}
}