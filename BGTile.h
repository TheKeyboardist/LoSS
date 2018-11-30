#pragma once
#include <iostream>
#include "PLayer.h"

using namespace std;

class BGTile
{
public:
	char m_cOutput;
	bool m_bIsLava;
	bool m_bIsWater;
	bool m_bIsHazard;
	bool m_bIsObstacle;
	bool m_bIsDoorOpen;
};