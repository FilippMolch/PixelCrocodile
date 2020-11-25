#pragma once
#ifndef Code
#define Code

#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Network.hpp>
#include <cmath>
#include <vector>
#include <fstream>
#include <math.h>
#include <boost/property_tree/json_parser.hpp>

using namespace std;
using namespace sf;
using namespace boost;
using namespace property_tree;

class GameClass
{
private:
	RenderWindow*		windowScreen;
	ContextSettings		setting;
	string				nickText = "";
	vector<int>			windowSizeXY;
	vector<vector<int>> paintVector;

	Texture canvas;
	Image   canvasImage;
	Sprite  canvasSprite;

	bool gameStart = false;
	bool nickInputFocus = true;
	bool playButtonFocus = false;
	bool index = true;
	bool cursorNick = true;
	bool loadJSON = false;
	bool inSetting = false;

	int lastTime = 0;
	int cursorShift = 0;
	int windowX;
	int windowY;
	
	struct ProgramSetting {
		int WindowSizeXDefault = 800;
		int WindowSizeYDefault = 640;
		
		int WindowSizeXJSON;
		int WindowSizeYJSON;

		int  antialiasingLevel;
		bool fullScreen;
	};

	struct EventVars
	{
		int mouseX;
		int mouseY;

		bool LMB;
		bool RMB;
	};

public:
	GameClass();

	ProgramSetting SettingsProgram;
	EventVars      eventVars;

	int getCharSize(char deco);

	bool drawSettingButtons();
	bool drawPlayButtons();
	bool XYHandler(int x, int y, int xSize, int ySize);

	void painting();
	void initSettingStruct();
	void settingDraw();
	void drawNickNameInput();
	void windowEvents();
	void gameMainLoop();

};

#endif Code