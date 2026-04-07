#include <iostream>
#include <string>
#include "PLAYER.h"
#include "ITEM.h"
#include "WEAPON.h"

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
		std::string itemName = "Sword";
		int weaponDmg = 10;
		Weapon weapon1(itemName, weaponDmg);
		std::cout << "Item name is: " << weapon1.getItemName() << "\n";
		std::cout << "Weapon damage is: " << weapon1.getWeaponDmg() << "\n";

	}

	std::cout << "Would you like to test (testname)? (0(no)/1(yes))\n";
	std::cin >> userAnswer;
	if (userAnswer == 1) {

		//function call here
		std::cout << "Third test function call\n";



	}

	std::cout << "End of test.\n";

	return 0;

}