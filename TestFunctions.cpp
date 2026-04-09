#include <iostream>
#include <string>
#include "PLAYER.h"
#include "ITEM.h"
#include "WEAPON.h"
#include "Inventory.h"
#include "ARMOR.h"

void LoadObjects(Inventory& inv) {

	Item* weapon1 = new Weapon("knife", 7, 10);
	Item* armor1 = new Armor("breastplate", 10);
	Item* weapon2 = new Weapon("katana", 12, 7);
	Item* armor2 = new Armor("leather", 5);

	inv.add(weapon1);
	inv.add(armor1);
	inv.add(weapon2);
	inv.add(armor2);

}

int TestFunctions() {

	//Prompt user for specific tests...
	int userAnswer{ 0 };
	std::cout << "Would you like to test Player? (0(no)/1(yes))\n";
	std::cin >> userAnswer;
	if (userAnswer == 1) {

		//function call here
		std::cout << "Testing Player functions...\n";
		std::string playerName = "Player";
		std::cout << "Enter player name: ";
		std::cin >> playerName;
		Player player(playerName);
		std::cout << "Player name is: " << player.getPlayerName() << "\n";
		std::cout << "Player position is: (" << player.getPlayerX() << ", " << player.getPlayerY() << ")\n";
		std::cout << "Player health is: " << player.getPlayerHP() << "\n";
		std::cout << "How much damage do you deal to player? ";
		std::cin >> userAnswer;
		player.takeDamage(userAnswer);
		std::cout << "Current HP: " << player.getPlayerHP() << "\n";
		std::cout << "How much heal do you deal to player? ";
		std::cin >> userAnswer;
		player.healHealth(userAnswer);
		std::cout << "Current HP: " << player.getPlayerHP() << "\n";
		std::cout << "Player test complete.\n";

	}

	std::cout << "Would you like to test Item? (0(no)/1(yes))\n";
	std::cin >> userAnswer;
	if (userAnswer == 1) {

		//function call here
		std::cout << "Testing Item functions...\n";
		std::cout << "Making a base class item: sword...\n";
		Weapon weapon1("Sword", 10, 9);
		std::cout << "Item name is: " << weapon1.getName() << "\n";
		std::cout << "Weapon damage is: " << weapon1.getDmg() << "\n";

	}

	std::cout << "Would you like to test inventory? (0(no)/1(yes))\n";
	std::cin >> userAnswer;
	if (userAnswer == 1) {

		//function call here
		std::cout << "Testing inventory functions...\n";
		std::string input;
		std::cout << "Enter 'inventory' to access inventory: ";
		std::cin >> input;
		if (input == "inventory") {

			std::cout << "Successfully accessing inventory...\n";
			Inventory inv;
			LoadObjects(inv);
			inv.interface();
		}

	}

	std::cout << "End of test.\n";

	return 0;

}

