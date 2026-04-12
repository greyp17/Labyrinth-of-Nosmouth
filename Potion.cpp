#include "POTION.h"
#include "PLAYER.h"
#include <iostream>

//Constructor
Potion::Potion(std::string itemName, std::string itemType) : Item(itemName, itemType) {

	

}

//Member Functions

//Polymorphism Functions
void Potion::inspect() {
	
	std::string inputType = getType();

	//gives stats of potion
	std::cout << "Potion Effect: " << inputType << "\n";
	std::cout << "";

}

void Potion::use(Player& player) {

	std::cout << "Can't equip potions. Can only be used in combat.\n";

}

void Potion::drink(Character& player) {

	//Tells user they must use in combat...
	std::string input = getName();

	if (input == "healing") {

		player.healHealth(15);

	}
	else if (input == "defense") {

		

	}
	else if (input == "damage") {

		

	}
	else if (input == "accuracy") {

		

	}
	std::cout << "Equipping " << input << "...\n";

}

//Getters

