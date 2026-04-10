#include "ITEM.h"

//Constructor
Item::Item(std::string itemName) {

	name = itemName;

}

//Position Getters
std::string Item::getName() {

	return name;

}
