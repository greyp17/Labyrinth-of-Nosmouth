#include "ARMOR.h"
#include <iostream>

//Constructor
Armor::Armor(std::string itemName, int armorDefense) : Item(itemName) {

	defense = armorDefense;

}

//Member Functions

//Polymorphism Functions
void Armor::inspect() {

	//gives stats of weapon
	std::cout << "give armor stat";

}

void Armor::use() {

	//equips weapon
	std::string input = getName();
	std::cout << "Equipping " << input << "...\n";

}

//Getters
int Armor::getDefense() {

	return defense;

}

std::string Armor::getType() {

	return type;

}
