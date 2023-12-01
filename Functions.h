#include <SFML/Graphics.hpp>
#include <string>
#include <iostream>

void setData(int &i, sf::Texture &texture, sf::Text &text, sf::Event &event) {
    if (i < 8) {
        std::string turns, num, path;
        num = std::to_string(i);
        path = "Hangman\\x.png";
        path[8] = num[0];

        if (7 - i != 0) {
            num = std::to_string(7 - i);
            turns = "Tries left: x";
            turns[12] = num[0];
        }

        else
            turns = "Game over!\n\n\n\n\n\n\n\nPress ESC to return to main menu!";

        texture.loadFromFile(path);
        text.setString(turns);
    }
}

void exitProg(int i, sf::Event event, sf::RenderWindow &window) {
    if (event.type == sf::Event::Closed || sf::Keyboard::isKeyPressed(sf::Keyboard::Escape) || (event.type == sf::Event::KeyReleased && i >= 8))
        window.close();
}

void createData(sf::VideoMode desktop, sf::Texture &texture, sf::Sprite &sprite) {
    float scale = desktop.width / 1920.0; //Find the ratio between your display and the of the images we've used (They're all created with respect to 1920x1080)

    texture.loadFromFile("Hangman\\0.png"); //Create chalkboard as a texture

    sprite.setTexture(texture); //Paste the texture onto a sprite

    sprite.setScale(scale, scale); //Scale up/down the image to fit the resolution
}

void displayData(sf::RenderWindow& window, sf::Sprite sprite, sf::Text data, sf::Text word, sf::Text categ, int i, bool end) {

    window.clear();
    window.draw(sprite);
    window.draw(data);
    window.draw(categ);
    window.draw(word);
    window.display();
}

void setText(sf::Text& data, sf::Text& categ, sf::Text& word, std::string category, std::string guess) {

    data.setCharacterSize(70);
    data.setPosition(50.f, 0.f);
    data.setStyle(sf::Text::Bold);
    data.setString("Tries Left: 7");

    categ.setCharacterSize(70);
    categ.setPosition(1000.f, 0.f);
    categ.setStyle(sf::Text::Bold);
    categ.setString(category);

    word.setCharacterSize(50);
    word.setPosition(600.f, 550.f);
    word.setStyle(sf::Text::Bold);
    word.setLetterSpacing(10.f);
    word.setString(guess);
}

char keyPress(sf::Event event) {
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

void checkInput(int& i, std::string& guess, std::string& execution, sf::Event event, int &count, bool &end) {
    char input = keyPress(event);
    int temp = count;
    std::cout << input;
    for (int i = 0; i < guess.size(); i++) {
        if (input == execution[i]) {
            guess[i] = execution[i];
            execution[i] = '*';
            count++;
        }
    }

    if (count == execution.length()) {
        end = 1;
    }

    if (temp == count) {
        i++;
    }
}
