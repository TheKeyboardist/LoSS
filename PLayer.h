#pragma once
#include <iostream>

using namespace std;

class Player
{
public:
	int m_x;
	int m_y;
	Player(int x, int y) : m_x(x), m_y(y)
	{
		//I have nothing here
	}

	Player()
	{
		m_x = 0;
		m_y = 0;
	}
};

