#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>

void main()
{

    sf::RenderWindow window(sf::VideoMode(), "F-RAM", sf::Style::Fullscreen);

    sf::Texture background;
    background.loadFromFile("Hangman\\Base.png");
    
    sf::VideoMode desktop = sf::VideoMode::getDesktopMode();
    float scale = desktop.width / 1920.0;
    
    sf::Sprite sprite;
    sprite.setTexture(background);
    sprite.setScale(scale, scale);

    sf::Font chalk;
    chalk.loadFromFile("KGBrokenVesselsSketch.ttf");


    sf::Text text;
    text.setFont(chalk);
    text.setCharacterSize(70);
    text.setPosition(250.f, 0.f);
    text.setStyle(sf::Text::Bold);
    text.setString("Hangman");

    int i = 0;
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed || sf::Keyboard::isKeyPressed(sf::Keyboard::Escape) || i>7)
                window.close();

            if (event.type == sf::Event::KeyReleased) {
                std::string num = std::to_string(i);
                std::string path = "Hangman\\x.png";
                path[8] = num[0];
                num = std::to_string(7-i);
                std::string turns = "Turns left: x";
                turns[12] = num[0];
                background.loadFromFile(path);
                text.setString(turns);
                i++;
            }
        }
        window.clear();
        window.draw(sprite);
        window.draw(text);
        window.display();
    }
}