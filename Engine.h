#pragma once
#include <iostream>
#include <string>
#include <conio.h>
#include <fstream>
#include "PLayer.h"
#include "BGTile.h"
#include "Action.h"
using namespace std;

class Engine
{
private:

	int row;
	int col;
	int x0, y0;
	int xn1, yn1, xn2, yn2;
public:
	int roomNum = 1;
	BGTile** matrix;
	string* tiles;
	Player player;
	bool ifFirst = true;
	char playerModel = 'P';
	bool quit = false;
	char wall = 186;
	char space = 0;
	char door = 143;
	char water = 126;
	char lava = 88;
	char cage = 35;
	char exit = 219;
	string tile;
	Action action;
	void BuildMap(string source)
	{
		ifstream path;
		path.open(source);
		path >> row >> col;
		path >> x0 >> y0;
		path >> xn1 >> yn1;
		path >> xn2 >> yn2;

		matrix = new BGTile*[col];
		for (int i = 0; i < col; i++)
		{
			matrix[i] = new BGTile[row];
			for (int j = 0; j < row; j++)
			{
				int b;
				path >> b;
				matrix[i][j].m_cOutput = b;
				if (matrix[i][j].m_cOutput == water)
				{
					matrix[i][j].m_bIsWater = true;
					matrix[i][j].m_bIsHazard = true;
				}
				else if (matrix[i][j].m_cOutput == lava)
				{
					matrix[i][j].m_bIsLava= true;
					matrix[i][j].m_bIsHazard = true;
				}
				else if (matrix[i][j].m_cOutput == cage)
				{
					matrix[i][j].m_bIsDoorOpen = false;
				}
			}

		}
	}

	void PrintMap(Player& player)
	{

		for (int i = player.m_y - 1; i <= player.m_y + 1; i++)
		{
			for (int j = player.m_x - 2; j <= player.m_x + 2; j++)
			{
				if (matrix[i][j].m_cOutput == cage && action.doorOpened == true)
				{
					matrix[i][j].m_cOutput = door;
				}
				if (i == player.m_y && j == player.m_x)
				{
					cout << playerModel;
				}
				else
				{
					cout << matrix[i][j].m_cOutput;
				}
				
			}
			cout << endl;
		}
		if(action.doorOpened == false && action.counter > 0)
		cout << "you have " << action.counter * 100 << " milliliters of liquid" << endl;
	}

	void makeMovement(Player& player)
	{

		char input;
		int haz;
		while (!quit)
		{
			DoorCheck1(2, 5, player);

			PrintMap(player);
				action.Check(player.m_x, player.m_y);
			
			if (action.m_bIsLibra == true)
			{
				PrintMap(player);
				action.m_bIsLibra = false;
			}

			if (matrix[player.m_y][player.m_x].m_bIsWater == true)
				cout << "You're drowning in the water" << endl;
			if (matrix[player.m_y][player.m_x].m_bIsLava == true)
				cout << "Lava is killing you" << endl;
			input = _getch();
			switch (input)
			{
			case 'w':
				if (player.m_y > 0 && matrix[player.m_y - 1][player.m_x].m_cOutput == space || matrix[player.m_y - 1][player.m_x].m_bIsHazard == true)
				{
					player.m_y--;

				}
				else if (matrix[player.m_y - 1][player.m_x].m_cOutput == door)
				{
					DoorCheck1(player.m_y - 1, player.m_x, player);
				}
				else if (matrix[player.m_y - 1][player.m_x].m_cOutput == exit)
				{
					system("cls");
					cout << "Confratulations. You managed to escape this place" << endl;
					system("pause");
					quit = true;
				}

				break;
			case 's':
				if ((player.m_y < col - 1 && matrix[player.m_y + 1][player.m_x].m_cOutput == space) || matrix[player.m_y + 1][player.m_x].m_bIsHazard == true)
				{
					player.m_y++;
				}
				else if (matrix[player.m_y + 1][player.m_x].m_cOutput == door)
				{
					DoorCheck1(player.m_y + 1, player.m_x, player);
				}
				break;
			case 'a':
					if ((player.m_x > 1 && matrix[player.m_y][player.m_x - 1].m_cOutput == space && matrix[player.m_y][player.m_x - 1].m_cOutput != wall) || matrix[player.m_y][player.m_x - 1].m_bIsHazard == true)
					{
						player.m_x = player.m_x - 1;

					}
					else if (matrix[player.m_y][player.m_x - 1].m_cOutput == door)
					{
						DoorCheck1(player.m_y, player.m_x - 1, player);
					}
				break;
			case 'd':
				if ((player.m_x < row - 1 && matrix[player.m_y][player.m_x + 1].m_cOutput == space && matrix[player.m_y][player.m_x + 1].m_cOutput != wall) || matrix[player.m_y][player.m_x + 1].m_bIsHazard == true)
				{
					player.m_x = player.m_x + 1;

				}
				else if (matrix[player.m_y][player.m_x + 1].m_cOutput == door)
				{
					DoorCheck1(player.m_y, player.m_x + 1, player);
				}
				break;
			case 'q':
				quit = true;
				break;
			}

			system("cls");

		}
	}


	void DoorCheck1(int i, int j, Player& player)
	{
		if (roomNum == 1)
		{

			if (ifFirst == true)
			{
				BuildMap(tiles[1]);
				player.m_y = y0;
				player.m_x = x0;
				ifFirst = false;
			}
			else if (i == yn1 && j == xn1)
			{
				BuildMap(tiles[0]);
				player.m_x = x0 + 1;
				player.m_y = y0;
				roomNum = 2;
			}
		}
		else if (roomNum == 2)
		{
			if (i == yn1 && j == xn1)
			{
				BuildMap(tiles[1]);
				player.m_x = xn1 + 1;
				player.m_y = yn1;
				roomNum = 1;
			}
			else if (i == yn2 && j == xn2)
			{
				BuildMap(tiles[2]);
				player.m_y = y0;
				player.m_x = x0;
				roomNum = 3;
			}
		}
		else if (roomNum == 3)
		{
			if (i == yn1 && j == xn1)
			{
				BuildMap(tiles[0]);
				player.m_x = xn2;
				player.m_y = yn2 + 1;
				roomNum = 2;
			}
		}
	}

	void takeTiles(string source)
	{
		int m_iRow;

		ifstream path;
		path.open(source);
		path >> m_iRow;
		tiles = new string[m_iRow];

		for (int i = 0; i < m_iRow; i++)
		{
			path >> tiles[i];

		}
	}

	void NewStart(Player& player)
	{
		BuildMap(tiles[1]);
		ifFirst = true;
		player.m_y = y0;
		player.m_x = x0;
		quit = false;
	}

};

