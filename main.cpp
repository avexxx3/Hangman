#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network/IpAddress.hpp>
#include "Functions.h"
#include <iostream>
#include <string>

int main() {
	createObjects();

	scalePositionButtons();

	//showTitle();

	while (window.isOpen()) {

		while (window.pollEvent(event)) {
			checkEventMenu();
		}
		printMenu();
	}

	return 0;
}