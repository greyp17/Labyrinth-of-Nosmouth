#include <iostream>
#include "Maze.h"
#include "RandomUtil.h"
#include "MAP.h"
#include "Global.h"
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
	mapArray.clear();
	mapArray.resize(mapHeight);

	// initializes all cells to 1 (wall)
	mapArray.assign(height, std::vector<int>(width, 1));

	// stack that tracks pairs of coordinates
	std::stack<std::pair<int, int>> cellStack;
	std::pair<int, int> startPoint = { 1, 1 };

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
bool Maze::isWalkable(int r, int c) const {
	if (!isValid(r, c)) return false; // Can't walk outside the world
	return mapArray[r][c] == 0;       // 0 is path, 1 is wall
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