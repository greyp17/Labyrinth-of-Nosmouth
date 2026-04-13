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
	
		maze.Random_Gen(maze.getMazeHeight(), maze.getMazeWidth());
		
		// to skip the game loop and test functions, you can set this to -1.
		this->playerHP = 100;

		// mapArray value '2' represents the player
		// there should NEVER be more than one '2' on the map at a time.


		std::pair<int, int> playerPosition = { 1, 1 };
		while (this->playerHP > 0 && Game_Run == 0) {
			maze.Print_Map();
			
			// movement testing
			std::string input;
			std::cout << "To move, enter (w, a, s, d) and press enter.\n";
			std::cout << "Current position: (" << playerPosition.first << ", " << playerPosition.second << ")\n";
			// this will be done with buttons later, it's clunky rn, i know.

			std::cin >> input;
			std::cout << "\n\n\n"; // clears space between map prints

			if (input == "W" || input == "w") {
				if (maze.getMapArrayValue(playerPosition.first - 1, playerPosition.second) == 1 || maze.getMapArrayValue(playerPosition.first - 1, playerPosition.second) == -1) {
					std::cout << "You can't move there!\n";
				}
				else {
					maze.setMapArrayValue(playerPosition.first, playerPosition.second, 0); // sets old player position to 0 (path)
					playerPosition.first -= 1; // kinda counter-intuitive, subtracting moves player up (because 0,0 is the top left)
				}
			}
			else if (input == "S" || input == "s") {
				if (maze.getMapArrayValue(playerPosition.first + 1, playerPosition.second) == 1 || maze.getMapArrayValue(playerPosition.first + 1, playerPosition.second) == -1) {
					std::cout << "You can't move there!\n";
				}
				else {
					maze.setMapArrayValue(playerPosition.first, playerPosition.second, 0);
					playerPosition.first += 1;
				}
			}
			else if (input == "A" || input == "a") {
				if (maze.getMapArrayValue(playerPosition.first, playerPosition.second - 1) == 1 || maze.getMapArrayValue(playerPosition.first, playerPosition.second - 1) == -1) {
					std::cout << "You can't move there!\n";
				}
				else {
					maze.setMapArrayValue(playerPosition.first, playerPosition.second, 0);
					playerPosition.second -= 1;
				}
			}
			else if (input == "D" || input == "d") {
				if (maze.getMapArrayValue(playerPosition.first, playerPosition.second + 1) == 1 || maze.getMapArrayValue(playerPosition.first, playerPosition.second + 1) == -1) {
					std::cout << "You can't move there!\n";
				}
				else {
					maze.setMapArrayValue(playerPosition.first, playerPosition.second, 0);
					playerPosition.second += 1;
				}
			}
			else {
				std::cout << "Invalid input. Please enter up, down, left, or right.\n";
			}
			maze.setMapArrayValue(playerPosition.first, playerPosition.second, 2); // updates the actual vector mapArray with the new player position

			

		}
		NewGame();
	}
	return 0;
	// end garrison work
}
// grey work start
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