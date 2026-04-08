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

void Inventory::remove(int itemNum) {
	itemNum -= 1;
	delete items[itemNum];
	items.erase(items.begin() + itemNum);

}

void Inventory::clear() {

	for (Item* item : items) {

		delete item;
		
	}

	items.clear();

}

