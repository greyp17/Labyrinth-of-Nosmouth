#include "Inventory.h"
#include "ITEM.h"
#include <vector>
#include <string>
#include <iostream>

// TO DO: make it accept lowercase, make a function that the others go through to use items (optimize code)
//		  more bounds checking, make acceptable command like "Remove 1" instead of whole process.

void Inventory::interface() {

	std::string input;
	display();
	std::cout << "Commands: Exit, Inspect, Use, Remove\n";
	std::cin >> input;

	if (input == "Exit") {

		// exit from inventory interface
		return;

	} 
	else if (input == "Inspect") {

		// display stats of item
		std::cout << "Which item? ";
		std::cin >> input;
		std::cout << "Displaying stats...\n"; //placeholder
		interface();

	}
	else if (input == "Use") {

		// call function to use item. add polymorphism to handle usage of potions vs other items
		std::cout << "Which item? ";
		std::cin >> input;
		std::cout << "Using item...\n"; //placeholder
		interface();

	}
	else if(input == "Remove") {

		// Remove item from inventory
		std::cout << "Which item? ";
		std::cin >> input;

		int inputNum{-99};
		try {

			inputNum = std::stoi(input);  
		
		}
		catch (std::invalid_argument&) {
			
			// Input is a string

		}

		std::cout << "Are you sure you would like to delete " << input << "? ";
		std::string inp;
		std::cin >> inp;

		if ((inp == "yes") || (inp == "1")) {
			
			if (inputNum == -99) {
				remove(input);
			}
			else {
				remove(inputNum);
			}

			interface();

		}
		else {

			interface();

		}


	}
	else {

		std::cout << "Not valid command.\nExiting inventory interface...\n";
		return;

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
	itemNum -= 1;
	delete items.at(itemNum);
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

	std::string input;
	std::cout << itemName << " not found.\nEnter item name (or cancel/0): ";
	std::cin >> input;

	if ((input == "cancel") || (input == "0")) {

		return 0;

	}
	else {

		element(input);

	}

}



