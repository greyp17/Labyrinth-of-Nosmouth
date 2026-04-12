#include <iostream>
#include <string>
#include "PLAYER.h"
#include "ITEM.h"
#include "WEAPON.h"
#include "Inventory.h"
#include "ARMOR.h"
#include "Combat.h"
#include "ENEMY.h"

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
		std::cout << "Player name is: " << player.getCharacterName() << "\n";
		std::cout << "Player position is: (" << player.getCharacterX() << ", " << player.getCharacterY() << ")\n";
		std::cout << "Player health is: " << player.getHealth() << "\n";
		std::cout << "How much damage do you deal to player? ";
		std::cin >> userAnswer;
		player.takeDamage(userAnswer);
		std::cout << "Current HP: " << player.getHealth() << "\n";
		std::cout << "How much heal do you deal to player? ";
		std::cin >> userAnswer;
		player.healHealth(userAnswer);
		std::cout << "Current HP: " << player.getHealth() << "\n";
		std::cout << "Player test complete.\n";

	}

	std::cout << "Would you like to test Item? (0(no)/1(yes))\n";
	std::cin >> userAnswer;
	if (userAnswer == 1) {

		//function call here
		std::cout << "Testing Item functions...\n";
		std::cout << "Making a base class item: sword...\n";
		Weapon weapon1("Sword", "weapon", 10, 9);
		std::cout << "Item name is: " << weapon1.getName() << "\n";
		std::cout << "Weapon damage is: " << weapon1.getDmg() << "\n";

	}

	std::cout << "Would you like to test Inventory? (0(no)/1(yes))\n";
	std::cin >> userAnswer;
	if (userAnswer == 1) {

		//function call here
		std::cout << "Testing inventory functions...\n";
		std::string input;
		std::cout << "Enter 'inventory' to access inventory: ";
		std::cin >> input;
		if (input == "inventory") {

			std::cout << "Successfully accessing inventory...\n";

			Player player("Hero");

			//Do this for inventory loop
			player.getInventory().interface(player);
		}

	}

	std::cout << "Would you like to test Combat? (0(no)/1(yes))\n";
	std::cin >> userAnswer;
	if (userAnswer == 1) {

		//function call here
		std::cout << "Testing Combat functions...\n";
		std::string input;

		Enemy enemy("Bandit");
		Player player("Hero");

		int result = combatStart(player, enemy);
		
		if (result == 1) {

			std::cout << "Player wins.\n";

		}
		else if (result == 0) {

			std::cout << "Player loses.\n";

		}

	}

	std::cout << "End of test.\n";

	return 0;

}

