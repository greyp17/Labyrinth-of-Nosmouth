#include "Inventory.h"
#include "ITEM.h"
#include <vector>
#include <string>
#include <iostream>

void Inventory::interface() {

	std::cout << "Inventory: ";

	//loop printing out stack of items within the vector
	int i{0};
	for (Item* item : items) {
		i++;
		std::cout << "(" << i << ") ";
		std::cout << item->getName() << " ";

	}

	std::cout << "\n";

}

void Inventory::add(Item* item) {

	items.push_back(item);

}

// Need to add out of bounds testing and error...
void Inventory::remove(int itemNum) {
	itemNum -= 1;
	delete items[itemNum];
	items.erase(items.begin() + itemNum);

}

void Inventory::remove(std::string item) {

	int num = element(item);
	num += 1;
	remove(num);

}

void Inventory::clear() {

	for (Item* item : items) {

		delete item;
		
	}

	items.clear();

}

int Inventory::element(std::string itemName) {

	for (int i{ 0 }; i < items.size(); i++) {

		if ((items[i]->getName()) == itemName) {

			return i;

		}

	}

	std::cout << itemName << "not found.";
	return -1;

}

