#include "ARMOR.h"

//Constructor
Armor::Armor(std::string itemName, int armorDefense) : Item(itemName) {

	defense = armorDefense;

}

//Getters
int Armor::getDefense() {

	return defense;

}

std::string Armor::getType() {

	return type;

}
