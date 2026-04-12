#include "ITEM.h"

//Constructor
Item::Item(std::string itemName, std::string itemType) {

	name = itemName;
	type = itemType;

}

//Position Getters
std::string Item::getName() {

	return name;

}

std::string Item::getType() {

	return type;

}
