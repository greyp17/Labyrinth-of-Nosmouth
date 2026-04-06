//grey code starts here
#include "MAP.h"
#include "TestFunctions.h"
#include <iostream>
#include <vector>
#include <random>

int MAP::RunGame() {
    while (this->Game_Run == 0) {
		if (this->difficulty == 1) {
			int RenderEasyMap[EasyHeight][EasyWidth] = {this->Random_Gen()};
			this->playerHP = 100;
			while (this->playerHP > 0 && this->Game_Run == 0) {
				// Game loop for Easy difficulty
				for (int width = 0; width < EasyHeight; width++) {
					for (int height = 0; height < EasyWidth; height++) {
						std::cout << RenderEasyMap[width][height];
					}
					std::cout << "\n";
				}
				this->playerHP -= 100;
				if (this->playerHP <= 0) {
					this->NewGame();
				}
			}
		}
		else if (this->difficulty == 2) {
			int RenderMediumMap[MediumHeight][MediumWidth] = { 0 };
			this->playerHP = 100;
			while (this->playerHP > 0 && this->Game_Run == 0) {
				// Game loop for Medium difficulty
				for (int width = 0; width < MediumHeight; width++) {
					for (int height = 0; height < MediumWidth; height++) {
						std::cout << RenderMediumMap[width][height];
					}
					std::cout << "\n";
				}
				this->playerHP -= 100;
				if (this->playerHP <= 0) {
					this->NewGame();
				}
			}
		}
		else if (this->difficulty == 3) {
			int RenderHardMap[HardHeight][HardWidth] = { 0 };
			this->playerHP = 100;
			while (this->playerHP > 0 && this->Game_Run == 0) {
				// Game loop for Hard difficulty
				for (int width = 0; width < HardHeight; width++) {
					for (int height = 0; height < HardWidth; height++) {
						std::cout << RenderHardMap[width][height];
					}
					std::cout << "\n";
				}
				this->playerHP -= 100;
				if (this->playerHP <= 0) {
					this->NewGame();
				}
			}
		}
		else if (this->Game_Run == 1) {
			std::cout << "Bye Bye" << "\n";
			return 0;
		}
		else {
			std::cout << "pick a new difficulty Easy(1) Medium(2) Hard(3)\n";
			std::cin >> this->difficulty;
		}
	}
	return 0;
}

int MAP::NewGame() {
    std::cout << "Game Over!" << "\n";

	int Play_again = -1;

	//Garrison did exception handling only
	while (Play_again != 0 && Play_again != 1) {
		try{
			
			int testFunction{0};
			// Temporary testing...
			std::cout << "Would you like to test functions? (0(no)/1(yes))\n";
			std::cin >> testFunction;

			if (testFunction == 1) {

				TestFunctions();

			}
			
			std::cout << "play again? (0(no)/1(yes))" << "\n";
			std::cin >> Play_again;

			if (Play_again == 1) {
				std::cout << "Please select a difficulty level Easy(1) Medium(2) Hard(3):" << "\n";
				std::cin >> this->difficulty;
				this->RunGame();
			}
			else if (Play_again == 0) {
				std::cout << "Thanks for playing!" << "\n";
				this->Game_Run = 1;
			}
			else {
				throw std::out_of_range("Invalid input. Please enter 0 or 1.");
			}
		}
		catch (const std::exception& e){
			std::cout << "Error: " << e.what() << "\n";
			Play_again = -1; // resets
		}
	}
	//end Garrison work
	return 0;
}

// Added a randomInt function from RandomUtil if we do this.
int MAP::Random_Gen() {
		std::random_device rd;
		std::default_random_engine engine{rd()};
		std::uniform_int_distribution<> maze{0,1};
		int tile = maze(engine);
		return 0;
}
//grey code ends here
