#include <iostream>
#include "Maze.h"
#include "RandomUtil.h"
#include "MAP.h"
#include "Global.h"



// Function to randomly generate the map.
int Maze::Random_Gen(int mapArray[][25], int mapHeight, int mapWidth) {

	for (int width = 0; width < mapHeight; width++) {
		for (int height = 0; height < mapWidth; height++) {
			mapArray[width][height] = randomInt(0, 1);
		}
	}

	return 1;

}

// Function to print map.
int Maze::Print_Map(int mapArray[][25], int mapHeight, int mapWidth) {

	for (int width = 0; width < mapHeight; width++) {
		for (int height = 0; height < mapWidth; height++) {
			std::cout << mapArray[width][height];
		}
		std::cout << "\n";
	}

	return 1;

}