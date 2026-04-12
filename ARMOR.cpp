#include "ARMOR.h"
#include "PLAYER.h"
#include <iostream>

//Constructor
Armor::Armor(std::string itemName, std::string itemType, int armorDefense) : Item(itemName, itemType) {

	defense = armorDefense;

}

//Member Functions

//Polymorphism Functions
void Armor::inspect() {

	//gives stats of weapon
	std::cout << "Defense: " << defense << "\n";

}

void Armor::use(Player& player) {

	//equips weapon
	std::string input = getName();
	std::cout << "Equipping " << input << " armor...\n";
	player.setDefense(getDefense());

}

//Getters
int Armor::getDefense() {

	return defense;

}

