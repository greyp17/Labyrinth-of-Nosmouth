#include <iostream>
#include "Maze.h"
#include <random>
#include "MAP.h"
#include "Global.h"


int Maze::mazeGen() {
	std::cout << difficulty;
	// Placeholder for maze generation logic
	// This function should generate a maze based on the selected difficulty level
	// and return a representation of the maze (e.g., a 2D array or a string)
	if (1) {
		int RenderEasyMap[EasyHeight][EasyWidth] = {};
		for (int width = 0; width < EasyHeight; width++) {
			for (int height = 0; height < EasyWidth; height++) {
				std::cout << RenderEasyMap[width][height];
			}
			std::cout << "\n";
		}
	}
	else if (2) {
		int RenderMediumMap[MediumHeight][MediumWidth] = { 0 };
		for (int width = 0; width < MediumHeight; width++) {
			for (int height = 0; height < MediumWidth; height++) {
				std::cout << RenderMediumMap[width][height];
			}
			std::cout << "\n";
		}

	}
	else if (difficulty == 3) {
		int RenderHardMap[HardHeight][HardWidth] = { 0 };
		// Game loop for Hard difficulty
		for (int width = 0; width < HardHeight; width++) {
			for (int height = 0; height < HardWidth; height++) {
				std::cout << RenderHardMap[width][height];
			}
			std::cout << "\n";
		}
	}
	return 0; // Return value is just a placeholder
}