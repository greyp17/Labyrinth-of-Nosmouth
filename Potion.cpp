#include "POTION.h"
#include "PLAYER.h"
#include "Inventory.h"
#include <iostream>

//Constructor
Potion::Potion(std::string itemName, std::string itemType) : Item(itemName, itemType) {

	

}

//Member Functions

//Polymorphism Functions
void Potion::inspect() {
	
	std::string inputType = getType();
	std::string input = getName();

	//gives stats of potion
	std::cout << "Potion Effect: ";

	if (input == "healing") {

		std::cout << "Heals the player 15 health.\n";

	}
	else if (input == "defense") {

		std::cout << "Reduces incoming damage by 5 for 3 turns.\n";

	}
	else if (input == "accuracy") {

		std::cout << "Increases hit chance by 20% for 3 turns.\n";

	}
	else if (input == "damage") {

		std::cout << "Adds +4 damage for 3 turns.\n";

	}

}

void Potion::use(Player& player) {

	std::cout << "Can't equip potions. Can only be used in combat.\n";

}

std::string Potion::drink(Player& player) {
	
	std::string input = getName();

	if (input == "healing") {

		player.healHealth(15);

	}
	else if (input == "defense") {

		player.setDefense(player.getDefense() + 5);

	}
	else if (input == "damage") {

		player.setDamage(player.getDamage() + 4);

	}
	else if (input == "accuracy") {

		player.setAccuracy(player.getAccuracy() + 2);

	}
	std::cout << "Drinking " << input << " potion...\n";
	return getName();
}

//Getters

