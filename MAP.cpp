#include "MAP.h"
#include "TestFunctions.h"
#include <iostream>
#include <vector>
#include "RandomUtil.h"
#include "Global.h"
#include "Maze.h"

// garrison work start
int MAP::RunGame() {
	while (Game_Run == 0) {
		Maze maze;
		if (difficulty == 1) {
			// these height + width values MUST ALL BE ODD NUMBERS for maze to be enclosed!!!
			maze.setMazeHeight(25);
			maze.setMazeWidth(25);
		}
		else if (difficulty == 2) {
			maze.setMazeHeight(25);
			maze.setMazeWidth(35);
		}
		else if (difficulty == 3) {
			maze.setMazeHeight(25);
			maze.setMazeWidth(45);
		}
		else {
			std::cout << "pick a new difficulty Easy(1) Medium(2) Hard(3)\n";
			std::cin >> difficulty;
			continue;
		}

		std::vector<std::vector<int>> mapArray(maze.getMazeHeight(), std::vector<int>(maze.getMazeWidth()));

		// grey work start
		maze.Random_Gen(maze.getMazeHeight(), maze.getMazeWidth());
		this->playerHP = 100;
		while (this->playerHP > 0 && Game_Run == 0) {
			// Game loop for Easy difficulty
			maze.Print_Map();
			this->playerHP -= 100;
			if (this->playerHP <= 0) {
				NewGame();
			}
		}

	}
	return 0;
}

int MAP::NewGame() {
	std::cout << "Game Over!" << "\n";

	int Play_again = -1;

	//Garrison did exception handling only
	while (Play_again != 0 && Play_again != 1) {
		try {

			int testFunction{ 0 };
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
		catch (const std::exception& e) {
			std::cout << "Error: " << e.what() << "\n";
			Play_again = -1; // resets
		}
	}
	// end grey work
	// end Garrison work
	return 0;
}