#include "Inventory.h"
#include "ITEM.h"
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include <cctype>

// TO DO: make a deconstructor instead of function for it

void Inventory::interface() {

	std::string input;
	int inputNum;
	int invLoop{1};

	while (invLoop == 1) {

		display();
		std::cout << "Commands: Exit, Inspect, Use/Equip, Remove\n";
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

			std::cout << "Displaying stats for " << input << "...\n";
			items.at(inputNum)->inspect();

		}
		else if (input == "use" || input == "equip") {

			// call function to use item. add polymorphism to handle usage of potions vs other items
			std::cout << "Which item? ";
			std::cin >> input;

			// With processInput now have the index for the item.
			inputNum = processInput(input);
			if (inputNum == -1) {
				continue;
			}
			
			items.at(inputNum)->use();

		}
		else if (input == "remove") {

			// Remove item from inventory
			std::cout << "Which item? ";
			std::cin >> input;

			// With processInput now have the index for the item.
			inputNum = processInput(input);
			if (inputNum == -1) {
				continue;
			}
			input = items.at(inputNum)->getName();
			//Another out of bounds error here to fix ^^^ try catch for out of bounds to reinput?

			std::cout << "Are you sure you would like to delete " << input << "? ";
			std::string inp;
			std::cin >> inp;
			inp = stringLower(inp);

			if ((inp == "yes") || (inp == "1")) {

				remove(inputNum);

			}

		}
		else {

			std::cout << "Not valid command.\n";
			continue;

		}



	}

}

void Inventory::display() {

	std::cout << "Inventory: ";

	if (items.size() == 0) {

		std::cout << "(empty)\n";

	}
	else {

		//loop printing out stack of items within the vector
		int i{ 0 };
		for (Item* item : items) {
			i++;
			std::cout << "(" << i << ") ";
			std::cout << item->getName() << " ";

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
	std::cout << itemName << " not found2.\nEnter item name (or cancel/0): ";
	std::cin >> input;
	input = stringLower(input);
	
	if ((input == "cancel") || (input == "0")) {

		return -1;

	}
	else {
		
		return processInput(input);

	}

}

