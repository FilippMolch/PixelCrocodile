#pragma once

#ifndef Cod
#define Cod

#include <iostream>
#include <SFML/Graphics.hpp>
#include <cmath>
#include <vector>

using namespace std;
using namespace sf;

class PaintClass
{

private:
	vector<vector<int>> paintArr;
	RenderWindow* windowScreen;

public:
	void painting();
	void addVector(int x, int y);

	PaintClass(RenderWindow* windowScreen);
	PaintClass();

};

#endif Cod