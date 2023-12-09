#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <string>
#include <iostream>
#include <Windows.h>
#include "Words.h"

bool showButtons = true, isFullscreen = false, musicPlaying = false, showInstr = false, showCredits = false;
int i = 0;
int j = 0; //Number of turns used, j=7 when user loses
int count = 0; //Number of letters correctly guessed
float scale;
bool end = 0; //end = 1 when user wins

std::string category;
std::string targetWord;
std::string guess; //Guess is the string with dashes equal to word's letters
std::string originalWord;
std::string guessed = "Letters Guessed:\n                     ";
int k = 17;


sf::Vector2i pos;
sf::Event event;
sf::RenderWindow window;
sf::Music music;
sf::SoundBuffer buffer;
sf::Sound clickSound;
sf::VideoMode desktop = sf::VideoMode::getDesktopMode();
sf::VideoMode fullscreen = sf::VideoMode::getDesktopMode();
sf::Texture bg; sf::Sprite bgSprite;
sf::Texture play; sf::Sprite playSprite;
sf::Texture instructions; sf::Sprite instructionsSprite;
sf::Texture exiT; sf::Sprite exitSprite;
sf::Texture instr; sf::Sprite instrSprite;
sf::Texture rtrn; sf::Sprite rtrnSprite;
sf::Texture note; sf::Sprite noteSprite;
sf::Texture credit; sf::Sprite creditSprite;
sf::Texture title; sf::Sprite titleSprite;
sf::Texture hangman; sf::Sprite hangmanSprite;
sf::Texture playAgain; sf::Sprite playAgainSprite;
sf::Texture rope; sf::Sprite ropeSprite;
sf::Texture cursor; sf::Sprite cursorSprite;
sf::Font chalk;
sf::Text gameHeading;
sf::Text creditsHead;
sf::Text credits;
sf::Text triesLeft;
sf::Text categ;
sf::Text guessObject;
sf::Text entered;
sf::Text winObject;
sf::Text loseObject;
sf::Text loseWord;

bool playGame();
void setText();

void createObjects() {
	if (!isFullscreen) {
		desktop.width = 1280, desktop.height = 720;
		window.create(sf::VideoMode(desktop.width, desktop.height), "Hangman");
	}

	else {
		fullscreen.width = 1280, fullscreen.height = 720;
		window.create(sf::VideoMode(desktop.width, desktop.height), "Hangman", sf::Style::Fullscreen);
	}

	scale = desktop.width / 1920.0; // 1920 is width of images to be put fullscreen. Initalized at start only

	//playAgainSprite
	playAgain.loadFromFile("Hangman\\PlayAgain.png");
	playAgainSprite.setTexture(playAgain);

	//Hangman sprite
	hangman.loadFromFile("Hangman\\0.png");
	hangmanSprite.setTexture(hangman);

	//Background Music
	music.openFromFile("bg.mp3");
	music.setLoop(true);

	//Click sound
	buffer.loadFromFile("click.wav");
	clickSound.setBuffer(buffer);

	//Background
	bg.loadFromFile("Hangman\\black.jpg");
	bgSprite.setTexture(bg);

	//Rope
	rope.loadFromFile("Hangman\\rope.png");
	ropeSprite.setTexture(rope);

	//Play Button
	play.loadFromFile("Hangman\\Play.png");
	playSprite.setTexture(play);

	//Instructions Button
	instructions.loadFromFile("Hangman\\Instructions.png");
	instructionsSprite.setTexture(instructions);

	//Exit Button
	exiT.loadFromFile("Hangman\\Exit.png");
	exitSprite.setTexture(exiT);

	//Instructions Screen
	instr.loadFromFile("Hangman\\instructions.jpg");
	instrSprite.setTexture(instr);

	//Return Button
	rtrn.loadFromFile("Hangman\\Return.png");
	rtrnSprite.setTexture(rtrn);

	//Music Button
	note.loadFromFile("Hangman\\noNote.png");
	noteSprite.setTexture(note);
	noteSprite.scale(0.04, 0.04);

	//Credit Button
	credit.loadFromFile("Hangman\\Credits.png");
	creditSprite.setTexture(credit);

	//Font
	chalk.loadFromFile("KGBrokenVesselsSketch.ttf");

	//Main menu heading
	gameHeading.setFont(chalk);
	gameHeading.setCharacterSize(85);
	gameHeading.setString("Hangman");
	gameHeading.setPosition(desktop.width / 2.0 - gameHeading.getGlobalBounds().width / 2, 0.f);

	//Credits headings
	creditsHead.setFont(chalk);
	creditsHead.setCharacterSize(85);
	creditsHead.setStyle(sf::Text::Bold);
	creditsHead.setString("  Developers\n\n\n\n\n\nMoral Support");

	//Credits members
	credits.setFont(chalk);
	credits.setCharacterSize(85);
	credits.setString("Armaghan Atiq\nAbdul Muhaimin\nFaheem Sarwar\n   Rimsha Irfan\n\n\n Ms Arooj Khalil\n Hammad Shahid");

	//Title Screen
	title.loadFromFile("Hangman\\Logo1.jpg");
	titleSprite.setTexture(title);
	titleSprite.scale(scale, scale); //Scaled at the start because it is only played once, when launching the game
}

void showTitle() {
	std::string titlePath = "Hangman\\Logo0.jpg"; //To change the image of logo, for animation effect
	float transparency = 0; //Initalize transparency as 0, meaning completely transparent
	bool pause = 0; //Pauses the transparency change after the first loop finishes.
	int cont; //To continue image from where the first path left off
	Sleep(100); //Black image for first 0.1s, so logo doesn't start immediately

	//From fully transparent to solid.
	while (transparency < 255) {

		for (int i = 1; i < 5 && transparency < 255; i++) {
			cont = i;
			titlePath[12] = std::to_string(i)[0];
			title.loadFromFile(titlePath);
			titleSprite.setTexture(title);

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
				return;

			for (int k = 0; k < 3 && transparency < 255; k++) {
				titleSprite.setColor(sf::Color(titleSprite.getColor().r, titleSprite.getColor().g, titleSprite.getColor().b, transparency));
				window.clear();
				window.draw(titleSprite);
				window.display();
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
					return;
				Sleep(20);
				transparency += 5;
			}
		}
	}

	transparency = 255; //Start again from fully solid to 0, where image becomes transparent again

	while (transparency > 0) {
		for (int i = cont + 1; i < 5 && transparency > 0; i++) {
			cont = 0;
			titlePath[12] = std::to_string(i)[0];
			title.loadFromFile(titlePath);
			titleSprite.setTexture(title);

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
				return;

			if (!pause) {
				Sleep(20);
				window.clear();
				window.draw(titleSprite);
				window.display();
				continue;
			}

			for (int k = 0; k < 3 && transparency > 0; k++) {
				titleSprite.setColor(sf::Color(titleSprite.getColor().r, titleSprite.getColor().g, titleSprite.getColor().b, transparency));
				window.clear();
				window.draw(titleSprite);
				window.display();
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
					return;
				Sleep(20);
				transparency -= 5;
			}
		}
		pause = 1; //Changes image 5 times before continuing again	
	}

	Sleep(500);
}

void scalePositionButtons() {
	hangmanSprite.scale(desktop.height * 0.75 / hangmanSprite.getGlobalBounds().height, desktop.height * 0.75 / hangmanSprite.getGlobalBounds().height);
	playAgainSprite.scale(scale, scale);
	bgSprite.scale(desktop.width * 1.0 / bgSprite.getLocalBounds().width, desktop.width * 1.0 / bgSprite.getLocalBounds().width);
	ropeSprite.scale(scale, scale);
	playSprite.scale(scale, scale);
	exitSprite.scale(scale, scale);
	instrSprite.scale(desktop.width * 1.0 / instrSprite.getLocalBounds().width, desktop.width * 1.0 / instrSprite.getLocalBounds().width);
	instructionsSprite.scale(scale, scale);
	rtrnSprite.scale(scale, scale);
	noteSprite.scale(scale, scale);
	creditSprite.scale(scale, scale);
	credits.setScale(scale, scale);
	creditsHead.setScale(scale, scale);
	triesLeft.scale(scale, scale);
	categ.scale(scale, scale);
	guessObject.scale(scale, scale);
	entered.scale(scale, scale);
	winObject.scale(scale, scale);
	loseObject.scale(scale, scale);
	loseWord.scale(scale, scale);

	float midY = desktop.height / 2.0;
	gameHeading.setPosition(desktop.width / 2.0 - gameHeading.getLocalBounds().width / 2, 0.f);
	noteSprite.setPosition(desktop.width - noteSprite.getGlobalBounds().width, 0);
	playSprite.setPosition(desktop.width / 2.0 - playSprite.getGlobalBounds().width / 2.0, midY); //Moves half the length of image to the left of desktop center, so the center of image aligns with center of desktop
	instructionsSprite.setPosition(desktop.width / 2.0 - instructionsSprite.getGlobalBounds().width / 2.0, midY + playSprite.getGlobalBounds().height + 10);
	exitSprite.setPosition(playSprite.getPosition().x, instructionsSprite.getPosition().y + instructionsSprite.getGlobalBounds().height + 10);
	rtrnSprite.setPosition(0, desktop.height - rtrnSprite.getGlobalBounds().height);
	creditSprite.setPosition(playSprite.getPosition().x + playSprite.getGlobalBounds().width - creditSprite.getGlobalBounds().width, exitSprite.getPosition().y);
	creditsHead.setPosition(desktop.width / 2.0 - creditsHead.getGlobalBounds().width / 2, desktop.height * 0.33);
	credits.setPosition(desktop.width / 2.0 - credits.getGlobalBounds().width / 2, creditsHead.getPosition().y + 100.f);
}

void exitProg() {
	if (event.type == sf::Event::Closed || sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
		window.close();
}

void minimize() {
	int temp = desktop.width;
	desktop.width = fullscreen.width;
	fullscreen.width = temp;

	temp = desktop.height;
	desktop.height = fullscreen.height;
	fullscreen.height = temp;

	if (!isFullscreen) {
		window.close();
		window.create(sf::VideoMode(desktop.width, desktop.height), "HANGMAN", sf::Style::Fullscreen);
		isFullscreen = 1;
		Sleep(40);
	}

	else {
		window.close();
		window.create(sf::VideoMode(desktop.width, desktop.height), "HANGMAN");
		isFullscreen = 0;
		Sleep(40);
	}

	scale = desktop.width * 1.0 / fullscreen.width;

	scalePositionButtons();
	setText();
}

void highlightButtons() {
	sf::Vector2i pos = sf::Mouse::getPosition(window);

	if (exitSprite.getGlobalBounds().contains(static_cast<sf::Vector2f>(pos)))
		exiT.loadFromFile("Hangman\\ExitBorder.png");
	else
		exiT.loadFromFile("Hangman\\Exit.png");

	if (creditSprite.getGlobalBounds().contains(static_cast<sf::Vector2f>(pos)))
		credit.loadFromFile("Hangman\\CreditsBorder.png");
	else
		credit.loadFromFile("Hangman\\Credits.png");

	if (playSprite.getGlobalBounds().contains(static_cast<sf::Vector2f>(pos)))
		play.loadFromFile("Hangman\\PlayBorder.png");
	else
		play.loadFromFile("Hangman\\Play.png");

	if (instructionsSprite.getGlobalBounds().contains(static_cast<sf::Vector2f>(pos)))
		instructions.loadFromFile("Hangman\\InstructionsBorder.png");
	else
		instructions.loadFromFile("Hangman\\Instructions.png");

	if (rtrnSprite.getGlobalBounds().contains(static_cast<sf::Vector2f>(pos)))
		rtrn.loadFromFile("Hangman\\ReturnBorder.png");
	else
		rtrn.loadFromFile("Hangman\\Return.png");

	if (playAgainSprite.getGlobalBounds().contains(static_cast<sf::Vector2f>(pos)))
		playAgain.loadFromFile("Hangman\\PlayAgainBorder.png");
	else
		playAgain.loadFromFile("Hangman\\PlayAgain.png");

	exitSprite.setTexture(exiT);
	creditSprite.setTexture(credit);
	playSprite.setTexture(play);
	instructionsSprite.setTexture(instructions);
	rtrnSprite.setTexture(rtrn);
	playAgainSprite.setTexture(playAgain);
}

void checkEventMenu() {
	sf::Vector2i pos;
	cursorSprite.setPosition(static_cast<sf::Vector2f>(sf::Mouse::getPosition(window)));
	window.draw(cursorSprite);
	if (event.type == sf::Event::Closed)
		window.close();

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::F11)) {
		minimize();
	}

	if (event.type == event.MouseMoved || showCredits) {
		highlightButtons();
	}

	if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
	{
		pos = sf::Mouse::getPosition(window);

		if ((instructionsSprite.getGlobalBounds().contains(static_cast<sf::Vector2f>(pos)) || playSprite.getGlobalBounds().contains(static_cast<sf::Vector2f>(pos)) || exitSprite.getGlobalBounds().contains(static_cast<sf::Vector2f>(pos)) || creditSprite.getGlobalBounds().contains(static_cast<sf::Vector2f>(pos))) && showButtons)
			clickSound.play();

		if (showButtons)
		{
			if (exitSprite.getGlobalBounds().contains(static_cast<sf::Vector2f>(pos)))
				window.close();

			if (playSprite.getGlobalBounds().contains(static_cast<sf::Vector2f>(pos)))
			{
				showButtons = false;
				while (playGame());
			}

			showButtons = true;
		}

		if (noteSprite.getGlobalBounds().contains(static_cast<sf::Vector2f>(pos)))
		{
			clickSound.play();
			if (musicPlaying) {
				music.pause();
				musicPlaying = 0;
				note.loadFromFile("Hangman\\noNote.png");
			}
			else {
				music.play();
				musicPlaying = 1;
				note.loadFromFile("Hangman\\Note.png");
			}
		}

		if (instructionsSprite.getGlobalBounds().contains(static_cast<sf::Vector2f>(pos)))
		{
			rtrnSprite.setPosition(0, desktop.height - rtrnSprite.getGlobalBounds().height);
			showInstr = true;
			showButtons = false;
		}

		if (showInstr && !showButtons && rtrnSprite.getGlobalBounds().contains(static_cast<sf::Vector2f>(pos)))
		{
			clickSound.play();
			showInstr = false;
			showButtons = true;
		}

		if (creditSprite.getGlobalBounds().contains(static_cast<sf::Vector2f>(pos)))
		{
			showCredits = true;
			showButtons = false;
		}
	}
}

void printCredits() {
	sf::Vector2i pos;
	rtrnSprite.setPosition(0, desktop.height - rtrnSprite.getGlobalBounds().height);
	creditsHead.setPosition(desktop.width / 2.0 - creditsHead.getGlobalBounds().width / 2, desktop.height * 0.33);
	credits.setPosition(desktop.width / 2.0 - credits.getGlobalBounds().width / 2, creditsHead.getPosition().y * 1.4);
	while (credits.getGlobalBounds().height + credits.getPosition().y + 50 > 0) {
		pos = sf::Mouse::getPosition(window);

		if (rtrnSprite.getGlobalBounds().contains(static_cast<sf::Vector2f>(pos))) {
			rtrn.loadFromFile("Hangman\\ReturnBorder.png");
		}

		else
			rtrn.loadFromFile("Hangman\\Return.png");

		if (rtrnSprite.getGlobalBounds().contains(static_cast<sf::Vector2f>(pos)) && sf::Mouse::isButtonPressed(sf::Mouse::Left))
			break;

		rtrnSprite.setTexture(rtrn);
		window.clear();
		window.draw(bgSprite);
		window.draw(creditsHead);
		window.draw(credits);
		window.draw(rtrnSprite);
		window.display();
		credits.setPosition(credits.getPosition().x, credits.getPosition().y - 1.5);
		creditsHead.setPosition(creditsHead.getPosition().x, creditsHead.getPosition().y - 1.5);
		Sleep(10);
	}
}

void printMenu() {
	window.clear();
	window.draw(bgSprite);
	if (showButtons)
	{
		window.draw(playSprite);
		window.draw(instructionsSprite);
		window.draw(exitSprite);
		window.draw(noteSprite);
		window.draw(creditSprite);
		window.draw(gameHeading);
		window.draw(ropeSprite);
	}

	if (showInstr)
	{
		window.draw(instrSprite);
		window.draw(rtrnSprite);
	}

	if (showCredits) {
		printCredits();
		clickSound.play();
		showCredits = false;
		showButtons = true;
	}
	window.display();
}

void displayData() {
	window.clear();
	window.draw(bgSprite);
	window.draw(hangmanSprite);
	window.draw(triesLeft);
	window.draw(guessObject);
	window.draw(entered);
	window.draw(categ);
	window.display();
}

char keyPress() {
	if (event.key.code == sf::Keyboard::A)
		return 'a';
	if (event.key.code == sf::Keyboard::B)
		return 'b';
	if (event.key.code == sf::Keyboard::C)
		return 'c';
	if (event.key.code == sf::Keyboard::D)
		return 'd';
	if (event.key.code == sf::Keyboard::E)
		return 'e';
	if (event.key.code == sf::Keyboard::F)
		return 'f';
	if (event.key.code == sf::Keyboard::G)
		return 'g';
	if (event.key.code == sf::Keyboard::H)
		return 'h';
	if (event.key.code == sf::Keyboard::I)
		return 'i';
	if (event.key.code == sf::Keyboard::J)
		return 'j';
	if (event.key.code == sf::Keyboard::K)
		return 'k';
	if (event.key.code == sf::Keyboard::L)
		return 'l';
	if (event.key.code == sf::Keyboard::M)
		return 'm';
	if (event.key.code == sf::Keyboard::N)
		return 'n';
	if (event.key.code == sf::Keyboard::O)
		return 'o';
	if (event.key.code == sf::Keyboard::P)
		return 'p';
	if (event.key.code == sf::Keyboard::Q)
		return 'q';
	if (event.key.code == sf::Keyboard::R)
		return 'r';
	if (event.key.code == sf::Keyboard::S)
		return 's';
	if (event.key.code == sf::Keyboard::T)
		return 't';
	if (event.key.code == sf::Keyboard::U)
		return 'u';
	if (event.key.code == sf::Keyboard::V)
		return 'v';
	if (event.key.code == sf::Keyboard::W)
		return 'w';
	if (event.key.code == sf::Keyboard::X)
		return 'x';
	if (event.key.code == sf::Keyboard::Y)
		return 'y';
	if (event.key.code == sf::Keyboard::Z)
		return 'z';
	else
		return '.';
}

void checkInput() {
	char input = keyPress();
	int temp = count;
	for (int i = 0; i < guess.size(); i++) {
		if (std::tolower(input) == std::tolower(targetWord[i])) {
			guess[i] = targetWord[i];
			targetWord[i] = '*';
			count++;
		}
	}

	if (j < 7 && temp == count) {
		guessed[k] = input;
		k = k + 3;
	}

	if (count == targetWord.length()) {
		end = 1;
	}

	if (temp == count) {
		j++;
	}
}

void setData() {
	if (j < 8) {
		std::string turns, num, path;
		num = std::to_string(j);
		path = "Hangman\\x.png";
		path[8] = num[0];
		num = std::to_string(7 - j);
		turns = "Tries Left: x";
		turns[12] = num[0];
		hangman.loadFromFile(path);
		hangmanSprite.setTexture(hangman);
		hangmanSprite.setPosition(20, 100);
		triesLeft.setString(turns);
	}
	entered.setString(guessed);
	guessObject.setString(guess);
}

void setText() {
	triesLeft.setFont(chalk);
	triesLeft.setCharacterSize(70);
	triesLeft.setPosition(50.f, 0.f);

	categ.setFont(chalk);
	categ.setCharacterSize(70);
	categ.setString(category);
	categ.setPosition(desktop.width - categ.getGlobalBounds().width - 50, 0.f);

	guessObject.setFont(chalk);
	guessObject.setCharacterSize(60);
	guessObject.setLetterSpacing(500.0 / (50 + guess.length()));
	guessObject.setString(guess);
	guessObject.setPosition(0.44 * desktop.width, 0.77 * desktop.height);

	entered.setFont(chalk);
	entered.setCharacterSize(70);
	entered.setString(guessed);
	entered.setPosition(desktop.width * 0.65, desktop.height * 0.25);

	winObject.setFont(chalk);
	winObject.setCharacterSize(85);
	winObject.setString("You win!");
	winObject.setPosition((desktop.width - winObject.getGlobalBounds().width) / 2, 20);

	loseObject.setFont(chalk);
	loseObject.setCharacterSize(85);
	loseObject.setString("You lose!");
	loseObject.setPosition((desktop.width - loseObject.getGlobalBounds().width) / 2, 20);

	loseWord.setFont(chalk);
	loseWord.setCharacterSize(70);
	loseWord.setString("Your original word was " + originalWord);
	loseWord.setPosition((desktop.width - loseWord.getGlobalBounds().width) / 2, desktop.height - loseWord.getGlobalBounds().height-20);
}
bool endScreen() {
	rtrnSprite.setPosition((desktop.width - rtrnSprite.getGlobalBounds().width) / 2, (desktop.height - rtrnSprite.getGlobalBounds().height) / 2);
	playAgainSprite.setPosition(rtrnSprite.getPosition().x, rtrnSprite.getPosition().y + playAgainSprite.getGlobalBounds().height + 20);
	while (1) {
		window.pollEvent(event);
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
			pos = sf::Mouse::getPosition(window);
			if (rtrnSprite.getGlobalBounds().contains(static_cast<sf::Vector2f>(pos))) {
				Sleep(200);
				return 0;
			}

			if (playAgainSprite.getGlobalBounds().contains(static_cast<sf::Vector2f>(pos)))
				return 1;
		}

		if (event.type == event.MouseMoved) {
			pos = sf::Mouse::getPosition(window);
			if (rtrnSprite.getGlobalBounds().contains(static_cast<sf::Vector2f>(pos)))
				rtrn.loadFromFile("Hangman\\ReturnBorder.png");
			else
				rtrn.loadFromFile("Hangman\\Return.png");

			if (playAgainSprite.getGlobalBounds().contains(static_cast<sf::Vector2f>(pos)))
				playAgain.loadFromFile("Hangman\\PlayAgainBorder.png");
			else
				playAgain.loadFromFile("Hangman\\PlayAgain.png");

			rtrnSprite.setTexture(rtrn);
			playAgainSprite.setTexture(playAgain);
		}

		window.clear();
		window.draw(bgSprite);
		if (end) {
			window.draw(winObject);
		}

		else {
			window.draw(loseWord);
			window.draw(loseObject);
		}
		window.draw(playAgainSprite);
		window.draw(rtrnSprite);
		window.display();
	}
}

bool playGame() {
	i = 0, j = 0, count = 0, end = 0, k = 17, guessed = "Letters Guessed:\n                                               ", triesLeft.setString("Tries Left: 7");
	sf::Vector2i pos;

	targetWord = Word(category);
	guess = targetWord;
	originalWord = targetWord;
	std::cout << originalWord;
	for (int l = 0; l < targetWord.length(); l++) {
		guess[l] = '_';
	}

	setText();
	setData();

	while (window.isOpen())
	{
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::F11)) {
				std::cout << scale << " ";
				minimize();
				std::cout << scale << " ";
			}



			if (event.type == event.KeyReleased && keyPress() != '.' && !end && j < 7) {
				checkInput();
				setData();
				displayData();
				std::cout << j;

				if (end || j >= 7) {
					Sleep(500);
					if (endScreen())
						return 1;
					else
						return 0;
				}
			}

			else
				displayData();
		}


	}
}
