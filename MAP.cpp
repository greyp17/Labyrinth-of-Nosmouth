//grey code starts here
#include "MAP.h"
#include "TestFunctions.h"
#include <iostream>
#include <vector>
#include "RandomUtil.h"
#include "Global.h"
#include "Maze.h"


int MAP::RunGame() {
    while (Game_Run == 0) {
		Maze maze;
		if (difficulty == 1) {
			int RenderEasyMap[EasyWidth][EasyHeight];
			maze.Random_Gen( RenderEasyMap, EasyHeight, EasyWidth);
			this->playerHP = 100;
			while (this->playerHP > 0 && Game_Run == 0) {
				// Game loop for Easy difficulty
				 maze.Print_Map( RenderEasyMap, EasyHeight, EasyWidth);
				this->playerHP -= 100;
				if (this->playerHP <= 0) {
					NewGame();
				}
			}
		}
		else if (difficulty == 2) {
			int RenderMediumMap[MediumWidth][MediumHeight] = { 0 };
			maze.Random_Gen(RenderMediumMap, MediumHeight, MediumWidth);
			this->playerHP = 100;
			while (this->playerHP > 0 && Game_Run == 0) {
				// Game loop for Medium difficulty
				maze.Print_Map( RenderMediumMap,  MediumHeight,  MediumWidth);
				this->playerHP -= 100;
				if (this->playerHP <= 0) {
					NewGame();
				}
			}
		}
		else if (difficulty == 3) {
			int RenderHardMap[HardWidth][HardHeight] = { 0 };
			maze.Random_Gen(RenderHardMap, HardHeight, HardWidth);
			this->playerHP = 100;
			while (this->playerHP > 0 && Game_Run == 0) {
				// Game loop for Hard difficulty
				 maze.Print_Map( RenderHardMap,  HardHeight, HardWidth);
				this->playerHP -= 100;
				if (this->playerHP <= 0) {
					NewGame();
				}
			}
		}
		else {
			std::cout << "pick a new difficulty Easy(1) Medium(2) Hard(3)\n";
			std::cin >> difficulty;
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
				std::cin >> difficulty;
				RunGame();
			}
			else if (Play_again == 0) {
				std::cout << "Thanks for playing!" << "\n";
				Game_Run = 1;
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

