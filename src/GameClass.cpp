#include "GameClass.h"

GameClass::GameClass() {
	
	initSettingStruct();

	setting.antialiasingLevel = SettingsProgram.antialiasingLevel;
	
	windowSizeXY = {SettingsProgram.WindowSizeXJSON,
					SettingsProgram.WindowSizeYJSON};

	int screenStyle = 7;

	if (SettingsProgram.fullScreen)
		screenStyle = 8;
	else
		screenStyle = 7;

	windowX = windowSizeXY[0];
	windowY = windowSizeXY[1];

	RenderWindow windowOther(VideoMode(windowSizeXY[0], windowSizeXY[1]), "PixelCrocodile", screenStyle, setting);
	windowOther.setFramerateLimit(60);

	windowScreen = &windowOther;

	this->gameMainLoop();

}

void GameClass::initSettingStruct() {

	try
	{
		ifstream ifs("files\\settings.json");
		ptree pt;
		read_json(ifs, pt);

		SettingsProgram.WindowSizeXJSON = pt.get<int>("screenSizeX");
		SettingsProgram.WindowSizeYJSON = pt.get<int>("screenSizeY");
		SettingsProgram.antialiasingLevel = pt.get<int>("antialiasingLevel");
		SettingsProgram.fullScreen = pt.get<bool>("fullScreen");
	}			
	catch (const std::exception&)
	{
		loadJSON = false;
	}



}

void GameClass::settingDraw() {

}

int GameClass::getCharSize(char deco) {

	switch (deco)
	{
	case 'I':
	case 'r':
	case 'f':
	case 'z':
	case 'c':
		return 8;
		break;
	case 'E':
	case 'F':
		return 7;
		break;
	case 'm':
	case 'w':
	case 'x':
	case 'X':
		return 11;
		break;
	case 'j':
	case 't':
		return 6;
		break;
	case 'l':
	case 'i':
		return 4;
		break;
	default:
		return 10;
		break;
	}

}

bool GameClass::drawPlayButtons() {
	string txt = "play";

	int y = 0;
	int textShift = 0;
	int MouseX = eventVars.mouseX;
	int MouseY = eventVars.mouseY;
	int width = 90;

	RectangleShape playButton(Vector2f(width, 30 - 5));
	Font playFont;
	Text playNameInputContent;

	playFont.loadFromFile("files\\font.ttf");

	playNameInputContent.setFont(playFont);
	playNameInputContent.setString(txt);
	playNameInputContent.move(windowX / 2 + width / 2 - 90 + 28 - textShift, windowY / 2 - 150 - 8 + 60 - 5 + y);
	playNameInputContent.setFillColor(Color::White);

	playButton.setFillColor(Color(70, 70, 70));
	playButton.move(windowX / 2 - width / 2, windowY / 2 - 90 + y);

	playButton.setOutlineThickness(3.f);

	bool xHandler = MouseX >= (windowX / 2) + (width / 2) - 90 && MouseX <= windowX / 2 + width - width / 2;
	bool yHandler = MouseY >= windowY / 2 - 90 + y && MouseY <= windowY / 2 - 90 + y + 30;

	if (xHandler && yHandler)
	{
		playButton.setOutlineColor(Color(200, 200, 200));
		if (Mouse::isButtonPressed(Mouse::Left))
			return true;
	}
	else
	{
		playButton.setOutlineColor(Color(90, 90, 90));
	}

	windowScreen->draw(playButton);
	windowScreen->draw(playNameInputContent);

	return false;
}


bool GameClass::drawSettingButtons() {
	string txt = "Setting";

	int y = 50;
	int textShift = 10;
	int MouseX = eventVars.mouseX;
	int MouseY = eventVars.mouseY;
	int width = 90;

	RectangleShape playButton(Vector2f(width, 30 - 5));
	Font playFont;
	Text playNameInputContent;

	playFont.loadFromFile("files\\font.ttf");

	playNameInputContent.setFont(playFont);
	playNameInputContent.setString(txt);
	playNameInputContent.move(windowX / 2 + width / 2 - 90 + 28 - textShift, windowY / 2 - 150 - 8 + 60 - 5 + y);
	playNameInputContent.setFillColor(Color::White);

	playButton.setFillColor(Color(70, 70, 70));
	playButton.move(windowX / 2 - width / 2, windowY / 2 - 90 + y);

	playButton.setOutlineThickness(3.f);

	bool xHandler = MouseX >= (windowX / 2) + (width / 2) - 90 && MouseX <= windowX / 2 + width - width / 2;
	bool yHandler = MouseY >= windowY / 2 - 90 + y && MouseY <= windowY / 2 - 90 + y + 30;

	if (xHandler && yHandler)
	{
		playButton.setOutlineColor(Color(200, 200, 200));
		if (Mouse::isButtonPressed(Mouse::Left))
			return true;
	}
	else
	{
		playButton.setOutlineColor(Color(90, 90, 90));
	}

	windowScreen->draw(playButton);
	windowScreen->draw(playNameInputContent);

	return false;
}

void GameClass::drawNickNameInput() {
	const int nickWidth = 300;
	int nickNameX = windowSizeXY[0];
	int nickNameY = windowSizeXY[1];
	int MouseX = eventVars.mouseX;
	int MouseY = eventVars.mouseY;
	int timeProgram = clock();
	RectangleShape cursor(Vector2f(2, 14));
	RectangleShape rect(Vector2f(nickWidth, 30));
	Font nickFont;
	Text nickNameInputContent;

	nickFont.loadFromFile("files\\font.ttf");

	nickNameInputContent.setFont(nickFont);
	nickNameInputContent.setString(nickText);
	nickNameInputContent.move(nickNameX / 2 - 150 + 5, nickNameY / 2 - 150 - 8);
	nickNameInputContent.setFillColor(Color::White);

	if (timeProgram >= 300 && index)
	{
		lastTime = timeProgram;
		index = false;
	}


	if (Mouse::isButtonPressed(Mouse::Left))
	{
		if (MouseX >= nickNameX / 2 - 150 && MouseX <= nickNameX / 2 + 150 && MouseY >= nickNameY / 2 - 150 && MouseY <= nickNameY / 2 - 150 + 30)
			nickInputFocus = true;
		else
			nickInputFocus = false;
	}

	cursor.setFillColor(Color::White);
	cursor.move(nickNameX / 2 - nickWidth / 2 + 10 + cursorShift, nickNameY / 2 - 150 + 10 - 2);

	rect.move(nickNameX / 2 - nickWidth / 2, nickNameY / 2 - 150);
	rect.setFillColor(Color(70, 70, 70));
	rect.setOutlineThickness((float)5);
	rect.setOutlineColor(Color(90, 90, 90));

	windowScreen->draw(rect);

	if (nickInputFocus)
	{
		if (timeProgram - lastTime >= 300)
		{
			lastTime = timeProgram;
			cursorNick = !cursorNick;
		}
		if (cursorNick)
			windowScreen->draw(cursor);
	}
	windowScreen->draw(nickNameInputContent);

}

void GameClass::windowEvents() {

	Event eve;

	while (windowScreen->pollEvent(eve))
	{
		if (eve.type == Event::Closed || Keyboard::isKeyPressed(Keyboard::Escape))
			windowScreen->close();


		if (eve.type == Event::TextEntered && nickInputFocus)
		{
			if (eve.text.unicode != 8 && nickText.size() < 20)
			{
				nickText += static_cast<char>(eve.text.unicode);

				char decode = static_cast<char>(eve.text.unicode);

				cursorShift += getCharSize(decode);

			}

			if (eve.text.unicode == 8 && nickText.size() > 0)
			{
				int res = (int)cursorShift / (int)nickText.size();
				nickText.pop_back();
				cursorShift -= res;
			}

		}

		if (eve.type == Event::MouseMoved)
		{
			eventVars.mouseX = eve.mouseMove.x;
			eventVars.mouseY = eve.mouseMove.y;
		}
	}

}

void GameClass::gameMainLoop() {

	while (windowScreen->isOpen())
	{

		this->windowEvents();

		if (!gameStart)
		{
			drawNickNameInput();
			
			if (drawPlayButtons())
			{
				gameStart = true;
			}

			if (drawSettingButtons())
			{
				this->settingDraw();
			}

			windowScreen->display();
			windowScreen->clear(Color(50, 50, 50));
			
		}

		if (Keyboard::isKeyPressed(Keyboard::Space)) 
		{
			gameStart = 1;
		}

		if (gameStart)
		{
			
			windowScreen->clear(Color::White);
			windowScreen->display();
		}
	}
}