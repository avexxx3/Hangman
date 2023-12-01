#include <string>
#include <cstdlib>
#include <time.h>

std::string Animal() {
	std::string array[100] = { "Horse", "Donkey", "Tiger", "Lion", "Panther", "Leopard", "Cheetah", "Bear", "Elephant", "Capybara", "Turtle", "Tortoise", "Crocodile", "Rabbit", "Porcupine", "Hare", "Pigeon", "Albatross", "Crow", "Fish", "Dolphin", "Frog", "Whale", "Alligator", "Eagle", "Squirrel", "Ostrich", "Fox", "Goat", "Jackal", "Emu", "Armadillo", "Eel", "Goose", "Rattlesnake", "Wolf", "Beagle", "Gorilla", "Chimpanzee", "Monkey", "Beaver", "Orangutan", "Antelope", "Bat", "Badger", "Giraffe", "Hermit Crab", "Giant Panda", "Hamster", "Cobra", "Shark", "Camel", "Hawk", "Deer", "Chameleon", "Hippopotamus", "Jaguar", "Chihuahua", "King Cobra", "Ibex", "Lizard", "Koala", "Kangaroo", "Iguana", "Llama", "Chinchillas", "Dodo", "Jellyfish", "Rhinoceros", "Hedgehog", "Zebra", "Possum", "Wombat", "Bison", "Bull", "Buffalo", "Sheep", "Meerkat", "Mouse", "Otter", "Sloth", "Owl", "Vulture", "Flamingo", "Racoon", "Mole", "Duck", "Swan", "Lynx", "Monitor lizard", "Elk", "Boar", "Lemur", "Mule", "Baboon", "Mammoth", "Whale", "Rat", "Snake", "Peacock" };
	srand(time(0));
	return array[rand() % 100];
}

std::string Country() {
	std::string array[156] = { "Afghanistan", "Albania", "Algeria", "Andorra", "Angola", "Argentina", "Armenia", "Australia", "Austria", "Azerbaijan", "Bahrain", "Bangladesh", "Barbados", "Belarus", "Belgium", "Belize", "Benin", "Bhutan", "Bolivia", "Botswana", "Brazil", "Brunei", "Bulgaria", "Burundi", "Cambodia", "Cameroon", "Canada", "Chad", "Chile", "China", "Colombia", "Comoros", "Croatia", "Cuba", "Cyprus", "Denmark", "Djibouti", "Dominica", "Ecuador", "Egypt", "Eritrea", "Estonia", "Eswatini", "Ethiopia", "Fiji", "Finland", "France", "Gabon", "Georgia", "Germany", "Ghana", "Greece", "Grenada", "Guatemala", "Guinea", "Guinea-Bissau", "Guyana", "Haiti", "Honduras", "Hungary", "Iceland", "India", "Indonesia", "Iran", "Iraq", "Ireland", "Italy", "Jamaica", "Japan", "Jordan", "Kazakhstan", "Kenya", "Kiribati", "Kosovo", "Kuwait", "Kyrgyzstan", "Laos", "Latvia", "Lebanon", "Lesotho", "Liberia", "Libya", "Liechtenstein", "Lithuania", "Luxembourg", "Madagascar", "Malawi", "Malaysia", "Maldives", "Mali", "Malta", "Mauritania", "Mauritius", "Mexico", "Moldova", "Monaco", "Mongolia", "Montenegro", "Morocco", "Mozambique", "Namibia", "Nauru", "Nepal", "Netherlands", "Nicaragua", "Niger", "Nigeria", "Norway", "Oman", "Pakistan", "Palau", "Panama", "Paraguay", "Peru", "Philippines", "Poland", "Portugal", "Qatar", "Romania", "Russia", "Rwanda", "Samoa", "Senegal", "Serbia", "Seychelles", "Singapore", "Slovakia", "Slovenia", "Somalia", "Spain", "Sudan", "Suriname", "Sweden", "Switzerland", "Syria", "Taiwan", "Tajikistan", "Tanzania", "Thailand", "Togo", "Tonga", "Tunisia", "Turkey", "Turkmenistan", "Tuvalu", "Uganda", "Ukraine", "Uruguay", "Uzbekistan", "Vanuatu", "Venezuela", "Vietnam", "Yemen", "Zambia", "Zimbabwe" };
	srand(time(0));
	return array[rand() % 156];
}

std::string Fruits() {
	std::string array[86] = { "Apple", "Apricot", "Avocado", "Banana", "Blackberry", "Blueberry", "Cantaloupe", "Cherry", "Coconut", "Cranberry", "Date", "Dragonfruit", "Elderberry", "Fig", "Grape", "Grapefruit", "Guava", "Honeydew", "Jackfruit", "Kiwi", "Kumquat", "Lemon", "Lime", "Lychee", "Mango", "Mulberry", "Nectarine", "Orange", "Papaya", "Peach", "Pear", "Pineapple", "Plum", "Pomegranate", "Quince", "Raspberry", "Redcurrant", "Starfruit", "Strawberry", "Tangerine", "Watermelon", "Acerola", "Appleberry", "Blackcurrant", "Boysenberry", "Carambola", "Cherimoya", "Cranberry", "Currant", "Dewberry", "Durian", "Elderberry", "Feijoa", "Gooseberry", "Huckleberry", "Jambul", "Kumquat", "Longan", "Loquat", "Lychee", "Mandarin", "Mamey", "Marula", "Medlar", "Mombin", "Mulberry", "Orange", "Papaw", "Pawpaw", "Persimmon", "Pineberry", "Pineapple", "Plum", "Pomegranate", "Pomelo", "Quince", "Redcurrant", "Rhubarb", "Soursop", "Starfruit", "Tamarillo", "Chayote", "Cherimoya", "Jackfruit", "Loquat", "Serviceberry" };
	srand(time(0));
	return array[rand() % 86];
}

std::string Word(std::string& category) {
	srand(time(0));
	int num = rand() % 3;
	switch (num) {
	case 0:
		category = "Animal";
		return(Animal());

	case 1:
		category = "Country";
		return(Country());

	case 2:
		category = "Fruits";
		return(Fruits());
	}
}