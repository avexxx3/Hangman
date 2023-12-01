#include <SFML/Graphics.hpp>
#include "Words.h"
#include <iostream>
#include <string>

void playGame()
{
    sf::VideoMode desktop = sf::VideoMode::getDesktopMode();
    sf::RenderWindow window(sf::VideoMode(desktop.width, desktop.height), "HANGMAN", sf::Style::Fullscreen);
    sf::Texture texture; sf::Sprite sprite; sf::Text data; sf::Text categ; sf::Text word; sf::Font font; sf::Event event; // Create all objects
    // word --> dashes being updated live as user inputs
    // data --> hangman text which then changes to turns left
    int j = 0, count = 0; //count is the number of correct alphabets
    bool end = 0, idk = 1; //idk = 1 means continue
    std::string category;
    std::string execution = Word(category); //execution contains the actual word
    execution[0] = tolower(execution[0]);
    std::string guess = execution; //guess is the string with dashes equal to word's letters

    for (int i = 0; i < execution.length(); i++) {
        guess[i] = '_';
    }

    createData(desktop, texture, sprite);

    font.loadFromFile("KGBrokenVesselsSketch.ttf"); //Create the font

    data.setFont(font);
    categ.setFont(font);
    word.setFont(font);

    std::cout << execution;

    setText(data, categ, word, category, guess);

    while (window.isOpen())
    {
        while (window.pollEvent(event))
        {
            // exitProg(i, event, window);


            //if (event.type == event.KeyReleased && keyPress(event)) //keypress returns the key pressed as a character
            //    idk = 1;

            if (event.type == event.KeyReleased && keyPress(event) != '.') {
                //check input
                char input = keyPress(event);
                int temp = count;
                std::cout << input;
                for (int i = 0; i < guess.size(); i++) {
                    if (input == execution[i]) {
                        std::cout << "Correct.\n";
                        guess[i] = execution[i];
                        execution[i] = '*';
                        count++;
                    }
                }

                if (count == execution.length()) {
                    end = 1;
                }

                if (temp == count) {
                    j++;
                }
                //set data
                if (event.type == sf::Event::KeyReleased && j < 8) {
                    std::string turns, num, path;
                    num = std::to_string(j);
                    path = "Hangman\\x.png";
                    path[41] = num[0];

                    if (7 - j != 0) {
                        num = std::to_string(7 - j);
                        turns = "Turns left: x";
                        turns[12] = num[0];
                    }

                    else
                        turns = "Game over!";

                    texture.loadFromFile(path);
                    data.setString(turns);
                }
                word.setString(guess);
            }

            //displayData(window, sprite, data, word, categ, i, end, idk);

            window.clear();
            window.draw(sprite);
            window.draw(data);
            if (end)
                data.setString("Congratulations!");
            if (idk) {
                window.draw(categ);
                window.draw(word);
            }
            window.display();

            if (end || j>=8) {
                window.close();
            }
        }
    }
}

int main()
{
    sf::VideoMode desktop = sf::VideoMode::getDesktopMode();

    sf::RenderWindow window(sf::VideoMode(desktop.width, desktop.height), "HANGMAN", sf::Style::Fullscreen);

    sf::Texture bg;
    bg.loadFromFile("Hangman\\Base.png");

    float scale = desktop.width / 1920.0; // 1920 is width of images to be put fullscreen

    sf::Sprite bgSprite;
    bgSprite.setTexture(bg);
    bgSprite.setScale(scale, scale);

    sf::Text data; sf::Text categ; sf::Text word; //text objects

    //settings buttons

    sf::Texture play;
    play.loadFromFile("Hangman\\Play.png");
    sf::Sprite playSprite(play);
    playSprite.scale(scale, scale);
    sf::Texture instructions;
    instructions.loadFromFile("Hangman\\Instructions.png");
    sf::Sprite instructionsSprite(instructions);
    instructionsSprite.scale(scale, scale);
    sf::Texture exit;
    exit.loadFromFile("Hangman\\Exit.png");
    sf::Sprite exitSprite(exit);
    exitSprite.scale(scale, scale);
    sf::Texture instr;
    instr.loadFromFile("Hangman\\7.png");
    sf::Sprite instrSprite(instr);
    instrSprite.scale(scale, scale);
    sf::Texture rtrn;
    rtrn.loadFromFile("Hangman\\Play.png");
    sf::Sprite rtrnSprite(rtrn);

    //set buttons' positions

    playSprite.setPosition(575, 550);
    instructionsSprite.setPosition(575, 650);
    exitSprite.setPosition(575, 750);
    rtrnSprite.setPosition(25, 950);



    //setting up Text

    sf::Font chalk;
    chalk.loadFromFile("KGBrokenVesselsSketch.ttf");
    sf::Text text;
    text.setFont(chalk);
    text.setCharacterSize(85);
    text.setPosition(600.f, 0.f);
    text.setStyle(sf::Text::Bold);
    text.setString("Hangman");

    int i = 0;
    bool showInstr=false;
    bool showButtons=true;
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed || sf::Keyboard::isKeyPressed(sf::Keyboard::Escape) || i > 7)
                window.close();

            if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
            {
                sf::Vector2i pos = sf::Mouse::getPosition(window);
                if(showButtons)
                    if (exitSprite.getGlobalBounds().contains(static_cast<sf::Vector2f>(pos)))
                        window.close();
                if (instructionsSprite.getGlobalBounds().contains(static_cast<sf::Vector2f>(pos)))
                {
                    showInstr = true;
                    showButtons = false;
                }
                    
                if (showInstr && !showButtons && rtrnSprite.getGlobalBounds().contains(static_cast<sf::Vector2f>(pos)))
                {
                    showInstr = false;
                    showButtons = true;
                }
                    
                if (playSprite.getGlobalBounds().contains(static_cast<sf::Vector2f>(pos)))
                    playGame();
            }
        }
        window.clear();
        window.draw(bgSprite);
        if (showButtons)
        {
            window.draw(playSprite);
            window.draw(instructionsSprite);
            window.draw(exitSprite);
        }   
        window.draw(text);

        if (showInstr)
        {
            window.clear();
            window.draw(instrSprite);
            window.draw(rtrnSprite);
        }
        window.display();
    }
    return 0;
}
