#pragma once
#include <iostream>
#include "PLayer.h"
#include "Engine.h"
using namespace std;

class Action
{
private:
	int lives = 3;

	bool questTaken = false;

	bool room1bottle1 = false;
	bool room1bottle2 = false;
	bool room2bottle1 = false;
	bool room2bottle2 = false;
public:
	int counter = 0;
	bool libraActivated = false;
	bool doorOpened = false;
	bool m_bIsLibra = false;
	bool gameOver = false;
	Player player;

	
	void LibraCheck(int x, int y)
	{
			if (((x == 2 && y == 2) || (x == 2 && y == 4) || (x == 3 && y == 3)) && libraActivated == false)
			{
				m_bIsLibra = true;
				Quest();
			}
			if (x == 13 && y == 10 && room1bottle1 == false)
			{
				counter++;
				room1bottle1 = true;
				system("cls");
				cout << "You found a little bottle with liquid" << endl;
				system("pause");
			}
			if (x == 5 && y == 11 && room1bottle2 == false)
			{
				counter++;
				room1bottle2 = true;
				system("cls");
				cout << "You found a little bottle with liquid" << endl;
				system("pause");
			}
			if (x == 10 && y == 2 && room2bottle1 == false)
			{
				counter++;
				room2bottle1 = true;
				system("cls");
				cout << "You found a little bottle with liquid" << endl;
				system("pause");
			}
			if (x == 10 && y == 4 && room2bottle2 == false)
			{
				counter++;
				room2bottle2 = true;
				system("cls");
				cout << "You found a little bottle with liquid" << endl;
				system("pause");
			}
	}
	void Check(int x, int y)
	{
		LibraCheck(x, y);
	}

	void Quest()
	{
		if (!questTaken)
		{
			questTaken = true;
			system("cls");
			cout << "You have come to a mysterous machine" << endl << "it looks like a container, linked with a libra" << endl;
			system("pause");
			system("cls");
			cout << "You notice a half filled bottle of clear liquid," << endl;
			cout << endl;
			cout << "standing on a shelf next to the machine" << endl;
			counter = counter + 4;
			system("pause");
			system("cls");
			cout << "There is a table with a text on the machine" << endl;
			cout << "% - To open the door to the next room, " << endl << "you need to pour a container with a full bottle of liquid" << endl;
			cout << "and pull the arm";
			system("pause");
			system("cls");
			cout << "1) pour the container with all amount of liquid I have got" << endl;
			cout << "2) I need to find more" << endl;
		}
		else
		{
			system("cls");
			cout << "1) pour the container with all amount of liquid I have got" << endl;
			cout << "2) I need to find more" << endl;
			int ch;
			cin >> ch;
			cin.ignore();
			switch (ch)
			{
			case 1:
				if (counter < 8)
				{
					cout << "nothing happened" << endl;
					break;
				}
				else
				{
					cout << "you opened the door" << endl;
					doorOpened = true;
					libraActivated = true;
					break;
				}

			case 2:
				break;
			}
			system("pause");
			system("cls");
		}


	}
};