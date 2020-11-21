#pragma once
#ifndef Code
#define Code

#include <iostream>
#include <SFML/Graphics.hpp>
#include <cmath>
#include <vector>
#include <PaintClass.h>
#include <fstream>
#include <boost/property_tree/json_parser.hpp>

using namespace std;
using namespace sf;
using namespace boost;
using namespace property_tree;

class GameClass
{
private:
	RenderWindow* windowScreen;
	ContextSettings setting;
	string nickText = "";

	bool gameStart = false;
	bool nickInputFocus = true;
	bool playButtonFocus = false;
	bool index = true;
	bool cursorNick = true;
	bool loadJSON = false;

	int lastTime = 0;
	int cursorShift = 0;
	int windowX = VideoMode::getFullscreenModes()[0].width;
	int windowY = VideoMode::getFullscreenModes()[0].height;
	
	struct ProgramSetting {
		int WindowSizeXDefault = 800;
		int WindowSizeYDefault = 640;
		
		int WindowSizeXJSON;
		int WindowSizeYJSON;
	};

public:
	GameClass();

	int getCharSize(char deco);
	vector<int> getScreenSize();

	bool drawSettingButtons();
	bool drawPlayButtons();

	void settingDraw();
	void drawNickNameInput();
	void windowEvents();
	void gameMainLoop();

};

#endif Code