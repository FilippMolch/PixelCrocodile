#include <iostream>
#include <SFML/Graphics.hpp>
#include <cmath>
#include <vector>

using namespace std;
using namespace sf;

ContextSettings set;
Texture texture;
RenderWindow win(VideoMode::getFullscreenModes()[0], "test", Style::Fullscreen, set);

bool gameStart = false;
bool nickInputFocus = true;
bool playButtonFocus = false;
bool index = true;
bool cursorNick = true;

int lastTime = 0;
int cursorShift = 0;
int windowX = VideoMode::getFullscreenModes()[0].width;
int windowY = VideoMode::getFullscreenModes()[0].height;

string nickText = "";

int getCharSize(char deco) {

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

void drawButtons(string txt, int y, int textShift) {
	
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
	playButton.setOutlineColor(Color(90, 90, 90));

	win.draw(playButton);
	win.draw(playNameInputContent);
}

void drawNickNameInput() {
	const int nickWidth = 300;
	int nickNameX = VideoMode::getFullscreenModes()[0].width;
	int nickNameY = VideoMode::getFullscreenModes()[0].height;
	int MouseX = Mouse::getPosition().x;
	int MouseY = Mouse::getPosition().y;
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

	win.draw(rect);
	if (nickInputFocus)
	{
		if (timeProgram - lastTime >= 300)
		{
			lastTime = timeProgram;
			cursorNick = !cursorNick;
		}
		if (cursorNick)
			win.draw(cursor);
	}
	win.draw(nickNameInputContent);
}

int main(){

	set.antialiasingLevel = 8;
	win.setFramerateLimit(60);

	while (win.isOpen())
	{
	
		Event eve;
	
		while (win.pollEvent(eve))
		{
			if (eve.type == Event::Closed || Keyboard::isKeyPressed(Keyboard::Escape))
				win.close();

	
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
					int res = cursorShift / nickText.size();
					nickText.pop_back();
					cursorShift -= res;
				}

			}
		}

		if (!gameStart)
		{
			drawNickNameInput();
			drawButtons("play", 0, 0);
			drawButtons("setting", 50, 7);
		}

		win.display();
		win.clear(Color(50, 50, 50));
	}

}