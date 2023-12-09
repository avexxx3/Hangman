#include <string>
#include <cstdlib>
#include <time.h>

std::string Animal() {
    std::string array[50] = { "Horse", "Tiger", "Lion", "Elephant", "Turtle", "Crocodile", "Rabbit", "Dolphin", "Frog", "Whale", "Eagle", "Fox", "Goat", "Monkey", "Antelope", "Bat", "Giraffe", "Panda", "Cobra", "Shark", "Camel", "Hawk", "Deer", "Hippopotamus", "Jaguar", "Kangaroo", "Iguana", "Llama", "Lizard", "Koala", "Chameleon", "Chihuahua", "Wolf", "Zebra", "Possum", "Wombat", "Bison", "Buffalo", "Sheep", "Meerkat", "Mouse", "Sloth", "Owl", "Vulture", "Racoon", "Mole", "Snake"};
    srand(time(0));
	return array[rand() % 50];
}

std::string Country() {
    std::string array[146] = {
        "Afghanistan", "Albania", "Algeria", "Argentina", "Australia", "Austria", "Bangladesh", "Belgium", "Brazil", "Canada",
        "Chile", "China", "Colombia", "Croatia", "Cuba", "Denmark", "Egypt", "Finland", "France", "Germany",
        "Greece", "India", "Indonesia", "Iran", "Iraq", "Ireland", "Israel", "Italy", "Japan", "Kenya",
        "Mexico", "Netherlands", "NewZealand", "Nigeria", "Norway", "Pakistan", "Peru", "Philippines", "Poland", "Portugal",
        "Russia", "SaudiArabia", "SouthAfrica", "SouthKorea", "Spain", "Sweden", "Switzerland", "Turkey", "Ukraine", "UnitedKingdom",
        "UnitedStates"};
	srand(time(0));
    return array[rand() % 146];
}


std::string Fruits() {
    std::string array[30] = { "Apple", "Banana", "Orange", "Grapes", "Strawberry", "Watermelon", "Pineapple", "Mango", "Peach", "Pear", "Cherry", "Blueberry", "Raspberry", "Blackberry", "Kiwi", "Lemon", "Lime", "Coconut", "Pomegranate", "Avocado", "Plum", "Cranberry", "Fig", "Apricot", "Papaya", "Grapefruit", "Tangerine", "Melon", "Guava", "Lychee" };
    srand(time(0));
	return array[rand() % 30];
}


std::string Colors() {
    std::string array[25] = { "Red", "Blue", "Green", "Yellow", "Orange", "Purple", "Pink", "Brown", "Black", "White", "Gray", "Cyan", "Magenta", "Lavender", "Teal", "Maroon", "Gold", "Silver", "Turquoise", "Olive", "Violet", "Indigo", "Beige", "Coral", "Salmon" };
    srand(time(0));
	return array[rand() % 25];
}

std::string Sports() {
    std::string array[25] = { "Football", "Basketball", "Soccer", "Tennis", "Baseball", "Golf", "Swimming", "Volleyball", "Hockey", "Rugby", "Boxing", "Cycling", "Wrestling", "Athletics", "Cricket", "Badminton", "Skating", "Skiing", "Gymnastics", "TableTennis", "Archery", "Diving", "Surfing", "Squash", "Fencing" };
    srand(time(0));
	return array[rand() % 25];
}

std::string Professions() {
    std::string array[25] = { "Doctor", "Teacher", "Engineer", "Lawyer", "Chef", "Police", "Firefighter", "Artist", "Musician", "Writer", "Actor", "Nurse", "Scientist", "Athlete", "Pilot", "Dentist", "Journalist", "Programmer", "Entrepreneur", "Designer", "Veterinarian", "Electrician", "Plumber", "Mechanic", "Carpenter" };
    srand(time(0));
	return array[rand() % 25];
}

std::string FoodDrinks() {
    std::string array[25] = { "Pizza", "Burger", "Coffee", "Pasta", "Sandwich", "Sushi", "IceCream", "Cake", "Chocolate", "Salad", "Juice", "Tea", "Soup", "Steak", "Wine", "Beer", "Bread", "Taco", "Smoothie", "Pancake", "Lemonade", "Muffin", "Popcorn", "Donut", "Cupcake" };
    srand(time(0));
	return array[rand() % 25];
}

std::string Vehicles() {
    std::string array[25] = { "Car", "Motorcycle", "Bicycle", "Truck", "Bus", "Train", "Airplane", "Helicopter", "Boat", "Scooter", "Subway", "Taxi", "Van", "Ambulance", "Jet", "Ferry", "CruiseShip", "Segway", "Yacht", "RV", "Glider", "Zeppelin", "Skateboard", "GolfCart", "Spaceship" };
    srand(time(0));
	return array[rand() % 25];
}

std::string Space() {
    std::string array[25] = { "Sun", "Moon", "Earth", "Mars", "Saturn", "Jupiter", "Pluto", "Neptune", "Galaxy", "Comet", "Meteor", "Asteroid", "Nebula", "BlackHole", "Quasar", "Supernova", "Spaceship", "Rocket", "Cosmos", "Orbit", "Constellation", "Lunar", "Solar", "Interstellar", "Telescope" };
    srand(time(0));
	return array[rand() % 25];
}

std::string VideoGames() {
    std::string array[25] = { "Mario", "Zelda", "Pacman", "Tetris", "Minecraft", "Fortnite", "CallofDuty", "FIFA", "Pokemon", "Overwatch", "Tekken", "AssassinsCreed", "LeagueofLegends", "MortalKombat", "Sonic", "Halo", "GTA", "RedDead", "Fallout", "Pubg", "MetalSlug", "Battlefield", "Destiny", "CounterStrike", "ResidentEvil" };
    srand(time(0));
	return array[rand() % 25];
}
std::string Word(std::string& category) {
	srand(time(0));
	int num = rand() % 10;
	switch (num) {
	case 0:
		category = "Animals";
		return(Animal());

	case 1:
		category = "Countries";
		return(Country());

	case 2:
		category = "Fruits";
		return(Fruits());
	case 3:
		category = "Colors";
		return(Colors());
	case 4:
		category = "Sports";
		return(Sports());
	case 5:
		category = "Professions";
		return(Professions());
	case 6:
		category = "Food/Drinks";
		return(FoodDrinks());
	case 7:
		category = "Vehicles";
		return(Vehicles());
	case 8:
		category = "Space";
		return(Space());
	case 9:
		category = "Video Games";
		return(VideoGames());
	}
}