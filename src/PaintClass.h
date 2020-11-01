#pragma once

#ifndef Code
#define Code

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
	void addVector();

	PaintClass(RenderWindow* windowScreen);
};

#endif Code