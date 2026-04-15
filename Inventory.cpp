#include "Inventory.h"
#include "ITEM.h"
#include "PLAYER.h"
#include "CHARACTER.h"
#include "LootTable.h"
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include <cctype>

//Deconstructor
Inventory::~Inventory() {

	clear();

}

void Inventory::interface(Player& player) {

	std::string input;
	int inputNum;
	int invLoop{1};

	while (invLoop == 1) {

		display();
		std::cout << "Commands: Exit, Inspect, Equip, Stats, Remove\n";
		std::cin >> input;
		input = stringLower(input);

		if (input == "exit") {

			// exit from inventory interface
			invLoop = 0;
			continue;

		}
		else if (input == "inspect") {

			// display stats of item
			std::cout << "Which item? ";
			std::cin >> input;

			// With processInput now have the index for the item.
			inputNum = processInput(input);
			if (inputNum == -1) {
				continue;
			}
			input = items.at(inputNum)->getName();
			std::string inputType = items.at(inputNum)->getType();

			std::cout << "Displaying stats for " << input << " " << inputType << "...\n";
			items.at(inputNum)->inspect();

		}
		else if (input == "equip") {

			// call function to use item. add polymorphism to handle usage of potions vs other items
			std::cout << "Which item? ";
			std::cin >> input;

			// With processInput now have the index for the item.
			inputNum = processInput(input);
			if (inputNum == -1) {
				continue;
			}
			input = items.at(inputNum)->getName();
			std::string inputType = items.at(inputNum)->getType();

			if (inputType == "armor") {

				armor = input;

			}
			else if (inputType == "weapon") {

				weapon = input;

			}

			items.at(inputNum)->use(player);

		}
		else if (input == "remove") {

			// Remove item from inventory
			std::cout << "Which item? ";
			std::cin >> input;

			// Call remove function...
			remove(input);

		}
		else if (input == "stats") {

			currentAccuracy = player.getAccuracy();
			currentDamage = player.getDamage();
			currentDefense = player.getDefense();

			std::cout << "Currently Equipped: Armor: " << armor << ", Weapon: " << weapon << "\n";
			std::cout << "Stats: \nAccuracy: " << currentAccuracy << "\nDamage: " << currentDamage <<
						"\nDefense: " << currentDefense << "\n";

		}
		else if (input == "dev") {

			std::cout << "Commands: Add\n";
			std::cin >> input;
			input = stringLower(input);

			if (input == "add") {

				player.invAdd(generateLoot());

			}

		}
		else {

			std::cout << "Not valid command.\n";
			continue;

		}



	}

}

void Inventory::remove(std::string input) {

	int inputNum = processInputSafe(input);
	if (inputNum == -1) {
		return;
	}

	remove(inputNum);
}

void Inventory::display() {

	std::cout << "Inventory: ";

	if (items.size() == 0) {

		std::cout << "(empty)\n";

	}
	else {

		//loop printing out stack of items within the vector
		int i{ 0 };
		int num{6};
		
		for (Item* item : items) {
			i++;
			std::cout << "(" << i << ") ";
			std::cout << item->getName() << " ";

			if (armor == item->getName() || weapon == item->getName()) {

				std::cout << "(equipped) ";

			}

			if (num == 6 && items.size() > num && i % num == 0) {

				std::cout << "\n";
				num = 8;

			}
			else if (num == 8 && items.size() > num && (i-6) % num == 0) {

				std::cout << "\n";

			}

		}

		std::cout << "\n";

	}



}

void Inventory::add(Item* item) {

	items.push_back(item);

}

// Need to add out of bounds testing and error...
void Inventory::remove(int itemNum) {
	delete items.at(itemNum);
	items.erase(items.begin() + itemNum);

}

void Inventory::clear() {

	for (Item* item : items) {

		delete item;
		
	}

	items.clear();

}

// Look into making this a util file if needed?
std::string Inventory::stringLower(std::string input) {

	std::transform(input.begin(), input.end(), input.begin(),
		[](unsigned char c) { return std::tolower(c); });

	return input;
}

int Inventory::processInput(std::string input) {
	
	int inputNum{0};
	try {

		inputNum = std::stoi(input);
		inputNum -= 1;

		if ((inputNum < 0) || (inputNum >= items.size())) {

			std::cout << inputNum + 1 << " not found.\nEnter item name (or cancel/0): ";
			std::cin >> input;

			if ((input == "cancel") || (input == "0")) {

				return -1;

			}
			else {

				return processInput(input);

			}

		}

	}
	catch (std::invalid_argument&) {
		
		input = stringLower(input);
		inputNum = element(input);

	}

	return inputNum;

}

int Inventory::element(std::string itemName) {

	for (int i{ 0 }; i < items.size(); i++) {
	
		if ((items[i]->getName()) == itemName) {

			return i;

		}

	}

	std::string input;
	std::cout << itemName << " not found.\nEnter item name (or cancel/0): ";
	std::cin >> input;
	input = stringLower(input);
	
	if ((input == "cancel") || (input == "0")) {

		return -1;

	}
	else {
		
		return processInput(input);

	}

}

std::vector<Item*>& Inventory::getItems() {

	return items;

}

int Inventory::processInputSafe(std::string input) {

	int inputNum{0};

	try {

		inputNum = std::stoi(input);
		inputNum -= 1;

		if ((inputNum < 0) || (inputNum >= (int)items.size())) {
			return -1;
		}

		return inputNum;
	}
	catch (std::invalid_argument&) {

		input = stringLower(input);
		inputNum = element(input);

		return inputNum; // element already returns index or -1
	}
}


