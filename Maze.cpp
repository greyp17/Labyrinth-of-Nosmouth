#include <iostream>
#include "Maze.h"
#include "RandomUtil.h"
#include "MAP.h"
#include "Global.h"
#include "LootTable.h"
#include "RandomUtil.h"
#include <vector>
#include <stack>
#include <algorithm>
#include <random>


/* OLD VERSION : randomly generates 0s and 1s, but doesn't guarantee a path from start to finish.
int Maze::Random_Gen(int mapHeight, int mapWidth) {
	mapArray.clear();
	mapArray.resize(mapHeight);

	this->height = mapHeight;
	this->width = mapWidth;

	for (int row = 0; row < mapHeight; ++row) {
		mapArray[row].reserve(mapWidth);
		for (int col = 0; col < mapWidth; ++col) {
			mapArray[row].push_back(1); // sets all cells to 1 (wall)
		}
	}
	return 1;
}*/

// start garrison work
// NEW VERSION: this is called a recursive backtracker. it's a little hard to explain
int Maze::Random_Gen(int mapHeight, int mapWidth) {
	std::random_device rd;
	std::default_random_engine rng(rd());

	this->height = mapHeight;
	this->width = mapWidth;	

	mapArray.clear();
	mapArray.resize(mapHeight);

	// initializes all cells to 1 (wall)
	mapArray.clear();
	mapArray.assign(height, std::vector<int>(mapWidth, 1));

	// stack that tracks pairs of coordinates
	std::stack<std::pair<int, int>> cellStack;
	std::pair<int, int> startPoint = { 1, 1 };

	if (mapHeight < 3 || mapWidth < 3) return -1; // Maze must be at least 3x3 to have a valid path

	// first cell (inside the outer wall layer) is the starting point, it gets set 0 (path)
	mapArray[1][1] = 0;
	cellStack.push(startPoint);

	while (!cellStack.empty()) {
		std::pair<int, int> currentCell = cellStack.top();

		// create other vector of cells that are 2 units away in every direction
		std::vector<std::pair<int, int>> neighbors;

		// need to be units of 2 to make paths between walls
		int directions[4][2] = { {0, 2}, {0, -2}, {2, 0}, {-2, 0} };

		for (int i = 0; i < 4; i++) {
			int newRow = currentCell.first + directions[i][0]; // checks the first value in directions, which is the row change
			int newCol = currentCell.second + directions[i][1]; // checks the second value in directions, which is the column change
			if (isValid(newRow, newCol) && mapArray[newRow][newCol] == 1) {
				neighbors.push_back({ newRow, newCol }); // if the cell is valid, add it to the neighbors vector
			}
		}

		if (!neighbors.empty()) {
			// for debugging: std::cout << "Current Cell: (" << currentCell.first << ", " << currentCell.second << ")\n";

			// randomly chooses neighbor
			std::shuffle(neighbors.begin(), neighbors.end(), rng);
			std::pair<int, int> nextCell = neighbors[0];

			// opens path between current cell and chosen neighbor
			int wallRow = (currentCell.first + nextCell.first) / 2;
			int wallCol = (currentCell.second + nextCell.second) / 2;
			mapArray[wallRow][wallCol] = 0;
			mapArray[nextCell.first][nextCell.second] = 0;
			cellStack.push(nextCell);
		}
		else {
			// if no neighbors, backtrack by going down the stack until the current cell has unvisited neighbors.
			cellStack.pop();
		}
	}
	int chestCount;
	int enemyCount;

	//this->setMapArrayValue(1, 1, 2); 

	//Generate chests and enemies based off of difficulty.
	if (height == 15 && width == 15) {
		chestCount = randomInt(3, 4);
		enemyCount = randomInt(4, 5);
	}
	else if (height == 25 && width == 25) {
		chestCount = randomInt(5, 6);
		enemyCount = randomInt(6, 7);
	} else {
		chestCount = randomInt(7, 8);
		enemyCount = randomInt(8, 9);
	}

	// Generate Chests into maze array in empty space
	while (chestCount > 0) {
		int r = randomInt(1, height - 2);
		int c = randomInt(1, width - 2);
		if (mapArray[r][c] == 0 && !(r == 1 && c == 1)) { // Only place a chest on a path cell
			
			mapArray[r][c] = 3; // 3 represents a chest
			chestCount--;
		}
	}

	// Generate Enemies into maze array in empty space
	// std::vector<std::pair<int,int>> enemyPos;
	while (enemyCount > 0) {
		int r = randomInt(1, height - 2);
		int c = randomInt(1, width - 2);
		if (mapArray[r][c] == 0 && !(r == 1 && c == 1)) { // Only place a enemy on a path cell
			mapArray[r][c] = 4; // 4 represents a enemy

			// Track enemy pos
			enemyPos.push_back({r, c});

			enemyCount--;
		}
	}

	mapArray[height - 2][width - 1] = 5; //5 is exit

	return 1;
}

void Maze::setMapArrayValue(int r, int c, int value) {
	if (isValid(r, c)) {
		mapArray[r][c] = value;
	}
}

int Maze::getMapArrayValue(int r, int c) const {
	if (isValid(r, c)) {
		return mapArray[r][c];
	}
	return -1; // Invalid coordinates (out of bounds)
}

// function to print map.
void Maze::Print_Map() {
	for (size_t r = 0; r < mapArray.size(); ++r) {
		for (size_t c = 0; c < mapArray[r].size(); ++c) {
			if (mapArray[r][c] == 1) {
				std::cout << "# "; // wall
			}
			else if (mapArray[r][c] == 2) {
				std::cout << "X "; // player
			}
			else if (mapArray[r][c] == 3) {
				std::cout << "C "; // chest
			}
			else if (mapArray[r][c] == 4) {
				std::cout << "E"; //Enemy
			}
			else {
				std::cout << "  "; // path
			}
		}
		std::cout << "\n";
	}
}

// checks if given coordinates are in grid
bool Maze::isValid(int r, int c) const {
	return (r >= 0 && r < height && c >= 0 && c < width);
}

// checks if given coordinates are walkable (not a wall)
bool Maze::isWalkable(int r, int c) {
	if (!isValid(r, c)) return false; // Can't walk outside the world

	int tile = mapArray[r][c];

	if (tile == 3) {

		void triggerChest();

	}
	else if (tile == 4) {

		// Logic to get rid of enemy on enemyPos
		for (int i = 0; i < enemyPos.size(); i++) {
			if (enemyPos[i].first == r && enemyPos[i].second == c) {
				enemyPos.erase(enemyPos.begin() + i);
				break;
			}
		}
		// Call to start combat

	}
	else if (tile == 5) {

		//exit to the maze... 


	}

	return (tile == 0 || tile == 3 || tile == 4 || tile == 5);       // 0 is path, 1 is wall, 3 is chest, 4 is enemy
}


void Maze::setMapArray(const std::vector<std::vector<int>>& array) {
	this->mapArray = array;
}

std::vector<std::vector<int>> Maze::getMapArray() const {
	return this->mapArray;
}

void Maze::setMazeHeight(int h) {
	this->height = h;
}

void Maze::setMazeWidth(int w) {
	this->width = w;
}

int Maze::getMazeHeight() {
	return this->height;
}

int Maze::getMazeWidth() {
	return this->width;
}
// end garrison work

void Maze::triggerChest() {

	player.invAdd(generateLoot());

}
/*
while (enemyCount > 0) {
	int r = randomInt(1, height - 2);
	int c = randomInt(1, width - 2);
	if (mapArray[r][c] == 0) { // Only place a enemy on a path cell
		mapArray[r][c] = 4; // 4 represents a enemy

		// Track enemy pos
		enemyPos.push_back({ r, c });

		enemyCount--;
	}
}
*/
void Maze::MoveEnemies() {

	//placeholder for moving enemies...
	for (int i{ 0 }; i < enemyPos.size(); i++) {

		int r = enemyPos[i].first;
		int c = enemyPos[i].second;

		int chance = randomInt(1, 10);
		int tries = 0;

		// Enemy 70% chance of moving
		if (chance > 3) {
			
			bool find = false;

			while (find == false && tries < 10) {

				int direction = randomInt(1, 4);

				// r is y, c is x
				// North... 1 up
				if (direction == 1) {

					if (mapArray[r - 1][c] == 0) {
						
						// say that its been found... stop loop
						find = true;
						// Change pos on the array
						mapArray[enemyPos[i].first][enemyPos[i].second] = 0;
						mapArray[enemyPos[i].first - 1][enemyPos[i].second] = 4;
						// Keeping track in the enemyPos
						enemyPos[i].first -= 1;

					}

				}
				// East... 1 right
				else if (direction == 2) {

					if (mapArray[r][c + 1] == 0) {

						// say that its been found... stop loop
						find = true;
						// Change pos on the array
						mapArray[enemyPos[i].first][enemyPos[i].second] = 0;
						mapArray[enemyPos[i].first][enemyPos[i].second + 1] = 4;
						// Keeping track in the enemyPos
						enemyPos[i].second += 1;

					}

				}
				// South... 1 down
				else if (direction == 3) {

					if (mapArray[r + 1][c] == 0) {

						// say that its been found... stop loop
						find = true;
						// Change pos on the array
						mapArray[enemyPos[i].first][enemyPos[i].second] = 0;
						mapArray[enemyPos[i].first + 1][enemyPos[i].second] = 4;
						// Keeping track in the enemyPos
						enemyPos[i].first += 1;

					}

				}
				// West... 1 left
				else {

					if (mapArray[r][c - 1] == 0) {

						// say that its been found... stop loop
						find = true;
						// Change pos on the array
						mapArray[enemyPos[i].first][enemyPos[i].second] = 0;
						mapArray[enemyPos[i].first][enemyPos[i].second - 1] = 4;
						// Keeping track in the enemyPos
						enemyPos[i].second -= 1;

					}

				}

				tries++;

			}

		}

	}

}