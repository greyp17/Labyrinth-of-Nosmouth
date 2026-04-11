#include "POTION.h"
#include <iostream>

//Constructor
Potion::Potion(std::string itemName) : Item(itemName) {

	

}

//Member Functions

//Polymorphism Functions
void Potion::inspect() {

	//gives stats of weapon
	std::cout << "give potion stat";

}

void Potion::use() {

	//Tells user they must use in combat...
	std::string input = getName();
	std::cout << "Equipping " << input << "...\n";

}

//Getters
std::string Potion::getType() {

	return type;

}
