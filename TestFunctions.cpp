#include <iostream>
#include <string>
#include "PLAYER.h"

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

	}
	std::cout << "Would you like to test (testname)? (0(no)/1(yes))\n";
	std::cin >> userAnswer;
	if (userAnswer == 1) {

		//function call here
		std::cout << "Second test function call\n";

	}

	std::cout << "End of test.\n";

	return 0;

}